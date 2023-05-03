#if defined _INC_hunger_init_inc
    #endinput
#endif
#define _INC_hunger_init_inc

#include <YSI_Coding\y_hooks>

const
    Float:REMOVE_HUNGER_WALKING     =     0.02,
    Float:REMOVE_HUNGER_JUMPING     =     0.2,
    Float:REMOVE_HUNGER_IDLING      =     0.01,
    Float:REMOVE_THIRST_WALKING     =     0.06,
    Float:REMOVE_THIRST_JUMPING     =     0.5,
    Float:REMOVE_THIRST_IDLING      =     0.04;

static
    PlayerBar:hungerBar[MAX_PLAYERS] = {PlayerBar:INVALID_PLAYER_BAR_ID,...},
    PlayerBar:thirstBar[MAX_PLAYERS] = {PlayerBar:INVALID_PLAYER_BAR_ID,...},
    PlayerText:hungerThirstTextDraw[MAX_PLAYERS][4] = {PlayerText:INVALID_PLAYER_TEXT_DRAW,...},
    Float:hungerValue[MAX_PLAYERS],
    Float:thirstValue[MAX_PLAYERS],
    hungerThirstTimer[MAX_PLAYERS];

forward Hunger_UpdateValues(const playerid);
public Hunger_UpdateValues(const playerid)
{
    if (Player_Spawned(playerid))
    {
        if (!Hunger_GetValue(playerid) && !Thirst_GetValue(playerid) || Hunger_GetValue(playerid) < 0 && Thirst_GetValue(playerid) < 0)
        {
            GameTextForPlayer(playerid, "~r~NIJE VAM DOBRO!", 3000, 3);
            Anim_SetPlayerAnimation(playerid, "crack");
            return SetPlayerWeather(playerid, 21);
        }

        if (!Hunger_GetValue(playerid) || Hunger_GetValue(playerid) < 0)
        {
            GameTextForPlayer(playerid, "~r~GLADNI STE!", 3000, 3);
            Anim_SetPlayerAnimation(playerid, "injured");
        }

        else if (!Thirst_GetValue(playerid) || Thirst_GetValue(playerid) < 0)
        {
            GameTextForPlayer(playerid, "~r~ZEDNI STE!", 3000, 3);
            SetPlayerWeather(playerid, 21);
        }

        else if (Hunger_GetValue(playerid) && Thirst_GetValue(playerid))
        {
            if (!WeedGrower_UsingMarijuana(playerid))
                SetPlayerWeather(playerid, 1);

            if (Anim_GetIndex(playerid) != -1)
                Anim_StopLooping(playerid);
        }

        new animidx = GetPlayerAnimationIndex(playerid);
        if (animidx == 1224 || animidx == 1196) // walking
        {
            Hunger_SetValue(playerid, Hunger_GetValue(playerid) - REMOVE_HUNGER_WALKING);
            Thirst_SetValue(playerid, Thirst_GetValue(playerid) - REMOVE_THIRST_WALKING);
        }

        else if (animidx == 1195) // jumping
        {
            Hunger_SetValue(playerid, Hunger_GetValue(playerid) - REMOVE_HUNGER_JUMPING);
            Thirst_SetValue(playerid, Thirst_GetValue(playerid) - REMOVE_THIRST_JUMPING);
        }

        else
        {
            Hunger_SetValue(playerid, Hunger_GetValue(playerid) - REMOVE_HUNGER_IDLING);
            Thirst_SetValue(playerid, Thirst_GetValue(playerid) - REMOVE_THIRST_IDLING);
        }
    }
    return 1;
}

stock Hunger_PlayerSpawned(const playerid)
{
    hungerThirstTimer[playerid] = SetTimerEx("Hunger_UpdateValues", 300, 1, "d", playerid);
    return 1;
}

stock Float:Hunger_GetValue(const playerid) return hungerValue[playerid];
stock Float:Thirst_GetValue(const playerid) return thirstValue[playerid];
stock HungerThirst_UI(const playerid, bool:status, bool:create, bool:show)
{
    if (!status)
    {
        DestroyPlayerProgressBar(playerid, hungerBar[playerid]);
        DestroyPlayerProgressBar(playerid, thirstBar[playerid]);
        hungerBar[playerid] = PlayerBar:INVALID_PLAYER_BAR_ID;
        thirstBar[playerid] = PlayerBar:INVALID_PLAYER_BAR_ID;
        
        for (new i = 0; i < 4; i++)
        {
            PlayerTextDrawDestroy(playerid, hungerThirstTextDraw[playerid][i]);
            hungerThirstTextDraw[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }
        return 1;
    }

    if (create)
    {
        hungerThirstTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 113.799873, 376.600219, "LD_BEAT:CHIT");
        PlayerTextDrawTextSize(playerid, hungerThirstTextDraw[playerid][0], 24.000000, 28.000000);
        PlayerTextDrawAlignment(playerid, hungerThirstTextDraw[playerid][0], 1);
        PlayerTextDrawColor(playerid, hungerThirstTextDraw[playerid][0], 255);
        PlayerTextDrawSetShadow(playerid, hungerThirstTextDraw[playerid][0], 0);
        PlayerTextDrawBackgroundColor(playerid, hungerThirstTextDraw[playerid][0], 255);
        PlayerTextDrawFont(playerid, hungerThirstTextDraw[playerid][0], 4);
        PlayerTextDrawSetProportional(playerid, hungerThirstTextDraw[playerid][0], 0);

        hungerThirstTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 113.799873, 396.901458, "LD_BEAT:CHIT");
        PlayerTextDrawTextSize(playerid, hungerThirstTextDraw[playerid][1], 24.000000, 28.000000);
        PlayerTextDrawAlignment(playerid, hungerThirstTextDraw[playerid][1], 1);
        PlayerTextDrawColor(playerid, hungerThirstTextDraw[playerid][1], 255);
        PlayerTextDrawSetShadow(playerid, hungerThirstTextDraw[playerid][1], 0);
        PlayerTextDrawBackgroundColor(playerid, hungerThirstTextDraw[playerid][1], 255);
        PlayerTextDrawFont(playerid, hungerThirstTextDraw[playerid][1], 4);
        PlayerTextDrawSetProportional(playerid, hungerThirstTextDraw[playerid][1], 0);

        hungerThirstTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 111.199989, 362.944396, "");
        PlayerTextDrawTextSize(playerid, hungerThirstTextDraw[playerid][2], 20.000000, 36.000000);
        PlayerTextDrawAlignment(playerid, hungerThirstTextDraw[playerid][2], 1);
        PlayerTextDrawColor(playerid, hungerThirstTextDraw[playerid][2], -1);
        PlayerTextDrawSetShadow(playerid, hungerThirstTextDraw[playerid][2], 0);
        PlayerTextDrawBackgroundColor(playerid, hungerThirstTextDraw[playerid][2], 0x00000000);
        PlayerTextDrawFont(playerid, hungerThirstTextDraw[playerid][2], 5);
        PlayerTextDrawSetProportional(playerid, hungerThirstTextDraw[playerid][2], 0);
        PlayerTextDrawSetPreviewModel(playerid, hungerThirstTextDraw[playerid][2], 2880);
        PlayerTextDrawSetPreviewRot(playerid, hungerThirstTextDraw[playerid][2], 180.000000, -75.000000, 0.000000, 1.000000);

        hungerThirstTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 111.500007, 402.166625, "");
        PlayerTextDrawTextSize(playerid, hungerThirstTextDraw[playerid][3], 28.000000, 16.000000);
        PlayerTextDrawAlignment(playerid, hungerThirstTextDraw[playerid][3], 1);
        PlayerTextDrawColor(playerid, hungerThirstTextDraw[playerid][3], -1);
        PlayerTextDrawSetShadow(playerid, hungerThirstTextDraw[playerid][3], 0);
        PlayerTextDrawBackgroundColor(playerid, hungerThirstTextDraw[playerid][3], 0x00000000);
        PlayerTextDrawFont(playerid, hungerThirstTextDraw[playerid][3], 5);
        PlayerTextDrawSetProportional(playerid, hungerThirstTextDraw[playerid][3], 0);
        PlayerTextDrawSetPreviewModel(playerid, hungerThirstTextDraw[playerid][3], 1509);
        PlayerTextDrawSetPreviewRot(playerid, hungerThirstTextDraw[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);

        hungerBar[playerid] = CreatePlayerProgressBar(playerid, 134.000000, 389.000000, 58.500000, 4.199999, -176155393, 100.00, BAR_DIRECTION_RIGHT);
        thirstBar[playerid] = CreatePlayerProgressBar(playerid, 134.000000, 409.000000, 58.500000, 4.199999, 346283007, 100.00, BAR_DIRECTION_RIGHT);
        HidePlayerProgressBar(playerid, hungerBar[playerid]);
        HidePlayerProgressBar(playerid, thirstBar[playerid]);
        return 1;
    }

    if (!show)
    {
        for (new i = 0; i < 4; i++)
            PlayerTextDrawHide(playerid, hungerThirstTextDraw[playerid][i]);

        HidePlayerProgressBar(playerid, hungerBar[playerid]);
        HidePlayerProgressBar(playerid, thirstBar[playerid]);
    }

    else if (show)
    {
        for (new i = 0; i < 4; i++)
            PlayerTextDrawShow(playerid, hungerThirstTextDraw[playerid][i]);

        ShowPlayerProgressBar(playerid, hungerBar[playerid]);
        ShowPlayerProgressBar(playerid, thirstBar[playerid]);
    }
    return 1;
}

stock Hunger_SetValue(const playerid, Float:value)
{
    hungerValue[playerid] = value;
    SetPlayerProgressBarValue(playerid, hungerBar[playerid], hungerValue[playerid]);
    ShowPlayerProgressBar(playerid, hungerBar[playerid]);

    new String: str_query_update = str_format(
        "UPDATE characters SET char_hunger = '%f' WHERE char_id = '%d'",
        hungerValue[playerid], Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}

stock Thirst_SetValue(const playerid, Float:value)
{
    thirstValue[playerid] = value;
    SetPlayerProgressBarValue(playerid, thirstBar[playerid], thirstValue[playerid]);
    ShowPlayerProgressBar(playerid, thirstBar[playerid]);

    new String: str_query_update = str_format(
        "UPDATE characters SET char_thirst = '%f' WHERE char_id = '%d'",
        thirstValue[playerid], Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}