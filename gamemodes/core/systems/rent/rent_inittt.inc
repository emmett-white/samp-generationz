#if defined _inc_rent_init
    #undef _inc_rent_init
#endif

#if defined _inc_rent_init_included
    #endinput
#endif
#define _inc_rent_init_included

#include <YSI_Coding\y_hooks>

const MAX_RENT_VEHICLES = 30,
    RENT_MINUTE_PRICE = 500;

static rentVehicle[MAX_RENT_VEHICLES],
    Text3D: rentVehicleLabel[MAX_RENT_VEHICLES],
    BitArray: Bit_RentVehicleStatus<MAX_RENT_VEHICLES>,
    rentTime[MAX_PLAYERS],
    rentVehicleID[MAX_PLAYERS],
    rentTimer[MAX_PLAYERS];

stock Rent_CreateVehicles()
{
    rentVehicle[0] = AddStaticVehicleEx(540, 1560.2183, -2308.9688, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[1] = AddStaticVehicleEx(540, 1560.2183, -2312.2061, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[2] = AddStaticVehicleEx(540, 1560.2183, -2315.5681, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[3] = AddStaticVehicleEx(540, 1560.2183, -2318.8123, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[4] = AddStaticVehicleEx(540, 1560.2183, -2322.0696, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[5] = AddStaticVehicleEx(540, 1560.2183, -2325.3303, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[6] = AddStaticVehicleEx(540, 1560.2183, -2328.5115, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[7] = AddStaticVehicleEx(540, 1560.2183, -2331.8928, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[8] = AddStaticVehicleEx(540, 1560.2183, -2335.0320, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[9] = AddStaticVehicleEx(540, 1560.2183, -2338.3940, 13.4457, 90.0000, 162, 162, 300);
    rentVehicle[10] = AddStaticVehicleEx(462, 1556.1979, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[11] = AddStaticVehicleEx(462, 1552.5760, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[12] = AddStaticVehicleEx(462, 1549.6201, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[13] = AddStaticVehicleEx(462, 1546.3022, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[14] = AddStaticVehicleEx(462, 1542.7219, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[15] = AddStaticVehicleEx(462, 1539.4819, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[16] = AddStaticVehicleEx(462, 1536.3226, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[17] = AddStaticVehicleEx(462, 1533.0640, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[18] = AddStaticVehicleEx(462, 1529.9437, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[19] = AddStaticVehicleEx(462, 1526.3627, -2360.4836, 13.0493, 0.0000, 162, 162, 300);
    rentVehicle[20] = AddStaticVehicleEx(471, 1521.6537, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[21] = AddStaticVehicleEx(471, 1518.5782, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[22] = AddStaticVehicleEx(471, 1515.3378, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[23] = AddStaticVehicleEx(471, 1512.0381, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[24] = AddStaticVehicleEx(471, 1508.8771, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[25] = AddStaticVehicleEx(471, 1505.3962, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[26] = AddStaticVehicleEx(471, 1502.3159, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[27] = AddStaticVehicleEx(471, 1498.8755, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[28] = AddStaticVehicleEx(471, 1495.5552, -2360.5181, 12.9461, 0.0000, 162, 162, 300);
    rentVehicle[29] = AddStaticVehicleEx(471, 1492.3750, -2360.5181, 12.9461, 0.0000, 162, 162, 300);

    for (new i = 0; i < MAX_RENT_VEHICLES; i++)
    {
        static tmpString[64];
        format(tmpString, sizeof(tmpString), ""LIGHTBLUE"[RENT - %s"LIGHTBLUE"]", (!Rent_GetVehicleStatus(rentVehicle[i]) ? ""GREEN"SLOBODNO" : ""RED"ZAUZETO"));
        rentVehicleLabel[i] = CreateDynamic3DTextLabel(tmpString, -1, 0.0, 0.0, 0.0, 10.00, .attachedvehicle = rentVehicle[i]);
        Vehicle_SetColor(rentVehicle[i], 162, 162);
        Vehicle_SetFuel(rentVehicle[i], 50);
    }
    return 1;
}

stock Rent_GetVehicleStatus(const vehicleid) return Bit_Get(Bit_RentVehicleStatus, vehicleid);
stock Rent_SetVehicleStatus(const vehicleid)
{
    new const status = !Rent_GetVehicleStatus(vehicleid);
    if (!status)
    {
        UpdateDynamic3DTextLabelText(rentVehicleLabel[vehicleid - 1], -1, ""LIGHTBLUE"[RENT - "GREEN"SLOBODNO "LIGHTBLUE"]");
        Bit_Set(Bit_RentVehicleStatus, vehicleid, false);
        return 1;
    }

    UpdateDynamic3DTextLabelText(rentVehicleLabel[vehicleid - 1], -1, ""LIGHTBLUE"[RENT - "RED"ZAUZETO "LIGHTBLUE"]");
    Bit_Set(Bit_RentVehicleStatus, vehicleid, true);
    return 1;
}

stock Rent_Vehicle(const vehid)
{
    for (new i = 0; i < MAX_RENT_VEHICLES; i++)
        if (vehid == rentVehicle[i])
            return 1;
    return 0;
}

stock Rent_GetPlayerVehicleID(const playerid) return rentVehicleID[playerid];
stock Rent_GetPlayerTime(const playerid) return rentTime[playerid];
stock Rent_SetPlayerTime(const playerid, const time = 0) return rentTime[playerid] = time;
stock Rent_Destroy(const playerid, const vehicleid)
{
    SetVehicleToRespawn(vehicleid);
    Rent_SetVehicleStatus(vehicleid);
    rentTime[playerid] = 0;
    KillTimer(rentTimer[playerid]);
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if (newstate == PLAYER_STATE_DRIVER)
    {
        if (Rent_Vehicle(GetPlayerVehicleID(playerid)))
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);
            
            if (Rent_GetVehicleStatus(GetPlayerVehicleID(playerid)) && !rentTime[playerid])
            {
                SendErrorMsg(playerid, "To vozilo je vec iznajmljeno.");
                return SetPlayerPos(playerid, x, y, z);
            }
            
            if (rentTime[playerid] && GetPlayerVehicleID(playerid) != Rent_GetPlayerVehicleID(playerid))
            {
                SendErrorMsg(playerid, "Vec imate svoje iznajmljeno vozilo! Za unrent: /unrent.");
                return SetPlayerPos(playerid, x, y, z);
            }

            if (!rentTime[playerid])
                Dialog_Show(playerid, "DIALOG_RENT", DIALOG_STYLE_INPUT,
                    ""MAIN_COLOR"GENERATIONZ - "WHITE"RENT VOZILO",
                    ""MAIN_COLOR"// "WHITE"Unesite na koliko minuta zelite da iznajmite vozilo\n\
                    "MAIN_COLOR"Pomoc: "LIGHTGRAY"Cena jednog minuta je $%d.",
                    ""MAIN_COLOR"Iznajmi", "Izlaz", RENT_MINUTE_PRICE
                );
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward Rent_DecreaseTime(const playerid);
public Rent_DecreaseTime(const playerid)
{
    if (!rentTime[playerid])
    {
        SendClientMessage(playerid, X11_LIGHTBLUE, "[RENT]: "WHITE"Isteklo je vreme renta!");
        SetVehicleToRespawn(Rent_GetPlayerVehicleID(playerid));
        Rent_SetVehicleStatus(Rent_GetPlayerVehicleID(playerid));
        KillTimer(rentTimer[playerid]);
    }
    rentTime[playerid]--;
    return 1;
}

Dialog: DIALOG_RENT(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return RemovePlayerFromVehicle(playerid);

    if (isnull(inputtext) && !IsNumeric(inputtext))
        return Dialog_Show(playerid, "DIALOG_RENT", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"GENERATIONZ - "WHITE"RENT VOZILO",
            ""MAIN_COLOR"// "WHITE"Unesite na koliko minuta zelite da iznajmite vozilo\n\
            "MAIN_COLOR"Pomoc: "LIGHTGRAY"Cena jednog minuta je $%d.",
            ""MAIN_COLOR"Iznajmi", "Izlaz", RENT_MINUTE_PRICE
        );

    if (!(1 <= strval(inputtext) <= 30))
    {
        SendErrorMsg(playerid, "Mozete iznajmiti najmanje 1 minut i najvise 30 minuta!");
        return Dialog_Show(playerid, "DIALOG_RENT", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"GENERATIONZ - "WHITE"RENT VOZILO",
            ""MAIN_COLOR"// "WHITE"Unesite na koliko minuta zelite da iznajmite vozilo\n\
            "MAIN_COLOR"Pomoc: "LIGHTGRAY"Cena jednog minuta je $%d.",
            ""MAIN_COLOR"Iznajmi", "Izlaz", RENT_MINUTE_PRICE
        );
    }

    rentTime[playerid] = strval(inputtext);

    new rentPrice = RENT_MINUTE_PRICE * rentTime[playerid];
    if (Account_GetMoney(playerid) < rentPrice)
    {
        SendErrorMsgF(playerid, "Nemate toliko novca, potrebno vam je jos: "RED"$%d"WHITE"!", rentPrice / rentTime[playerid]);
        return Dialog_Show(playerid, "DIALOG_RENT", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"GENERATIONZ - "WHITE"RENT VOZILO",
            ""MAIN_COLOR"// "WHITE"Unesite na koliko minuta zelite da iznajmite vozilo\n\
            "MAIN_COLOR"Pomoc: "LIGHTGRAY"Cena jednog minuta je $%d.",
            ""MAIN_COLOR"Iznajmi", "Izlaz", RENT_MINUTE_PRICE
        );
    }

    Account_SetMoney(playerid, Account_GetMoney(playerid) - rentPrice);
    GivePlayerMoney(playerid, -rentPrice);
    va_GameTextForPlayer(playerid, "~r~-$%d", 5000, 3, rentPrice);

    rentVehicleID[playerid] = GetPlayerVehicleID(playerid);
    Rent_SetVehicleStatus(rentVehicleID[playerid]);
    SendCustomMsgF(playerid, X11_LIGHTBLUE, "[RENT]: "WHITE"Uspesno ste iznajmili vozilo na "LIGHTBLUE"%d minut(a).", rentTime[playerid]);
    rentTimer[playerid] = SetTimerEx("Rent_DecreaseTime", 60000, 1, "d", playerid);
    return 1;
}