#if defined _INC_job_init_inc
    #endinput
#endif
#define _INC_job_init_inc

#include <YSI_Coding\y_hooks>

#include <job_postman>
#include <job_lawnmower>
#include <job_busdriver>
#include <job_weedgrower>

static accountJob[MAX_PLAYERS],
    BitArray: Bit_JobUniform<MAX_PLAYERS>,
    BitArray: Bit_JobStarted<MAX_PLAYERS>;

hook OnGameModeInit()
{
    Postman_Init();
    Mower_Init();
    BusDriver_Init();
    WeedGrower_Init();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    Postman_DestroyVehicles();
    Mower_DestroyVehicles();
    BusDriver_DestroyVehicles();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Bit_Set(Bit_JobUniform, playerid, false);
    Bit_Set(Bit_JobStarted, playerid, false);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock Account_JobStarted(const playerid) return Bit_Get(Bit_JobStarted, playerid);
stock Account_GetJobUniform(const playerid) return Bit_Get(Bit_JobUniform, playerid);
stock Account_GetJob(const playerid) return accountJob[playerid];
stock Account_SetJob(const playerid, const jobid)
{
    accountJob[playerid] = jobid;

    new String: str_query_update = str_format(
        "UPDATE characters SET char_job = '%d' WHERE char_id = '%d'",
        Account_GetJob(playerid), Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}

stock Account_SetJobUniform(const playerid, const jobid, const bool:status)
{
    Bit_Set(Bit_JobUniform, playerid, status);
    switch (jobid)
    {
        // Postman
        case 1:
        {
            SetPlayerSkin(playerid, Account_GetJobUniform(playerid) ? 119 : Account_GetSkin(playerid));
            UI_UpdateInfoTD(playerid);
            SendInfoMsgF(playerid, "%s ste opremu.", Account_GetJobUniform(playerid) ? "Obukli" : "Skinuli");
        }

        // Lawn mower
        case 2:
        {
            SetPlayerSkin(playerid, Account_GetJobUniform(playerid) ? 222 : Account_GetSkin(playerid));
            UI_UpdateInfoTD(playerid);
            SendInfoMsgF(playerid, "%s ste opremu.", Account_GetJobUniform(playerid) ? "Obukli" : "Skinuli");
        }

        // Bus driver
        case 3:
        {
            SetPlayerSkin(playerid, Account_GetJobUniform(playerid) ? 24 : Account_GetSkin(playerid));
            UI_UpdateInfoTD(playerid);
            SendInfoMsgF(playerid, "%s ste opremu.", Account_GetJobUniform(playerid) ? "Obukli" : "Skinuli");
        }

        // Weed grower
        case 4:
        {
            SetPlayerSkin(playerid, Account_GetJobUniform(playerid) ? 79 : Account_GetSkin(playerid));
            UI_UpdateInfoTD(playerid);
            SendInfoMsgF(playerid, "%s ste opremu.", Account_GetJobUniform(playerid) ? "Obukli" : "Skinuli");
        }
    }
    return 1;
}

stock Account_SetJobStarted(const playerid, const jobid, const bool:status)
{
    Bit_Set(Bit_JobStarted, playerid, status);

    if (!status)
    {
        DisablePlayerCheckpoint(playerid);
        return 1;
    }

    switch (jobid)
    {
        // Postmann
        case 1: Postman_SetCheckpoint(playerid, 1);
        // Lawn mower
        case 2: Mower_SetCheckpoint(playerid, 1);
        // Bus driver
        case 3: BusDriver_SetCheckpoint(playerid, 1);
        // Weed grower
        case 4: WeedGrower_SetCheckpoint(playerid, 1);
    }
    return 1;
}

stock Account_GetJobNameByID(const jobid)
{
    static tmpString[24];
    switch (jobid)
    {
        case 0: tmpString = "Nezaposlen";
        case 1: tmpString = "Postar";
        case 2: tmpString = "Kosac trave";
        case 3: tmpString = "Vozac autobusa";
        case 4: tmpString = "Uzgajivac marihuane";
    }
    return tmpString;
}