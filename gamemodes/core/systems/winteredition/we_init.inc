#if defined _INC_we_init_inc
    #endinput
#endif
#define _INC_we_init_inc

#include <YSI_Coding\y_hooks>

static BitArray: Bit_WinterStatusAll<MAX_PLAYERS>;

stock Winter_GetAllStatus(const playerid) return Bit_Get(Bit_WinterStatusAll, playerid);
stock Winter_SetStatusAll(const playerid)
{
    new const bool: status = !Winter_GetAllStatus(playerid);
    if (!status)
    {
        if (Winter_GetColdBreathStatus(playerid))
            Winter_SetColdBreathStatus(playerid);
        
        if (Winter_GetSnowCapStatus(playerid))
            Winter_SetSnowCapStatus(playerid);
        
        if (Winter_GetSnowflakeStatus(playerid))
            Winter_SetSnowflakeStatus(playerid);
        
        if (Winter_GetSnowObjStatus(playerid))
            Winter_ShowSnowObjects(playerid);

        Bit_Set(Bit_WinterStatusAll, playerid, false);
        return 1;
    }

    if (!Winter_GetColdBreathStatus(playerid))
        Winter_SetColdBreathStatus(playerid);
    
    if (!Winter_GetSnowCapStatus(playerid))
        Winter_SetSnowCapStatus(playerid);
    
    if (!Winter_GetSnowflakeStatus(playerid))
        Winter_SetSnowflakeStatus(playerid);
    
    if (!Winter_GetSnowObjStatus(playerid))
        Winter_ShowSnowObjects(playerid);

    Bit_Set(Bit_WinterStatusAll, playerid, true);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    Bit_Set(Bit_WinterStatusAll, playerid, false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}