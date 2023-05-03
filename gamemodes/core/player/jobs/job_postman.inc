#if defined _INC_job_postman_inc
    #endinput
#endif
#define _INC_job_postman_inc

#include <YSI_Coding\y_hooks>

const POSTMAN_VEHICLES = 10;

static postmanVehicle[POSTMAN_VEHICLES],
    Text3D:postmanVehicleLabel[sizeof(postmanVehicle)],
    postmanCheckpoint[MAX_PLAYERS],
    postmanCheckpointNum[MAX_PLAYERS];

TIMER__ POSTMAN_ClearAnimation[2000](playerid)
{
    Anim_StopLooping(playerid);
    ClearAnimations(playerid);
}

TIMER__ POSTMAN_CheckCheckpoint[500](playerid)
{
    switch (Postman_GetCheckpoint(playerid))
    {
        case 1:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1071.6151, -1215.0144, 16.8906))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 2);
            }
        }

        case 2:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1123.3676, -1129.6696, 23.8047))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 3);
            }
        }

        case 3:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1284.7571, -1091.1569, 28.2578))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 4);
            }
        }

        case 4:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1510.2542, -1060.2144, 25.0625))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 5);
            }
        }

        case 5:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1631.8560, -1171.4182, 24.0781))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 6);
            }
        }

        case 6:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1886.7686, -1113.6216, 26.2758))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 7);
            }
        }

        case 7:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 2112.7109, -1212.5715, 23.9645))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 8);
            }
        }

        case 8:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 2148.4624, -1433.4806, 25.5391))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 9);
            }
        }

        case 9:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 2101.9526, -1809.0143, 13.5547))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 10);
            }
        }

        case 10:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1831.0863, -1841.4227, 13.5781))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 11);
            }
        }

        case 11:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 1285.9806, -1583.1572, 13.5469))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer POSTMAN_ClearAnimation(playerid);
                SendServerMsg(playerid, "Uspesno ste ostavili postu, otidjite na sledecu lokaciju.");
                Postman_SetCheckpoint(playerid, 12);
            }
        }

        case 12:
        {
            if (IsPlayerInRangeOfPoint(playerid, 3.0, 972.5764, -1254.3005, 16.9451))
            {
                if (IsPlayerInAnyVehicle(playerid))
                    return SendErrorMsg(playerid, "Izadjite iz vozila.");

                Postman_SetCheckpoint(playerid, 13);
            }
        }
    }
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (Postman_Vehicle(vehicleid))
    {
        if (Account_GetJob(playerid) != 1)
            return ClearAnimations(playerid);

        SendInfoMsg(playerid, "Ulazite u vozilo za raznosenje poste.");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock Postman_Init()
{
    CreateDynamic3DTextLabel("["WHITE"POSTAR"MAIN_COLOR"]\n\
        "WHITE"Da se zaposlite kucajte\n"MAIN_COLOR"/posao", MAIN_COLOR_HEX, 986.8093, -1252.5247, 16.9844, 15.00
    );
    CreateDynamicPickup(1210, 1, 986.8093, -1252.5247, 16.9844, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("["WHITE"POSTAR"MAIN_COLOR"]\n\
        "WHITE"Da uzmete/skinete opremu\n"MAIN_COLOR"/posaooprema\n\
        "WHITE"Da zapocnete posao\n"MAIN_COLOR"/pokreniposao", MAIN_COLOR_HEX, 979.5859, -1254.7031, 16.9465, 15.00
    );
    CreateDynamicPickup(1275, 1, 979.5859, -1254.7031, 16.9465, .streamdistance = 30.00);

    postmanVehicle[0] = AddStaticVehicleEx(482, 991.2191, -1265.6125, 15.1526, 179.7848, 1, 1, 120);
    postmanVehicle[1] = AddStaticVehicleEx(482, 997.2009, -1266.3077, 15.1474, 179.5169, 1, 1, 120);
    postmanVehicle[2] = AddStaticVehicleEx(482, 1006.8557, -1274.6348, 15.3062, 89.8202, 1, 1, 120);
    postmanVehicle[3] = AddStaticVehicleEx(482, 979.6185, -1264.6442, 15.8800, 179.8249, 1, 1, 120);
    postmanVehicle[4] = AddStaticVehicleEx(462, 965.7846, -1267.5760, 16.5811, 269.7040, 0, 0, 120);
    postmanVehicle[5] = AddStaticVehicleEx(462, 965.9861, -1264.2219, 16.5845, 268.4675, 0, 0, 120);
    postmanVehicle[6] = AddStaticVehicleEx(462, 967.2225, -1261.0532, 16.5851, 270.7853, 0, 0, 120);
    postmanVehicle[7] = AddStaticVehicleEx(462, 966.4259, -1256.7970, 16.5743, 270.1453, 0, 0, 120);
    postmanVehicle[8] = AddStaticVehicleEx(462, 984.3411, -1263.2120, 16.5726, 180.9212, 0, 0, 120);
    postmanVehicle[9] = AddStaticVehicleEx(462, 987.7801, -1264.4944, 16.5776, 181.1003, 0, 0, 120);

    for (new i = 0; i < POSTMAN_VEHICLES; i++)
    {
        postmanVehicleLabel[i] = CreateDynamic3DTextLabel("[POSTAR]", X11_YELLOW, 0.0, 0.0, 0.0, 30.00, .attachedvehicle = postmanVehicle[i]);
        Vehicle_SetColor(postmanVehicle[i], 194, 194);
    }
    return 1;
}

stock Postman_DestroyVehicles()
{
    for (new i = 0; i < POSTMAN_VEHICLES; i++)
    {
        DestroyVehicle(postmanVehicle[i]);
        DestroyDynamic3DTextLabel(postmanVehicleLabel[i]);
    }
    return 1;
}

stock Postman_Vehicle(const vehid)
{
    for (new i = 0; i < POSTMAN_VEHICLES; i++)
        if (vehid == postmanVehicle[i])
            return 1;
    return 0;
}

stock Postman_GetCheckpoint(const playerid) return postmanCheckpointNum[playerid];
stock Postman_SetCheckpoint(const playerid, const checkpoint)
{
    postmanCheckpointNum[playerid] = checkpoint;
    switch (checkpoint)
    {
        case 1:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1071.6151, -1215.0144, 16.8906, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 2:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1123.3676, -1129.6696, 23.8047, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 3:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1284.7571, -1091.1569, 28.2578, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 4:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1510.2542, -1060.2144, 25.0625, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 5:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1631.8560, -1171.4182, 24.0781, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 6:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1886.7686, -1113.6216, 26.2758, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 7:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 2112.7109, -1212.5715, 23.9645, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 8:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 2148.4624, -1433.4806, 25.5391, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 9:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 2101.9526, -1809.0143, 13.5547, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 10:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1831.0863, -1841.4227, 13.5781, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 11:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 1285.9806, -1583.1572, 13.5469, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 12:
        {
            SendServerMsg(playerid, "Pratite checkpoint oznacen na mapi!");
            postmanCheckpoint[playerid] = SetPlayerCheckpoint(playerid, 972.5764, -1254.3005, 16.9451, 3.0);
            repeat POSTMAN_CheckCheckpoint(playerid);
        }

        case 13:
        {
            SendServerMsg(playerid, "Uspesno ste razneli postu po gradu!");

            new money = minmaxrandom(3000, 11000);
            Account_SetMoney(playerid, Account_GetMoney(playerid) + money);
            GivePlayerMoney(playerid, money);
            
            va_GameTextForPlayer(playerid, "~g~+$%d", 5000, 3, money);
            DisablePlayerCheckpoint(playerid);
        }
    }
    return 1;
}