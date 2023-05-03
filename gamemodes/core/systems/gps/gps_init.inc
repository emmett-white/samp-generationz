#if defined _INC_gps_init_inc
    #endinput
#endif
#define _INC_gps_init_inc

#include <YSI_Coding\y_hooks>

const MAX_GPS = 20;

static
    gpsID[MAX_GPS],
    gpsCreated[MAX_GPS],
    gpsName[MAX_GPS][32],
    Float:gpsX[MAX_GPS],
    Float:gpsY[MAX_GPS],
    Float:gpsZ[MAX_GPS],
    gpsStoreString[YSI_MAX_STRING],
    gpsCheckpoint[MAX_PLAYERS],
    Float:gpsCheckpointX[MAX_PLAYERS],
    Float:gpsCheckpointY[MAX_PLAYERS],
    Float:gpsCheckpointZ[MAX_PLAYERS],
    gpsTimer[MAX_PLAYERS],
    gpsTotal;

forward GPS_ShowDistance(const playerid);
public GPS_ShowDistance(const playerid)
{
    new Float:gpsDistance = GetPlayerDistanceFromPoint(playerid, gpsCheckpointX[playerid], gpsCheckpointY[playerid], gpsCheckpointZ[playerid]);
    UI_ShowInfoMessage(playerid, 1000, "Preostalo ~y~%0.2fm ~w~do lokacije.", gpsDistance);
}

hook OnGameModeInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM gps", "GPS_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if (gpsCheckpoint[playerid])
    {
        DisablePlayerCheckpoint(playerid);
        GameTextForPlayer(playerid, "Stigli ste na odrediste!", 1000, 1);
        KillTimer(gpsTimer[playerid]);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward GPS_Load();
public GPS_Load()
{
    if (!cache_num_rows())
        return 0;

    static rows;
    cache_get_row_count(rows);

    for (new i = 0; i < rows; i++)
    {
        cache_get_value_name_int(i, "gps_id", gpsID[i]);
        cache_get_value_name(i, "gps_name", gpsName[i]);
        cache_get_value_name_float(i, "gps_x", gpsX[i]);
        cache_get_value_name_float(i, "gps_y", gpsY[i]);
        cache_get_value_name_float(i, "gps_z", gpsZ[i]);

        format(gpsStoreString, sizeof(gpsStoreString), "%s[%d]. %s\n", gpsStoreString, gpsID[i], gpsName[i]);
        gpsCreated[i] = 1;

        gpsTotal++;
    }

    printf("[GPS]: Ucitano %d gps.", gpsTotal);
    return 1;
}

stock GPS_Create(const gpsid, const gpsname[], Float:gpsx, Float:gpsy, Float:gpsz)
{
    gpsID[gpsid] = gpsid;
    gpsX[gpsid] = gpsx;
    gpsY[gpsid] = gpsy;
    gpsZ[gpsid] = gpsz;
    gpsCreated[gpsid] = 1;

    strcopy(gpsName[gpsid], gpsname);
    format(gpsStoreString, sizeof(gpsStoreString), "%s[%d]. %s\n", gpsStoreString, gpsID[gpsid] + 1, gpsName[gpsid]);

    new String:str_query_insert = str_format(
        "INSERT INTO gps (gps_id, gps_name, gps_x, gps_y, gps_z) VALUES ('%d', '%e', '%f', '%f', '%f')",
        gpsid + 1, gpsName[gpsid], gpsX[gpsid], gpsY[gpsid], gpsZ[gpsid]
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
    return 1;
}

stock GPS_ShowMenu(const playerid)
{
    Dialog_Show(playerid, "DIALOG_GPSMENU", DIALOG_STYLE_LIST, "GPS - Lokacije", gpsStoreString, "Odaberi", "Izlaz");
    return 1;
}

stock GPS_GetNextID()
{
    for (new i = 0; i < MAX_GPS; i++)
        if (!gpsCreated[i])
            return i;
    return MAX_GPS;
}

Dialog:DIALOG_GPSMENU(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    task_await(
        MySQL_QueryS(
            str_format("SELECT * FROM gps WHERE gps_id = '%d'", listitem + 1)
        )
    );

    if (cache_num_rows())
    {
        SendInfoMsgF(playerid, "Lokacija "ORANGE"%s "WHITE"je oznacena na mapi.", gpsName[listitem]);
        SetPlayerCheckpoint(playerid, gpsX[listitem], gpsY[listitem], gpsZ[listitem], 3.00);

        gpsCheckpointX[playerid] = gpsX[listitem];
        gpsCheckpointY[playerid] = gpsY[listitem];
        gpsCheckpointZ[playerid] = gpsZ[listitem];
        gpsTimer[playerid] = SetTimerEx("GPS_ShowDistance", 1000, true, "d", playerid);
        gpsCheckpoint[playerid] = 1;
    }
    return 1;
}