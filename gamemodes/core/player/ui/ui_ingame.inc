#if defined _INC_ui_ingame_inc
    #endinput
#endif
#define _INC_ui_ingame_inc

#include <YSI_Coding\y_hooks>

static
    PlayerText:uiTextDrawIG[MAX_PLAYERS][41] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerText:uiLoadingTextDraw[MAX_PLAYERS] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerText:uiLoginTextDraw[MAX_PLAYERS][24] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerText:uiInfoTextDraw[MAX_PLAYERS] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerBar:uiLoadingProgressBar[MAX_PLAYERS] = {PlayerBar: INVALID_PLAYER_BAR_ID,...},
    bool:uiTextDrawIGStatus[MAX_PLAYERS] = false,
    bool:uiTextDrawSpeedo[MAX_PLAYERS] = false,
    bool:uiLoadingCreated[MAX_PLAYERS] = false,
    bool:uiLoginTextDrawStatus[MAX_PLAYERS] = false,
    Timer:uiLoadingTimer[MAX_PLAYERS][2],
    Timer:uiInfoTimer[MAX_PLAYERS],
    uiLoadingDelay[MAX_PLAYERS],
    uiInfoDelay[MAX_PLAYERS],
    bool:uiInfoTextDrawCreated[MAX_PLAYERS],
    vehicleEngine[MAX_PLAYERS],
    vehicleLights[MAX_PLAYERS],
    vehicleColor[MAX_VEHICLES][2],
    vehicleFuel[MAX_VEHICLES];

new const randomMessages[][] =
{
    "Ako vam nesto nije jasno, pitajte staff team na /askq.",
    "Ukoliko ste pronasli bug na serveru, prijavite ga na /report.",
    "Srecne praznike zeli vam Generation Zed staff team!",
    "Hvala vam sto igrate na nasem serveru.",
    "Zelis postati clan staff teama? Javi se vlasniku/adminu zaduzenom za staff team!",
    "Sakupljajte sate igre, sto vise sati igre, vece su nagrade!",
    "Svakog vikenda staff team dodeljuje nagrade svim igracima!"
};

new const modelNames[][] =
{
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel",
    "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus",
    "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
    "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection",
    "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus",
    "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie",
    "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral",
    "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder",
    "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van",
    "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale",
    "Oceanic","Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy",
    "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX",
    "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper",
    "Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking",
    "Blista Compact", "Police Maverick", "Boxvillde", "Benson", "Mesa", "RC Goblin",
    "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher", "Super GT",
    "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt",
    "Tanker", "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra",
    "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune",
    "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer",
    "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent",
    "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", "Primo",
    "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite",
    "Windsor", "Monster", "Monster", "Uranus", "Jester", "Sultan", "Stratium",
    "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
    "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper",
    "Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400",
    "News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
    "Freight Box", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car",
    "Police Car", "Police Car", "Police Ranger", "Picador", "S.W.A.T", "Alpha",
    "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs", "Boxville",
    "Tiller", "Utility Trailer"
};

TIMER__ UI_HIDELOADINGUI[uiLoadingDelay[playerid] + 500](playerid)
{
    DestroyPlayerProgressBar(playerid, uiLoadingProgressBar[playerid]);
    PlayerTextDrawDestroy(playerid, uiLoadingTextDraw[playerid]);
    uiLoadingTextDraw[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    uiLoadingProgressBar[playerid] = PlayerBar:INVALID_PLAYER_BAR_ID;
    uiLoadingCreated[playerid] = false;
    uiLoadingDelay[playerid] = 0;

    stop uiLoadingTimer[playerid][0];
    stop uiLoadingTimer[playerid][1];
}

TIMER__ UI_UPDATELOADINGUI[1000](playerid)
{
    new Float:value = GetPlayerProgressBarValue(playerid, uiLoadingProgressBar[playerid]);
    value = floatround(value);
    if (value != 100)
        SetPlayerProgressBarValue(playerid, uiLoadingProgressBar[playerid], value + (floatround(100 / (uiLoadingDelay[playerid] / 1000))));
    else
        SetPlayerProgressBarValue(playerid, uiLoadingProgressBar[playerid], 0.0);
    return 1;
}

TIMER__ UI_InfoTimer[uiInfoDelay[playerid]](playerid)
{
    UI_DestroyInfoMessage(playerid);
}

stock UI_ShowLoadingTextDraw(const playerid, const string:message[], const delay, va_args<>)
{
    if (uiLoadingCreated[playerid])
        return 0;

    uiLoadingProgressBar[playerid] = CreatePlayerProgressBar(playerid,
        272.000000, 272.000000, 95.500000, 9.200000,
        MAIN_COLOR_HEX, 100.0000, BAR_DIRECTION_RIGHT
    );

    uiLoadingTextDraw[playerid] = va_CreatePlayerTextDraw(playerid, 317.100036, 262.177825, va_return(message, 2));
    PlayerTextDrawLetterSize(playerid,                  uiLoadingTextDraw[playerid], 0.196500, 0.766222);
    PlayerTextDrawTextSize(playerid,                    uiLoadingTextDraw[playerid], 0.000000, 392.000000);
    PlayerTextDrawAlignment(playerid,                   uiLoadingTextDraw[playerid], 2);
    PlayerTextDrawColor(playerid,                       uiLoadingTextDraw[playerid], -1);
    PlayerTextDrawSetShadow(playerid,                   uiLoadingTextDraw[playerid], 0);
    PlayerTextDrawSetOutline(playerid,                  uiLoadingTextDraw[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid,             uiLoadingTextDraw[playerid], 255);
    PlayerTextDrawFont(playerid,                        uiLoadingTextDraw[playerid], 1);
    PlayerTextDrawSetProportional(playerid,             uiLoadingTextDraw[playerid], 1);

    ShowPlayerProgressBar(playerid, uiLoadingProgressBar[playerid]);
    PlayerTextDrawShow(playerid, uiLoadingTextDraw[playerid]);

    uiLoadingCreated[playerid] = true;
    uiLoadingDelay[playerid] = delay;

    uiLoadingTimer[playerid][0] = defer UI_HIDELOADINGUI(playerid);
    uiLoadingTimer[playerid][1] = repeat UI_UPDATELOADINGUI(playerid);
    return 1;
}

stock UI_GetPlayerIGTD(const playerid) return uiTextDrawIGStatus[playerid];
stock UI_GetPlayerSpeedoTD(const playerid) return uiTextDrawSpeedo[playerid];
stock UI_SetPlayerIGTD(const playerid)
{
    new const bool: status = !UI_GetPlayerIGTD(playerid);
    if (!status)
    {
        for (new i = 0; i <= 28; i++)
        {
            PlayerTextDrawDestroy(playerid, uiTextDrawIG[playerid][i]);
            uiTextDrawIG[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }
        return 1;
    }

    uiTextDrawIG[playerid][0] = CreatePlayerTextDraw(playerid, 587.425415, 6.522210, "GenerationZ");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][0], 0.290000, 0.942388);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][0], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][0], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, uiTextDrawIG[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][0], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][0], 1);

    uiTextDrawIG[playerid][1] = CreatePlayerTextDraw(playerid, 554.400146, 3.333322, "]");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][1], 0.189999, 0.828444);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][1], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, uiTextDrawIG[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][1], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][1], 1);

    uiTextDrawIG[playerid][2] = CreatePlayerTextDraw(playerid, 554.400146, 12.533333, "]");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][2], 0.189999, 0.828444);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][2], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, uiTextDrawIG[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][2], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][2], 1);

    uiTextDrawIG[playerid][3] = CreatePlayerTextDraw(playerid, 547.701782, 8.333317, "]");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][3], 0.189999, 0.828444);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][3], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, uiTextDrawIG[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][3], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][3], 1);

    uiTextDrawIG[playerid][4] = CreatePlayerTextDraw(playerid, 601.201782, 15.799983, "roleplay");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][4], 0.240500, 0.834666);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][4], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, uiTextDrawIG[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][4], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][4], 3);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][4], 1);

    uiTextDrawIG[playerid][5] = CreatePlayerTextDraw(playerid, 605.375000, 0.649989, "_"); // santa hat
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][5], 20.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][5], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][5], 0);
    // PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][5], 0x00000000);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][5], 0);
    // PlayerTextDrawSetPreviewRot(playerid, uiTextDrawIG[playerid][5], 0.000000, 0.000000, 0.000000, 1.000000);

    uiTextDrawIG[playerid][6] = CreatePlayerTextDraw(playerid, -2.500000, 433.633361, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][6], 0.000000, 1.170001);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][6], 698.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][6], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][6], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][6], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][6], 1);

    uiTextDrawIG[playerid][7] = CreatePlayerTextDraw(playerid, -2.500000, 433.133331, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][7], 0.000000, 1.170001);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][7], 698.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][7], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][7], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][7], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][7], 1);

    uiTextDrawIG[playerid][8] = CreatePlayerTextDraw(playerid, -6.000000, 430.322265, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][8], 680.000000, 1.679998);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][8], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][8], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][8], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][8], 0);

    uiTextDrawIG[playerid][9] = CreatePlayerTextDraw(playerid, -6.000000, 444.823150, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][9], 680.000000, 1.639997);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][9], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][9], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][9], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][9], 0);

    uiTextDrawIG[playerid][10] = CreatePlayerTextDraw(playerid, 2.000000, 433.433380, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][10], 85.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][10], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][10], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][10], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][10], 0);

    uiTextDrawIG[playerid][11] = CreatePlayerTextDraw(playerid, 572.000000, 432.188934, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][11], 87.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][11], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][11], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][11], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][11], 0);

    uiTextDrawIG[playerid][12] = CreatePlayerTextDraw(playerid, 44.399993, 434.533386, "]____________________________]");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][12], 0.193999, 0.791110);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][12], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][12], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][12], 1);

    uiTextDrawIG[playerid][13] = CreatePlayerTextDraw(playerid, 44.399993, 434.533386, "DUPLI_RESPEKTI");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][13], 0.163498, 0.703999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][13], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][13], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][13], 1);

    uiTextDrawIG[playerid][14] = CreatePlayerTextDraw(playerid, 605.900024, 431.422271, "GENERATIONZED");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][14], 0.163498, 0.703999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][14], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][14], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][14], 1);

    uiTextDrawIG[playerid][15] = CreatePlayerTextDraw(playerid, 605.900024, 437.422637, "VERSION_1.0");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][15], 0.163498, 0.703999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][15], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][15], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][15], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][15], 1);

    uiTextDrawIG[playerid][16] = CreatePlayerTextDraw(playerid, 326.800262, 434.933776, "Ukoliko Vam je nesto nejasno, obratite se staff teamu putem /askq komande");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][16], 0.163498, 0.703999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][16], 0.000000, 711.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][16], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][16], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][16], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][16], 1);

    uiTextDrawIG[playerid][17] = CreatePlayerTextDraw(playerid, 500.100341, 106.189109, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][17], 0.000000, 5.799999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][17], 605.883056, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][17], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][17], 187);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][17], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][17], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][17], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][17], 1);

    uiTextDrawIG[playerid][18] = CreatePlayerTextDraw(playerid, 500.100341, 106.189109, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][18], 0.000000, 5.799999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][18], 605.883056, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][18], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][18], 187);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][18], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][18], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][18], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][18], 1);

    uiTextDrawIG[playerid][19] = CreatePlayerTextDraw(playerid, 499.899963, 104.922225, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][19], 106.489891, 7.810018);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][19], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][19], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][19], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][19], 0);

    uiTextDrawIG[playerid][20] = CreatePlayerTextDraw(playerid, 525.498352, 106.788894, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][20], 1.900001, 40.570240);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][20], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][20], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][20], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][20], 0);

    uiTextDrawIG[playerid][21] = CreatePlayerTextDraw(playerid, 499.898376, 147.233367, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][21], 107.000000, 2.209999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][21], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][21], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][21], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][21], 0);

    uiTextDrawIG[playerid][22] = CreatePlayerTextDraw(playerid, 550.600341, 104.755493, "INFO");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][22], 0.187500, 0.778666);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][22], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][22], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][22], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][22], 1);

    uiTextDrawIG[playerid][23] = CreatePlayerTextDraw(playerid, 501.100341, 151.277801, ReturnPlayerName(playerid));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][23], 0.166500, 0.723999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][23], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][23], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][23], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][23], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][23], 1);

    uiTextDrawIG[playerid][24] = CreatePlayerTextDraw(playerid, 529.900268, 119.155509, "BANKA:~n~ZLATO:~n~LEVEL:");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][24], 0.130999, 0.786221);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][24], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][24], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][24], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][24], 1);

    uiTextDrawIG[playerid][25] = CreatePlayerTextDraw(playerid, 605.394042, 119.555503, "~g~$~w~UCITAVANJE");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][25], 0.130999, 0.786221);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][25], 3);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][25], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][25], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][25], 1);

    uiTextDrawIG[playerid][26] = CreatePlayerTextDraw(playerid, 605.394042, 126.455398, "UCITAVANJE~y~G");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][26], 0.130999, 0.786221);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][26], 3);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][26], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][26], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][26], 1);

    uiTextDrawIG[playerid][27] = CreatePlayerTextDraw(playerid, 605.394042, 132.955673, "UCITAVANJE");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][27], 0.130999, 0.786221);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][27], 3);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][27], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][27], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][27], 1);

    uiTextDrawIG[playerid][28] = CreatePlayerTextDraw(playerid, 490.500000, 115.511062, "");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][28], 42.000000, 30.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][28], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][28], 0x00000000);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][28], 5);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][28], 0);
    PlayerTextDrawSetPreviewModel(playerid, uiTextDrawIG[playerid][28], 240);
    PlayerTextDrawSetPreviewRot(playerid, uiTextDrawIG[playerid][28], -10.000000, 0.000000, 0.000000, 1.000000);

    // showing 28 textdraws (no speedometer)
    for (new i = 0; i <= 28; i++)
        PlayerTextDrawShow(playerid, uiTextDrawIG[playerid][i]);
    return 1;
}

stock UI_GetLoginTextDrawStatus(const playerid) return uiLoginTextDrawStatus[playerid];
stock UI_CreateLoginTextDraw(const playerid)
{
    new const bool: status = !UI_GetLoginTextDrawStatus(playerid);
    if (!status)
    {
        for (new i = 0; i < 24; i++)
        {
            PlayerTextDrawDestroy(playerid, uiLoginTextDraw[playerid][i]);
            uiLoginTextDraw[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }
        uiLoginTextDrawStatus[playerid] = false;
        return 1;
    }

    uiLoginTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, -7.500000, -10.511126, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][0], 755.000000, 146.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][0], 128);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][0], 0);

    uiLoginTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, -7.500000, -10.511126, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][1], 755.000000, 146.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][1], 128);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][1], 0);

    uiLoginTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, -14.000000, 304.333343, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][2], 755.000000, 146.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][2], 128);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][2], 0);

    uiLoginTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, -14.000000, 304.333343, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][3], 755.000000, 146.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][3], 128);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][3], 0);

    uiLoginTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 281.500000, 28.844436, "GENERATION");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][4], 0.617500, 2.390221);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][4], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][4], 3);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][4], 1);

    uiLoginTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 340.899414, 36.400020, "Z");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][5], 0.931000, 3.659554);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][5], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][5], 796937471);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][5], 3);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][5], 1);

    uiLoginTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 386.899414, 31.422237, "DOBRODOSLI");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][6], 0.184000, 0.909332);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][6], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][6], 1);

    uiLoginTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 286.000000, 390.200103, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][7], 61.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][7], 796937471);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][7], 0);

    uiLoginTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 239.597167, 395.700439, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][8], 61.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][8], 796937471);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][8], 0);

    uiLoginTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 332.702850, 396.000457, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][9], 61.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][9], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][9], 796937471);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][9], 0);

    uiLoginTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 236.000000, 357.222259, "");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][10], 65.000000, 54.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][10], 0x00000000);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][10], 0);
    PlayerTextDrawSetPreviewModel(playerid, uiLoginTextDraw[playerid][10], 294);
    PlayerTextDrawSetPreviewRot(playerid, uiLoginTextDraw[playerid][10], 0.000000, 0.000000, 0.000000, 1.000000);

    uiLoginTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 328.500000, 357.844482, "");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][11], 65.000000, 54.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][11], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][11], 0x00000000);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][11], 0);
    PlayerTextDrawSetPreviewModel(playerid, uiLoginTextDraw[playerid][11], 294);
    PlayerTextDrawSetPreviewRot(playerid, uiLoginTextDraw[playerid][11], 0.000000, 0.000000, 0.000000, 1.000000);

    uiLoginTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 282.500000, 351.622253, "");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][12], 65.000000, 54.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][12], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][12], 0x00000000);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][12], 0);
    PlayerTextDrawSetPreviewModel(playerid, uiLoginTextDraw[playerid][12], 217);
    PlayerTextDrawSetPreviewRot(playerid, uiLoginTextDraw[playerid][12], 0.000000, 0.000000, 0.000000, 1.000000);

    uiLoginTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 315.500000, 338.088897, "DEVELOPER~N~EMMETT");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][13], 0.128499, 0.604444);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][13], 0.000000, 167.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][13], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][13], 1);

    uiLoginTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 268.000000, 344.933349, "MAPPER~N~NIKO");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][14], 0.128499, 0.604444);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][14], 0.000000, 167.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][14], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][14], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][14], 1);

    uiLoginTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 361.600006, 344.588958, "VLASNIK~n~EMMETT");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][15], 0.128499, 0.604444);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][15], 0.000000, 167.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][15], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][15], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][15], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][15], 1);

    uiLoginTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 29.500000, 335.444427, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][16], 171.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][16], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][16], 153);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][16], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][16], 0);

    uiLoginTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 29.500000, 335.444427, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][17], 171.000000, 2.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][17], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][17], 796937471);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][17], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][17], 0);

    uiLoginTextDraw[playerid][18] = CreatePlayerTextDraw(playerid, 114.500000, 338.088928, "GENERATIONZ_INFORMACIJE");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][18], 0.154999, 0.635555);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][18], 0.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][18], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][18], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][18], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][18], 1);

    uiLoginTextDraw[playerid][19] = CreatePlayerTextDraw(playerid, 53.599891, 357.145050, "PRE SVEGA HVALA STO IGRATE NA NASEM SERVERU. OVAJ SERVER JE OSNOVAN 2023. GODINE SA CILJEM DA IZMENIMO SA:MP SCENU");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][19], 0.154999, 0.635555);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][19], 174.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][19], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][19], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][19], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][19], 1);

    uiLoginTextDraw[playerid][20] = CreatePlayerTextDraw(playerid, 53.799903, 380.945800, "I POBOLJSAMO JE. JER, DANAS JE MALI BROJ DOBRIH I USPESNIH SERVERA, POLAKO SVE PROPADA I MI SMO TU DA POKUSAMO DA PROMENIMO TO..");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][20], 0.154999, 0.635555);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][20], 173.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][20], 1);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][20], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][20], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][20], 1);

    uiLoginTextDraw[playerid][21] = CreatePlayerTextDraw(playerid, 603.500000, 308.844451, "UZIVAJTE~N~U_IGRI");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][21], 0.351499, 1.382222);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][21], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][21], 796937471);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][21], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][21], 3);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][21], 1);

    uiLoginTextDraw[playerid][22] = CreatePlayerTextDraw(playerid, 318.500000, 131.721954, "UNESITE_TACNU_LOZINKU");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][22], 0.144499, 0.598222);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][22], 2);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][22], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][22], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][22], 1);

    uiLoginTextDraw[playerid][23] = CreatePlayerTextDraw(playerid, 636.500000, 429.555664, "Ukoliko imate nekih problema sa prijavom ili slicno~n~prijavite vlasniku na mail adresu:~n~iam.deksy]gmail.com");
    PlayerTextDrawLetterSize(playerid, uiLoginTextDraw[playerid][23], 0.130499, 0.598222);
    PlayerTextDrawTextSize(playerid, uiLoginTextDraw[playerid][23], 679.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiLoginTextDraw[playerid][23], 3);
    PlayerTextDrawColor(playerid, uiLoginTextDraw[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, uiLoginTextDraw[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, uiLoginTextDraw[playerid][23], 255);
    PlayerTextDrawFont(playerid, uiLoginTextDraw[playerid][23], 2);
    PlayerTextDrawSetProportional(playerid, uiLoginTextDraw[playerid][23], 1);

    for (new i = 0; i < 24; i++)
        PlayerTextDrawShow(playerid, uiLoginTextDraw[playerid][i]);

    uiLoginTextDrawStatus[playerid] = true;
    return 1;
}

stock UI_UpdateInfoTD(const playerid)
{
    PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][23], ReturnPlayerName(playerid));
    
    if (!Account_GetBankCard(playerid))
        PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][25], "~r~Nemate racun"); 
    else va_PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][25], "~g~$~w~%d", Account_GetBankMoney(playerid));
    
    va_PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][26], "~w~%d~y~G", Account_GetGold(playerid));
    va_PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][27], "%d", GetPlayerScore(playerid));
    PlayerTextDrawSetPreviewModel(playerid, uiTextDrawIG[playerid][28], GetPlayerSkin(playerid));
    PlayerTextDrawShow(playerid, uiTextDrawIG[playerid][28]);
    return 1;
}

stock UI_SetSpeedometer(const playerid, bool:status)
{
    if (!status)
    {
        for (new i = 29; i <= 40; i++)
        {
            PlayerTextDrawDestroy(playerid, uiTextDrawIG[playerid][i]);
            uiTextDrawIG[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }
        return 1;
    }

    // speedometer
    uiTextDrawIG[playerid][29] = CreatePlayerTextDraw(playerid, 504.500000, 362.355560, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][29], 0.000000, 6.249999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][29], 616.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][29], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][29], -1);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][29], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][29], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][29], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][29], 1);

    uiTextDrawIG[playerid][30] = CreatePlayerTextDraw(playerid, 504.500000, 362.355560, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][30], 0.000000, 6.249999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][30], 616.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][30], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][30], -1);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][30], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][30], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][30], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][30], 1);

    uiTextDrawIG[playerid][31] = CreatePlayerTextDraw(playerid, 502.099884, 360.233367, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][31], 116.000000, 8.250005);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][31], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][31], 107721471);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][31], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][31], 0);

    uiTextDrawIG[playerid][32] = CreatePlayerTextDraw(playerid, 502.199951, 419.367065, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][32], 115.789741, 1.369999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][32], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][32], 107721471);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][32], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][32], 0);

    uiTextDrawIG[playerid][33] = CreatePlayerTextDraw(playerid, 520.000000, 399.688964, "___");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][33], 0.345000, 1.525333);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][33], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][33], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][33], 3);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][33], 1);

    uiTextDrawIG[playerid][34] = CreatePlayerTextDraw(playerid, 610.099853, 403.877960, "P");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][34], 0.278000, 1.307555);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][34], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][34], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][34], 1);

    uiTextDrawIG[playerid][35] = CreatePlayerTextDraw(playerid, 559.500122, 361.322418, GetVehicleName(GetPlayerVehicleID(playerid)));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][35], 0.152500, 0.660444);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][35], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][35], 255);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][35], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][35], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][35], 1);

    // va_CreatePlayerTextDraw(playerid, 509.399963, 371.166717, "Svetla: %s",
        // (Vehicle_GetLights(playerid) ? "~g~Upaljena" : "~r~Ugasena"));

    uiTextDrawIG[playerid][36] = CreatePlayerTextDraw(playerid, 509.399963, 371.166717, "Svetla: ");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][36], 0.135000, 0.666666);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][36], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][36], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][36], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][36], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][36], 1);

    uiTextDrawIG[playerid][37] = CreatePlayerTextDraw(playerid, 509.399963, 376.667053, "MOTOR: ~r~___");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][37], 0.135000, 0.666666);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][37], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][37], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][37], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][37], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][37], 1);

    uiTextDrawIG[playerid][38] = va_CreatePlayerTextDraw(playerid, 509.399963, 382.278320, "POJAS: %s",
        (Player_GetSeatbelt(playerid) ? "~g~Zavezan" : "~r~Odvezan"));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][38], 0.135000, 0.666666);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][38], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][38], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][38], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][38], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][38], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][38], 1);

    uiTextDrawIG[playerid][39] = va_CreatePlayerTextDraw(playerid, 509.399963, 387.878662, "GORIVO: %d~y~L", Vehicle_GetFuel(playerid));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][39], 0.135000, 0.666666);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][39], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][39], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][39], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][39], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][39], 1);

    uiTextDrawIG[playerid][29] = CreatePlayerTextDraw(playerid, 504.500000, 362.355560, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][29], 0.000000, 6.249999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][29], 616.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][29], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][29], -1);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][29], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][29], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][29], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][29], 1);

    uiTextDrawIG[playerid][30] = CreatePlayerTextDraw(playerid, 504.500000, 362.355560, "box");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][30], 0.000000, 6.249999);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][30], 616.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][30], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][30], -1);
    PlayerTextDrawUseBox(playerid, uiTextDrawIG[playerid][30], 1);
    PlayerTextDrawBoxColor(playerid, uiTextDrawIG[playerid][30], 187);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][30], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][30], 1);

    uiTextDrawIG[playerid][31] = CreatePlayerTextDraw(playerid, 502.099884, 360.233367, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][31], 116.000000, 8.250004);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][31], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][31], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][31], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][31], 0);

    uiTextDrawIG[playerid][32] = CreatePlayerTextDraw(playerid, 502.199951, 419.367065, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][32], 115.789741, 1.369999);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][32], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][32], 275326975);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][32], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][32], 0);

    uiTextDrawIG[playerid][33] = CreatePlayerTextDraw(playerid, 520.000000, 399.688964, "299");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][33], 0.344999, 1.525333);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][33], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][33], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][33], 3);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][33], 1);

    uiTextDrawIG[playerid][34] = CreatePlayerTextDraw(playerid, 610.099853, 403.877960, "P");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][34], 0.277999, 1.307554);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][34], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][34], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][34], 1);

    uiTextDrawIG[playerid][35] = CreatePlayerTextDraw(playerid, 559.500122, 361.322418, GetVehicleName(GetPlayerVehicleID(playerid)));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][35], 0.152500, 0.660444);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][35], 2);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][35], 255);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][35], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][35], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][35], 1);

    uiTextDrawIG[playerid][36] = CreatePlayerTextDraw(playerid, 509.399963, 371.166717, "Svetla: ");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][36], 0.135000, 0.666665);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][36], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][36], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][36], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][36], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][36], 1);

    uiTextDrawIG[playerid][37] = CreatePlayerTextDraw(playerid, 509.399963, 376.667053, "MOTOR: ~r~___");
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][37], 0.135000, 0.666665);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][37], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][37], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][37], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][37], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][37], 1);

    uiTextDrawIG[playerid][38] = va_CreatePlayerTextDraw(playerid, 509.399963, 382.278320, "POJAS: %s", (Player_GetSeatbelt(playerid) ? "~g~Zavezan" : "~r~Odvezan"));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][38], 0.135000, 0.666665);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][38], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][38], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][38], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][38], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][38], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][38], 1);

    uiTextDrawIG[playerid][39] = va_CreatePlayerTextDraw(playerid, 509.399963, 387.878662, "GORIVO: %d~y~L", Vehicle_GetFuel(playerid));
    PlayerTextDrawLetterSize(playerid, uiTextDrawIG[playerid][39], 0.136875, 0.614164);
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][39], 741.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][39], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][39], 255);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][39], 2);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][39], 1);

    uiTextDrawIG[playerid][40] = CreatePlayerTextDraw(playerid, 560.850097, 352.916809, "");
    PlayerTextDrawTextSize(playerid, uiTextDrawIG[playerid][40], 57.000000, 73.000000);
    PlayerTextDrawAlignment(playerid, uiTextDrawIG[playerid][40], 1);
    PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, uiTextDrawIG[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, uiTextDrawIG[playerid][40], 0x00000000);
    PlayerTextDrawFont(playerid, uiTextDrawIG[playerid][40], 5);
    PlayerTextDrawSetProportional(playerid, uiTextDrawIG[playerid][40], 0);
    PlayerTextDrawSetPreviewModel(playerid, uiTextDrawIG[playerid][40], 560);
    PlayerTextDrawSetPreviewRot(playerid, uiTextDrawIG[playerid][40], -10.000000, 0.000000, -30.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, uiTextDrawIG[playerid][40], 1, 1);

    for (new i = 29; i <= 40; i++)
    {
        PlayerTextDrawSetPreviewModel(playerid, uiTextDrawIG[playerid][40], GetVehicleModel(GetPlayerVehicleID(playerid)));
        PlayerTextDrawSetPreviewVehCol(playerid, uiTextDrawIG[playerid][40], Vehicle_GetColor(GetPlayerVehicleID(playerid), 0), Vehicle_GetColor(GetPlayerVehicleID(playerid), 1));
        PlayerTextDrawShow(playerid, uiTextDrawIG[playerid][i]);
    }
    return 1;
}

stock UI_DestroyInfoMessage(const playerid)
{
    if (!uiInfoTextDrawCreated[playerid])
        return 0;

    PlayerTextDrawDestroy(playerid, uiInfoTextDraw[playerid]);
    uiInfoTextDraw[playerid] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
    uiInfoDelay[playerid] = 0;
    uiInfoTextDrawCreated[playerid] = false;
    stop uiInfoTimer[playerid];
    return 1;
}

stock UI_ShowInfoMessage(const playerid, const delay, const string: message[], va_args<>)
{
    if (uiInfoTextDrawCreated[playerid])
        return 0;

    uiInfoTextDraw[playerid] = CreatePlayerTextDraw(playerid, 316.600067, 302.390167, va_return(message, va_start<3>));
    PlayerTextDrawLetterSize(playerid, uiInfoTextDraw[playerid], 0.252499, 1.164443);
    PlayerTextDrawTextSize(playerid, uiInfoTextDraw[playerid], 0.000000, 972.000000);
    PlayerTextDrawAlignment(playerid, uiInfoTextDraw[playerid], 2);
    PlayerTextDrawColor(playerid, uiInfoTextDraw[playerid], -1);
    PlayerTextDrawSetShadow(playerid, uiInfoTextDraw[playerid], 0);
    PlayerTextDrawSetOutline(playerid, uiInfoTextDraw[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, uiInfoTextDraw[playerid], 255);
    PlayerTextDrawFont(playerid, uiInfoTextDraw[playerid], 1);
    PlayerTextDrawSetProportional(playerid, uiInfoTextDraw[playerid], 1);

    uiInfoTextDrawCreated[playerid] = true;
    uiInfoDelay[playerid] = delay;
    uiInfoTimer[playerid] = defer UI_InfoTimer(playerid);
    return PlayerTextDrawShow(playerid, uiInfoTextDraw[playerid]);
}

stock Vehicle_GetColor(const vehicleid, const color/* 0/1 */) return vehicleColor[vehicleid][color];
stock Vehicle_SetColor(const vehicleid, const color1, const color2)
{
    vehicleColor[vehicleid][0] = color1;
    vehicleColor[vehicleid][1] = color2;
    ChangeVehicleColor(vehicleid, Vehicle_GetColor(vehicleid, 0), Vehicle_GetColor(vehicleid, 1));
    return 1;
}

stock GetVehicleSpeed(const vehicleid)
{
    static Float: pos_y,
        Float: pos_x,
        Float: pos_z,

        Float: veh_speed;

    GetVehicleVelocity(vehicleid, pos_x, pos_y, pos_z);
    // veh_speed = (floatsqroot((pos_x * pos_x) + (pos_y * pos_y) + (pos_z * pos_z)) * 180);
    veh_speed = VectorSize(pos_x, pos_y, pos_z) * 180;
    
    return floatround(veh_speed, floatround_round);
}

stock GetVehicleName(const vehicleid)
{
    new modelid = GetVehicleModel(vehicleid),
        name[32];
 
    if(400 <= modelid <= 611)
        strcat(name, modelNames[modelid - 400]);
    else
        name = "Unknown";
    return name;
}

stock Vehicle_GetEngine(const playerid) return vehicleEngine[playerid];
stock Vehicle_GetLights(const playerid) return vehicleLights[playerid];
stock Vehicle_GetFuel(const playerid) return vehicleFuel[GetPlayerVehicleID(playerid)];

stock Vehicle_SetEngine(const playerid)
{
    new const status = !Vehicle_GetEngine(playerid);
    static engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);

    if (!status)
    {
        SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, lights, alarm, doors, bonnet, boot, objective);
        PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][37], "Motor: ~r~Ugasen");
        vehicleEngine[playerid] = 0;
        return 1;
    }

    SetVehicleParamsEx(GetPlayerVehicleID(playerid), 1, lights, alarm, doors, bonnet, boot, objective);
    PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][37], "Motor: ~g~Upaljen");
    vehicleEngine[playerid] = 1;
    return 1;
}

stock Vehicle_SetLights(const playerid)
{
    new const status = !Vehicle_GetLights(playerid);
    static engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);

    if (!status)
    {
        SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, 0, alarm, doors, bonnet, boot, objective);
        PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][36], "Svetla: ~r~Ugasena");
        vehicleLights[playerid] = 0;
        return 1;
    }

    SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, 1, alarm, doors, bonnet, boot, objective);
    PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][36], "Svetla: ~g~Upaljena");
    vehicleLights[playerid] = 1;
    return 1;
}

stock Vehicle_SetSeatbelt(const playerid)
{
    new const status = !Player_GetSeatbelt(playerid);
    if (!status)
    {
        Player_SetSeatbelt(playerid, false);
        PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][38], "POJAS: ~r~Odvezan");
        SendServerMsg(playerid, "Odvezali ste pojas.");
        return 1;
    }

    Player_SetSeatbelt(playerid, true);
    PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][38], "POJAS: ~g~Zavezan");
    SendServerMsg(playerid, "Zavezali ste pojas.");
    return 1;
}

stock Vehicle_SetFuel(const vehicleid, const value)
{
    vehicleFuel[vehicleid] = value;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    vehicleEngine[playerid] = 0;
    vehicleLights[playerid] = 0;

    if (Player_GetSeatbelt(playerid))
        Vehicle_SetSeatbelt(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    UI_SetSpeedometer(playerid, (newstate == PLAYER_STATE_DRIVER ? (true) : (false)));

    if (newstate == PLAYER_STATE_ONFOOT && oldstate != PLAYER_STATE_PASSENGER)
    {
        if (Player_GetSeatbelt(playerid))
            Vehicle_SetSeatbelt(playerid);

        if (Vehicle_GetEngine(playerid))
            Vehicle_SetEngine(playerid);

        if (Vehicle_GetLights(playerid))
            Vehicle_SetLights(playerid);
    }

    if (GetPlayerState(playerid) != PLAYER_STATE_PASSENGER)
    {
        Vehicle_SetEngine(playerid);
        Vehicle_SetLights(playerid);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if (GetPlayerState(playerid) != PLAYER_STATE_PASSENGER)
    {
        if (Player_GetSeatbelt(playerid))
            Vehicle_SetSeatbelt(playerid);

        if (Vehicle_GetEngine(playerid))
            Vehicle_SetEngine(playerid);

        if (Vehicle_GetLights(playerid))
            Vehicle_SetLights(playerid);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (IsPlayerInAnyVehicle(playerid) && PRESSED(KEY_AIM))
    {
        PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][34], X11_DARKRED);
        PlayerTextDrawShow(playerid, uiTextDrawIG[playerid][34]);
    }

    else if (IsPlayerInAnyVehicle(playerid) && RELEASED(KEY_AIM))
    {
        PlayerTextDrawColor(playerid, uiTextDrawIG[playerid][34], X11_WHITE);
        PlayerTextDrawShow(playerid, uiTextDrawIG[playerid][34]);
    }

    else if (IsPlayerInAnyVehicle(playerid) && PRESSED(KEY_SUBMISSION) && Vehicle_GetFuel(playerid))
        Vehicle_SetEngine(playerid);
    else if (IsPlayerInAnyVehicle(playerid) && PRESSED(KEY_NO))
        Vehicle_SetLights(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

PTASK__ Speedo_UpdateVehStatus[1000](playerid)
{
    if (IsPlayerInAnyVehicle(playerid))
        va_PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][33], "%d", GetVehicleSpeed(GetPlayerVehicleID(playerid)));
}

PTASK__ Speedo_UpdateFuel[120000](playerid)
{
    if (IsPlayerInAnyVehicle(playerid))
    {
        if (!Vehicle_GetFuel(playerid))
            return 0;

        Vehicle_SetFuel(playerid, Vehicle_GetFuel(playerid) - 1);
        if (!Vehicle_GetFuel(playerid) && Vehicle_GetEngine(playerid))
            Vehicle_SetEngine(playerid);

        va_PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][39], "GORIVO: %d~y~L", Vehicle_GetFuel(playerid));
    }
    return 1;
}

PTASK__ UI_UpdateRandomMsg[5000](playerid)
{
    PlayerTextDrawSetString(playerid, uiTextDrawIG[playerid][16], randomMessages[random(sizeof(randomMessages))]);
}