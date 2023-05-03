#if defined _INC_house_init_inc
    #endinput
#endif
#define _INC_house_init_inc

#include <YSI_Coding\y_hooks>

const MAX_HOUSES = 200;

static
    houseTotal,
    houseID[MAX_HOUSES],
    houseCreated[MAX_HOUSES],
    housePickup[MAX_HOUSES],
    houseMapIcon[MAX_HOUSES],
    housePrice[MAX_HOUSES],
    houseVW[MAX_HOUSES],
    houseLocked[MAX_HOUSES],
    houseOwned[MAX_HOUSES],
    Text3D:houseLabel[MAX_HOUSES],
    houseOwner[MAX_HOUSES][MAX_PLAYER_NAME],
    houseDesc[MAX_HOUSES][MAX_REASON_LENGTH],
    Float: houseExtX[MAX_HOUSES],
    Float: houseExtY[MAX_HOUSES],
    Float: houseExtZ[MAX_HOUSES],
    Float: houseIntX[MAX_HOUSES],
    Float: houseIntY[MAX_HOUSES],
    Float: houseIntZ[MAX_HOUSES];

public Float: House_GetPos(const houseid, const index)
{
    static Float:ret = -1.00;
    switch (index)
    {
        case 0: ret = houseExtX[houseid];
        case 1: ret = houseExtY[houseid];
        case 2: ret = houseExtZ[houseid];
    }
    return ret;
}

hook OnGameModeInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM houses", "House_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SECONDARY_ATTACK))
    {
        for (new i; i < MAX_HOUSES; i++)
        {
            if (!houseCreated[i])
                break;

            if (IsPlayerInRangeOfPoint(playerid, 2.0, houseExtX[i], houseExtY[i], houseExtZ[i]))
            {
                if (Account_GetHouse(playerid) == i || !House_IsLocked(i))
                {
                    SetPlayerVirtualWorld(playerid, houseVW[i]);
                    Streamer_UpdateEx(playerid, houseIntX[i], houseIntY[i], houseIntZ[i], houseVW[i], .compensatedtime = 2000);
                }
                else
                    return GameTextForPlayer(playerid, "~r~KUCA JE ZAKLJUCANA!", 3000, 3);
            }
        
            if (IsPlayerInRangeOfPoint(playerid, 2.0, houseIntX[i], houseIntY[i], houseIntZ[i]) && GetPlayerVirtualWorld(playerid) == houseVW[i])
            {
                SetPlayerVirtualWorld(playerid, 0);
                Streamer_UpdateEx(playerid, houseExtX[i], houseExtY[i], houseExtZ[i], 0, .compensatedtime = 2000);
                return 1;
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward House_Load();
public House_Load()
{
    if (!cache_num_rows())
        return 0;

    new
        tmpString[128],
        rows;

    cache_get_row_count(rows);
    for (new i = 0; i < rows; i++)
    {
        cache_get_value_name_int(i, "house_id", houseID[i]);
        cache_get_value_name_int(i, "house_owned", houseOwned[i]);
        cache_get_value_name_int(i, "house_locked", houseLocked[i]);
        cache_get_value_name_int(i, "house_price", housePrice[i]);
        cache_get_value_name(i, "house_owner", houseOwner[i]);
        cache_get_value_name(i, "house_desc", houseDesc[i]);
        cache_get_value_name_int(i, "house_vw", houseVW[i]);
        cache_get_value_name_float(i, "house_extx", houseExtX[i]);
        cache_get_value_name_float(i, "house_exty", houseExtY[i]);
        cache_get_value_name_float(i, "house_extz", houseExtZ[i]);
        cache_get_value_name_float(i, "house_intx", houseIntX[i]);
        cache_get_value_name_float(i, "house_inty", houseIntY[i]);
        cache_get_value_name_float(i, "house_intz", houseIntZ[i]);

        if (houseOwned[i])
        {
            format(tmpString, sizeof(tmpString), "[KUCA - %d]\nVlasnik: %s\nOpis: %s\nCena: $%d", i, houseOwner[i], houseDesc[i], housePrice[i]);
            houseMapIcon[i] = CreateDynamicMapIcon(houseExtX[i], houseExtY[i], houseExtZ[i], 32, 1);
        }

        else
        {
            format(tmpString, sizeof(tmpString), "[KUCA - %d]\nOva kuca je na prodaju!\nVlasnik: %s\nOpis: %s\nCena: $%d\nDa kupite kucu kucajte /kupikucu!", i, houseOwner[i], houseDesc[i], housePrice[i]);
            houseMapIcon[i] = CreateDynamicMapIcon(houseExtX[i], houseExtY[i], houseExtZ[i], 31, 1);
        }

        houseCreated[i] = 1;
        houseLabel[i] = CreateDynamic3DTextLabel(tmpString, X11_GREEN, houseExtX[i], houseExtY[i], houseExtZ[i], 30.0);
        housePickup[i] = CreateDynamicPickup(1272, 1, houseExtX[i], houseExtY[i], houseExtZ[i]);

        houseTotal++;
    }
    printf("[HOUSES]: Ucitano %d kuca.", houseTotal);
    return 1;
}

stock House_GetMaxHouses() return MAX_HOUSES;
stock House_GetOwner(const houseid) return houseOwner[houseid];
stock House_GetDescription(const houseid) return houseDesc[houseid];
stock House_GetPrice(const houseid) return housePrice[houseid];
stock House_IsLocked(const houseid) return houseLocked[houseid];
stock House_HasOwner(const houseid) return houseOwned[houseid];
stock House_GetVW(const houseid) return houseVW[houseid];
stock House_Create(const playerid, const houseid, const price, Float: x, Float: y, Float: z)
{
    strcopy(houseOwner[houseid], "Niko");
    strcopy(houseDesc[houseid], "Na prodaju");

    houseID[houseid] = houseid;
    housePrice[houseid] = price;
    houseCreated[houseid] =
    houseLocked[houseid] = 1;
    houseOwned[houseid] = 0;
    houseVW[houseid] = houseid;
    houseExtX[houseid] = x;
    houseExtY[houseid] = y;
    houseExtZ[houseid] = z;
    houseIntX[houseid] = -277.4879;
    houseIntY[houseid] = 1584.5845;
    houseIntZ[houseid] = 462.7619;

    static tmpString[128];
    format(tmpString, sizeof(tmpString), "[KUCA - %d]\nOva kuca je na prodaju!\nVlasnik: %s\nOpis: %s\nCena: $%d\nDa kupite kucu kucajte /kupikucu!",
        houseid, houseOwner[houseid], houseDesc[houseid], housePrice[houseid]
    );

    houseLabel[houseid] = CreateDynamic3DTextLabel(tmpString, X11_GREEN, houseExtX[houseid], houseExtY[houseid], houseExtZ[houseid], 30.00);
    housePickup[houseid] = CreateDynamicPickup(1272, 1, houseExtX[houseid], houseExtY[houseid], houseExtZ[houseid]);
    houseMapIcon[houseid] = CreateDynamicMapIcon(houseExtX[houseid], houseExtY[houseid], houseExtZ[houseid], 31, 1);

    SendServerMsgF(playerid, "Kreirali ste kucu! ID Kuce: %d", houseid);
    return 1;
}

stock House_Destroy(const playerid, const houseid)
{
    houseCreated[houseid] = 0;
    houseID[houseid] = MAX_HOUSES;

    DestroyDynamicPickup(housePickup[houseid]);
    DestroyDynamicMapIcon(houseMapIcon[houseid]);
    DestroyDynamic3DTextLabel(houseLabel[houseid]);
    SendServerMsgF(playerid, "Obrisali ste kucu! ID Kuce: %d", houseid);
    return 1;
}

stock House_Buy(const playerid, const houseid)
{
    SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kuca): "WHITE"Uspesno ste kupili kucu za $%d!", House_GetPrice(houseid));
    houseOwned[houseid] = 1;
    strcopy(houseOwner[houseid], ReturnPlayerName(playerid));
    strcopy(houseDesc[houseid], "");

    new tmpString[50 + MAX_PLAYER_NAME];
    format(tmpString, sizeof(tmpString), "[KUCA - %d]\nVlasnik: %s\nOpis: %s\nCena: $%d",
        houseid, ReturnPlayerName(playerid), houseDesc[houseid], House_GetPrice(houseid)
    );
    UpdateDynamic3DTextLabelText(houseLabel[houseid], X11_GREEN, tmpString);

    DestroyDynamicMapIcon(houseMapIcon[houseid]);
    houseMapIcon[houseid] = CreateDynamicMapIcon(houseExtX[houseid], houseExtY[houseid], houseExtZ[houseid], 32, 1);
    return 1;
}

stock House_SetDescription(const houseid, const string: desc[])
{
    strcopy(houseDesc[houseid], desc);
    new String: str_query_update = str_format(
        "UPDATE houses SET house_desc = '%e' WHERE house_id = '%d'", desc, (houseid + 1)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);

    new fmt[50 + MAX_PLAYER_NAME];
    format(fmt, sizeof(fmt), "[KUCA - %d]\nVlasnik: %s\nOpis: %s\nCena: $%d",
        houseid, House_GetOwner(houseid), houseDesc[houseid], House_GetPrice(houseid)
    );
    UpdateDynamic3DTextLabelText(houseLabel[houseid], X11_GREEN, fmt);
    return 1;
}

stock House_SetLocked(const houseid, const value)
{
    houseLocked[houseid] = value;
    new String: str_query_update = String: str_format(
        "UPDATE houses SET house_locked = '%d' WHERE house_id = '%d'", House_IsLocked(houseid), (houseid + 1)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}

stock House_Goto(const playerid, const houseid)
{
    if (!houseID[houseid] || houseID[houseid] < 0)
        return 0;

    Streamer_UpdateEx(playerid, houseExtX[houseid], houseExtY[houseid] + 2.00, houseExtZ[houseid], .compensatedtime = 2000);
    if (IsPlayerInAnyVehicle(playerid))
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        SetVehiclePos(vehicleid, houseExtX[houseid] + 2.00, houseExtY[houseid], houseExtZ[houseid]);
        PutPlayerInVehicle(playerid, vehicleid, 0);
    }
    return 1;
}

stock House_GetNextID()
{
    for (new i = 0; i < MAX_HOUSES; ++i)
        if (!houseCreated[i])
            return i;
    return MAX_HOUSES;
}

stock House_GetNearby(const playerid)
{
    for (new i = 0; i < MAX_HOUSES; ++i)
        if (IsPlayerInRangeOfPoint(playerid, 2.0, houseExtX[i], houseExtY[i], houseExtZ[i]))
            return i;
    return MAX_HOUSES;
}

stock House_GetNearbyInt(const playerid)
{
    for (new i = 0; i < MAX_HOUSES; ++i)
        if (IsPlayerInRangeOfPoint(playerid, 2.0, houseIntX[i], houseIntY[i], houseIntZ[i]))
            return i;
    return MAX_HOUSES;
}

stock House_OpenMenu(const playerid)
{
    if (Account_GetHouse(playerid) == -1)
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Nemate kucu!");

    new houseid = House_GetNearby(playerid);
    if (houseid == House_GetMaxHouses())
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Morate biti blizu kuce!");

    if (strcmp(ReturnPlayerName(playerid), House_GetOwner(houseid)))
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Morate biti kod svoje kuce!");

    static tmpString[32];
    strcopy(tmpString, (!House_IsLocked(houseid) ? (""DARKRED"Zakljucaj") : (""LIGHTGREEN"Otkljucaj")));

    Dialog_Show(playerid, "DIALOG_HOUSEMENU", DIALOG_STYLE_LIST,
        ""MAIN_COLOR"GENERATIONZ - "WHITE"Kuca",
        "Promeni opis kuce\n%s kucu\nProdaj kucu",
        ""MAIN_COLOR"Potvrdi", "Izlaz", tmpString
    );
    return 1;
}