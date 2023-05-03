#if defined _INC_selection_init_inc
    #endinput
#endif
#define _INC_selection_init_inc

#include <YSI_Coding\y_hooks>

static
    PlayerText:selectionTextDraw[MAX_PLAYERS][13] = {PlayerText:INVALID_PLAYER_TEXT_DRAW,...},
    bool:selectionTextDrawStatus[MAX_PLAYERS],
    selectionCarDoors[MAX_PLAYERS][4],
    selectionCarWindows[MAX_PLAYERS][4],
    selectionCarBonnet[MAX_PLAYERS],
    selectionCarBoot[MAX_PLAYERS],
    selectionCarModel[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    selectionTextDrawStatus[playerid] = false;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_YES))
        Selection_CreateUI(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == selectionTextDraw[playerid][8])
        Selection_CreateUI(playerid);

    else if (playertextid == selectionTextDraw[playerid][4])
    {
        House_OpenMenu(playerid);
        Selection_CreateUI(playerid);
    }

    else if (playertextid == selectionTextDraw[playerid][5])
    {
        Dialog_Show(playerid, "DIALOG_VEHICLETYPE", DIALOG_STYLE_LIST,
            ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
            "Automobil\nMotor\nBicikl\nTraktor", ""MAIN_COLOR"Odaberi", "Izlaz"
        );
        Selection_CreateUI(playerid);
    }

    else if (playertextid == selectionTextDraw[playerid][7])
    {
        Selection_CreateUI(playerid);
        UI_CreateIDCard(playerid);
    }

    else if (playertextid == PlayerText:UI_ReturnIDCardTD(playerid, 23))
        UI_CreateIDCard(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock bool:Selection_GetUI(const playerid) return selectionTextDrawStatus[playerid];
stock Selection_CreateUI(const playerid)
{
    new const bool:status = !Selection_GetUI(playerid);
    if (!status)
    {
        for (new i = 0; i < 13; i++)
        {
            PlayerTextDrawDestroy(playerid, selectionTextDraw[playerid][i]);
            selectionTextDraw[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }

        CancelSelectTextDraw(playerid);
        selectionTextDrawStatus[playerid] = false;
        return 1;
    }

    selectionTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 287.000000, 111.177886, "LD_POOL:BALL");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][0], 66.000000, 71.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][0], 796937471);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][0], 0);

    selectionTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 356.701263, 170.821685, "LD_POOL:BALL");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][1], 66.000000, 71.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][1], 796937471);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][1], 0);

    selectionTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 214.092559, 171.321716, "LD_POOL:BALL");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][2], 66.000000, 71.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][2], 796937471);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][2], 0);

    selectionTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 287.000000, 226.983673, "LD_POOL:BALL");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][3], 66.000000, 71.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][3], 796937471);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][3], 0);

    selectionTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 278.100067, 100.411102, "");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][4], 82.000000, 92.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][4], 0x00000000);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][4], true);
    PlayerTextDrawSetPreviewModel(playerid, selectionTextDraw[playerid][4], 19522);
    PlayerTextDrawSetPreviewRot(playerid, selectionTextDraw[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][4], true);

    selectionTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 206.100036, 160.144470, "");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][5], 82.000000, 92.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][5], 0x00000000);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][5], true);
    PlayerTextDrawSetPreviewModel(playerid, selectionTextDraw[playerid][5], 11746);
    PlayerTextDrawSetPreviewRot(playerid, selectionTextDraw[playerid][5], 0.000000, -90.000000, 0.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][5], true);

    selectionTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 361.600067, 183.788879, "");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][6], 54.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][6], 0x00000000);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][6], true);
    PlayerTextDrawSetPreviewModel(playerid, selectionTextDraw[playerid][6], 1274);
    PlayerTextDrawSetPreviewRot(playerid, selectionTextDraw[playerid][6], 0.000000, 0.000000, 180.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][6], true);

    selectionTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 298.600067, 236.677795, "");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][7], 43.000000, 51.000000);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][7], 0x00000000);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][7], true);
    PlayerTextDrawSetPreviewModel(playerid, selectionTextDraw[playerid][7], 1581);
    PlayerTextDrawSetPreviewRot(playerid, selectionTextDraw[playerid][7], 0.000000, 0.000000, 0.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][7], true);

    selectionTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 319.100067, 318.444335, "ZATVORI");
    PlayerTextDrawTextSize(playerid, selectionTextDraw[playerid][8], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, selectionTextDraw[playerid][8], 0.287499, 1.568888);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][8], 2);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][8], -16777063);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, selectionTextDraw[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][8], 3);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, selectionTextDraw[playerid][8], true);

    selectionTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 320.000000, 176.933334, "IMOVINA");
    PlayerTextDrawLetterSize(playerid, selectionTextDraw[playerid][9], 0.176000, 0.629333);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][9], 2);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, selectionTextDraw[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][9], 1);

    selectionTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 390.000000, 237.066711, "FIRMA");
    PlayerTextDrawLetterSize(playerid, selectionTextDraw[playerid][10], 0.176000, 0.629333);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][10], 2);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, selectionTextDraw[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][10], 1);

    selectionTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 247.000000, 238.311157, "VOZILO");
    PlayerTextDrawLetterSize(playerid, selectionTextDraw[playerid][11], 0.176000, 0.629333);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][11], 2);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, selectionTextDraw[playerid][11], 1);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][11], 1);

    selectionTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 319.400085, 293.688964, "LICNA_KARTA");
    PlayerTextDrawLetterSize(playerid, selectionTextDraw[playerid][12], 0.176000, 0.629333);
    PlayerTextDrawAlignment(playerid, selectionTextDraw[playerid][12], 2);
    PlayerTextDrawColor(playerid, selectionTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, selectionTextDraw[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, selectionTextDraw[playerid][12], 1);
    PlayerTextDrawBackgroundColor(playerid, selectionTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, selectionTextDraw[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, selectionTextDraw[playerid][12], 1);

    for (new i = 0; i < 13; i++)
        PlayerTextDrawShow(playerid, selectionTextDraw[playerid][i]);

    SelectTextDraw(playerid, X11_GRAY);
    selectionTextDrawStatus[playerid] = true;
    return 1;
}

stock Selection_UpdateCarStatus(const playerid)
{
    new tmpString[10][32];

    strcopy(tmpString[0], Vehicle_GetDoorStatus(selectionCarModel[playerid], 0) == 1 ? ""LIGHTGREEN"Otvorena" : ""DARKRED"Zatvorena");
    strcopy(tmpString[1], Vehicle_GetDoorStatus(selectionCarModel[playerid], 1) == 1 ? ""LIGHTGREEN"Otvorena" : ""DARKRED"Zatvorena");
    strcopy(tmpString[2], Vehicle_GetDoorStatus(selectionCarModel[playerid], 2) == 1 ? ""LIGHTGREEN"Otvorena" : ""DARKRED"Zatvorena");
    strcopy(tmpString[3], Vehicle_GetDoorStatus(selectionCarModel[playerid], 3) == 1 ? ""LIGHTGREEN"Otvorena" : ""DARKRED"Zatvorena");
    strcopy(tmpString[4], Vehicle_GetWindowStatus(selectionCarModel[playerid], 0) == 1 ? ""LIGHTGREEN"Otvoren" : ""DARKRED"Zatvoren");
    strcopy(tmpString[5], Vehicle_GetWindowStatus(selectionCarModel[playerid], 1) == 1 ? ""LIGHTGREEN"Otvoren" : ""DARKRED"Zatvoren");
    strcopy(tmpString[6], Vehicle_GetWindowStatus(selectionCarModel[playerid], 2) == 1 ? ""LIGHTGREEN"Otvoren" : ""DARKRED"Zatvoren");
    strcopy(tmpString[7], Vehicle_GetWindowStatus(selectionCarModel[playerid], 3) == 1 ? ""LIGHTGREEN"Otvoren" : ""DARKRED"Zatvoren");
    strcopy(tmpString[8], Vehicle_GetBonnetStatus(selectionCarModel[playerid]) == 1 ? ""LIGHTGREEN"Otvorena" : ""DARKRED"Zatvorena");
    strcopy(tmpString[9], Vehicle_GetBootStatus(selectionCarModel[playerid]) == 1 ? ""LIGHTGREEN"Otvoren" : ""DARKRED"Zatvoren");

    Dialog_Show(playerid, "DIALOG_CONTROLCAR", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
        ""WHITE"Opcija\t"WHITE"Status\n\
        Lociraj vozilo\t-\n\
        Leva prednja vrata\t%s\n\
        Desna prednja vrata\t%s\n\
        Leva zadnja vrata\t%s\n\
        Desna zadnja vrata\t%s\n\
        Levi prednji prozor\t%s\n\
        Desni prednji prozor\t%s\n\
        Levi zadnji prozor\t%s\n\
        Desni zadnji prozor\t%s\n\
        Hauba\t%s\n\
        Gepek\t%s", ""MAIN_COLOR"Odaberi", "Izlaz",
        tmpString[0], tmpString[1], tmpString[2], tmpString[3],
        tmpString[4], tmpString[5], tmpString[6], tmpString[7],
        tmpString[8], tmpString[9]
    );
    return 1;
}

Dialog: DIALOG_VEHICLETYPE(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    switch (listitem)
    {
        case 0:
        {
            task_await(
                MySQL_QueryS(
                    str_format("SELECT * FROM vehicles WHERE vehicle_owner = '%e' ORDER BY vehicle_owner ASC", ReturnPlayerName(playerid))
                )
            );

            if (!cache_num_rows())
                return SendErrorMsg(playerid, "Nemate nijedan automobil!");

            static rows, tmpString[64];
            strcopy(tmpString, "");

            cache_get_row_count(rows);
            for (new i = 0; i < rows; i++)
            {
                static tmpInt;
                cache_get_value_name_int(i, "vehicle_model", tmpInt);
                Vehicle_SetPlayerModelID(playerid, i, tmpInt);

                format(tmpString, sizeof(tmpString), "%s\n%s", tmpString, Vehicle_GetModelName(Vehicle_GetPlayerModelID(playerid, i)));
                Dialog_Show(playerid, "DIALOG_VEHICLESELECT", DIALOG_STYLE_LIST,
                    ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
                    tmpString, ""MAIN_COLOR"Odaberi", "Izlaz"
                );
            }
        }

        case 1:
        {
            Dialog_Show(playerid, "DIALOG_VEHICLETYPE", DIALOG_STYLE_LIST,
                ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
                "Automobil\nMotor\nBicikl\nTraktor", ""MAIN_COLOR"Odaberi", "Izlaz"
            );
            SendErrorMsg(playerid, "Ta opcija trenutno nije u mogucnosti!");
        }

        case 2:
        {
            Dialog_Show(playerid, "DIALOG_VEHICLETYPE", DIALOG_STYLE_LIST,
                ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
                "Automobil\nMotor\nBicikl\nTraktor", ""MAIN_COLOR"Odaberi", "Izlaz"
            );
            SendErrorMsg(playerid, "Ta opcija trenutno nije u mogucnosti!");
        }

        case 3:
        {
            Dialog_Show(playerid, "DIALOG_VEHICLETYPE", DIALOG_STYLE_LIST,
                ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
                "Automobil\nMotor\nBicikl\nTraktor", ""MAIN_COLOR"Odaberi", "Izlaz"
            );
            SendErrorMsg(playerid, "Ta opcija trenutno nije u mogucnosti!");
        }
    }

    return 1;
}

Dialog: DIALOG_VEHICLESELECT(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return Selection_CreateUI(playerid);

    selectionCarModel[playerid] = Vehicle_GetPlayerModelID(playerid, listitem);
    Selection_UpdateCarStatus(playerid);
    return 1;
}


Dialog: DIALOG_CONTROLCAR(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return Dialog_Show(playerid, "DIALOG_VEHICLETYPE", DIALOG_STYLE_LIST,
            ""MAIN_COLOR"GENERATIONZ - "WHITE"VOZILO",
            "Automobil\nMotor\nBicikl\nTraktor", ""MAIN_COLOR"Odaberi", "Izlaz"
        );

    switch (listitem)
    {
        case 1..4:
        {
            if (GetVehicleModel(GetPlayerVehicleID(playerid)) != selectionCarModel[playerid])
                return SendErrorMsg(playerid, "Niste u odabranom vozilu!");

            selectionCarDoors[playerid][listitem - 1] = !selectionCarDoors[playerid][listitem - 1];
            Vehicle_SetDoorStatus(selectionCarModel[playerid], GetPlayerVehicleID(playerid), listitem - 1, selectionCarDoors[playerid][listitem - 1]);
            Selection_UpdateCarStatus(playerid);
        }

        case 5..8:
        {
            if (GetVehicleModel(GetPlayerVehicleID(playerid)) != selectionCarModel[playerid])
                return SendErrorMsg(playerid, "Niste u odabranom vozilu!");

            selectionCarWindows[playerid][listitem - 5] = !selectionCarWindows[playerid][listitem - 5];
            Vehicle_SetWindowStatus(selectionCarModel[playerid], GetPlayerVehicleID(playerid), listitem - 5, selectionCarWindows[playerid][listitem - 5]);
            Selection_UpdateCarStatus(playerid);
        }

        case 9:
        {
            if (GetVehicleModel(GetPlayerVehicleID(playerid)) != selectionCarModel[playerid])
                return SendErrorMsg(playerid, "Niste u odabranom vozilu!");

            if (Vehicle_GetBootStatus(selectionCarModel[playerid]))
                return SendErrorMsg(playerid, "Prvo morate zatvoriti gepek!");

            selectionCarBonnet[playerid] = !selectionCarBonnet[playerid];
            Vehicle_SetBonnetStatus(selectionCarModel[playerid], GetPlayerVehicleID(playerid), selectionCarBonnet[playerid]);
            Selection_UpdateCarStatus(playerid);
        }

        case 10:
        {
            if (GetVehicleModel(GetPlayerVehicleID(playerid)) != selectionCarModel[playerid])
                return SendErrorMsg(playerid, "Niste u odabranom vozilu!");

            if (Vehicle_GetBonnetStatus(selectionCarModel[playerid]))
                return SendErrorMsg(playerid, "Prvo morate zatvoriti haubu!");

            selectionCarBoot[playerid] = !selectionCarBoot[playerid];
            Vehicle_SetBootStatus(selectionCarModel[playerid], GetPlayerVehicleID(playerid), selectionCarBoot[playerid]);
            Selection_UpdateCarStatus(playerid);
        }
    }
    return 1;
}

Dialog: DIALOG_HOUSEMENU(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    switch (listitem)
    {
        case 0:
        {
            Dialog_Show(playerid, "DIALOG_HOUSEDESC", DIALOG_STYLE_INPUT,
                ""MAIN_COLOR"GENERATIONZ - "WHITE"Opis kuce",
                "Unesite opis za vasu kucu:",
                ""MAIN_COLOR"Potvrdi", "Nazad"
            );
        }

        case 1:
        {
            new houseid = House_GetNearby(playerid);
            House_SetLocked(houseid, (!House_IsLocked(houseid) ? (1) : (0)));

            SendInfoMsgF(playerid, "%s ste kucu.", (!House_IsLocked(houseid) ? ("Otkljucali") : ("Zakljucali")));
            House_OpenMenu(playerid);
        }

        case 2:
        {
            Dialog_Show(playerid, "DIALOG_HOUSESELL", DIALOG_STYLE_INPUT,
                ""MAIN_COLOR"GENERATIONZ - "WHITE"Prodaj kucu",
                "Unesite id igraca kome zelite prodati i cenu za koliko zelite prodati kucu:",
                ""MAIN_COLOR"Unesi", "Nazad"
            );
        }
    }
    return 1;
}

Dialog: DIALOG_HOUSEDESC(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return House_OpenMenu(playerid);

    new houseid = House_GetNearby(playerid);

    if (isnull(inputtext))
        return House_OpenMenu(playerid);

    if (strval(inputtext) > MAX_REASON_LENGTH)
    {
        SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Predugacak opis kuce!");
        return House_OpenMenu(playerid);
    }

    if (!strcmp(inputtext, House_GetDescription(houseid), false))
    {
        SendCustomMsgF(playerid, X11_RED, "(Kuca!): "WHITE"Ne mozete postaviti isti opis!");
        return House_OpenMenu(playerid);
    }

    House_SetDescription(houseid, inputtext);
    SendCustomMsgF(playerid, X11_GREEN, "(Kuca): "WHITE"Promenili ste opis kuce!");
    return 1;
}

Dialog: DIALOG_HOUSESELL(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return House_OpenMenu(playerid);

    static
        targetid,
        price;

    if (sscanf(inputtext, "ri", targetid, price))
    {
        SendErrorMsg(playerid, "Unesite ID/Ime igraca i cenu kuce!");
        return House_OpenMenu(playerid);
    }

    new
        houseid = House_GetNearby(playerid),
        Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    if (IsPlayerInRangeOfPoint(targetid, 3.0, x, y, z))
    {
        SendErrorMsg(playerid, "Igrac kome zelite prodati kucu nije blizu Vas!");
        return House_OpenMenu(playerid);
    }

    if (Account_GetMoney(targetid) < price)
    {
        SendErrorMsg(playerid, "Igrac kome zelite prodati kucu nema dovoljno novca!");
        return House_OpenMenu(playerid);
    }

    SendInfoMsgF(playerid, "Prodali ste kucu igracu %s za "GREEN"$"WHITE"%d!", ReturnPlayerName(targetid), price);
    SendInfoMsgF(targetid, "%s Vam je prodao kucu za "GREEN"$"WHITE"%d!", ReturnPlayerName(playerid), price);
    House_Buy(targetid, houseid);

    new String: str_query_update = str_format("UPDATE houses SET house_owner = '%e' WHERE house_id = '%d'", ReturnPlayerName(targetid), houseid);
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}