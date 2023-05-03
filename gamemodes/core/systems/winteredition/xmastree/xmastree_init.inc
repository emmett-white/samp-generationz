#if defined _INC_xmastree_init_inc
    #endinput
#endif
#define _INC_xmastree_init_inc

#include <YSI_Coding\y_hooks>

const MAX_XMAS_TREE = 50;

static xmasTreeTotal,
    xmasTreeID[MAX_XMAS_TREE],
    xmasTreeObj[MAX_XMAS_TREE],
    xmasTreeCreated[MAX_XMAS_TREE],
    Text3D:xmasTreeLabel[MAX_XMAS_TREE],
    Float:xmasTreeX[MAX_XMAS_TREE],
    Float:xmasTreeY[MAX_XMAS_TREE],
    Float:xmasTreeZ[MAX_XMAS_TREE];

hook OnGameModeInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM xmastree", "Xmas_LoadTrees");
    return 1;
}

forward Xmas_LoadTrees();
public Xmas_LoadTrees()
{
    if (!cache_num_rows())
        return 0;

    new rows, tmpString[128];
    cache_get_row_count(rows);

    for (new i = 0; i < rows; i++)
    {
        cache_get_value_name_int(i, "xmas_id", xmasTreeID[i]);
        cache_get_value_name_float(i, "xmas_x", xmasTreeX[i]);
        cache_get_value_name_float(i, "xmas_y", xmasTreeY[i]);
        cache_get_value_name_float(i, "xmas_z", xmasTreeZ[i]);
    
        xmasTreeCreated[i] = 1;

        xmasTreeObj[i] = CreateDynamicObject(
            19076, xmasTreeX[i], xmasTreeY[i], xmasTreeZ[i] - 2.00, 0.0, 0.0, 0.0, .streamdistance = 500.00, .drawdistance = 500.00
        );

        format(tmpString, sizeof(tmpString), ""YELLOW"[JELKA - "WHITE"%d"YELLOW"]\n- Zelimo Vam srecne praznike, uzivajte! - ", i);
        xmasTreeLabel[i] = CreateDynamic3DTextLabel(tmpString, -1, xmasTreeX[i], xmasTreeY[i], xmasTreeZ[i], 50.00);
        xmasTreeTotal++;
    }

    printf("[XMAS TREE]: Ucitano %d jelki.", xmasTreeTotal);
    return 1;
}

stock Xmas_GetMaxTrees() return MAX_XMAS_TREE;
stock Xmas_CreateTree(const xmasid, Float:x, Float:y, Float:z)
{
    xmasTreeID[xmasid] = xmasid;
    xmasTreeCreated[xmasid] = 1;
    xmasTreeX[xmasid] = x;
    xmasTreeY[xmasid] = y;
    xmasTreeZ[xmasid] = z;
    xmasTreeObj[xmasid] = CreateDynamicObject(
        19076, x, y, z - 2.00, 0.0, 0.0, 0.0, .streamdistance = 500.00, .drawdistance = 500.00
    );

    static tmpString[128];
    format(tmpString, sizeof(tmpString), ""YELLOW"[JELKA - "WHITE"%d"YELLOW"]\n- Zelimo Vam srecne praznike, uzivajte! - ", xmasTreeID[xmasid]);
    xmasTreeLabel[xmasid] = CreateDynamic3DTextLabel(tmpString, -1, x, y, z, 50.00);
    return 1;
}

stock Xmas_DestroyTree(const xmasid)
{
    xmasTreeCreated[xmasid] = 0;
    xmasTreeID[xmasid] = MAX_XMAS_TREE;

    DestroyDynamicObject(xmasTreeObj[xmasid]);
    DestroyDynamic3DTextLabel(xmasTreeLabel[xmasid]);
    return 1;
}

stock Xmas_GotoTree(const playerid, const xmasid)
{
    if (!xmasTreeID[xmasid] || xmasTreeID[xmasid] < 0)
        return 0;

    Streamer_UpdateEx(playerid, xmasTreeX[xmasid], xmasTreeY[xmasid] + 2.00, xmasTreeZ[xmasid], .compensatedtime = 2000);
    if (IsPlayerInAnyVehicle(playerid))
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        SetVehiclePos(vehicleid, xmasTreeX[xmasid] + 2.00, xmasTreeY[xmasid], xmasTreeZ[xmasid]);
        PutPlayerInVehicle(playerid, vehicleid, 0);
    }
    return 1;
}

stock Xmas_GetNextTreeID()
{
    for (new i = 0; i < MAX_XMAS_TREE; ++i)
        if (!xmasTreeCreated[i])
            return i;

    return MAX_XMAS_TREE;
}

stock Xmas_GetNearbyID(const playerid)
{
    for (new i = 0; i < MAX_XMAS_TREE; i++)
        if (IsPlayerInRangeOfPoint(playerid, 2.0, xmasTreeX[i], xmasTreeY[i], xmasTreeZ[i]))
            return i;
    return MAX_XMAS_TREE;
}