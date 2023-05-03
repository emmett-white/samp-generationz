#if defined _INC_kiosk_init_inc
    #endinput
#endif
#define _INC_kiosk_init_inc

#include <YSI_Coding\y_hooks>

const MAX_KIOSK = 50;

static
	kioskTotal,
	kioskID[MAX_KIOSK],
	kioskCreated[MAX_KIOSK],
	kioskObject[MAX_KIOSK],
	kioskCurrentID[MAX_KIOSK],
	bool:kioskEditing[MAX_PLAYERS],
	Float:kioskX[MAX_KIOSK],
	Float:kioskY[MAX_KIOSK],
	Float:kioskZ[MAX_KIOSK],
	Float:kioskRotX[MAX_KIOSK],
	Float:kioskRotY[MAX_KIOSK],
	Float:kioskRotZ[MAX_KIOSK],
	PlayerText:kioskTextDraw[MAX_PLAYERS][15] = {PlayerText:INVALID_PLAYER_TEXT_DRAW,...},
	kioskItemSelected[MAX_PLAYERS],
	kioskChoosingItem[MAX_PLAYERS];

static const kioskItems[][][] =
{
	{"Burger", 7},
	{"Pizza", 10},
	{"Sok od jabuke", 5},
	{"Voda", 1}
};

hook OnGameModeInit()
{
	mysql_tquery(MySQL_GetHandle(), "SELECT * FROM kiosk", "Kiosk_Load");
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEditDynObject(playerid, STREAMER_TAG_OBJECT:objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if (response == EDIT_RESPONSE_FINAL)
	{
		new kioskid = Kiosk_ReturnCurrentID(playerid);
		kioskX[kioskid] = x;
		kioskY[kioskid] = y;
		kioskZ[kioskid] = z;
		kioskRotX[kioskid] = rx;
		kioskRotY[kioskid] = ry;
		kioskRotZ[kioskid] = rz;

		new String: str_query_update = str_format(
			"UPDATE kiosk SET \
			kiosk_x = '%f', kiosk_y = '%f', kiosk_z = '%f', kiosk_rx = '%f', kiosk_ry = '%f', kiosk_rz = '%f' \
			WHERE kiosk_id = '%d'",
			x, y, z, rx, ry, rz, (kioskid + 1)
		);
		mysql_tquery_s(MySQL_GetHandle(), str_query_update);

		SendInfoMsgF(playerid, "%s ste kiosk %d.", (Kiosk_GetEditingMode(playerid) ? "Azurirali" : "Kreirali"), kioskid);

		if (Kiosk_GetEditingMode(playerid))
			Kiosk_SetEditingMode(playerid, false);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (newkeys & KEY_NO)
	{
		new kioskid = Kiosk_GetNearby(playerid);
		if (kioskid == Kiosk_GetMaxIDs())
			return Y_HOOKS_BREAK_RETURN_0;

		kioskTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 169.600006, 134.466674, "LD_POOL:BALL");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][0], 64.000000, 71.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][0], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][0], 796937471);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][0], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][0], 0);

		kioskTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 169.860000, 134.166702, "LD_POOL:BALL");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][1], 64.000000, 71.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][1], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][1], 796937471);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][1], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][1], 0);

		kioskTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 408.399993, 134.460006, "LD_POOL:BALL");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][2], 64.000000, 71.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][2], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][2], 796937471);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][2], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][2], 0);

		kioskTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 408.399993, 134.460006, "LD_POOL:BALL");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][3], 64.000000, 71.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][3], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][3], 796937471);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][3], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][3], 0);

		kioskTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 247.398437, 134.460006, "LD_POOL:BALL");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][4], 64.000000, 71.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][4], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][4], 796937471);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][4], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][4], 0);

		kioskTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 330.203491, 134.460006, "LD_POOL:BALL");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][5], 64.000000, 71.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][5], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][5], 796937471);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][5], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][5], 0);

		kioskTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 173.500000, 131.355560, "");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][6], 55.000000, 81.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][6], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][6], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][6], 0x00000000);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][6], 5);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][6], 0);
		PlayerTextDrawSetPreviewModel(playerid, kioskTextDraw[playerid][6], 2703);
		PlayerTextDrawSetPreviewRot(playerid, kioskTextDraw[playerid][6], 90.000000, 0.000000, -10.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid, kioskTextDraw[playerid][6], true);

		kioskTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 248.500000, 136.333312, "");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][7], 61.000000, 66.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][7], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][7], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][7], 0x00000000);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][7], 5);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][7], 0);
		PlayerTextDrawSetPreviewModel(playerid, kioskTextDraw[playerid][7], 19580);
		PlayerTextDrawSetPreviewRot(playerid, kioskTextDraw[playerid][7], 90.000000, 0.000000, 0.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid, kioskTextDraw[playerid][7], true);

		kioskTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 331.500000, 139.444396, "");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][8], 63.000000, 59.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][8], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][8], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][8], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][8], 0x00000000);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][8], 5);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][8], 0);
		PlayerTextDrawSetPreviewModel(playerid, kioskTextDraw[playerid][8], 19564);
		PlayerTextDrawSetPreviewRot(playerid, kioskTextDraw[playerid][8], 0.000000, 0.000000, 180.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid, kioskTextDraw[playerid][8], true);

		kioskTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 370.500000, 132.599945, "");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][9], 90.000000, 69.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][9], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][9], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][9], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][9], 0x00000000);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][9], 5);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][9], 0);
		PlayerTextDrawSetPreviewModel(playerid, kioskTextDraw[playerid][9], 1484);
		PlayerTextDrawSetPreviewRot(playerid, kioskTextDraw[playerid][9], 0.000000, -30.000000, 180.000000, 1.000000);
		PlayerTextDrawSetSelectable(playerid, kioskTextDraw[playerid][9], true);

		kioskTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 317.400177, 219.888885, "_");
		PlayerTextDrawLetterSize(playerid, kioskTextDraw[playerid][10], 0.215000, 1.046221);
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][10], 0.000000, 363.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][10], 2);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][10], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][10], 0);
		PlayerTextDrawSetOutline(playerid, kioskTextDraw[playerid][10], 1);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][10], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][10], 1);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][10], 1);

		kioskTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 241.000000, 241.488891, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][11], 68.000000, 21.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][11], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][11], 1392408217);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][11], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][11], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][11], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][11], 0);

		kioskTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 325.900970, 241.466705, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][12], 68.000000, 21.000000);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][12], 1);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][12], -16777063);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][12], 0);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][12], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][12], 4);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][12], 0);

		kioskTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 273.599975, 247.466644, "KUPI");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][13], 8.0, 20.0);
		PlayerTextDrawLetterSize(playerid, kioskTextDraw[playerid][13], 0.234000, 0.977777);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][13], 2);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][13], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][13], 0);
		PlayerTextDrawSetOutline(playerid, kioskTextDraw[playerid][13], 1);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][13], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][13], 1);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][13], 1);
		PlayerTextDrawSetSelectable(playerid, kioskTextDraw[playerid][13], true);

		kioskTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 359.599975, 247.466644, "IZLAZ");
		PlayerTextDrawTextSize(playerid, kioskTextDraw[playerid][14], 8.0, 20.0);
		PlayerTextDrawLetterSize(playerid, kioskTextDraw[playerid][14], 0.234000, 0.977777);
		PlayerTextDrawAlignment(playerid, kioskTextDraw[playerid][14], 2);
		PlayerTextDrawColor(playerid, kioskTextDraw[playerid][14], -1);
		PlayerTextDrawSetShadow(playerid, kioskTextDraw[playerid][14], 0);
		PlayerTextDrawSetOutline(playerid, kioskTextDraw[playerid][14], 1);
		PlayerTextDrawBackgroundColor(playerid, kioskTextDraw[playerid][14], 255);
		PlayerTextDrawFont(playerid, kioskTextDraw[playerid][14], 1);
		PlayerTextDrawSetProportional(playerid, kioskTextDraw[playerid][14], 1);
		PlayerTextDrawSetSelectable(playerid, kioskTextDraw[playerid][14], true);

		for (new i = 0; i < 15; i++)
			PlayerTextDrawShow(playerid, kioskTextDraw[playerid][i]);

		SelectTextDraw(playerid, 0x00000080);
		SendInfoMsg(playerid, "Ukoliko vam ostanu textdrawovi i ne mozete da ih sklonite, kucajte /kioskui!");

		kioskChoosingItem[playerid] = 1;
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
	for (new i = 6; i <= 9; i++)
	{
		if (playertextid == kioskTextDraw[playerid][i])
		{
			// i - 5 explained
			// kioskTextDraw[playerid][6] => index 6 - 5 => 1 => kiosKitemSelected[playerid] = 1;
			// kioskTextDraw[playerid][7] => index 7 - 5 => 2 => kiosKitemSelected[playerid] = 2;
			// kioskTextDraw[playerid][8] => index 8 - 5 => 3 => kiosKitemSelected[playerid] = 3;
			// kioskTextDraw[playerid][9] => index 9 - 5 => 4 => kiosKitemSelected[playerid] = 4;
			kioskItemSelected[playerid] = i - 5;
		}
	}

	if (kioskItemSelected[playerid])
		va_PlayerTextDrawSetString(playerid, kioskTextDraw[playerid][10], "Odabrano: %s - Cena: ~g~$~w~%d",
			kioskItems[kioskItemSelected[playerid] - 1][0][0], kioskItems[kioskItemSelected[playerid] - 1][1][0]
		);

	if (playertextid == kioskTextDraw[playerid][13] && kioskItemSelected[playerid])
	{
		Dialog_Show(playerid, "DIALOG_KIOSKBUY", DIALOG_STYLE_MSGBOX,
			""MAIN_COLOR"GENERATIONZ - "WHITE"KIOSK",
			""WHITE"Odabrano: "MAIN_COLOR"%s\n"WHITE"Za kupovinu pritisnite "MAIN_COLOR"Kupi"WHITE".",
			""MAIN_COLOR"Kupi", "Izlaz", kioskItems[kioskItemSelected[playerid] - 1][0][0]
		);
	}

	else if (playertextid == kioskTextDraw[playerid][14])
	{
		Kiosk_DestroyUI(playerid);
		CancelSelectTextDraw(playerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

PTASK__ KIOSK_Nearby[1000](playerid)
{
	new kioskid = Kiosk_GetNearby(playerid);
	if (kioskid == Kiosk_GetMaxIDs())
		return 0;

	if (!kioskChoosingItem[playerid])
		UI_ShowInfoMessage(playerid, 1000, "Pritisnite ~y~'~w~N~y~' ~w~za meni.");
	return 1;
}

forward Kiosk_Load();
public Kiosk_Load()
{
	if (!cache_num_rows())
		return 0;

	new rows;
	cache_get_row_count(rows);
	for (new i = 0; i < rows; i++)
	{
		cache_get_value_name_int(i, "kiosk_id", kioskID[i]);
		cache_get_value_name_float(i, "kiosk_x", kioskX[i]);
		cache_get_value_name_float(i, "kiosk_y", kioskY[i]);
		cache_get_value_name_float(i, "kiosk_z", kioskZ[i]);
		cache_get_value_name_float(i, "kiosk_rx", kioskRotX[i]);
		cache_get_value_name_float(i, "kiosk_ry", kioskRotY[i]);
		cache_get_value_name_float(i, "kiosk_rz", kioskRotZ[i]);

		kioskCreated[i] = 1;
		kioskObject[i] = CreateDynamicObject(3861, kioskX[i], kioskY[i], kioskZ[i], kioskRotX[i], kioskRotY[i], kioskRotZ[i], .streamdistance = 600.00, .drawdistance = 600.00);
		kioskTotal++;
	}

	printf("[KIOSK]: Ucitano %d kioska.", kioskTotal);
	return 1;
}

stock Kiosk_ChoosingItem(const playerid) return kioskChoosingItem[playerid];
stock Kiosk_GetMaxIDs() return MAX_KIOSK;
stock Kiosk_ReturnCurrentID(const playerid) return kioskCurrentID[playerid];
stock Kiosk_SetCurrentID(const playerid, const kioskid) return kioskCurrentID[playerid] = kioskid;
stock Kiosk_ReturnObject(const kioskid) return kioskObject[kioskid];
stock Kiosk_SetEditingMode(const playerid, const bool:status) return kioskEditing[playerid] = status;
stock Kiosk_GetEditingMode(const playerid) return kioskEditing[playerid];
stock Kiosk_Create(const kioskid, Float:x, Float:y, Float:z)
{
	kioskID[kioskid] = kioskid;
	kioskCreated[kioskid] = 1;
	kioskX[kioskid] = x;
	kioskY[kioskid] = y;
	kioskZ[kioskid] = z;
	kioskObject[kioskid] = CreateDynamicObject(3861, x, y, z, kioskRotX[kioskid], kioskRotY[kioskid], kioskRotZ[kioskid], .streamdistance = 600.00, .drawdistance = 600.00);
	return 1;
}

stock Kiosk_Destroy(const kioskid)
{
	kioskID[kioskid] = MAX_KIOSK;
	kioskCreated[kioskid] = 0;
	DestroyDynamicObject(kioskObject[kioskid]);
	return 1;
}

stock Kiosk_Goto(const playerid, const kioskid)
{
    if (!kioskID[kioskid] || kioskID[kioskid] < 0)
        return 0;

    Streamer_UpdateEx(playerid, kioskX[kioskid], kioskY[kioskid] + 4.00, kioskZ[kioskid], .compensatedtime = 2000);
    if (IsPlayerInAnyVehicle(playerid))
    {
    	new vehicleid = GetPlayerVehicleID(playerid);
        SetVehiclePos(vehicleid, kioskX[kioskid] + 4.00, kioskY[kioskid], kioskZ[kioskid]);
        PutPlayerInVehicle(playerid, vehicleid, 0);
    }
    return 1;
}

stock Kiosk_GetNextID()
{
	for (new i = 0; i < MAX_KIOSK; i++)
		if (!kioskCreated[i])
			return i;
	return MAX_KIOSK;
}

stock Kiosk_GetNearby(const playerid)
{
	for (new i = 0; i < MAX_KIOSK; i++)
		if (IsPlayerInRangeOfPoint(playerid, 5.0, kioskX[i], kioskY[i], kioskZ[i]))
			return i;
	return MAX_KIOSK;
}

stock Kiosk_DestroyUI(const playerid)
{
	for (new i = 0; i < 15; i++)
	{
		PlayerTextDrawDestroy(playerid, kioskTextDraw[playerid][i]);
		kioskTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
	}
	return 1;
}

Dialog: DIALOG_KIOSKBUY(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;

	switch (kioskItemSelected[playerid])
	{
		case 1:
		{
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Kupili ste burger!");
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Da pojedete kucajte /ranac -> burger -> koristi!");
			GameTextForPlayer(playerid, "~r~-$7", 3000, 3);
			Account_SetMoney(playerid, Account_GetMoney(playerid) - 7);
			GivePlayerMoney(playerid, -7);
		}

		case 2:
		{
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Kupili ste pizzu!");
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Da pojedete kucajte /ranac -> pizza -> koristi!");
			GameTextForPlayer(playerid, "~r~-$10", 3000, 3);
			Account_SetMoney(playerid, Account_GetMoney(playerid) - 10);
			GivePlayerMoney(playerid, -10);
		}

		case 3:
		{
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Kupili ste sok od jabuke!");
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Da pojedete kucajte /ranac -> sok od jabuke -> koristi!");
			GameTextForPlayer(playerid, "~r~-$5", 3000, 3);
			Account_SetMoney(playerid, Account_GetMoney(playerid) - 5);
			GivePlayerMoney(playerid, -5);
		}

		case 4:
		{
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Kupili ste vodu!");
			SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Kiosk): "WHITE"Da pojedete kucajte /ranac -> voda -> koristi!");
			GameTextForPlayer(playerid, "~r~-$1", 3000, 3);
			Account_SetMoney(playerid, Account_GetMoney(playerid) - 1);
			GivePlayerMoney(playerid, -1);
		}
	}
	return 1;
}