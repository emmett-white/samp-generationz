#if defined _INC_job_lawnmower_inc
    #endinput
#endif
#define _INC_job_lawnmower_inc

#include <YSI_Coding\y_hooks>

const MOWER_VEHICLES = 7,
    MOWER_GRASS_OBJECTS = 20;

static mowerVehicle[MOWER_VEHICLES],
    Text3D: mowerVehicleLabel[MOWER_VEHICLES],
    mowerCheckpoint[MAX_PLAYERS],
    mowerCheckpointNum[MAX_PLAYERS],
    mowerObject[MAX_PLAYERS][MOWER_GRASS_OBJECTS];

TIMER__ MOWER_UFNREEZEPLAYER[1000](playerid)
{
    TogglePlayerControllable(playerid, true);
}

TIMER__ MOWER_CheckCheckpoint[500](playerid)
{
    switch (Mower_GetCheckpoint(playerid))
    {
        case 1:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 915.326171, -1061.959716, 22.504980))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][0]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 2);
            }
        }

        case 2:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 888.632812, -1063.368286, 22.611110))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][1]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 3);
            }
        }

        case 3:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 946.746093, -1124.932128, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][2]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 4);
            }
        }

        case 4:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 913.304687, -1110.281494, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][3]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 5);
            }
        }

        case 5:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 914.625183, -1123.605346, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][4]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 6);
            }
        }

        case 6:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 924.541381, -1093.986450, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][5]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 7);
            }
        }

        case 7:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 910.704223, -1088.410644, 22.098939))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][6]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 8);
            }
        }

        case 8:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 887.352783, -1083.744873, 21.993900))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][7]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 9);
            }
        }

        case 9:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 850.834777, -1082.043945, 22.298919))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][8]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 10);
            }
        }

        case 10:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 824.393676, -1074.510986, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][9]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 11);
            }
        }

        case 11:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 815.849914, -1084.990356, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][10]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 12);
            }
        }

        case 12:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 815.571411, -1105.612060, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][11]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 13);
            }
        }

        case 13:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 824.662597, -1124.370727, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][12]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 14);
            }
        }

        case 14:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 851.468750, -1115.620605, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][13]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 15);
            }
        }

        case 15:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 876.744506, -1123.285888, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][14]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 16);
            }
        }

        case 16:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 895.281127, -1119.840942, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][15]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 17);
            }
        }

        case 17:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 942.479614, -1094.306518, 21.692899))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][16]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 18);
            }
        }

        case 18:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 851.546569, -1093.052490, 21.995910))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][17]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 19);
            }
        }

        case 19:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 880.778320, -1094.046875, 21.995910))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][18]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 20);
            }
        }

        case 20:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 867.854736, -1086.947753, 21.995910))
            {
                TogglePlayerControllable(playerid, false);
                defer MOWER_UFNREEZEPLAYER(playerid);
                DestroyPlayerObject(playerid, mowerObject[playerid][19]);
                SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
                Mower_SetCheckpoint(playerid, 21);
            }
        }
    }
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (Mower_Vehicle(vehicleid))
    {
        if (Account_GetJob(playerid) != 2)
            return ClearAnimations(playerid);

        SendInfoMsg(playerid, "Ulazite u vozilo za kosenje trave.");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock Mower_Init()
{
    CreateDynamic3DTextLabel("["WHITE"KOSAC TRAVE"MAIN_COLOR"]\n\
        "WHITE"Da se zaposlite kucajte\n"MAIN_COLOR"/posao\n\
        "WHITE"Da uzmete/skinete opremu\n"MAIN_COLOR"/posaooprema\n\
        "WHITE"Da zapocnete posao\n"MAIN_COLOR"/pokreniposao", MAIN_COLOR_HEX, 940.5753, -1085.9894, 24.2962, 15.00
    );
    CreateDynamicPickup(1210, 1, 940.5753, -1085.9894, 24.2962, .streamdistance = 30.00);

    mowerVehicle[0] = AddStaticVehicleEx(572, 931.1790, -1063.0134, 23.9024, 90.0000, -1, -1, 120);
    mowerVehicle[1] = AddStaticVehicleEx(572, 931.1790, -1065.8960, 23.9024, 90.0000, -1, -1, 120);
    mowerVehicle[2] = AddStaticVehicleEx(572, 931.1790, -1068.7369, 23.9024, 90.0000, -1, -1, 120);
    mowerVehicle[3] = AddStaticVehicleEx(572, 931.1790, -1071.6180, 23.9024, 90.0000, -1, -1, 120);
    mowerVehicle[4] = AddStaticVehicleEx(572, 931.1790, -1074.4598, 23.9024, 90.0000, -1, -1, 120);
    mowerVehicle[5] = AddStaticVehicleEx(572, 931.1790, -1077.5955, 23.9024, 90.0000, -1, -1, 120);
    mowerVehicle[6] = AddStaticVehicleEx(572, 931.1790, -1080.7356, 23.9024, 90.0000, -1, -1, 120);

    for (new i = 0; i < MOWER_VEHICLES; i++)
    {
        mowerVehicleLabel[i] = CreateDynamic3DTextLabel("[KOSAC TRAVE]", X11_YELLOW, 0.0, 0.0, 0.0, 30.00, .attachedvehicle = mowerVehicle[i]);
        Vehicle_SetColor(mowerVehicle[i], 128, 128);
        Vehicle_SetFuel(mowerVehicle[i], 50);
    }
    return 1;
}

stock Mower_CreatePlayerObjects(const playerid)
{
    mowerObject[playerid][0] = CreatePlayerObject(playerid, 822, 915.326171, -1061.959716, 22.504980, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][1] = CreatePlayerObject(playerid, 822, 888.632812, -1063.368286, 22.611110, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][2] = CreatePlayerObject(playerid, 822, 946.746093, -1124.932128, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][3] = CreatePlayerObject(playerid, 822, 913.304687, -1110.281494, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][4] = CreatePlayerObject(playerid, 822, 914.625183, -1123.605346, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][5] = CreatePlayerObject(playerid, 822, 924.541381, -1093.986450, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][6] = CreatePlayerObject(playerid, 822, 910.704223, -1088.410644, 22.098939, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][7] = CreatePlayerObject(playerid, 822, 887.352783, -1083.744873, 21.993900, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][8] = CreatePlayerObject(playerid, 822, 850.834777, -1082.043945, 22.298919, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][9] = CreatePlayerObject(playerid, 822, 824.393676, -1074.510986, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][10] = CreatePlayerObject(playerid, 822, 815.849914, -1084.990356, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][11] = CreatePlayerObject(playerid, 822, 815.571411, -1105.612060, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][12] = CreatePlayerObject(playerid, 822, 824.662597, -1124.370727, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][13] = CreatePlayerObject(playerid, 822, 851.468750, -1115.620605, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][14] = CreatePlayerObject(playerid, 822, 876.744506, -1123.285888, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][15] = CreatePlayerObject(playerid, 822, 895.281127, -1119.840942, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][16] = CreatePlayerObject(playerid, 822, 942.479614, -1094.306518, 21.692899, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][17] = CreatePlayerObject(playerid, 822, 851.546569, -1093.052490, 21.995910, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][18] = CreatePlayerObject(playerid, 822, 880.778320, -1094.046875, 21.995910, 0.000000, 0.000000, 0.000000, 800.00); 
    mowerObject[playerid][19] = CreatePlayerObject(playerid, 822, 867.854736, -1086.947753, 21.995910, 0.000000, 0.000000, 0.000000, 800.00);
    return 1;
}

stock Mower_DestroyVehicles()
{
    for (new i = 0; i < MOWER_VEHICLES; i++)
    {
        DestroyVehicle(mowerVehicle[i]);
        DestroyDynamic3DTextLabel(mowerVehicleLabel[i]);
    }
    return 1;
}

stock Mower_Vehicle(const vehid)
{
    for (new i = 0; i < MOWER_VEHICLES; i++)
        if (vehid == mowerVehicle[i])
            return 1;
    return 0;
}

stock Mower_GetCheckpoint(const playerid) return mowerCheckpointNum[playerid];
stock Mower_SetCheckpoint(const playerid, const checkpoint)
{
    mowerCheckpointNum[playerid] = checkpoint;
    switch (checkpoint)
    {
        case 1:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 915.326171, -1061.959716, 22.504980, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 2:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 888.632812, -1063.368286, 22.611110, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 3:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 946.746093, -1124.932128, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 4:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 913.304687, -1110.281494, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 5:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 914.625183, -1123.605346, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 6:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 924.541381, -1093.986450, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 7:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 910.704223, -1088.410644, 22.098939, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 8:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 887.352783, -1083.744873, 21.993900, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 9:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 850.834777, -1082.043945, 22.298919, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 10:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 824.393676, -1074.510986, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 11:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 815.849914, -1084.990356, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 12:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 815.571411, -1105.612060, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 13:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 824.662597, -1124.370727, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 14:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 851.468750, -1115.620605, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 15:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 876.744506, -1123.285888, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 16:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 895.281127, -1119.840942, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 17:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 942.479614, -1094.306518, 21.692899, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 18:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 851.546569, -1093.052490, 21.995910, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 19:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 880.778320, -1094.046875, 21.995910, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 20:
        {
            mowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 867.854736, -1086.947753, 21.995910, 2.0);
            repeat MOWER_CheckCheckpoint(playerid);
        }

        case 21:
        {
            SendServerMsg(playerid, "Uspesno ste pokosili travu po dvoristu!");

            new money = minmaxrandom(3000, 8000);
            Account_SetMoney(playerid, Account_GetMoney(playerid) + money);
            GivePlayerMoney(playerid, money);
            
            va_GameTextForPlayer(playerid, "~g~+$%d", 5000, 3, money);
            DisablePlayerCheckpoint(playerid);
        }
    }
    return 1;
}