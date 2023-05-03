#if defined _INC_admin_commands_inc
    #endinput
#endif
#define _INC_admin_commands_inc

#include <YSI_Coding\y_hooks>

static adminVehicle[MAX_PLAYERS] = -1,
	createdAdminVehicle[MAX_PLAYERS],
	Text3D: adminVehicleLabel[MAX_PLAYERS],
	playerDeveloper[MAX_PLAYERS],
	adminJetpack[MAX_PLAYERS],
	gDriftMode;

hook OnPlayerDisconnect(playerid, reason)
{
	createdAdminVehicle[playerid] = 0;
	if (adminVehicle[playerid] != -1)
		DestroyVehicle(adminVehicle[playerid]);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

Command(name: setrank, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	static
		targetid,
		rank[24];

	if (sscanf(params, "rs[24]", targetid, rank))
		return SendSyntaxMsg(playerid, "/setrank [targetid] [rank (igrac|moderator|admin)]");

	new rankid = Rank_GetIDByName(rank);
	if (Rank_GetID(targetid) == rankid)
		return SendErrorMsg(playerid, "Taj igrac vec poseduje taj rank!");

	if (!strcmp(rank, "igrac", false))
		Rank_Set(targetid, playerid, "igrac");
	else if (!strcmp(rank, "moderator", false))
		Rank_Set(targetid, playerid, "moderator");
	else if (!strcmp(rank, "admin", false))
	{
		if (strcmp(ReturnPlayerName(playerid), "Emmett_White", false))
			return SendErrorMsg(playerid, "Samo Emmett moze postavljati administratora.");
		Rank_Set(targetid, playerid, "admin");
	}
	else SendErrorMsg(playerid, "Taj rank ne postoji!");
	return 1;
}

Command(name: ah, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	Dialog_Show(playerid, "DIALOG_ADMINHELP", DIALOG_STYLE_MSGBOX,
		""YELLOW"GENERATIONZ - "WHITE"Admin komande",
		""YELLOW"______________________________________________________\n\n\
		"YELLOW"Administrator: "WHITE"/veh /time /weather /pos /kill /cc /kreirajjelku /obrisijelku /portjelka\n\
		"YELLOW"Administrator: "WHITE"/kreirajkucu /obrisikucu /portkuca /kreirajrent /obrisirent /portrent\n\
		"YELLOW"Administrator: "WHITE"/kick /vrespawn /jetpack /pm /setrank /playmusic /a /givegun\n\
		"YELLOW"Administrator: "WHITE"/kreirajkiosk /obrisikiosk /izmenikiosk /portkiosk /goto /gethere\n\
		"YELLOW"Administrator: "WHITE"/setorg /setorgrank /kreirajgps /hungerall /thirstall /setskin\n\
		%s\n\
		"YELLOW"______________________________________________________",
		""YELLOW"Zatvori", "",
		playerDeveloper[playerid] ?
		""YELLOW"Developer: "WHITE"/setdeveloper /bolnica /bankaint /spawn /testwe /loadingmsg /angvel\n\
		"YELLOW"Developer: "WHITE"/infomsg /drift /getdob /houseext /splitname /testwl" : ""
	);
	return 1;
}

Command(name: veh, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	if (createdAdminVehicle[playerid])
	{
		DestroyVehicle(adminVehicle[playerid]);
		GameTextForPlayer(playerid, "~r~Vozilo unisteno!", 3000, 3);
		DestroyDynamic3DTextLabel(adminVehicleLabel[playerid]);
		createdAdminVehicle[playerid] = !createdAdminVehicle[playerid];

		if (Player_GetSeatbelt(playerid))
        	Vehicle_SetSeatbelt(playerid);

	    if (Vehicle_GetEngine(playerid))
	        Vehicle_SetEngine(playerid);

	    if (Vehicle_GetLights(playerid))
	        Vehicle_SetLights(playerid);
		return 1;
	}
	
	static vehid, color1, color2, Float: x, Float: y, Float: z, Float: a;
	if (sscanf(params, "iii", vehid, color1, color2))
		return SendSyntaxMsg(playerid, "/veh [vehid] [color1] [color2]");

	if (!(400 <= vehid <= 611))
		return SendErrorMsg(playerid, "Pogresan ID vozila (400-611)!");

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	adminVehicle[playerid] = CreateVehicle(vehid, x, y, z, a, color1, color2, 0);
	PutPlayerInVehicle(playerid, adminVehicle[playerid], 0);
	va_GameTextForPlayer(playerid, "~y~Vozilo ID: %d", 3000, 3, vehid);
	Vehicle_SetColor(GetPlayerVehicleID(playerid), color1, color2);
	Vehicle_SetFuel(adminVehicle[playerid], 50);

	static tmpString[64];
	format(tmpString, sizeof(tmpString), ""YELLOW"[ VLASNIK: "WHITE"%s "YELLOW"]", ReturnPlayerName(playerid));
	adminVehicleLabel[playerid] = CreateDynamic3DTextLabel(tmpString, -1, 0.0, 0.0, 0.0, 30.00, .attachedvehicle = adminVehicle[playerid]);
	createdAdminVehicle[playerid] = !createdAdminVehicle[playerid];
	return 1;
}

Command(name: bolnica, rank: Rank_Administrator(), args: playerid, const string: params[])
{
    Streamer_UpdateEx(playerid, 1165.7496, -1339.2876, 13.5935, .compensatedtime = 2000);
    return 1;
}

Command(name: bankaint, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	Streamer_UpdateEx(playerid, 1376.723510, -21.226245, 1004.034240, .compensatedtime = 2000);
	return 1;
}

Command(name: time, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/time [0-24]");

	if (!(0 <= strval(params) <= 24))
		return SendErrorMsg(playerid, "Odaberite vreme izmedju 0 i 24!");

	SetWorldTime(strval(params));
	Rank_StaffMessage(X11_ORANGE, "* %s je podesio sate na %d.", ReturnPlayerName(playerid), strval(params));
	return 1;
}

Command(name: weather, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/weather [0-20]");

	if (!(0 <= strval(params) <= 20))
		return SendErrorMsg(playerid, "Odaberite vreme izmedju 0 i 20!");

	SetWorldTime(strval(params));
	Rank_StaffMessage(X11_ORANGE, "* %s je podesio vreme na %d.", ReturnPlayerName(playerid), strval(params));
	return 1;
}

Command(name: spawn, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	SetPlayerPos(playerid, 1591.921,-2334.499,13.152);
	return 1;
}

Command(name: pos, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	static Float: x, Float: y, Float: z;
	if (sscanf(params, "fff", x, y, z))
		return SendSyntaxMsg(playerid, "/pos [x] [y] [z]");

	Streamer_UpdateEx(playerid, x, y, z, .compensatedtime = 2000);
	return 1;
}

Command(name: kill, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/kill [targetid]");

	if (!IsPlayerConnected(strval(params)))
		return SendErrorMsg(playerid, "Taj korisnik nije prijavljen!");

	SetPlayerHealth(strval(params), 0.0);
	SendServerMsgF(strval(params), "%s Vas je ubio.", ReturnPlayerName(playerid));
	SendServerMsgF(playerid, "Ubili ste %s.", ReturnPlayerName(strval(params)));
	return 1;
}

Command(name: cc, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/cc [lines]");

	if (!(10 <= strval(params) <= 60))
		return SendErrorMsg(playerid, "Ne mozete ispod 10 linija i iznad 60 linija!");

	foreach (new i: Player)
		Player_ClearChat(i, playerid, strval(params));
	return 1;
}

Command(name: testwe, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	Winter_SetStatusAll(playerid);
	return 1;
}

Command(name: kreirajjelku, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new Float: x, Float: y, Float: z,
		xmasid = Xmas_GetNextTreeID();

	if (xmasid == Xmas_GetMaxTrees())
		return SendCustomMsgF(playerid, X11_RED, "(Jelka!): "WHITE"Kreiran je maksimalan broj jelki!");

	GetPlayerPos(playerid, x, y, z);
	Xmas_CreateTree(xmasid, x, y, z);

	new String: str_query_insert = str_format(
		"INSERT INTO xmastree (xmas_id, xmas_x, xmas_y, xmas_z) VALUES ('%d', '%f', '%f', '%f')",
		xmasid + 1, x, y, z 
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
	return 1;
}

Command(name: obrisijelku, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new xmasid = Xmas_GetNearbyID(playerid);
	if (xmasid == Xmas_GetMaxTrees())
		return SendErrorMsg(playerid, "Morate biti blizu jelke!");

	Xmas_DestroyTree(xmasid);
	SendCustomMsgF(playerid, X11_RED, "(Jelka): "WHITE"Obrisali ste jelku "RED"%d"WHITE".", xmasid);

	new String: str_query_delete = str_format("DELETE FROM xmastree WHERE xmas_id = '%d'", xmasid + 1);
	mysql_tquery_s(MySQL_GetHandle(), str_query_delete);
	return 1;
}

Command(name: portjelka, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/portjelka [id]");

	if (!Xmas_GotoTree(playerid, strval(params)))
		return SendErrorMsg(playerid, "Pogresan ID!");
	Xmas_GotoTree(playerid, strval(params));
	return 1;
}

Command(name: kreirajkucu, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new Float:x, Float:y, Float:z,
        houseid = House_GetNextID();

    if (houseid == House_GetMaxHouses())
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Kreiran je maksimalan broj kuca!");

    if (isnull(params) || !IsNumeric(params))
        return SendSyntaxMsg(playerid, "/kreirajkucu [price]");

    GetPlayerPos(playerid, x, y, z);
    House_Create(playerid, houseid, strval(params), x, y, z);

    new String: str_query_insert = str_format(
        "INSERT INTO houses (house_id, house_owner, house_vw, house_extx, house_exty, house_extz, house_desc, house_price) \
        VALUES ('%d', 'Niko', '%d', '%f', '%f', '%f', 'Na prodaju', '%d')", (houseid + 1), (houseid + 1), x, y, z, strval(params)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
    return 1;
}

Command(name: obrisikucu, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new houseid = House_GetNearby(playerid);
    if (houseid == House_GetMaxHouses())
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Morate biti blizu neke kuce!");

    House_Destroy(playerid, houseid);

    new String: str_query_delete = str_format("DELETE FROM houses WHERE house_id = '%d'", (houseid + 1));
    mysql_tquery_s(MySQL_GetHandle(), str_query_delete);
	return 1;
}

Command(name: kreirajvozilo, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new vehicleid = Vehicle_GetNextID(),
		modelid,
		Float:x, Float:y, Float:z, Float:a,
		color1, color2,
		locked;

	if (sscanf(params, "iiii", modelid, color1, color2, locked))
		return SendSyntaxMsg(playerid, "/kreirajvozilo [modelid] [color1] [color2] [locked(0-1)]");

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	Vehicle_Create(vehicleid, modelid, "Niko", x, y, z, a, color1, color2, locked);
	SendCustomMsgF(playerid, MAIN_COLOR_HEX, "(Vozilo): "WHITE"Kreirali ste vozilo!");
	return 1;
}

Command(name: loadingmsg, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	static delay, msg[MAX_REASON_LENGTH];
	if (sscanf(params, "s["#MAX_REASON_LENGTH"]i", msg, delay))
		return SendSyntaxMsg(playerid, "/loadingmsg [text] [delay(s)]");

	UI_ShowLoadingTextDraw(playerid, msg, (delay * 1000));
	return 1;
}

Command(name: angvel, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	static pos[2],
		Float:value;

	if (sscanf(params, "s[2]f", pos, value))
		return SendSyntaxMsg(playerid, "/angvel [x|y|z] [value]");

	if (!strcmp(pos, "x", false))
		SetVehicleAngularVelocity(GetPlayerVehicleID(playerid), value, 0.0, 0.0);
	else if (!strcmp(pos, "y", false))
		SetVehicleAngularVelocity(GetPlayerVehicleID(playerid), 0.0, value, 0.0);
	else if (!strcmp(pos, "z", false))
		SetVehicleAngularVelocity(GetPlayerVehicleID(playerid), 0.0, 0.0, value);
	return 1;
}

Command(name: setdeveloper, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	if (!IsPlayerAdmin(playerid))
		return SendErrorMsg(playerid, "Samo RCON Administrator!");

	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/setdeveloper [targetid]");

	if (!IsPlayerConnected(strval(params)))
		return 0;

	playerDeveloper[strval(params)] = !playerDeveloper[strval(params)];
	return 1;
}

/*Command(name: kreirajklupu, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new Float:x, Float:y, Float:z,
        benchid = Bench_GetNextID();

    if (benchid == Bench_GetMaxBenches())
        return SendCustomMsgF(playerid, X11_YELLOW, "(Klupa!): "WHITE"Kreiran je maksimalan broj klupa!");

    GetPlayerPos(playerid, x, y, z);
    Bench_Create(benchid, x, y, z);
    Bench_SetCurrentID(playerid, benchid);
    EditDynamicObject(playerid, Bench_ReturnObject(benchid));

    new String: str_query_insert = str_format(
		"INSERT INTO benches (bench_id, bench_x, bench_y, bench_z, bench_rotx, bench_roty, bench_rotz) \
		VALUES ('%d', '%f', '%f', '%f', '0.0', '0.0', '0.0')",
		(benchid + 1), x, y, z
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
	return 1;
}

Command(name: obrisiklupu, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new benchid = Bench_GetNearby(playerid);
    if (benchid == Bench_GetMaxBenches())
        return SendCustomMsgF(playerid, X11_YELLOW, "(Klupa!): "WHITE"Morate biti blizu neke klupe!");

    Bench_Destroy(benchid);
    SendCustomMsgF(playerid, X11_YELLOW, "(Klupa): "WHITE"Obrisali ste klupu %d.", benchid);
    new String: str_query_delete = str_format("DELETE FROM benches WHERE bench_id = '%d'", (benchid + 1));
    mysql_tquery_s(MySQL_GetHandle(), str_query_delete);
	return 1;
}

Command(name: portklupa, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/portklupa [id]");

	if (!Bench_Goto(playerid, strval(params)))
		return SendErrorMsg(playerid, "Pogresan ID!");
	Bench_Goto(playerid, strval(params));
	return 1;
}

Command(name: izmeniklupu, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new benchid = Bench_GetNearby(playerid);
	if (benchid == Bench_GetMaxBenches())
		return SendCustomMsgF(playerid, X11_RED, "(Klupa!): "WHITE"Morate biti blizu neke klupe!");

	Bench_SetCurrentID(playerid, benchid);
	Bench_SetEditingMode(playerid, true);
	EditDynamicObject(playerid, Bench_ReturnObject(benchid));
	return 1;
}*/

Command(name: jetpack, rank: Rank_Administrator() && Rank_Moderator(), args: playerid, const string: params[])
{
	adminJetpack[playerid] = !adminJetpack[playerid];
	if (!adminJetpack[playerid])
	{
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		GameTextForPlayer(playerid, "~r~SKINULI STE JETPACK!", 3000, 3);
		return 1;
	}

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
	GameTextForPlayer(playerid, "~g~UZELi STE JETPACK!", 3000, 3);
	return 1;
}

Command(name: kreirajrent, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new rentid = Rent_GetNextID(),
		Float:x, Float:y, Float:z;

	GetPlayerPos(playerid, x, y, z);
	Rent_Create(rentid, x, y, z);

	new String: str_query_insert = str_format(
		"INSERT INTO rents (rent_id, rent_x, rent_y, rent_z) VALUES ('%d', '%f', '%f', '%f')",
		(rentid + 1), x, y, z
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
	return 1;
}

Command(name: drift, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	gDriftMode = !gDriftMode;
	SetGravity(!gDriftMode ? 0.008 : 0.006);
	return 1;
}

Command(name: hungerall, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	static Float:value;
	if (sscanf(params, "f", value))
		return SendSyntaxMsg(playerid, "/hungerall [value]");

	if (!(0.00 <= value <= 100.00))
		return SendErrorMsg(playerid, "Ne mozete ispod 0.00 i iznad 100.00!");

	foreach (new i: Player)
	{
		Hunger_SetValue(i, value);
		SendCustomMsgF(i, X11_ORANGE, "#Hunger: "WHITE"Administrator %s je postavio svima glad na "ORANGE"%.2f"WHITE"!", ReturnPlayerName(playerid), value);
	}
	return 1;
}

Command(name: thirstall, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	static Float:value;
	if (sscanf(params, "f", value))
		return SendSyntaxMsg(playerid, "/thirstall [value]");

	if (!(0.00 <= value <= 100.00))
		return SendErrorMsg(playerid, "Ne mozete ispod 0.00 i iznad 100.00!");

	foreach (new i: Player)
	{
		Thirst_SetValue(i, value);
		SendCustomMsgF(i, X11_ORANGE, "#Thirst: "WHITE"Administrator %s je postavio svima zedj na "ORANGE"%.2f"WHITE"!", ReturnPlayerName(playerid), value);
	}
	return 1;
}

Command(name: kreirajkiosk, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new Float:x, Float:y, Float:z,
        kioskid = Kiosk_GetNextID();

    if (kioskid == Kiosk_GetMaxIDs())
        return SendCustomMsgF(playerid, X11_YELLOW, "(Kiosk!): "WHITE"Kreiran je maksimalan broj klupa!");

    GetPlayerPos(playerid, x, y, z);
    Kiosk_Create(kioskid, x, y, z);
    Kiosk_SetCurrentID(playerid, kioskid);
    EditDynamicObject(playerid, Kiosk_ReturnObject(kioskid));

    new String: str_query_insert = str_format(
		"INSERT INTO kiosk (kiosk_id, kiosk_x, kiosk_y, kiosk_z, kiosk_rx, kiosk_ry, kiosk_rz) \
		VALUES ('%d', '%f', '%f', '%f', '0.0', '0.0', '0.0')",
		(kioskid + 1), x, y, z
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
	return 1;
}

Command(name: obrisikiosk, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new kioskid = Kiosk_GetNearby(playerid);
    if (kioskid == Kiosk_GetMaxIDs())
        return SendCustomMsgF(playerid, X11_YELLOW, "(Kiosk!): "WHITE"Morate biti blizu nekog kioska!");

    Kiosk_Destroy(kioskid);
    SendCustomMsgF(playerid, X11_YELLOW, "(Kiosk): "WHITE"Obrisali ste klupu %d.", kioskid);
    new String: str_query_delete = str_format("DELETE FROM kiosk WHERE kiosk_id = '%d'", (kioskid + 1));
    mysql_tquery_s(MySQL_GetHandle(), str_query_delete);
	return 1;
}

Command(name: izmenikiosk, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	new kioskid = Kiosk_GetNearby(playerid);
	if (kioskid == Kiosk_GetMaxIDs())
		return SendCustomMsgF(playerid, X11_RED, "(Kiosk!): "WHITE"Morate biti blizu nekog kioska!");

	Kiosk_SetCurrentID(playerid, kioskid);
	Kiosk_SetEditingMode(playerid, true);
	EditDynamicObject(playerid, Kiosk_ReturnObject(kioskid));
	return 1;
}

Command(name: infomsg, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	UI_ShowInfoMessage(playerid, 2000, "Tvoje ime je %s", ReturnPlayerName(playerid));
	return 1;
}

Command(name: houseext, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	if (isnull(params) && !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/houseext [houseid]");

	new i = strval(params);
	SetPlayerPos(playerid, House_GetPos(i, 0), House_GetPos(i, 1), House_GetPos(i, 2));
	return 1;
}

Command(name: splitname, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	static
		targetid,
		part;

	if (sscanf(params, "ri", targetid, part))
		return SendSyntaxMsg(playerid, "/splitname [targetid] [part(1-name|2-lastname)]");

	SendInfoMsgF(playerid, "%s", Player_SplitName(targetid, part == 1 ? "name" : part == 2 ? "lastname" : ""));
	return 1;
}

Command(name: getdob, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	SendInfoMsgF(playerid, "%s", Account_GetDOB(playerid));
	return 1;
}

Command(name: kreirajgps, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	if (isnull(params))
		return SendSyntaxMsg(playerid, "/kreirajgps [ime lokacije]");

	new
		gpsid = GPS_GetNextID(),
		Float:x, Float:y, Float:z;

	GetPlayerPos(playerid, x, y, z);
	GPS_Create(gpsid, params, x, y, z);
	SendInfoMsg(playerid, "Uspesno ste kreirali GPS.");
	return 1;
}

Command(name: testwl, rank: Rank_Administrator(), args: playerid, const string: params[])
{
	if (!playerDeveloper[playerid])
		return SendErrorMsg(playerid, "Samo developer!");

	if (isnull(params) || !IsNumeric(params))
		return SendSyntaxMsg(playerid, "/testwl [value]");
	
	WantedLevel_Set(playerid, strval(params));
	return 1;
}