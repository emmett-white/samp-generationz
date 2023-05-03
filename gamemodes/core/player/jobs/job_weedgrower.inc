#if defined _INC_job_weedgrower_inc
    #endinput
#endif
#define _INC_job_weedgrower_inc

#include <YSI_Coding\y_hooks>

const WEEDGROWER_BACKPACK_INDEX = 9;

static
    weedGrowerSeed[MAX_PLAYERS],
    weedGrowerBag[MAX_PLAYERS],
    weedGrowerCheckpoint[MAX_PLAYERS],
    weedGrowerCheckpointNum[MAX_PLAYERS],
    weedGrowerObject[6],
    weedGrowerJobDone[MAX_PLAYERS],
    weedGrowerPlayerMarijuana[MAX_PLAYERS],
    weedGrowerUsingMarijuana[MAX_PLAYERS],
    Timer:weedGrowerTimer[MAX_PLAYERS],
    Float:weedGrowerZCoordinate[MAX_PLAYERS];

new Float:weedGrowerObjectPos[][] =
{
    {2508.31152, -955.77863, 82.10620}, // 79.10620 is under ground
    {2513.63013, -955.48462, 82.10620}, // 79.10620 is under ground
    {2517.85278, -956.24628, 82.10620}, // 79.10620 is under ground
    {2517.80664, -962.90759, 82.10620}, // 79.10620 is under ground
    {2512.61060, -962.77399, 82.10620}, // 79.10620 is under ground
    {2508.92529, -962.35120, 82.10623} // 79.10623 is under ground
};

TIMER__ WEEDGROWER_WeedEffect[30000](playerid)
{
    SetPlayerWeather(playerid, 1);
    SetPlayerDrunkLevel(playerid, 0);
    GameTextForPlayer(playerid, "~y~Efekat droge je prosao!", 3000, 3);

    weedGrowerUsingMarijuana[playerid] = 0;
}

TIMER__ WEEDGROWER_UnFreezePlayer[2000](playerid)
{
    Anim_StopLooping(playerid);
    ClearAnimations(playerid);
}

TIMER__ WEEDGROWER_CheckCheckpoint[500](playerid)
{
    switch (WeedGrower_GetCheckpoint(playerid))
    {
        case 1:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[0][0], weedGrowerObjectPos[0][1], weedGrowerObjectPos[0][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                weedGrowerObject[0] = CreatePlayerObject(playerid, 3409, weedGrowerObjectPos[0][0], weedGrowerObjectPos[0][1], weedGrowerObjectPos[0][2] - 3.00,   0.00000, 0.00000, 0.54000, 30.00);
                WeedGrower_SetCheckpoint(playerid, 2);
            }
        }

        case 2:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[1][0], weedGrowerObjectPos[1][1], weedGrowerObjectPos[1][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                weedGrowerObject[1] = CreatePlayerObject(playerid, 3409, weedGrowerObjectPos[1][0], weedGrowerObjectPos[1][1], weedGrowerObjectPos[1][2] - 3.00,   0.00000, 0.00000, 0.54000, 30.00);
                WeedGrower_SetCheckpoint(playerid, 3);
            }
        }

        case 3:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[2][0], weedGrowerObjectPos[2][1], weedGrowerObjectPos[2][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                weedGrowerObject[2] = CreatePlayerObject(playerid, 3409, weedGrowerObjectPos[2][0], weedGrowerObjectPos[2][1], weedGrowerObjectPos[2][2] - 3.00,   0.00000, 0.00000, 0.54000, 30.00);
                WeedGrower_SetCheckpoint(playerid, 4);
            }
        }

        case 4:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[3][0], weedGrowerObjectPos[3][1], weedGrowerObjectPos[3][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                weedGrowerObject[3] = CreatePlayerObject(playerid, 3409, weedGrowerObjectPos[3][0], weedGrowerObjectPos[3][1], weedGrowerObjectPos[3][2] - 3.00,   0.00000, 0.00000, 0.54000, 30.00);
                WeedGrower_SetCheckpoint(playerid, 5);
            }
        }

        case 5:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[4][0], weedGrowerObjectPos[4][1], weedGrowerObjectPos[4][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                weedGrowerObject[4] = CreatePlayerObject(playerid, 3409, weedGrowerObjectPos[4][0], weedGrowerObjectPos[4][1], weedGrowerObjectPos[4][2] - 3.00,   0.00000, 0.00000, 0.54000, 30.00);
                WeedGrower_SetCheckpoint(playerid, 6);
            }
        }

        case 6:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[5][0], weedGrowerObjectPos[5][1], weedGrowerObjectPos[5][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                weedGrowerObject[5] = CreatePlayerObject(playerid, 3409, weedGrowerObjectPos[5][0], weedGrowerObjectPos[5][1], weedGrowerObjectPos[5][2] - 3.00,   0.00000, 0.00000, 0.54000, 30.00);
                WeedGrower_SetCheckpoint(playerid, 7);
            }
        }

        case 8:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[0][0], weedGrowerObjectPos[0][1], weedGrowerObjectPos[0][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                DestroyPlayerObject(playerid, weedGrowerObject[0]);
                WeedGrower_SetCheckpoint(playerid, 9);
            }
        }

        case 9:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[1][0], weedGrowerObjectPos[1][1], weedGrowerObjectPos[1][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                DestroyPlayerObject(playerid, weedGrowerObject[1]);
                WeedGrower_SetCheckpoint(playerid, 10);
            }
        }

        case 10:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[2][0], weedGrowerObjectPos[2][1], weedGrowerObjectPos[2][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                DestroyPlayerObject(playerid, weedGrowerObject[2]);
                WeedGrower_SetCheckpoint(playerid, 11);
            }
        }

        case 11:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[3][0], weedGrowerObjectPos[3][1], weedGrowerObjectPos[3][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                DestroyPlayerObject(playerid, weedGrowerObject[3]);
                WeedGrower_SetCheckpoint(playerid, 12);
            }
        }

        case 12:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[4][0], weedGrowerObjectPos[4][1], weedGrowerObjectPos[4][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                DestroyPlayerObject(playerid, weedGrowerObject[4]);
                WeedGrower_SetCheckpoint(playerid, 13);
            }
        }

        case 13:
        {
            if (IsPlayerInRangeOfPoint(playerid, 2.0, weedGrowerObjectPos[5][0], weedGrowerObjectPos[5][1], weedGrowerObjectPos[5][2]))
            {
                Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                defer WEEDGROWER_UnFreezePlayer(playerid);
                DestroyPlayerObject(playerid, weedGrowerObject[5]);
                WeedGrower_SetCheckpoint(playerid, 14);
            }
        }
    }
}

TIMER__ WEEDGROWER_GrowWeed[5000](playerid)
{
    if (weedGrowerZCoordinate[playerid] == 1.00)
    {
        stop weedGrowerTimer[playerid];
        SendCustomMsgF(playerid, X11_CYAN, "Sada idite i uberite marihuanu.");
        WeedGrower_SetCheckpoint(playerid, 8);
    }

    weedGrowerZCoordinate[playerid] += 0.25;
    for (new i = 0; i < sizeof(weedGrowerObject); i++)
        MovePlayerObject(playerid, weedGrowerObject[i], weedGrowerObjectPos[i][0], weedGrowerObjectPos[i][1], ((weedGrowerObjectPos[i][2] - 3.00) + weedGrowerZCoordinate[playerid]), 1.00);
}

stock WeedGrower_Init()
{
    CreateDynamic3DTextLabel("[UZGAJIVAC MARIHUANE]\n"WHITE"Da se zaposlite kucajte\n"MAIN_COLOR"/posao", MAIN_COLOR_HEX, 2491.6658,-957.3235,82.3045, 15.00);
    CreateDynamicPickup(1210, 1, 2491.6658,-957.3235,82.3045, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("[UZGAJIVAC MARIHUANE]\n\
        "WHITE"Da uzmete opremu kucajte\n"MAIN_COLOR"/posaooprema\n\
        "WHITE"Da zapocnete posao kucajte\n"MAIN_COLOR"/pokreniposao", MAIN_COLOR_HEX, 2495.8860,-953.0092,82.2543, 15.00
    );
    CreateDynamicPickup(1275, 1, 2495.8860,-953.0092,82.2543, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("[TORBA]\n"WHITE"Da uzmete torbu kucajte\n"MAIN_COLOR"/uzmitorbu", MAIN_COLOR_HEX, 2488.9578,-961.3019,82.2570, 15.00);
    CreateDynamic3DTextLabel("[SEME MARIHUANE]\n"WHITE"Da uzmete seme kucajte\n"MAIN_COLOR"/uzmiseme", MAIN_COLOR_HEX, 2489.2358,-958.2571,82.2619, 15.00);
    return 1;
}

stock WeedGrower_GetBag(const playerid) return weedGrowerBag[playerid];
stock WeedGrower_SetBag(const playerid)
{
    SetPlayerAttachedObject(playerid, WEEDGROWER_BACKPACK_INDEX, 19559, 1, -0.110900, -0.073500, 0.000000, 0.000000, 90.000000, 0.000000, 1.000000, 1.000000, 1.000000);
    weedGrowerBag[playerid] = 1;
    return 1;
}

stock WeedGrower_GetPlayerMarijuana(const playerid) return weedGrowerPlayerMarijuana[playerid];
stock WeedGrower_SetPlayerMarijuana(const playerid, const value)
{
    weedGrowerPlayerMarijuana[playerid] = value;
    new String: str_query_update = str_format(
        "UPDATE characters SET char_marijuana = '%d' WHERE char_id = '%d'",
        WeedGrower_GetPlayerMarijuana(playerid), Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}

stock WeedGrower_GetSeed(const playerid) return weedGrowerSeed[playerid];
stock WeedGrower_SetSeed(const playerid)
{
    weedGrowerSeed[playerid] = 12;
    return 1;
}

stock WeedGrower_StopJob(const playerid)
{
    RemovePlayerAttachedObject(playerid, WEEDGROWER_BACKPACK_INDEX);
    weedGrowerSeed[playerid] = 0;
    weedGrowerBag[playerid] = 0;
    return 1;
}

stock WeedGrower_GetJobDone(const playerid) return weedGrowerJobDone[playerid];
stock WeedGrower_SetJobDone(const playerid) return weedGrowerJobDone[playerid] = 1;
stock WeedGrower_GetCheckpoint(const playerid) return weedGrowerCheckpointNum[playerid];
stock WeedGrower_SetCheckpoint(const playerid, const checkpoint)
{
    weedGrowerCheckpointNum[playerid] = checkpoint;
    switch (checkpoint)
    {
        case 1:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[0][0], weedGrowerObjectPos[0][1], weedGrowerObjectPos[0][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 2:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[1][0], weedGrowerObjectPos[1][1], weedGrowerObjectPos[1][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 3:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[2][0], weedGrowerObjectPos[2][1], weedGrowerObjectPos[2][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 4:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[3][0], weedGrowerObjectPos[3][1], weedGrowerObjectPos[3][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 5:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[4][0], weedGrowerObjectPos[4][1], weedGrowerObjectPos[4][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 6:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[5][0], weedGrowerObjectPos[5][1], weedGrowerObjectPos[5][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 7:
        {
            GameTextForPlayer(playerid, "~y~Uspesno ste posadili marihuanu!", 3000, 3);
            SendInfoMsg(playerid, "Sada sacekajte da seme poraste pa ga uberite.");
            DisablePlayerCheckpoint(playerid);
            weedGrowerTimer[playerid] = repeat WEEDGROWER_GrowWeed(playerid);
        }

        case 8:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[0][0], weedGrowerObjectPos[0][1], weedGrowerObjectPos[0][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 9:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[1][0], weedGrowerObjectPos[1][1], weedGrowerObjectPos[1][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 10:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[2][0], weedGrowerObjectPos[2][1], weedGrowerObjectPos[2][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 11:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[3][0], weedGrowerObjectPos[3][1], weedGrowerObjectPos[3][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 12:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[4][0], weedGrowerObjectPos[4][1], weedGrowerObjectPos[4][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 13:
        {
            weedGrowerCheckpoint[playerid] = SetPlayerCheckpoint(playerid, weedGrowerObjectPos[5][0], weedGrowerObjectPos[5][1], weedGrowerObjectPos[5][2], 1.00);
            repeat WEEDGROWER_CheckCheckpoint(playerid);
        }

        case 14:
        {
            GameTextForPlayer(playerid, "~y~Uspesno ste ubrali marihuanu!", 3000, 3);
            SendInfoMsg(playerid, "Sada otidjite gde ste uzeli torbu i ostavite je komandom /ostavitorbu.");
            DisablePlayerCheckpoint(playerid);
            WeedGrower_SetJobDone(playerid);
        }

        case 15:
        {
            new
                money = minmaxrandom(10000, 25000),
                marijuana = minmaxrandom(200, 400);

            SendCustomMsgF(playerid, X11_CYAN, "POSAO: "WHITE"Zavrsili ste sa poslom.");
            SendCustomMsgF(playerid, X11_CYAN, "POSAO: "WHITE"Dobili ste %d marihuane.", marijuana);
            WeedGrower_SetPlayerMarijuana(playerid, marijuana);

            Account_SetMoney(playerid, Account_GetMoney(playerid) + money);
            GivePlayerMoney(playerid, money);

            va_GameTextForPlayer(playerid, "~g~+$%d", 5000, 3, money);
        }
    }
}

stock WeedGrower_UsingMarijuana(const playerid) return weedGrowerUsingMarijuana[playerid];
stock WeedGrower_UseMarijuana(const playerid)
{
    if (weedGrowerUsingMarijuana[playerid])
        return SendErrorMsg(playerid, "Vec ste naduvani, sacekajte malo!");

    WeedGrower_SetPlayerMarijuana(playerid, (WeedGrower_GetPlayerMarijuana(playerid) - 10));
    SetPlayerWeather(playerid, 66);

    new Float:armour;
    GetPlayerArmour(playerid, armour);
    SetPlayerArmour(playerid, (armour + 50.00));
    SetPlayerDrunkLevel(playerid, 4000);

    weedGrowerUsingMarijuana[playerid] = 1;
    defer WEEDGROWER_WeedEffect(playerid);
    return 1;
}