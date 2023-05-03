#if defined _INC_bench_init_inc
    #endinput
#endif
#define _INC_bench_init_inc

#include <YSI_Coding\y_hooks>

const MAX_BENCHES = 100;

static
	benchTotal,
	benchID[MAX_BENCHES],
	benchCurrentID[MAX_BENCHES],
	benchCreated[MAX_BENCHES],
	bool:benchEditing[MAX_PLAYERS],
	benchObject[MAX_BENCHES],
	Text3D:benchLabel[MAX_BENCHES],
	Float:benchX[MAX_BENCHES],
	Float:benchY[MAX_BENCHES],
	Float:benchZ[MAX_BENCHES],
	Float:benchRotX[MAX_BENCHES],
	Float:benchRotY[MAX_BENCHES],
	Float:benchRotZ[MAX_BENCHES],
	benchPlayerSitting[MAX_PLAYERS];

hook OnGameModeInit()
{
	mysql_tquery(MySQL_GetHandle(), "SELECT * FROM benches", "Bench_Load");
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEditDynObject(playerid, STREAMER_TAG_OBJECT:objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if (response == EDIT_RESPONSE_FINAL)
	{
		new benchid = Bench_ReturnCurrentID(playerid);
		benchX[benchid] = x;
		benchY[benchid] = y;
		benchZ[benchid] = z;
		benchRotX[benchid] = rx;
		benchRotY[benchid] = ry;
		benchRotZ[benchid] = rz;

		new String: str_query_update = str_format(
			"UPDATE benches SET \
			bench_x = '%f', bench_y = '%f', bench_z = '%f', bench_rotx = '%f', bench_roty = '%f', bench_rotz = '%f' \
			WHERE bench_id = '%d'",
			x, y, z, rx, ry, rz, (benchid + 1)
		);
		mysql_tquery_s(MySQL_GetHandle(), str_query_update);

		DestroyDynamic3DTextLabel(benchLabel[benchid]);
		benchLabel[benchid] = CreateDynamic3DTextLabel("Pritisnite "YELLOW"'N' "WHITE"da sednete.", -1, x, y, z, 30.00);
		SendInfoMsgF(playerid, "%s ste klupu %d.", (Bench_GetEditingMode(playerid) ? "Azurirali" : "Kreirali"), benchid);

		if (Bench_GetEditingMode(playerid))
			Bench_SetEditingMode(playerid, false);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (newkeys & KEY_NO)
	{
		benchPlayerSitting[playerid] = !benchPlayerSitting[playerid];

		new benchid = Bench_GetNearby(playerid);
		if (benchid == Bench_GetMaxBenches())
			return 0;

		if (!benchPlayerSitting[playerid])
		{
			Anim_StopLooping(playerid);
			ClearAnimations(playerid);
			return 1;
		}

		SetPlayerPos(playerid, benchX[benchid], benchY[benchid] + 0.8, benchZ[benchid] - 0.8);
		SetPlayerFacingAngle(playerid, benchRotX[benchid]);
		Anim_Loop(playerid,"MISC","seat_lr",2.0,1,0,0,0,0);
		GameTextForPlayer(playerid, "~y~STISNITE PONOVO N DA USTANETE", 3000, 3);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

forward Bench_Load();
public Bench_Load()
{
	if (!cache_num_rows())
		return 0;

	new rows;
	cache_get_row_count(rows);
	for (new i = 0; i < rows; i++)
	{
		cache_get_value_name_int(i, "bench_id", benchID[i]);
		cache_get_value_name_float(i, "bench_x", benchX[i]);
		cache_get_value_name_float(i, "bench_y", benchY[i]);
		cache_get_value_name_float(i, "bench_z", benchZ[i]);
		cache_get_value_name_float(i, "bench_rotx", benchRotX[i]);
		cache_get_value_name_float(i, "bench_roty", benchRotY[i]);
		cache_get_value_name_float(i, "bench_rotz", benchRotZ[i]);

		benchCreated[i] = 1;
		benchObject[i] = CreateDynamicObject(1280, benchX[i], benchY[i], benchZ[i], benchRotX[i], benchRotY[i], benchRotZ[i], .streamdistance = 600.00, .drawdistance = 600.00);
		benchLabel[i] = CreateDynamic3DTextLabel("Pritisnite "YELLOW"'N' "WHITE"da sednete.", -1, benchX[i], benchY[i], benchZ[i], 30.00);
		benchTotal++;
	}

	printf("[BENCHES]: Ucitano %d klupa.", benchTotal);
	return 1;
}

stock Bench_GetMaxBenches() return MAX_BENCHES;
stock Bench_ReturnCurrentID(const playerid) return benchCurrentID[playerid];
stock Bench_SetCurrentID(const playerid, const benchid) return benchCurrentID[playerid] = benchid;
stock Bench_ReturnObject(const benchid) return benchObject[benchid];
stock Bench_SetEditingMode(const playerid, const bool:status) return benchEditing[playerid] = status;
stock Bench_GetEditingMode(const playerid) return benchEditing[playerid];
stock Bench_Create(const benchid, Float:x, Float:y, Float:z)
{
	benchID[benchid] = benchid;
	benchCreated[benchid] = 1;
	benchX[benchid] = x;
	benchY[benchid] = y;
	benchZ[benchid] = z;
	benchObject[benchid] = CreateDynamicObject(1280, x, y, z, benchRotX[benchid], benchRotY[benchid], benchRotZ[benchid], .streamdistance = 600.00, .drawdistance = 600.00);
	benchLabel[benchid] = CreateDynamic3DTextLabel("Pritisnite "YELLOW"'N' "WHITE"da sednete.", -1, x, y, z, 30.00);
	return 1;
}

stock Bench_Destroy(const benchid)
{
	benchID[benchid] = MAX_BENCHES;
	benchCreated[benchid] = 0;
	DestroyDynamic3DTextLabel(benchLabel[benchid]);
	DestroyDynamicObject(benchObject[benchid]);
	return 1;
}

stock Bench_Goto(const playerid, const benchid)
{
    if (!benchID[benchid] || benchID[benchid] < 0)
        return 0;

    Streamer_UpdateEx(playerid, benchX[benchid], benchY[benchid] + 2.00, benchZ[benchid], .compensatedtime = 2000);
    if (IsPlayerInAnyVehicle(playerid))
    {
    	new vehicleid = GetPlayerVehicleID(playerid);
        SetVehiclePos(vehicleid, benchX[benchid] + 2.00, benchY[benchid], benchZ[benchid]);
        PutPlayerInVehicle(playerid, vehicleid, 0);
    }
    return 1;
}

stock Bench_GetNextID()
{
	for (new i = 0; i < MAX_BENCHES; i++)
		if (!benchCreated[i])
			return i;
	return MAX_BENCHES;
}

stock Bench_GetNearby(const playerid)
{
	for (new i = 0; i < MAX_BENCHES; i++)
		if (IsPlayerInRangeOfPoint(playerid, 2.0, benchX[i], benchY[i], benchZ[i]))
			return i;
	return MAX_BENCHES;
}