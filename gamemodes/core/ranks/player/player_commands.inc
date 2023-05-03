#if defined _INC_player_commands_inc
    #endinput
#endif
#define _INC_player_commands_inc

forward Float: House_GetPos(const houseid, const index);

static
	BitArray:Bit_Seatbelt<MAX_PLAYERS>,
	houseLocated[MAX_PLAYERS],
	askqTimer[MAX_PLAYERS],
	reportTimer[MAX_PLAYERS],
	BitArray:Bit_PDDuty<MAX_PLAYERS>;

stock Player_GetSeatbelt(const playerid) return Bit_Get(Bit_Seatbelt, playerid);
stock Player_SetSeatbelt(const playerid, bool:value)
{
	Bit_Set(Bit_Seatbelt, playerid, value);
	return 1;
}

Command(name: rank, rank: Rank_Player(), args: playerid, const string: params[])
{
	SendInfoMsgF(playerid, "Vas trenutni rank: %s", Rank_GetNameByID(Rank_GetID(playerid)));
	return 1;
}

Command(name: help, rank: Rank_Player(), args: playerid, const string: params[])
{
	Dialog_Show(playerid, "DIALOG_PLAYERHELP", DIALOG_STYLE_MSGBOX,
		""MAIN_COLOR"GENERATIONZ - "WHITE"Komande",
		""MAIN_COLOR"______________________________________________________\n\n\
		"MAIN_COLOR"Komande: "WHITE"/stats /askq /report /id /we /vreme /pojas\n\
		"MAIN_COLOR"Komande: "WHITE"/kupikucu, /banka /otvoriracun /unrent\n\
		"MAIN_COLOR"Komande: "WHITE"/poslovi /hours /anim /vreme /otkaz\n\
		"MAIN_COLOR"Komande: "WHITE"/posao /posaooprema /b /gps /rank /smokeweed\n\
		"MAIN_COLOR"Organizacija: "WHITE"/f /rank /members /orgrank\n\
		"MAIN_COLOR"______________________________________________________",
		""MAIN_COLOR"Zatvori"
	);
	return 1;
}

Command(name: we, rank: Rank_Player(), args: playerid, const string: params[])
{
	static tmpStr[5][40];
    strcopy(tmpStr[0], (Winter_GetSnowObjStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    strcopy(tmpStr[1], (Winter_GetSnowflakeStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    strcopy(tmpStr[2], (Winter_GetSnowCapStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    strcopy(tmpStr[4], (Winter_GetColdBreathStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    
    if (Winter_GetAllStatus(playerid))
        strcopy(tmpStr[3], ""LIGHTGREEN"Iskljuci sve");
    else
        strcopy(tmpStr[3], ""DARKRED"Ukljuci sve");

    Dialog_Show(playerid, "DIALOG_WINTER", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOR"GENERATIONZ - "WHITE"Winter Edition",
        ""MAIN_COLOR"Opcija\t"MAIN_COLOR"Status\n\
        "WHITE"Sneg po mapi\t%s\n\
        "WHITE"Padanje snega\t%s\n\
        "WHITE"Kapica\t%s\n\
        "WHITE"Dah iz usta\t%s\n\
        "WHITE"%s",
        "Potvrdi", "Izlaz",
        tmpStr[0], tmpStr[1], tmpStr[2], tmpStr[4], tmpStr[3]
    );
    return 1;
}

Command(name: pojas, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (IsPlayerInAnyVehicle(playerid))
		Vehicle_SetSeatbelt(playerid);
	return 1;
}

Command(name: otvoriracun, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 2.0, 1376.3872, -29.5206, 1000.8729))
		return SendErrorMsg(playerid, "Morate biti u banci!");

	if (Account_GetBankCard(playerid))
		return SendErrorMsg(playerid, "Vec imate otvoren bankovni racun!");

	Account_SetBankCard(playerid, 1);
	UI_UpdateInfoTD(playerid);
	SendServerMsg(playerid, "Uspesno ste otvorili bankovni racun!");
	return 1;
}

Command(name: banka, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 2.0, 1375.9037, -26.0387, 1000.8729))
		return SendErrorMsg(playerid, "Morate biti u banci!");

	if (!Account_GetBankCard(playerid))
		return SendErrorMsg(playerid, "Morate otvoriti bankovni racun!");

	Dialog_Show(playerid, "DIALOG_BANK", DIALOG_STYLE_TABLIST_HEADERS,
		""MAIN_COLOR"GENERATIONZ - "WHITE"Banka",
		""MAIN_COLOR"Opcija\t"MAIN_COLOR"Stanje\n\
		"WHITE"Podigni novac\t"DARKGREEN"$"WHITE"%d "GREY"u banci\n\
		"WHITE"Ostavi novac\t"DARKGREEN"$"WHITE"%d "GREY"kod sebe\n\
		"WHITE"Prebaci novac", ""MAIN_COLOR"Potvrdi", "Izlaz",
		Account_GetBankMoney(playerid), Account_GetMoney(playerid)
	);
	return 1;
}

Command(name: posao, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Account_GetJob(playerid))
		return SendErrorMsg(playerid, "Vec imate posao! Za otkaz, idite u opstinu.");

	// Postman
	if (IsPlayerInRangeOfPoint(playerid, 2.0, 986.8093, -1252.5247, 16.9844))
	{
		Account_SetJob(playerid, 1);
		SendServerMsg(playerid, "Uspesno ste se zaposlili kao postar!");
		SendServerMsg(playerid, "Komande posla: /posaooprema, /pokreniposao, /prekiniposao");
	}

	// Lawn mower
	else if (IsPlayerInRangeOfPoint(playerid, 2.0, 940.5753, -1085.9894, 24.2962))
	{
		Account_SetJob(playerid, 2);
		SendServerMsg(playerid, "Uspesno ste se zaposlili kao kosac trave!");
		SendServerMsg(playerid, "Komande posla: /posaooprema, /pokreniposao, /prekiniposao");
	}

	// Bus driver
	else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1808.0718,-1904.3878,13.5755))
	{
		Account_SetJob(playerid, 3);
		SendServerMsg(playerid, "Uspesno ste se zaposlili kao bus vozac!");
		SendServerMsg(playerid, "Komande posla: /posaooprema, /pokreniposao, /prekiniposao");
	}

	// Weed grower
	else if (IsPlayerInRangeOfPoint(playerid, 2.0, 2491.6658,-957.3235,82.3045))
	{
		Account_SetJob(playerid, 4);
		SendServerMsg(playerid, "Uspesno ste se zaposlili kao uzgajivac marihuane!");
		SendServerMsg(playerid, "Komande posla: /posaooprema, /pokreniposao, /uzmiseme, /uzmitorbu, /prekiniposao");
	}
	return 1;
}

Command(name: posaooprema, rank: Rank_Player(), args: playerid, const string: params[])
{
	// Postman
	if (IsPlayerInRangeOfPoint(playerid, 2.0, 979.5859, -1254.7031, 16.9465) && Account_GetJob(playerid) == 1)
		Account_SetJobUniform(playerid, Account_GetJob(playerid), !Account_GetJobUniform(playerid));
	// Lawn mower
	else if (IsPlayerInRangeOfPoint(playerid, 2.0, 940.5753, -1085.9894, 24.2962) && Account_GetJob(playerid) == 2)
		Account_SetJobUniform(playerid, Account_GetJob(playerid), !Account_GetJobUniform(playerid));
	// Bus driver
	else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1808.1638,-1907.4720,13.5732) && Account_GetJob(playerid) == 3)
		Account_SetJobUniform(playerid, Account_GetJob(playerid), !Account_GetJobUniform(playerid));
	// Weed grower
	else if (IsPlayerInRangeOfPoint(playerid, 2.0, 2495.8860,-953.0092,82.2543) && Account_GetJob(playerid) == 4)
		Account_SetJobUniform(playerid, Account_GetJob(playerid), !Account_GetJobUniform(playerid));
	return 1;
}

Command(name: otkaz, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 2.0, 1025.9491, -681.8823, -3.9059))
		return SendErrorMsg(playerid, "Morate biti u opstini!");

	if (!Account_GetJob(playerid))
		return SendErrorMsg(playerid, "Nemate posao!");

	if (Account_GetJobUniform(playerid))
		Account_SetJobUniform(playerid, Account_GetJob(playerid), false);
			
	Account_SetJob(playerid, 0);
	SendCustomMsgF(playerid, X11_LIGHTBLUE, "POSAO: "WHITE"Uspesno ste dali otkaz na poslu!");
	return 1;
}

Command(name: pokreniposao, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!Account_GetJobUniform(playerid))
		return SendErrorMsg(playerid, "Niste uzeli opremu za posao.");

	switch (Account_GetJob(playerid))
	{
		// Postman
		case 1:
		{
			if (!IsPlayerInRangeOfPoint(playerid, 2.0, 979.5859, -1254.7031, 16.9465))
				return SendErrorMsg(playerid, "Morate biti na mestu gde ste uzeli opremu za posao!");

			SendInfoMsg(playerid, "Zapoceli ste posao.");
			Account_SetJobStarted(playerid, Account_GetJob(playerid), true);
		}

		// Lawn mower
		case 2:
		{
			if (!IsPlayerInRangeOfPoint(playerid, 2.0, 940.5753, -1085.9894, 24.2962))
				return SendErrorMsg(playerid, "Morate biti na mestu gde ste uzeli opremu za posao!");

			SendInfoMsg(playerid, "Zapoceli ste posao.");
			Account_SetJobStarted(playerid, Account_GetJob(playerid), true);
		}

		// Bus driver
		case 3:
		{
			if (!IsPlayerInRangeOfPoint(playerid, 2.0, 1808.1638,-1907.4720,13.5732))
				return SendErrorMsg(playerid, "Morate biti na mestu gde ste uzeli opremu za posao!");

			// SendInfoMsg(playerid, "Zapoceli ste posao.");
			Dialog_Show(playerid, "DIALOG_BUSROUTE", DIALOG_STYLE_LIST,
				""MAIN_COLOR"GENERATIONZ - "WHITE"Bus linija",
				""MAIN_COLOR"1. "WHITE"Prva ruta\n"MAIN_COLOR"2. "WHITE"Druga ruta (NIJE DOSTUPNO)",
				""MAIN_COLOR"Odaberi", "Izlaz"
			);
		}

		// Weed grower
		case 4:
		{
			if (!IsPlayerInRangeOfPoint(playerid, 2.0, 2495.8860,-953.0092,82.2543))
				return SendErrorMsg(playerid, "Morate biti na mestu gde ste uzeli opremu za posao!");

			if (!WeedGrower_GetBag(playerid))
				return SendErrorMsg(playerid, "Niste uzeli torbu!");

			if (!WeedGrower_GetSeed(playerid))
				return SendErrorMsg(playerid, "Niste uzeli seme!");

			SendInfoMsg(playerid, "Zapoceli ste posao.");
			Account_SetJobStarted(playerid, Account_GetJob(playerid), true);
		}
	}
	return 1;
}

Command(name: ostavitorbu, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Account_GetJob(playerid) != 4)
		return SendErrorMsg(playerid, "Nemate posao uzgajivac marihuane!");

	if (!IsPlayerInRangeOfPoint(playerid, 2.0, 2488.9578,-961.3019,82.2570))
		return SendErrorMsg(playerid, "Niste na mestu gde se uzima torba!");

	if (!WeedGrower_GetJobDone(playerid))
		return SendErrorMsg(playerid, "Niste zavrsili posao!");

	WeedGrower_StopJob(playerid);
	WeedGrower_SetCheckpoint(playerid, 15);
	return 1;
}

Command(name: uzmitorbu, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Account_GetJob(playerid) != 4)
		return SendErrorMsg(playerid, "Nemate posao uzgajivac marihuane!");

	if (!IsPlayerInRangeOfPoint(playerid, 2.0, 2488.9578,-961.3019,82.2570))
		return SendErrorMsg(playerid, "Niste na mestu gde se uzima torba!");

	if (WeedGrower_GetBag(playerid))
		return SendErrorMsg(playerid, "Vec ste uzeli torbu!");

	WeedGrower_SetBag(playerid);
	SendCustomMsgF(playerid, X11_CYAN, "POSAO: "WHITE"Uzeli ste torbu gde cete staviti marihuanu.");
	return 1;
}

Command(name: uzmiseme, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Account_GetJob(playerid) != 4)
		return SendErrorMsg(playerid, "Nemate posao uzgajivac marihuane!");

	if (!IsPlayerInRangeOfPoint(playerid, 2.0, 2489.2358,-958.2571,82.2619))
		return SendErrorMsg(playerid, "Niste na mestu gde se uzima seme!");

	if (WeedGrower_GetSeed(playerid))
		return SendErrorMsg(playerid, "Vec ste uzeli seme!");

	WeedGrower_SetSeed(playerid);
	SendCustomMsgF(playerid, X11_CYAN, "POSAO: "WHITE"Uzeli ste seme koje cete posaditi.");
	return 1;
}

Command(name: prekiniposao, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!Account_GetJob(playerid))
		return SendErrorMsg(playerid, "Nemate posao!");

	if (!Account_JobStarted(playerid))
		return SendErrorMsg(playerid, "Niste zapoceli sa poslom!");

	Account_SetJobStarted(playerid, Account_GetJob(playerid), false);
	SendInfoMsg(playerid, "Prekinuli ste sa poslom.");

	if (Account_GetJob(playerid) == 4)
		WeedGrower_StopJob(playerid);
	return 1;
}

Command(name: hours, rank: Rank_Player(), args: playerid, const string: params[])
{
	SendInfoMsgF(playerid, "Sati igre na serveru: %d.", Account_GetHours(playerid));
	return 1;
}

Command(name: unrent, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!Rent_GetPlayerTime(playerid))
		return SendErrorMsg(playerid, "Nemate iznajmljeno vozilo!");

	Rent_Destroy(playerid);
	SendCustomMsgF(playerid, X11_CYAN, "RENT: "WHITE"Vise ne iznajmljujete vozilo!");
	return 1;
}

Command(name: kupikucu, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Account_GetHouse(playerid) != -1)
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Vec imate kucu!");

    new houseid = House_GetNearby(playerid);
    if (houseid == House_GetMaxHouses())
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Morate biti blizu neke kuce!");

    if (House_HasOwner(houseid))
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Ta kuca nije na prodaju.");

    if (Account_GetMoney(playerid) < House_GetPrice(houseid))
        return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Nemate dovoljno novca za ovu kucu!");

    Account_SetHouse(playerid, houseid);
    Account_SetMoney(playerid, (Account_GetMoney(playerid) - House_GetPrice(houseid)));
    GivePlayerMoney(playerid, -House_GetPrice(houseid));
    House_Buy(playerid, houseid);

    new String: str_query_update = str_format(
        "UPDATE houses SET house_owned = '1', house_owner = '%e' WHERE house_id = '%d'",
        ReturnPlayerName(playerid), (houseid + 1)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

// Command(name: kuca, rank: Rank_Player(), args: playerid, const string: params[])
// {
// 	if (Account_GetHouse(playerid) == -1)
//         return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Nemate kucu!");

//     new houseid = House_GetNearby(playerid);
//     if (houseid == House_GetMaxHouses())
//         return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Morate biti blizu kuce!");

//     if (strcmp(ReturnPlayerName(playerid), House_GetOwner(houseid)))
//         return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Morate biti kod svoje kuce!");

//     static tmpString[32];
//     strcopy(tmpString, (!House_IsLocked(houseid) ? (""DARKRED"Zakljucaj") : (""LIGHTGREEN"Otkljucaj")));

//     Dialog_Show(playerid, "DIALOG_HOUSEMENU", DIALOG_STYLE_LIST,
//         ""MAIN_COLOR"GENERATIONZ - "WHITE"Kuca",
//         "Komande za kucu\nPromeni opis kuce\n%s kucu\nProdaj kucu",
//         ""MAIN_COLOR"Potvrdi", "Izlaz", tmpString
//     );
// 	return 1;
// }

Command(name: locirajkucu, rank: Rank_Player(), args: playerid, const string: params[])
{
	new houseid = Account_GetHouse(playerid);
	if (houseid == -1)
		return SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Nemate kucu!");

	if (houseLocated[playerid])
	{
		houseLocated[playerid] = !houseLocated[playerid];
		SendCustomMsgF(playerid, X11_LIGHTGREEN, "(Kuca): "WHITE"Prekinuli ste lociranje Vase kuce!");
		DisablePlayerCheckpoint(playerid);
		return 1;
	}

	SendCustomMsgF(playerid, X11_LIGHTGREEN, "(Kuca): "WHITE"Vasa kuca je oznacena na mapi!");
	SetPlayerCheckpoint(playerid, House_GetPos(houseid, 0), House_GetPos(houseid, 1), House_GetPos(houseid, 2), 4.00);
	houseLocated[playerid] = !houseLocated[playerid];
	return 1;
}

Command(name: poslovi, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 1.00, 1024.2988, -681.9590, -3.9059))
		return SendErrorMsg(playerid, "Morate biti u opstini!");

	Dialog_Show(playerid, "DIALOG_JOBLIST", DIALOG_STYLE_INPUT,
		""MAIN_COLOR"GENERATIONZ - "WHITE"Lista poslova",
		""MAIN_COLOR"1 - "WHITE"Postar\n"MAIN_COLOR"2 - "WHITE"Kosac trave\n"MAIN_COLOR"3 - "WHITE"Bus vozac\n"MAIN_COLOR"4 - "WHITE"Uzgajivac marihuane\n\n"WHITE"Unesite broj posla, na mapi ce\n\
		Vam biti oznacen zeljeni posao.", ""MAIN_COLOR"Unesi", "Izlaz"
	);
	return 1;
}

Command(name: anim, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (isnull(params) || IsNumeric(params))
		return SendSyntaxMsg(playerid, "/anim [list|name|stop]");

	if (!strcmp(params, "list", false))
	{
		SendCustomMsgF(playerid, X11_LIGHTGRAY, "Animacije: carjacked | drunk | bomb | laugh | lookout | robman | lay");
        SendCustomMsgF(playerid, X11_LIGHTGRAY, "Animacije: wave | slapass | deal | crack | groundsit | chat | chat2");
        SendCustomMsgF(playerid, X11_LIGHTGRAY, "Animacije: fucku | taichi | kiss | injured | sup1 | sup2 | sup3 | rap1");
        SendCustomMsgF(playerid, X11_LIGHTGRAY, "Animacije: rap2 | push | medic | koface | lifejump | leftslap | strip");
        SendCustomMsgF(playerid, X11_LIGHTGRAY, "Animacije: dance1 | dance2 | dance3 | dance4 | bed | lean | aim | sit");
        return 1;
	}

	else if (!strcmp(params, "stop", false))
	{
		ClearAnimations(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		Anim_StopLooping(playerid);
		Anim_SetIndex(playerid, -1);
	}

	else
	{
		Anim_SetIndex(playerid, -1);
		Anim_SetPlayerAnimation(playerid, params);
	}
	return 1;
}

Command(name: vreme, rank: Rank_Player(), args: playerid, const string: params[])
{
	static tmpString[64], currentHour, currentMin, currentSec;
	gettime(currentHour, currentMin, currentSec);

	Anim_Play(playerid, "COP_AMBIENT", "Coplook_watch", 3.5, 0, 0, 0, 0, 0);
	va_GameTextForPlayer(playerid, "~y~- %02d:%02d:%02d -", 3000, 3, currentHour, currentMin, currentSec);

	format(tmpString, sizeof(tmpString), "%s podize ruku i gleda na sat.", ReturnPlayerName(playerid));
	Rank_RadiusMessage(20.0, playerid, tmpString, PURPLE_COLOR_HEX, PURPLE_COLOR_HEX, PURPLE_COLOR_HEX, PURPLE_COLOR_HEX, PURPLE_COLOR_HEX);
	return 1;
}

Command(name: id, rank: Rank_Player(), args: playerid, const string: params[])
{
	static targetName;
	if (sscanf(params, "u", targetName))
		return SendSyntaxMsg(playerid, "/id [playername]");

	if (!IsPlayerConnected(targetName))
		return SendErrorMsg(playerid, "Taj igrac nije prijavljen.");

	SendCustomMsgF(playerid, X11_CYAN, "====================================================");
	SendCustomMsgF(playerid, X11_CYAN, ""LIGHTGRAY"%s "CYAN"[ID:"LIGHTGRAY"%d"CYAN"]", ReturnPlayerName(targetName), targetName);
	SendCustomMsgF(playerid, X11_CYAN, "====================================================");
	return 1;
}

Command(name: askq, rank: Rank_Player(), args: playerid, const string: params[])
{
	static tmpString[32], staffCount;
	foreach (new i: Player)
	{
		if (Rank_GetID(i) == Rank_Moderator() || Rank_GetID(i) == Rank_Administrator())
		{
			strcopy(tmpString, ""LIGHTGREEN"Ima staff-a");
			staffCount++;
		}
	}

	if (!staffCount)
	{
		strcopy(tmpString, ""RED"Nema staff-a");
		return SendCustomMsgF(playerid, X11_RED, "ASKQ: "WHITE"Nema staff team-a, pa nemate kome poslati pitanje!");
	}

	if (gettime() < askqTimer[playerid])
		return SendCustomMsgF(playerid, X11_RED, "ASKQ: "WHITE"Pitanje mozete postaviti svaka 2 minuta!");

	Dialog_Show(playerid, "DIALOG_ASKQSELECT", DIALOG_STYLE_TABLIST_HEADERS,
		""MAIN_COLOR"GENERATIONZ - "WHITE"PITANJE",
		""WHITE"Opcija\t"WHITE"Status\n\
		"WHITE"Staff team-u\t%s",
		""MAIN_COLOR"Odaberi", "Izlaz", tmpString
	);
	return 1;
}

Command(name: report, rank: Rank_Player(), args: playerid, const string: params[])
{
	static tmpString[32], staffCount;
	foreach (new i: Player)
	{
		if (Rank_GetID(i) == Rank_Moderator() || Rank_GetID(i) == Rank_Administrator())
		{
			strcopy(tmpString, ""LIGHTGREEN"Ima staff-a");
			staffCount++;
		}
	}

	if (!staffCount)
	{
		strcopy(tmpString, ""RED"Nema staff-a");
		return SendCustomMsgF(playerid, X11_RED, "ASKQ: "WHITE"Nema staff team-a, pa nemate kome poslati prijavu!");
	}

	if (gettime() < reportTimer[playerid])
		return SendCustomMsgF(playerid, X11_RED, "ASKQ: "WHITE"Prijavu mozete poslati svaka 2 minuta!");

	Dialog_Show(playerid, "DIALOG_REPORTSELECT", DIALOG_STYLE_TABLIST_HEADERS,
		""MAIN_COLOR"GENERATIONZ - "WHITE"PRIJAVA",
		""WHITE"Opcija\t"WHITE"Status\n\
		"WHITE"Staff team-u\t%s",
		""MAIN_COLOR"Odaberi", "Izlaz", tmpString
	);
	return 1;
}

Command(name: kioskui, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!Kiosk_ChoosingItem(playerid))
		return 0;

	Kiosk_DestroyUI(playerid);
	return 1;
}

Command(name: cardealershipui, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!Vehicle_ViewingCatalogue(playerid))
		return 0;

	Vehicle_CreateCOSUI(playerid, false);
	return 1;
}

Command(name: f, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (!Org_GetID(playerid))
		return SendErrorMsg(playerid, "Niste u organizaciji!");

	if (isnull(params))
		return SendSyntaxMsg(playerid, "/f [text]");

	switch (Org_GetID(playerid))
	{
		case 1:
		{
			foreach (new i: Player)
				if (Org_GetID(i) == 1)
					SendCustomMsgF(i, X11_BLUE, "(POLICIJA) | "WHITE"%s[%d]: "LIGHTGRAY"%s", ReturnPlayerName(playerid), playerid, params);
		}

		case 2:
		{
			foreach (new i: Player)
				if (Org_GetID(i) == 2)
					SendCustomMsgF(i, X11_RED, "(HITNA POMOC) | "WHITE"%s[%d]: "LIGHTGRAY"%s", ReturnPlayerName(playerid), playerid, params);
		}
	}
	return 1;
}

Command(name: pdduznost, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Org_GetID(playerid) != 1)
		return SendErrorMsg(playerid, "Niste clan policije!");

	if (!IsPlayerInRangeOfPoint(playerid, 2.0, -6.0318,2661.6643,-49.2784))
		return SendErrorMsg(playerid, "Niste na mestu gde se uzima duznost!");

	if (Bit_Get(Bit_PDDuty, playerid))
	{
		SendCustomMsgToAllF(X11_BLUE, "#Policija: "WHITE"Policajac "BLUE"%s "WHITE"vise nije na duznosti.", ReturnPlayerName(playerid));
		Bit_Set(Bit_PDDuty, playerid, false);
		ResetPlayerWeapons(playerid);
		SetPlayerColor(playerid, X11_WHITE);
		SetPlayerSkin(playerid, Account_GetSkin(playerid));
		return 1;
	}

	SendCustomMsgToAllF(X11_BLUE, "#Policija: "WHITE"Policajac "BLUE"%s "WHITE"je sada na duznosti.", ReturnPlayerName(playerid));
	Bit_Set(Bit_PDDuty, playerid, true);

	SetPlayerColor(playerid, X11_BLUE);
	GivePlayerWeapon(playerid, 3, 1);
	GivePlayerWeapon(playerid, 22, 100);
	GivePlayerWeapon(playerid, 3, 1);
	return 1;
}

Command(name: pdoprema, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Org_GetID(playerid) != 1)
		return SendErrorMsg(playerid, "Niste clan policije!");

	if (!IsPlayerInRangeOfPoint(playerid, 2.0, -6.0318,2661.6643,-49.2784))
		return SendErrorMsg(playerid, "Niste na mestu gde se uzima oprema!");

	if (!Bit_Get(Bit_PDDuty, playerid))
		return SendErrorMsg(playerid, "Prvo morate uzeti duznost!");

	Dialog_Show(playerid, "DIALOG_PDEQUIP", DIALOG_STYLE_LIST,
		""BLUE"Policija - "WHITE"Oprema",
		""BLUE"1. "WHITE"Patrolna oprema\n\
		"BLUE"2. "WHITE"Specijalna oprema\n\
		"BLUE"3. "WHITE"Snajperska oprema\n\
		"BLUE"4. "WHITE"Normalna oprema",
		""BLUE"Odaberi", "Izlaz"
	);
	return 1;
}

Command(name: gps, rank: Rank_Player(), args: playerid, const string: params[])
{
	GPS_ShowMenu(playerid);
	return 1;
}

Command(name: b, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (isnull(params))
		return SendSyntaxMsg(playerid, "/b [ooc text]");

	static tmpString[128];
	format(tmpString, sizeof(tmpString), ""LIGHTBLUE"(OOC): (%d)%s: "WHITE"%s", playerid, ReturnPlayerName(playerid), params);
	Rank_RadiusMessage(20.0, playerid, tmpString, X11_WHITE, X11_WHITE, X11_WHITE, X11_WHITE, X11_WHITE);
	return 1;
}

Command(name: orgrank, rank: Rank_Player(), args: playerid, const string: params[])
{
	if (Org_GetRank(playerid) != 5)
		return SendErrorMsg(playerid, "Samo lideri organizacije!");

	static
		targetid,
		rankid;

	if (sscanf(params, "ri", targetid, rankid))
		return SendSyntaxMsg(playerid, "/orgrank [targetid] [rank (1-5)]");

	if (targetid == _:playerid)
		return SendErrorMsg(playerid, "Ne mozete sami sebi postavljati rank!");

	if (!Org_GetID(targetid))
		return SendErrorMsg(playerid, "Taj igrac nije u organizaciji!");

	if (!(0 <= rankid <= 5))
		return SendErrorMsg(playerid, "Nepostojeci rank, (0-5)!");

	if (!rankid && Org_GetID(targetid))
	{
		SendCustomMsgF(targetid, X11_RED, "(Organizacija): "WHITE"%s Vas je izbacio iz organizacije.", ReturnPlayerName(playerid));
		SendCustomMsgF(playerid, X11_RED, "(Organizacija): "WHITE"Igraca %s ste izbacili iz organizacije.", ReturnPlayerName(targetid));
		Org_SetID(targetid, 0);
		Org_SetRank(targetid, 0);
		Account_SetSkin(targetid, 1);
		return 1;
	}

	if (rankid == Org_GetRank(targetid))
		return SendErrorMsg(playerid, "Taj igrac je vec taj rank!");

	Org_SetRank(targetid, rankid);
	SendCustomMsgF(targetid, X11_LIGHTGREEN, "(Organizacija): "WHITE"%s Vam je postavio '"LIGHTGREEN"%d"WHITE"' rank.", ReturnPlayerName(playerid), rankid);
	SendCustomMsgF(playerid, X11_LIGHTGREEN, "(Organizacija): "WHITE"Igracu %s ste postavili '"LIGHTGREEN"%d"WHITE"' rank.", ReturnPlayerName(targetid), rankid);
	return 1;
}

Command(name: stats, rank: Rank_Player(), args: playerid, const string: params[])
{
	Dialog_Show(playerid, "DIALOG_STATS", DIALOG_STYLE_MSGBOX,
		""MAIN_COLOR"GENERATIONZ - "WHITE"Statistika",
		""MAIN_COLOR"_____________________________\n\
		"MAIN_COLOR"Ime i prezime: "WHITE"%s %s\n\
		"MAIN_COLOR"Spol: "WHITE"%s\n\
		"MAIN_COLOR"ID: "WHITE"%d\n\n\
		"MAIN_COLOR"Rank: "WHITE"%s\n\
		"MAIN_COLOR"Skin: "WHITE"%d\n\
		"MAIN_COLOR"Sati igre: "WHITE"%d\n\
		"MAIN_COLOR"Level: "WHITE"%d\n\
		"MAIN_COLOR"Exp: "WHITE"%d/%d\n\
		"MAIN_COLOR"Novac kod sebe: "DARKGREEN"$"WHITE"%d\n\
		"MAIN_COLOR"Novac u banci: "DARKGREEN"$"WHITE"%d\n\
		"MAIN_COLOR"Zlato: "WHITE"%d"YELLOW"g\n\
		"MAIN_COLOR"Marihuana: "WHITE"%dg\n\n\
		"MAIN_COLOR"Kuca: "WHITE"%d\n\n\
		"MAIN_COLOR"Posao: "WHITE"%s\n\
		"MAIN_COLOR"Organizacija: "WHITE"%s (rank: %d)\n\
		"MAIN_COLOR"_____________________________",
		"Izlaz", "",
		Player_SplitName(playerid, "name"), Player_SplitName(playerid, "lastname"),
		((Account_GetGender(playerid) == 1) ? "Musko" : "Zensko"),
		playerid, Rank_GetNameByID(Rank_GetID(playerid)),
		Account_GetSkin(playerid), Account_GetHours(playerid),
		Account_GetScore(playerid), Account_GetExp(playerid), (Account_GetScore(playerid) * 2),
		Account_GetMoney(playerid), Account_GetBankMoney(playerid), Account_GetGold(playerid),
		WeedGrower_GetPlayerMarijuana(playerid), Account_GetHouse(playerid),
		Account_GetJobNameByID(Account_GetJob(playerid)),
		Org_GetNameByID(Org_GetID(playerid)), Org_GetRank(playerid)
	);
	return 1;
}

Command(name: smokeweed, rank: Rank_Player(), args: playerid, const string: params)
{
	if (WeedGrower_GetPlayerMarijuana(playerid) < 10)
		return SendErrorMsg(playerid, "Nemate marihuane kod sebe (min. 10g)!");

	WeedGrower_UseMarijuana(playerid);
	return 1;
}

Dialog: DIALOG_PDEQUIP(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;

	switch (listitem)
	{
		case 0:
		{
			SendInfoMsg(playerid, "Uzeli ste opremu za patroliranje!");
			ResetPlayerWeapons(playerid);
			GivePlayerWeapon(playerid, 22, 100);
			GivePlayerWeapon(playerid, 41, 500);
			GivePlayerWeapon(playerid, 3, 1);
			SetPlayerSkin(playerid, Account_GetSkin(playerid));
		}
		
		case 1:
		{
			SendInfoMsg(playerid, "Uzeli ste opremu specijalnu opremu!");
			ResetPlayerWeapons(playerid);
			GivePlayerWeapon(playerid, 22, 100);
			GivePlayerWeapon(playerid, 31, 200);
			GivePlayerWeapon(playerid, 29, 200);
			GivePlayerWeapon(playerid, 17, 200);
			SetPlayerSkin(playerid, 285);
		}

		case 2:
		{
			SendInfoMsg(playerid, "Uzeli ste opremu za snajperiste!");
			ResetPlayerWeapons(playerid);
			GivePlayerWeapon(playerid, 22, 100);
			GivePlayerWeapon(playerid, 34, 100);
			SetPlayerSkin(playerid, Account_GetSkin(playerid));
		}

		case 3:
		{
			SendInfoMsg(playerid, "Uzeli ste normalnu opremu!");
			ResetPlayerWeapons(playerid);
			GivePlayerWeapon(playerid, 3, 1);
			GivePlayerWeapon(playerid, 22, 100);
			GivePlayerWeapon(playerid, 3, 1);
			SetPlayerSkin(playerid, Account_GetSkin(playerid));
		}
	}
	return 1;
}

Dialog: DIALOG_BUSROUTE(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;

	BusDriver_SetRoute(playerid, (listitem + 1));
	Account_SetJobStarted(playerid, Account_GetJob(playerid), true);
	return 1;
}

Dialog: DIALOG_ASKQSELECT(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;
	
	if (!listitem)
		Dialog_Show(playerid, "DIALOG_ASKQSTAFF", DIALOG_STYLE_INPUT,
			""MAIN_COLOR"GENERATIONZ - "WHITE"PITANJE",
			""WHITE"Unesite pitanje koje zelite da postavite staff team-u:",
			""MAIN_COLOR"Unesi", "Izlaz"
		);
	return 1;
}

Dialog: DIALOG_REPORTSELECT(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;
	
	if (!listitem)
		Dialog_Show(playerid, "DIALOG_REPORTSTAFF", DIALOG_STYLE_INPUT,
			""MAIN_COLOR"GENERATIONZ - "WHITE"PRIJAVA",
			""WHITE"Unesite prijavu koju zelite da posaljete staff team-u:",
			""MAIN_COLOR"Unesi", "Izlaz"
		);
	return 1;
}

Dialog: DIALOG_ASKQSTAFF(const playerid, response, listitem, const string: inputtext[])
{
	if (!response)
		return Command_Call(name: askq, args: playerid, "");

	if (isnull(inputtext))
	{
		SendCustomMsgF(playerid, X11_RED, "ASKQ: "WHITE"Morate napisati nesto, (inv/askq)!");
		return Command_Call(name: askq, args: playerid, "");
	}

	if (strlen(inputtext) > 128)
	{
		SendCustomMsgF(playerid, X11_RED, "ASKQ: "WHITE"Predugacak tekst, (inv/askq)!");
		return Command_Call(name: askq, args: playerid, "");	
	}

	SendCustomMsgF(playerid, X11_YELLOW, "ASKQ: "WHITE"Poslali ste pitanje staff team-u!");
	Rank_StaffMessage(X11_YELLOW, "#Q: "WHITE"%s(%d) pita: "YELLOW"%s", ReturnPlayerName(playerid), playerid, inputtext);
	askqTimer[playerid] = (gettime() + (60 * ASKQ_TIMER_MIN));
	return 1;
}

Dialog: DIALOG_REPORTSTAFF(const playerid, response, listitem, const string: inputtext[])
{
	if (!response)
		return Command_Call(name: report, args: playerid, "");

	if (isnull(inputtext))
	{
		SendCustomMsgF(playerid, X11_RED, "REPORT: "WHITE"Morate napisati nesto, (inv/report)!");
		return Command_Call(name: report, args: playerid, "");
	}

	if (strlen(inputtext) > 128)
	{
		SendCustomMsgF(playerid, X11_RED, "REPORT: "WHITE"Predugacak tekst, (inv/report)!");
		return Command_Call(name: report, args: playerid, "");	
	}

	SendCustomMsgF(playerid, X11_RED, "REPORT: "WHITE"Poslali ste prijavu staff team-u!");
	Rank_StaffMessage(X11_RED, "#REPORT: "WHITE"%s(%d) prijavljuje: "RED"%s", ReturnPlayerName(playerid), playerid, inputtext);
	reportTimer[playerid] = (gettime() + (60 * ASKQ_TIMER_MIN));
	return 1;
}

Dialog: DIALOG_PLAYERHELP(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;

	return 1;
}

Dialog:DIALOG_WINTER(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    switch (listitem)
    {
    	case 0:
    	{
    		Winter_ShowSnowObjects(playerid);
    		return Command_Call(name: we, args: playerid, "");
    	}
    	
        case 1:
    	{
    		Winter_SetSnowflakeStatus(playerid);
    		return Command_Call(name: we, args: playerid, "");
    	}
    	
        case 2:
    	{
    		Winter_SetSnowCapStatus(playerid);
    		return Command_Call(name: we, args: playerid, "");
    	}
    	
        case 3:
    	{
    		Winter_SetColdBreathStatus(playerid);
    		return Command_Call(name: we, args: playerid, "");
    	}
    	
        case 4:
        {
        	Winter_SetStatusAll(playerid);
        	return Command_Call(name: we, args: playerid, "");
        }
    }
    return 1;
}

Dialog: DIALOG_BANK(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;

	switch (listitem)
	{
		case 0:
		{
			if (!Account_GetBankMoney(playerid))
			{
				SendErrorMsg(playerid, "Nemate novca u banci!");
				Command_Call(name: banka, args: playerid, "");
				return 1;
			}

			Dialog_Show(playerid, "DIALOG_BANKTAKEMONEY", DIALOG_STYLE_INPUT,
				""MAIN_COLOR"GENERATIONZ - "WHITE"Podigni novac",
				""MAIN_COLOR"Banka: "WHITE"Unesite koliko novca podizete:",
				""MAIN_COLOR"Potvrdi", "Izlaz"
			);
		}

		case 1:
		{
			if (!Account_GetMoney(playerid))
			{
				SendErrorMsg(playerid, "Nemate novca kod sebe!");
				Command_Call(name: banka, args: playerid, "");
				return 1;
			}

			Dialog_Show(playerid, "DIALOG_BANKLEAVEMONEY", DIALOG_STYLE_INPUT,
				""MAIN_COLOR"GENERATIONZ - "WHITE"Ostavi novac",
				""MAIN_COLOR"Banka: "WHITE"Unesite koliko novca ostavljate:",
				""MAIN_COLOR"Potvrdi", "Izlaz"
			);
		}

		case 2:
		{
			if (!Account_GetBankMoney(playerid) && !Account_GetMoney(playerid))
			{
				SendErrorMsg(playerid, "Nemate novca ni u banci ni kod sebe!");
				Command_Call(name: banka, args: playerid, "");
				return 1;
			}

			Dialog_Show(playerid, "DIALOG_BANKTRANSFERMONEY", DIALOG_STYLE_LIST,
				""MAIN_COLOR"GENERATIONZ - "WHITE"Prebaci novac",
				""WHITE"Prebaci sa bankovnog racuna\n"WHITE"Prebaci sa novcem kod sebe",
				""MAIN_COLOR"Potvrdi", "Izlaz"
			);
		}
	}
	return 1;
}

Dialog: DIALOG_BANKTAKEMONEY(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return Command_Call(name: banka, args: playerid, "");

	if (Account_GetBankMoney(playerid) < strval(inputtext))
	{
		SendErrorMsg(playerid, "Nemate toliko novca u banci!");
		Command_Call(name: banka, args: playerid, "");
		return 1;
	}

	SendServerMsgF(playerid, "Podigli ste "DARKGREEN"$"WHITE"%d iz banke.", strval(inputtext));
	Account_SetBankMoney(playerid, Account_GetBankMoney(playerid) - strval(inputtext));
	Account_SetMoney(playerid, Account_GetMoney(playerid) + strval(inputtext));
	GivePlayerMoney(playerid, strval(inputtext));

	UI_UpdateInfoTD(playerid);
	return 1;
}

Dialog: DIALOG_BANKLEAVEMONEY(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return Command_Call(name: banka, args: playerid, "");

	if (Account_GetMoney(playerid) < strval(inputtext))
	{
		SendErrorMsg(playerid, "Nemate toliko novca kod sebe!");
		Command_Call(name: banka, args: playerid, "");
		return 1;
	}

	SendServerMsgF(playerid, "Ostavili ste "DARKGREEN"$"WHITE"%d u banku.", strval(inputtext));
	Account_SetBankMoney(playerid, Account_GetBankMoney(playerid) + strval(inputtext));
	Account_SetMoney(playerid, Account_GetMoney(playerid) - strval(inputtext));
	GivePlayerMoney(playerid, -strval(inputtext));

	UI_UpdateInfoTD(playerid);
	return 1;
}

Dialog: DIALOG_BANKTRANSFERMONEY(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return Command_Call(name: banka, args: playerid, "");

	switch (listitem)
	{
		case 0:
		{
			Dialog_Show(playerid, "DIALOG_TFBANKMONEY", DIALOG_STYLE_INPUT,
				""MAIN_COLOR"GENERATIONZ - "WHITE"Prebaci novac",
				""WHITE"Unesite kolicinu novca i id/ime igraca kojem saljete novac:",
				""MAIN_COLOR"Potvrdi", "Izlaz"
			);
		}

		case 1:
		{
			Dialog_Show(playerid, "DIALOG_TFPOCKETMONEY", DIALOG_STYLE_INPUT,
				""MAIN_COLOR"GENERATIONZ - "WHITE"Prebaci novac",
				""WHITE"Unesite kolicinu novca i id/ime igraca kojem saljete novac:",
				""MAIN_COLOR"Potvrdi", "Izlaz"
			);
		}
	}
	return 1;
}

Dialog: DIALOG_TFBANKMONEY(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return Command_Call(name: banka, args: playerid, "");

	static targetid, money;
	if (sscanf(inputtext, "ir", money, targetid))
	{
		SendErrorMsg(playerid, "Unesite kolicinu novca i ID/Ime igraca kojem saljete!");
		return Command_Call(name: banka, args: playerid, "");
	}

	if (!IsPlayerConnected(targetid))
	{
		SendErrorMsg(playerid, "Taj korisnik nije prijavljen!");
		return Command_Call(name: banka, args: playerid, "");
	}

	if (Account_GetBankMoney(playerid) < money)
	{
		SendErrorMsg(playerid, "Nemate toliko novca na bankovnom racunu!");
		return Command_Call(name: banka, args: playerid, "");
	}

	if (!Account_GetBankCard(targetid))
	{
		SendErrorMsg(playerid, "Taj korisnik nema otvoren bankovni racun!");
		return Command_Call(name: banka, args: playerid, "");
	}

	SendServerMsgF(playerid, "Poslali ste "DARKGREEN"$"WHITE"%d igracu "MAIN_COLOR"%s"WHITE".", money, ReturnPlayerName(targetid));
	SendServerMsgF(playerid, "Dobili ste "DARKGREEN"$"WHITE"%d od igraca "MAIN_COLOR"%s"WHITE".", money, ReturnPlayerName(playerid));

	Account_SetBankMoney(playerid, Account_GetMoney(playerid) - money);
	Account_SetBankMoney(targetid, Account_GetBankMoney(targetid) + money);
	UI_UpdateInfoTD(playerid);
	UI_UpdateInfoTD(targetid);
	return 1;
}

Dialog: DIALOG_TFPOCKETMONEY(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return Command_Call(name: banka, args: playerid, "");

	static targetid, money;
	if (sscanf(inputtext, "ir", money, targetid))
	{
		SendErrorMsg(playerid, "Unesite kolicinu novca i ID/Ime igraca kojem saljete!");
		return Command_Call(name: banka, args: playerid, "");
	}

	if (!IsPlayerConnected(targetid))
	{
		SendErrorMsg(playerid, "Taj korisnik nije prijavljen!");
		return Command_Call(name: banka, args: playerid, "");
	}

	if (Account_GetMoney(playerid) < money)
	{
		SendErrorMsg(playerid, "Nemate toliko novca kod sebe!");
		return Command_Call(name: banka, args: playerid, "");
	}

	if (!Account_GetBankCard(targetid))
	{
		SendErrorMsg(playerid, "Taj korisnik nema otvoren bankovni racun!");
		return Command_Call(name: banka, args: playerid, "");
	}

	SendServerMsgF(playerid, "Poslali ste "DARKGREEN"$"WHITE"%d igracu "MAIN_COLOR"%s"WHITE".", money, ReturnPlayerName(targetid));
	SendServerMsgF(playerid, "Dobili ste "DARKGREEN"$"WHITE"%d od igraca "MAIN_COLOR"%s"WHITE".", money, ReturnPlayerName(playerid));

	Account_SetMoney(playerid, Account_GetMoney(playerid) - money);
	GivePlayerMoney(playerid, -money);
	Account_SetBankMoney(targetid, Account_GetBankMoney(targetid) + money);
	
	UI_UpdateInfoTD(playerid);
	UI_UpdateInfoTD(targetid);
	return 1;
}

Dialog: DIALOG_JOBLIST(const playerid, response, listitem, string: inputtext[])
{
	if (!response)
		return 1;

	if (isnull(inputtext) && !IsNumeric(inputtext))
		return Command_Call(name: poslovi, args: playerid, "");

	switch (strval(inputtext))
	{
		case 1:
		{
			SetPlayerCheckpoint(playerid, 986.8093, -1252.5247, 16.9844, 3.00);
			GameTextForPlayer(playerid, "~w~POSAO JE ~g~OZNACEN ~w~NA MAPI!", 3000, 3);
		}

		case 2:
		{
			SetPlayerCheckpoint(playerid, 940.5753, -1085.9894, 24.2962, 3.00);
			GameTextForPlayer(playerid, "~w~POSAO JE ~g~OZNACEN ~w~NA MAPI!", 3000, 3);
		}

		case 3:
		{
			SetPlayerCheckpoint(playerid, 1808.0718,-1904.3878,13.5755, 3.00);
			GameTextForPlayer(playerid, "~w~POSAO JE ~g~OZNACEN ~w~NA MAPI!", 3000, 3);
		}
		
		default: Command_Call(name: poslovi, args: playerid, "");
	}
	return 1;
}