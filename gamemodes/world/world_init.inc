#if defined _INC_world_init_inc
    #endinput
#endif
#define _INC_world_init_inc

#include <YSI_Coding\y_hooks>

#include <maps/map_spawn>
#include <maps/map_hospital>
#include <maps/map_bank>
#include <maps/map_winteredition>
#include <maps/map_lspd>
#include <maps/map_postmanjob>
#include <maps/map_mowerjob>
#include <maps/map_houseint>
#include <maps/map_cityhall>
#include <maps/map_cardealership>
#include <maps/map_tuneshop>
#include <maps/map_weedgrower>

hook OnGameModeInit()
{
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);
    EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();
    SetWeather(1);

    static hour;
    gettime(hour);
    SetWorldTime(hour);

    Hospital_CreateObjects();
    Spawn_CreateObjects();
    WE_CreateObjects();
    Bank_CreateObjects();
    LSPD_CreateObjects();
    PostOffice_CreateObjects();
    Mower_CreateObjects();
    House_CreateObjects();
    CityHall_CreateObjects();
    CarDS_CreateObjects();
    TuneShop_CreateObects();
    WeedGrower_CreateObjects();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    Hospital_RemoveObjects(playerid);
    LSPD_RemoveObjects(playerid);
    Mower_RemoveObjects(playerid);
    Mower_CreatePlayerObjects(playerid);
    CarDS_RemoveObjects(playerid);
    TuneShop_RemoveObjects(playerid);
    WeedGrower_RemoveObjects(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SECONDARY_ATTACK))
    {
        // Hospital
        if (IsPlayerInRangeOfPoint(playerid, 2.0, 1165.7496, -1339.2876, 13.5935))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1127.0082, -1317.1527, 4395.3857, .compensatedtime = 2000);
        }

        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1127.0082, -1317.1527, 4395.3857))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1165.7496, -1339.2876, 13.5935, .compensatedtime = 2000);
        }

        // Bank
        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1573.2830, -1338.1477, 16.4844))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1387.6700, -26.8067, 1000.8729, .compensatedtime = 2000);
        }

        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1387.6700, -26.8067, 1000.8729))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1573.2830,-1338.1477,16.4844, .compensatedtime = 2000);
        }

        // LSPD
        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1553.7448,-1675.7839,16.1953))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, -7.6248, 2687.9856, -44.0646, .compensatedtime = 2000);
        }

        else if (IsPlayerInRangeOfPoint(playerid, 2.0, -7.6248, 2687.9856, -44.0646))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1553.7448, -1675.7839, 16.1953, .compensatedtime = 2000);
        }

        // City Hall
        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1481.0414, -1771.2716, 18.7958))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1041.7997, -689.5055, -2.3966, .compensatedtime = 2000);
        }

        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1041.7997, -689.5055, -2.3966))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1481.0414, -1771.2716, 18.7958, .compensatedtime = 2000);
        }

        // Car dealership
        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1786.3329, -1707.2350, 13.3732))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1781.5547, -1707.3173, 13.3805, .compensatedtime = 2000);
        }

        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1781.5547, -1707.3173, 13.3805))
        {
            UI_ShowLoadingTextDraw(playerid, "UCITAVANJE OBJEKATA...", 2000);
            Streamer_UpdateEx(playerid, 1786.3329, -1707.2350, 13.3732, .compensatedtime = 2000);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}