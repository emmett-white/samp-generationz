#if defined _INC_rent_init_inc
    #endinput
#endif
#define _INC_rent_init_inc

#include <YSI_Coding\y_hooks>

#if defined MAX_RENT_PICKUPS
    #undef MAX_RENT_PICKUPS
#endif
const MAX_RENT_PICKUPS = 50;

static rentID[MAX_RENT_PICKUPS],
    rentPickup[MAX_RENT_PICKUPS],
    rentCreated[MAX_RENT_PICKUPS],
    Text3D:rentPickupLabel[MAX_RENT_PICKUPS],
    Text3D:rentVehicleLabel[MAX_PLAYERS],
    Float:rentX[MAX_RENT_PICKUPS],
    Float:rentY[MAX_RENT_PICKUPS],
    Float:rentZ[MAX_RENT_PICKUPS],
    rentVehicle[MAX_PLAYERS],
    rentTime[MAX_PLAYERS],
    rentSelected[MAX_PLAYERS],
    rentOwner[MAX_PLAYERS][MAX_PLAYER_NAME],
    Timer:rentTimer[MAX_PLAYERS],
    totalRents;

static const rentVehicleList[][][] =
{
    // vehicle name     id      price
    {"Landstalker",     400,    250},
    {"Sentinel",        405,    200},
    {"Admiral",         445,    230},
    {"Faggio",          462,    70},
    {"Quad",            471,    100}
};

hook OnGameModeInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM rents", "Rent_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_NO))
    {
        new rentid = Rent_GetNearby(playerid);
        if (rentid == MAX_RENT_PICKUPS)
            return 0;

        if (!rentTime[playerid])
            Rent_ShowDialog(playerid);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if (newstate == PLAYER_STATE_DRIVER)
    {
        foreach (new i: Player)
        {
            if (IsPlayerInVehicle(playerid, rentVehicle[i]))
                if (strcmp(rentOwner[i], ReturnPlayerName(playerid), false))
                {
                    SendCustomMsgF(playerid, X11_RED, "RENT: "WHITE"To nije vase iznajmljeno vozilo!");
                    return ClearAnimations(playerid);
                }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward Rent_Load();
public Rent_Load()
{
    if (!cache_num_rows())
        return 0;

    new rows;
    cache_get_row_count(rows);

    for (new i = 0; i < rows; i++)
    {
        cache_get_value_name_int(i, "rent_id", rentID[i]);
        cache_get_value_name_float(i, "rent_x", rentX[i]);
        cache_get_value_name_float(i, "rent_y", rentY[i]);
        cache_get_value_name_float(i, "rent_z", rentZ[i]);

        rentCreated[i] = 1;
        rentPickup[i] = CreateDynamicPickup(19606, 1, rentX[i], rentY[i], rentZ[i] - 0.5);
        rentPickupLabel[i] = CreateDynamic3DTextLabel(""CYAN"RENT VOZILA\n"WHITE"Da iznajmite vozilo stisnite "CYAN"'N'", -1, rentX[i], rentY[i], rentZ[i], 30.00);
        totalRents++;
    }

    printf("[RENTS]: Ucitano %d rent vozila.", totalRents);
    return 1;
}

stock Rent_GetMaxPickups() return MAX_RENT_PICKUPS;
stock Rent_GetPlayerTime(const playerid) return rentTime[playerid];
stock Rent_Create(const rentid, Float:x, Float:y, Float:z)
{
    rentID[rentid] = rentid;
    rentX[rentid] = x;
    rentY[rentid] = y;
    rentZ[rentid] = z;
    rentCreated[rentid] = 1;

    rentPickup[rentid] = CreateDynamicPickup(19606, 1, x, y, z - 0.5);
    rentPickupLabel[rentid] = CreateDynamic3DTextLabel(""CYAN"RENT VOZILA\n"WHITE"Da iznajmite vozilo stisnite "CYAN"'N'", -1, x, y, z, 30.00);
    return 1;
}

stock Rent_GetNextID()
{
    for (new i = 0; i < MAX_RENT_PICKUPS; i++)
        if (!rentCreated[i])
            return i;
    return MAX_RENT_PICKUPS;
}

stock Rent_GetNearby(const playerid)
{
    for (new i = 0; i < MAX_RENT_PICKUPS; i++)
        if (IsPlayerInRangeOfPoint(playerid, 2.0, rentX[i], rentY[i], rentZ[i]))
            return i;
    return MAX_RENT_PICKUPS;
}

stock Rent_ShowDialog(const playerid)
    return Dialog_Show(playerid, "DIALOG_RENTSELECT", DIALOG_STYLE_TABLIST_HEADERS,
            ""CYAN"GENERATIONZ - "WHITE"RENT VOZILA",
            ""WHITE"Vozilo\t"WHITE"cena/1min\n\
            %s\t"DARKGREEN"$"WHITE"%d\n\
            %s\t"DARKGREEN"$"WHITE"%d\n\
            %s\t"DARKGREEN"$"WHITE"%d\n\
            %s\t"DARKGREEN"$"WHITE"%d\n\
            %s\t"DARKGREEN"$"WHITE"%d",
            ""CYAN"Odaberi", "Izlaz",
            rentVehicleList[0][0], rentVehicleList[0][2],
            rentVehicleList[1][0], rentVehicleList[1][2],
            rentVehicleList[2][0], rentVehicleList[2][2],
            rentVehicleList[3][0], rentVehicleList[3][2],
            rentVehicleList[4][0], rentVehicleList[4][2]
        );

stock Rent_Destroy(const playerid)
{
    DestroyVehicle(rentVehicle[playerid]);
    DestroyDynamic3DTextLabel(rentVehicleLabel[playerid]);
    stop rentTimer[playerid];
    rentTime[playerid] = 0;
    return 1;
}

TIMER__ RENT_DecreaseTime[60000](playerid)
{
    rentTime[playerid]--;
    if (!rentTime[playerid])
    {
        SendCustomMsgF(playerid, X11_CYAN, "RENT: "WHITE"Isteklo je vreme renta!");
        Rent_Destroy(playerid);
    }
}

Dialog: DIALOG_RENTSELECT(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    rentSelected[playerid] = listitem + 1;
    Dialog_Show(playerid, "DIALOG_RENTTIME", DIALOG_STYLE_INPUT,
        ""CYAN"GENERATIONZ - "WHITE"RENT VOZILA",
        ""WHITE"Unesite na koliko minuta zelite iznajmiti vozilo:",
        ""CYAN"Unesi", "Izlaz"
    );
    return 1;
}

Dialog: DIALOG_RENTTIME(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return Rent_ShowDialog(playerid);

    if (!(1 <= strval(inputtext) <= 30))
    {
        SendErrorMsg(playerid, "Ne mozete ispod 1 minuta i iznad 30 minuta!");
        return Rent_ShowDialog(playerid);
    }

    rentTime[playerid] = strval(inputtext);
    rentTimer[playerid] = repeat RENT_DecreaseTime(playerid);
    new rentPrice = (rentVehicleList[rentSelected[playerid] - 1][2][0] * rentTime[playerid]);

    strcopy(rentOwner[playerid], ReturnPlayerName(playerid));
    GivePlayerMoney(playerid, -rentPrice);
    Account_SetMoney(playerid, Account_GetMoney(playerid) - rentPrice);
    va_GameTextForPlayer(playerid, "~r~-$%d", 3000, 3, rentPrice);

    new Float:x, Float:y, Float:z, Float:a, tmpString[MAX_REASON_LENGTH];
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    
    format(tmpString, sizeof(tmpString), ""CYAN"RENT VOZILO\n"CYAN"- "WHITE"%s "CYAN"-", ReturnPlayerName(playerid));
    rentVehicle[playerid] = CreateVehicle(rentVehicleList[rentSelected[playerid] - 1][1][0], x, y, z, a, 130, 130, 60 * 60);
    rentVehicleLabel[playerid] = CreateDynamic3DTextLabel(tmpString, -1, x + 5.00, y, z, 30.00, .attachedvehicle = rentVehicle[playerid]);
    
    SendCustomMsgF(playerid, X11_CYAN, "RENT: "WHITE"Uspesno ste iznajmili vozilo na %d minuta!", rentTime[playerid]);

    PutPlayerInVehicle(playerid, rentVehicle[playerid], 0);
    Vehicle_SetColor(rentVehicle[playerid], 130, 130);
    Vehicle_SetFuel(rentVehicle[playerid], 50);
    return 1;
}