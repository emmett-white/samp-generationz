#if defined _INC_mobile_init_inc
	#endinput
#endif
#define _INC_mobile_init_inc

#include <YSI_Coding\y_hooks>

/*
	MOBILE OPTIONS
	1. View number
	2. Call player
	3. Message player
	4. Credit status
	5. Sms ad
	6. Drop mobile
*/

new
	mobileStatus[MAX_PLAYERS],
	mobileNumber[MAX_PLAYERS],
	mobileCredit[MAX_PLAYERS],
	mobilePower[MAX_PLAYERS],
	mobileSelectedPlayer[MAX_PLAYERS],
	bool:mobileUIStatus[MAX_PLAYERS],
	mobileStringNumber[MAX_PLAYERS][8],
	PlayerText:mobileTextDraw[MAX_PLAYERS][29] = {PlayerText:INVALID_PLAYER_TEXT_DRAW,...};

stock Mobile_Get(const playerid) return mobileStatus[playerid];
stock Mobile_Set(const playerid, const status)
{
	mobileStatus[playerid] = status;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobile = '%d' WHERE char_id = '%d'",
		Mobile_Get(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_GetNumber(const playerid) return mobileNumber[playerid];
stock Mobile_SetNumber(const playerid, const number)
{
	mobileNumber[playerid] = number;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobilenum = '%d' WHERE char_id = '%d'",
		Mobile_GetNumber(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_GetCredit(const playerid) return mobileCredit[playerid];
stock Mobile_SetCredit(const playerid, const value)
{
	mobileCredit[playerid] = value;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobilecredit = '%d' WHERE char_id = '%d'",
		Mobile_GetCredit(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_GetPower(const playerid) return mobilePower[playerid];
stock Mobile_SetPower(const playerid, const status)
{
	mobilePower[playerid] = status;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobilepower = '%d' WHERE char_id = '%d'",
		Mobile_GetPower(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_SelectedPlayer(const playerid) return mobileSelectedPlayer[playerid];
stock Mobile_SelectPlayer(const playerid, const targetid) return mobileSelectedPlayer[playerid] = targetid;

stock Mobile_GetUI(const playerid) return mobileUIStatus[playerid];
stock Mobile_CreateUI(const playerid)
{
	new const bool:status = !Mobile_GetUI(playerid);
	if (!status)
	{
		for (new i = 0; i < 29; i++)
		{
			PlayerTextDrawDestroy(playerid, mobileTextDraw[playerid][i]);
			mobileTextDraw[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
		}
		mobileUIStatus[playerid] = false;
		CancelSelectTextDraw(playerid);
		return 1;
	}

	mobileTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 271.100067, 132.932434, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][0], 93.000000, 195.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][0], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][0], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][0], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][0], 0);

	mobileTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 265.200103, 129.687850, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][1], 15.000000, 19.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][1], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][1], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][1], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][1], 0);

	mobileTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 264.900299, 312.299011, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][2], 15.000000, 19.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][2], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][2], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][2], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][2], 0);

	mobileTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 356.000244, 129.565643, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][3], 15.000000, 19.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][3], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][3], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][3], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][3], 0);

	mobileTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 356.000213, 312.365875, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][4], 15.000000, 19.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][4], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][4], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][4], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][4], 0);

	mobileTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 267.700256, 136.999176, "LD_SPAC:WHITE");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][5], 56.000000, 186.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][5], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][5], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][5], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][5], 0);

	mobileTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 312.200256, 137.354827, "LD_SPAC:WHITE");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][6], 56.000000, 184.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][6], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][6], 255);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][6], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][6], 0);

	mobileTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 305.700256, 300.943664, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][7], 23.000000, 28.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][7], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][7], 151587327);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][7], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][7], 0);

	mobileTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 308.200195, 304.499176, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][8], 18.000000, 21.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][8], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][8], 421075455);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][8], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][8], 0);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][8], true);

	mobileTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 270.500000, 147.800231, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][9], 95.369651, 156.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][9], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][9], 151587327);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][9], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][9], 0);

	mobileTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 324.700531, 132.311157, "---------");
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][10], 0.179499, 1.425777);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][10], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][10], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][10], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][10], 1);

	mobileTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 301.000000, 135.088897, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][11], 8.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][11], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][11], 421075455);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][11], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][11], 0);

	mobileTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 303.500152, 138.689117, "LD_BEAT:CHIT");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][12], 3.000000, 3.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][12], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][12], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][12], 0);

	mobileTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 272.800018, 165.089019, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][13], 91.000000, 1.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][13], 1);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][13], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][13], 0);

	mobileTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 317.200073, 154.533294, "_");
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][14], 0.207499, 0.959110);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][14], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][14], -1378294017);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][14], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][14], 1);

	mobileTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 289.000000, 178.177764, "1");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][15], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][15], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][15], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][15], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][15], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][15], true);

	mobileTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 317.301727, 178.177764, "2");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][16], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][16], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][16], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][16], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][16], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][16], true);

	mobileTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 347.103546, 178.177764, "3");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][17], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][17], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][17], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][17], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][17], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][17], true);

	mobileTextDraw[playerid][18] = CreatePlayerTextDraw(playerid, 289.000000, 205.379425, "4");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][18], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][18], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][18], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][18], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][18], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][18], true);

	mobileTextDraw[playerid][19] = CreatePlayerTextDraw(playerid, 317.301727, 205.079406, "5");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][19], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][19], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][19], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][19], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][19], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][19], true);

	mobileTextDraw[playerid][20] = CreatePlayerTextDraw(playerid, 347.103546, 205.579437, "6");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][20], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][20], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][20], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][20], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][20], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][20], true);

	mobileTextDraw[playerid][21] = CreatePlayerTextDraw(playerid, 289.000000, 230.280944, "7");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][21], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][21], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][21], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][21], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][21], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][21], true);

	mobileTextDraw[playerid][22] = CreatePlayerTextDraw(playerid, 317.301727, 229.980926, "8");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][22], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][22], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][22], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][22], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][22], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][22], true);

	mobileTextDraw[playerid][23] = CreatePlayerTextDraw(playerid, 347.103546, 230.080932, "9");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][23], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][23], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][23], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][23], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][23], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][23], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][23], true);

	mobileTextDraw[playerid][24] = CreatePlayerTextDraw(playerid, 317.603607, 253.892639, "0");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][24], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][24], 0.338500, 1.487999);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][24], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][24], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][24], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][24], true);

	mobileTextDraw[playerid][25] = CreatePlayerTextDraw(playerid, 295.500000, 276.488891, "(");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][25], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][25], 0.583999, 1.662222);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][25], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][25], 16711935);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][25], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][25], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][25], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][25], true);

	mobileTextDraw[playerid][26] = CreatePlayerTextDraw(playerid, 338.602844, 276.388916, "(");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][26], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][26], -0.590500, 1.680888);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][26], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][26], -16776961);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][26], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][26], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][26], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][26], true);

	mobileTextDraw[playerid][27] = va_CreatePlayerTextDraw(playerid, 316.899932, 349.800201, "UNESITE BROJ: ~w~%d", Mobile_GetNumber(Mobile_SelectedPlayer(playerid)));
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][27], 0.221999, 0.940444);
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][27], 0.000000, 220.000000);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][27], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][27], 796937471);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, mobileTextDraw[playerid][27], 1);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][27], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][27], 1);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][27], 1);

	mobileTextDraw[playerid][28] = CreatePlayerTextDraw(playerid, 345.700500, 251.422119, "<");
	PlayerTextDrawTextSize(playerid, mobileTextDraw[playerid][28], 8.0, 20.0);
	PlayerTextDrawLetterSize(playerid, mobileTextDraw[playerid][28], 0.259999, 2.023110);
	PlayerTextDrawAlignment(playerid, mobileTextDraw[playerid][28], 2);
	PlayerTextDrawColor(playerid, mobileTextDraw[playerid][28], -1378294017);
	PlayerTextDrawSetShadow(playerid, mobileTextDraw[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, mobileTextDraw[playerid][28], 255);
	PlayerTextDrawFont(playerid, mobileTextDraw[playerid][28], 3);
	PlayerTextDrawSetProportional(playerid, mobileTextDraw[playerid][28], 1);
	PlayerTextDrawSetSelectable(playerid, mobileTextDraw[playerid][28], true);

	for (new i = 0; i < 29; i++)
		PlayerTextDrawShow(playerid, mobileTextDraw[playerid][i]);

	SelectTextDraw(playerid, MAIN_COLOR_HEX);
	mobileUIStatus[playerid] = true;
	return 1;
}

hook OnPlayerConnect(playerid)
{
	Mobile_SelectPlayer(playerid, 0xFFFF);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
	if (playertextid == mobileTextDraw[playerid][26] || playertextid == mobileTextDraw[playerid][8])
		Mobile_CreateUI(playerid);

	for (new i = 15; i <= 24; i++)
	{
		if (playertextid == mobileTextDraw[playerid][i])
		{
			if (strlen(mobileStringNumber[playerid]) > 5)
				return 0;

			static
				tmpString[8],
				fmtString[8];

			strcopy(tmpString, mobileStringNumber[playerid]);

			if (isnull(mobileStringNumber[playerid]))
				format(fmtString, sizeof(fmtString), "%s", itos(i - 14));

			else
				format(fmtString, sizeof(fmtString), "%s%s", tmpString, itos(i - 14));

			strcopy(mobileStringNumber[playerid], fmtString);
			PlayerTextDrawSetString(playerid, mobileTextDraw[playerid][14], mobileStringNumber[playerid]);
		}
	}

	if (playertextid == mobileTextDraw[playerid][28])
	{
		if (isnull(mobileStringNumber[playerid]))
			return 0;

		strcopy(mobileStringNumber[playerid][strlen(mobileStringNumber[playerid]) - 1], "");
		PlayerTextDrawSetString(playerid, mobileTextDraw[playerid][14], mobileStringNumber[playerid]);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}