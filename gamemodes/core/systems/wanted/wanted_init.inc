#if defined _INC_wanted_init_inc
    #endinput
#endif
#define _INC_wanted_init_inc

#include <YSI_Coding\y_hooks>

const WANTED_LEVEL_TIME = 15; // 15 mins in jail for one wanted level (2wl = 30min)

static
    wantedLevel[MAX_PLAYERS],
    Timer:wantedLevelTimer[MAX_PLAYERS],
    Timer:wantedLevelDecrease[MAX_PLAYERS],
    bool:wantedLevelTDStatus[MAX_PLAYERS],
    PlayerText:wantedLevelTextDraw[MAX_PLAYERS] = PlayerText:INVALID_PLAYER_TEXT_DRAW;

TIMER__ WL_BlinkStar[1000](playerid)
{
    wantedLevelTDStatus[playerid] = !wantedLevelTDStatus[playerid];
    if (wantedLevelTDStatus[playerid])
        PlayerTextDrawHide(playerid, wantedLevelTextDraw[playerid]);
    else
        PlayerTextDrawShow(playerid, wantedLevelTextDraw[playerid]);
}

TIMER__ WL_Decrease[120000](playerid)
{
    WantedLevel_Set(playerid, (WantedLevel_Get(playerid) - 1));
}

hook OnPlayerConnect(playerid)
{
    wantedLevelTextDraw[playerid] = CreatePlayerTextDraw(playerid, 70.000061, 315.189178, "~r~]~w~]]]]]");
    PlayerTextDrawLetterSize(playerid, wantedLevelTextDraw[playerid], 0.298000, 1.083555);
    PlayerTextDrawTextSize(playerid, wantedLevelTextDraw[playerid], 0.000000, 167.000000);
    PlayerTextDrawAlignment(playerid, wantedLevelTextDraw[playerid], 2);
    PlayerTextDrawColor(playerid, wantedLevelTextDraw[playerid], -1);
    PlayerTextDrawSetShadow(playerid, wantedLevelTextDraw[playerid], 0);
    PlayerTextDrawSetOutline(playerid, wantedLevelTextDraw[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, wantedLevelTextDraw[playerid], 255);
    PlayerTextDrawFont(playerid, wantedLevelTextDraw[playerid], 2);
    PlayerTextDrawSetProportional(playerid, wantedLevelTextDraw[playerid], 1);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    WantedLevel_Set(playerid, (WantedLevel_Get(playerid) + 1));
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if (WantedLevel_Get(playerid))
        Account_SetJailTime(playerid, (WANTED_LEVEL_TIME * WantedLevel_Get(playerid)));
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock WantedLevel_Get(const playerid) return wantedLevel[playerid];
stock WantedLevel_Set(const playerid, const value)
{
    if (value > 6)
        return 0;

    switch (value)
    {
        case 0:
        {
            PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "______");
            stop wantedLevelTimer[playerid];
            stop wantedLevelDecrease[playerid];
        }
        case 1: PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "~r~]~w~]]]]]");
        case 2: PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "~r~]]~w~]]]]");
        case 3: PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "~r~]]]~w~]]]");
        case 4: PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "~r~]]]]~w~]]");
        case 5: PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "~r~]]]]]~w~]");
        case 6: PlayerTextDrawSetString(playerid, wantedLevelTextDraw[playerid], "~r~]]]]]]");
    }
    PlayerTextDrawShow(playerid, wantedLevelTextDraw[playerid]);
    
    if (value)
    {
        if (wantedLevelTimer[playerid])
            stop wantedLevelTimer[playerid];

        if (wantedLevelDecrease[playerid])
            stop wantedLevelDecrease[playerid];
        
        wantedLevelTimer[playerid] = repeat WL_BlinkStar(playerid);
        wantedLevelDecrease[playerid] = repeat WL_Decrease(playerid);
    }

    wantedLevel[playerid] = value;
    new String:str_query_update = str_format(
        "UPDATE characters SET char_wl = '%d' WHERE char_id = '%d'",
        WantedLevel_Get(playerid), Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}