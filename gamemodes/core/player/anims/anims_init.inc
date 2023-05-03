#if defined _INC_anims_init_inc
    #endinput
#endif
#define _INC_anims_init_inc

#include <YSI_Coding\y_hooks>

static
    animPlayerLibsPreloaded[MAX_PLAYERS],
    animPlayerUsingLoopAnim[MAX_PLAYERS],
    animIndex[MAX_PLAYERS],
    animCurrentLib[MAX_PLAYERS][16];

static animList[][] =
{
    "carjacked", "drunk", "bomb", "laugh", "lookout", "robman", "lay",
    "wave", "slapass", "deal", "crack", "groundsit", "chat", "chat2",
    "fucku", "taichi", "kiss", "injured", "sup1", "sup2", "sup3", "rap1",
    "rap2", "push", "medic", "koface", "lifejump", "leftslap", "strip",
    "dance1", "dance2", "dance3", "dance4", "bed", "lean", "aim", "sit"
};

hook OnPlayerConnect(playerid)
{
    animPlayerLibsPreloaded[playerid] = 
    animPlayerUsingLoopAnim[playerid] = 0;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSpawn(playerid)
{
    if(!animPlayerLibsPreloaded[playerid])
    {
        Anim_PreloadLib(playerid,"BOMBER");
        Anim_PreloadLib(playerid,"RAPPING");
        Anim_PreloadLib(playerid,"SHOP");
        Anim_PreloadLib(playerid,"BEACH");
        Anim_PreloadLib(playerid,"FOOD");
        Anim_PreloadLib(playerid,"ON_LOOKERS");
        Anim_PreloadLib(playerid,"DEALER");
        Anim_PreloadLib(playerid,"CRACK");
        Anim_PreloadLib(playerid,"CARRY");
        Anim_PreloadLib(playerid,"COP_AMBIENT");
        Anim_PreloadLib(playerid,"PARK");
        Anim_PreloadLib(playerid,"INT_HOUSE");
        Anim_PreloadLib(playerid,"FOOD");
        Anim_PreloadLib(playerid,"PED");
        animPlayerLibsPreloaded[playerid] = 1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(animPlayerUsingLoopAnim[playerid])
        animPlayerUsingLoopAnim[playerid] = 0;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock Anim_GetCurrentLib(const playerid) return animCurrentLib[playerid];
stock Anim_GetIndex(const playerid) return animIndex[playerid];
stock Anim_SetIndex(const playerid, const index) return animIndex[playerid] = index;

stock Anim_Play(const playerid, const string: animlib[], const string:animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
    strcopy(animCurrentLib[playerid], animlib);
    return ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp);
}

stock Anim_PreloadLib(const playerid, const string: animlib[])
    return ApplyAnimation(playerid, animlib, "null", 0.0, 0, 0, 0, 0, 0);

stock Anim_Loop(const playerid, const string: animlib[], const string: animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
    strcopy(animCurrentLib[playerid], animlib);
    animPlayerUsingLoopAnim[playerid] = 1;
    return ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp);
}

stock Anim_StopLooping(const playerid)
{
    animPlayerUsingLoopAnim[playerid] = 0;
    animIndex[playerid] = -1;
    return ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
}

stock Anim_SetPlayerAnimation(const playerid, const string: anim[])
{
    for (new i = 0; i < sizeof(animList); i++)
    {
        if (!strcmp(animList[i], anim, false))
        {
            animIndex[playerid] = i;
            break;
        }
    }

    if (Anim_GetIndex(playerid) < 0)
        return SendCustomMsgF(playerid, X11_RED, "(Animacija!): "WHITE"Nismo pronasli tu animaciju!");

    switch (Anim_GetIndex(playerid))
    {
        case 0: Anim_Loop(playerid,"PED","CAR_jackedRHS",4.0,0,1,1,1,0);
        case 1: Anim_Loop(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
        case 2: Anim_Loop(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
        case 3: Anim_Play(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
        case 4: Anim_Play(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
        case 5: Anim_Loop(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
        case 6: Anim_Loop(playerid,"BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
        case 7: Anim_Loop(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
        case 8: Anim_Play(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
        case 9: Anim_Play(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
        case 10: Anim_Loop(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
        case 11: Anim_Loop(playerid,"BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
        case 12: Anim_Loop(playerid,"PED","IDLE_CHAT",4.0,1,0,0,1,1);
        case 13: Anim_Loop(playerid,"MISC","Idle_Chat_02",4.0,1,0,0,1,1);
        case 14: Anim_Play(playerid,"PED","fucku",4.0,0,0,0,0,0);
        case 15: Anim_Loop(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);
        case 16: Anim_Loop(playerid, "KISSING", "Playa_Kiss_02", 3.0, 1, 1, 1, 1, 0);
        case 17: Anim_Loop(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
        case 18: Anim_Play(playerid,"GANGS","hndshkba",4.0,0,0,0,0,0);
        case 19: Anim_Play(playerid,"GANGS","hndshkda",4.0,0,0,0,0,0);
        case 20: Anim_Play(playerid,"GANGS","hndshkfa_swt",4.0,0,0,0,0,0);
        case 21: Anim_Loop(playerid,"RAPPING","RAP_A_Loop",4.0,1,0,0,0,0);
        case 22: Anim_Loop(playerid,"GANGS","prtial_gngtlkD",4.0,1,0,0,0,0);
        case 23: Anim_Play(playerid,"GANGS","shake_cara",4.0,0,0,0,0,0);
        case 24: Anim_Play(playerid,"MEDIC","CPR",4.0,0,0,0,0,0);
        case 25: Anim_Loop(playerid,"PED","KO_shot_face",4.0,0,1,1,1,0);
        case 26: Anim_Loop(playerid,"PED","EV_dive",4.0,0,1,1,1,0);
        case 27: Anim_Play(playerid,"PED","BIKE_elbowL",4.0,0,0,0,0,0);
        case 28: Anim_Loop(playerid,"STRIP", "strip_A", 4.1, 1, 1, 1, 1, 1 );
        case 29: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
        case 30: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
        case 31: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
        case 32: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
        case 33: Anim_Loop(playerid,"INT_HOUSE","BED_Loop_R",4.0,1,0,0,0,0);
        case 34: Anim_Loop(playerid,"GANGS","leanIDLE",4.0,0,1,1,1,0);
        case 35: Anim_Loop(playerid,"PED","gang_gunstand",4.0,1,1,1,1,1);
        case 36: Anim_Loop(playerid,"MISC","seat_lr",2.0,1,0,0,0,0);
    }
    return 1;
}