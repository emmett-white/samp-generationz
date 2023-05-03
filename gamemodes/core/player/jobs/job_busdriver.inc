#if defined _INC_job_busdriver_inc
    #endinput
#endif
#define _INC_job_busdriver_inc

#include <YSI_Coding\y_hooks>

const
    BUS_VEHICLES = 7,
    MAX_BUS_ACTORS = 24;

static
    busActorTimer,
    busVehicle[BUS_VEHICLES],
    busActor[MAX_BUS_ACTORS] = {INVALID_PLAYER_ID,...},
    busDriverCheckpointNum[MAX_PLAYERS],
    busDriverCheckpoint[MAX_PLAYERS],
    busDriverRoute[MAX_PLAYERS],
    Text3D:busVehicleLabel[BUS_VEHICLES];

new Float: busVehiclePos[][] =
{
    {1804.9100, -1930.9232, 13.5969},
    {1800.1079, -1930.9232, 13.5969},
    {1795.1201, -1930.9232, 13.5969},
    {1790.3376, -1930.9232, 13.5969},
    {1785.3398, -1930.9299, 13.5969},
    {1780.6783, -1930.9232, 13.5969},
    {1776.2146, -1930.9232, 13.5969}
};

new Float: busActorPos[][] =
{
    {2021.1794, -1943.9353, 13.5469},
    {2019.1901, -1943.5428, 13.5469},
    {2017.8805, -1944.2711, 13.5469},
    {2016.7048, -1942.5334, 13.5469},

    {2094.3599, -1771.3463, 13.5525},
    {2093.5132, -1772.8035, 13.5505},
    {2093.9121, -1774.9719, 13.5469},
    {2092.3582, -1775.2959, 13.5469},

    {2079.1943, -1364.1831, 23.9844},
    {2078.8804, -1362.4860, 23.9844},
    {2078.4600, -1360.5576, 23.9844},
    {2077.8521, -1358.6777, 23.9844},

    {1792.2375, -1264.2705, 13.6328},
    {1791.1038, -1265.4172, 13.6328},
    {1789.5574, -1265.6433, 13.6328},
    {1789.7712, -1267.7622, 13.6328},

    {1200.1743, -1274.0615, 13.5469},
    {1198.4423, -1273.7421, 13.5469},
    {1196.5098, -1274.8026, 13.5469},
    {1194.8040, -1274.9058, 13.5469},

    {831.6686, -1313.7579, 13.5469},
    {829.9374, -1314.1353, 13.5469},
    {828.4867, -1313.6553, 13.5469},
    {826.6667, -1314.3718, 13.5469}
};

new const busActorNames[][][] =
{
    {"Bane", 6}, {"Aleksa", 1}, {"Jovan", 17}, {"Borivoje", 16}, {"Borko", 15},
    {"Bozidar", 24}, {"Savo", 23}, {"Sreten", 32}, {"Mihailo", 34}, {"Jakov", 43},
    {"Jovana", 11}, {"Marijana", 12}, {"Aleksandra", 13}, {"Sladjana", 55}, {"Zorica", 65},
    {"Tamara", 69}, {"Suzana", 76}, {"Olga", 93}, {"Milica", 131}, {"Katarina", 141},
    {"Veljko", 147}, {"Slavica", 148}, {"Milan", 153}, {"Marina", 150}
};

TIMER__ BUSDRIVER_UnFreezePlayer[5000](playerid)
{
    TogglePlayerControllable(playerid, true);
}

TIMER__ BUSDRIVER_CheckCheckpoint[500](playerid)
{
    switch (BusDriver_GetCheckpoint(playerid))
    {
        case 1:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 2020.6660,-1940.2485,13.3431))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                BusDriver_DestroyActors(0, 4);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 2);
            }
        }
        
        case 2:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 2089.9463,-1772.7950,13.1135))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                BusDriver_DestroyActors(4, 8);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 3);
            }
        }
        
        case 3:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 2074.9883,-1362.3033,23.5562))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                BusDriver_DestroyActors(8, 12);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 4);
            }
        }
        
        case 4:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1792.9467,-1268.3153,13.2038))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                BusDriver_DestroyActors(12, 16);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 5);
            }
        }
        
        case 5:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1199.6593,-1277.4910,13.3558))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                BusDriver_DestroyActors(16, 20);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 6);
            }
        }
        
        case 6:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 831.0175,-1317.8641,13.3750))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                BusDriver_DestroyActors(20, 24);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 7);
            }
        }

        case 7:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1808.0718,-1904.3878,13.5755))
            {
                TogglePlayerControllable(playerid, false);
                defer BUSDRIVER_UnFreezePlayer(playerid);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                BusDriver_SetCheckpoint(playerid, 8);
            }
        }
    }
    return 1;
}

forward BusDriver_SpawnActors(const id_start, const id_end);
public BusDriver_SpawnActors(const id_start, const id_end)
{
    for (new i = id_start; i < id_end; i++)
        FCNPC_SetSkin(busActor[i], busActorNames[i][1][0]);

    KillTimer(busActorTimer);
    return 1;
}

stock BusDriver_Init()
{
    CreateDynamic3DTextLabel("["WHITE"VOZAC AUTOBUSA"MAIN_COLOR"]\n\
        "WHITE"Da se zaposlite kucajte\n"MAIN_COLOR"/posao", MAIN_COLOR_HEX, 1808.0718,-1904.3878,13.5755, 15.00
    );
    CreateDynamicPickup(1210, 1, 1808.0718,-1904.3878,13.5755, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("["WHITE"VOZAC AUTOBUSA"MAIN_COLOR"]\n\
        "WHITE"Da uzmete opremu kucajte\n"MAIN_COLOR"/posaooprema\n\
        "WHITE"Da zapocnete posao kucajte\n"MAIN_COLOR"/pokreniposao", MAIN_COLOR_HEX, 1808.1638,-1907.4720,13.5732, 15.00
    );
    CreateDynamicPickup(1275, 1, 1808.1638,-1907.4720,13.5732, .streamdistance = 30.00);

    CreateDynamicObject(19377, 1803.57227, -1930.28198, 12.18770,   0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19377, 1792.93115, -1930.33691, 12.18770,   0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19377, 1781.21204, -1930.21863, 12.18770,   0.00000, 90.00000, 0.00000);

    // line 1
    CreateDynamicObject(1257, 2019.70190, -1944.59814, 13.60760,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(1257, 2094.27710, -1773.11340, 13.51670,   0.00000, 0.00000, -14.46000);
    CreateDynamicObject(1257, 2079.52539, -1362.45410, 23.87250,   0.00000, 0.00000, 0.66000);
    CreateDynamicObject(1257, 1790.46094, -1265.09033, 13.58340,   0.00000, 0.00000, 124.44000);
    CreateDynamicObject(1257, 1198.56689, -1273.22583, 13.56030,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1257, 829.91650, -1313.19836, 13.45995,   0.00000, 0.00000, 90.71999);
    // line 2
    CreateDynamicObject(1257, 1849.07666, -1523.44250, 13.54716,   0.00000, 0.00000, -21.42000);
    CreateDynamicObject(1257, 1518.88586, -1433.09314, 13.55174,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1257, 1365.46570, -1126.21753, 23.88868,   0.00000, 0.00000, 354.40555);
    CreateDynamicObject(1257, 1205.71643, -928.42029, 43.04910,   0.00000, 0.00000, 96.72000);
    CreateDynamicObject(1257, 765.93829, -1040.24438, 24.17350,   0.00000, 0.00000, 108.78000);
    CreateDynamicObject(1257, 519.64862, -1455.21326, 15.25627,   0.00000, 0.00000, 184.74001);

    for (new i = 0; i < BUS_VEHICLES; i++)
    {
        busVehicle[i] = AddStaticVehicleEx(431, busVehiclePos[i][0], busVehiclePos[i][1], busVehiclePos[i][2], 0.0000, 1, 1, 120);
        busVehicleLabel[i] = CreateDynamic3DTextLabel("[VOZAC AUTOBUSA]", X11_YELLOW, 0.0, 0.0, 0.0, 30.00, .attachedvehicle = busVehicle[i]);
        Vehicle_SetColor(busVehicle[i], 1, 1);
        Vehicle_SetFuel(busVehicle[i], 50);
    }
    return 1;
}

stock BusDriver_DestroyVehicles()
{
    for (new i = 0; i < BUS_VEHICLES; i++)
    {
        DestroyVehicle(busVehicle[i]);
        DestroyDynamic3DTextLabel(busVehicleLabel[i]);
    }
    return 1;
}

stock BusDriver_Vehicle(const vehid)
{
    for (new i = 0; i < BUS_VEHICLES; i++)
        if (vehid == busVehicle[i])
            return 1;
    return 0;
}

stock BusDriver_DestroyActors(const id_start, const id_end)
{
    for (new i = id_start; i < id_end; i++)
        FCNPC_Destroy(busActor[i]);
    return 1;
}

stock BusDriver_GetRoute(const playerid) return busDriverRoute[playerid];
stock BusDriver_SetRoute(const playerid, const route) return busDriverRoute[playerid] = route;
stock BusDriver_GetCheckpoint(const playerid) return busDriverCheckpointNum[playerid];
stock BusDriver_SetCheckpoint(const playerid, const checkpoint)
{
    busDriverCheckpointNum[playerid] = checkpoint;
    switch (checkpoint)
    {
        case 1:
        {
            if (BusDriver_GetRoute(playerid) == 1)
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 2020.6660,-1940.2485,13.3431, 2.0);
            else
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);

            for (new i = 0; i < (MAX_BUS_ACTORS / 6); i++)
            {
                busActor[i] = FCNPC_Create(busActorNames[i][0]);
                busActorTimer = SetTimerEx("BusDriver_SpawnActors", 5000, false, "ii", 0, (MAX_BUS_ACTORS / 6));
                FCNPC_Spawn(busActor[i], 0, busActorPos[i][0], busActorPos[i][1], busActorPos[i][2]);
            }

            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 2:
        {
            if (BusDriver_GetRoute(playerid) == 1)
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 2089.9463,-1772.7950,13.1135, 2.0);
            else
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);

            for (new i = (MAX_BUS_ACTORS / 6); i < (MAX_BUS_ACTORS / 3); i++)
            {
                busActor[i] = FCNPC_Create(busActorNames[i][0]);
                busActorTimer = SetTimerEx("BusDriver_SpawnActors", 5000, false, "ii", 0, (MAX_BUS_ACTORS / 6));
                FCNPC_Spawn(busActor[i], 0, busActorPos[i][0], busActorPos[i][1], busActorPos[i][2]);
            }

            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 3:
        {
            if (BusDriver_GetRoute(playerid) == 1)
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 2074.9883,-1362.3033,23.5562, 2.0);
            else
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);

            for (new i = (MAX_BUS_ACTORS / 3); i < (MAX_BUS_ACTORS / 2); i++)
            {
                busActor[i] = FCNPC_Create(busActorNames[i][0]);
                busActorTimer = SetTimerEx("BusDriver_SpawnActors", 5000, false, "ii", 0, (MAX_BUS_ACTORS / 6));
                FCNPC_Spawn(busActor[i], 0, busActorPos[i][0], busActorPos[i][1], busActorPos[i][2]);
            }

            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 4:
        {
            if (BusDriver_GetRoute(playerid) == 1)
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1792.9467,-1268.3153,13.2038, 2.0);
            else
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);

            for (new i = (MAX_BUS_ACTORS / 2); i < (MAX_BUS_ACTORS - 8); i++)
            {
                busActor[i] = FCNPC_Create(busActorNames[i][0]);
                busActorTimer = SetTimerEx("BusDriver_SpawnActors", 5000, false, "ii", 0, (MAX_BUS_ACTORS / 6));
                FCNPC_Spawn(busActor[i], 0, busActorPos[i][0], busActorPos[i][1], busActorPos[i][2]);
            }

            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 5:
        {
            if (BusDriver_GetRoute(playerid) == 1)
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1199.6593,-1277.4910,13.3558, 2.0);
            else
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);

            for (new i = (MAX_BUS_ACTORS - 8); i < (MAX_BUS_ACTORS - 4); i++)
            {
                busActor[i] = FCNPC_Create(busActorNames[i][0]);
                busActorTimer = SetTimerEx("BusDriver_SpawnActors", 5000, false, "ii", 0, (MAX_BUS_ACTORS / 6));
                FCNPC_Spawn(busActor[i], 0, busActorPos[i][0], busActorPos[i][1], busActorPos[i][2]);
            }

            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 6:
        {
            if (BusDriver_GetRoute(playerid) == 1)
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 831.0175,-1317.8641,13.3750, 2.0);
            else
                busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);

            for (new i = (MAX_BUS_ACTORS - 4); i < MAX_BUS_ACTORS; i++)
            {
                busActor[i] = FCNPC_Create(busActorNames[i][0]);
                busActorTimer = SetTimerEx("BusDriver_SpawnActors", 5000, false, "ii", 0, (MAX_BUS_ACTORS / 6));
                FCNPC_Spawn(busActor[i], 0, busActorPos[i][0], busActorPos[i][1], busActorPos[i][2]);
            }

            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 7:
        {
            busDriverCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1808.0718,-1904.3878,13.5755, 2.0);
            repeat BUSDRIVER_CheckCheckpoint(playerid);
        }

        case 8:
        {
            SendServerMsg(playerid, "Uspesno ste prevezli putnike!");

            new money = minmaxrandom(4000, 12000);
            Account_SetMoney(playerid, Account_GetMoney(playerid) + money);
            GivePlayerMoney(playerid, money);
            
            va_GameTextForPlayer(playerid, "~g~+$%d", 5000, 3, money);
            DisablePlayerCheckpoint(playerid);
        }
    }
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (BusDriver_Vehicle(vehicleid))
    {
        if (Account_GetJob(playerid) != 3)
            return ClearAnimations(playerid);

        SendInfoMsg(playerid, "Ulazite u autobus.");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}