#if defined _INC_ui_idcard_inc
    #endinput
#endif
#define _INC_ui_idcard_inc

static
    PlayerText:IDCardTextDraw[MAX_PLAYERS][26] = {PlayerText:INVALID_PLAYER_TEXT_DRAW,...},
    bool:uiIDCardStatus[MAX_PLAYERS];

stock UI_ReturnIDCardTD(const playerid, const index) return _:IDCardTextDraw[playerid][index];
stock UI_GetIDCard(const playerid) return uiIDCardStatus[playerid];
stock UI_CreateIDCard(const playerid)
{
    new const bool:status = !UI_GetIDCard(playerid);
    if (!status)
    {
        for (new i = 0; i < 26; i++)
        {
            PlayerTextDrawDestroy(playerid, IDCardTextDraw[playerid][i]);
            IDCardTextDraw[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }

        CancelSelectTextDraw(playerid);
        uiIDCardStatus[playerid] = false;
        return 1;
    }

    IDCardTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 234.000000, 156.866668, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][0], 168.000000, 112.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][0], 336860415);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][0], 0);

    IDCardTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 226.699981, 207.133560, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][1], 181.000000, -50.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][1], 428072256);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][1], 0);

    IDCardTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 224.899871, 207.133560, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][2], 187.000000, 62.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][2], 64);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][2], 0);

    IDCardTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 224.099822, 208.378005, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][3], 187.000000, 62.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][3], 64);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][3], 0);

    IDCardTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 257.200042, 158.888854, "LICNA_KARTA");
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][4], 0.203000, 0.591999);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][4], 2);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][4], 1);

    IDCardTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 294.500000, 178.222259, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][5], 0.570000, 72.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][5], 0);

    IDCardTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 216.500000, 172.422225, "");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][6], 93.000000, 89.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][6], 0x00000000);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, IDCardTextDraw[playerid][6], GetPlayerSkin(playerid));
    PlayerTextDrawSetPreviewRot(playerid, IDCardTextDraw[playerid][6], -10.000000, 0.000000, 0.000000, 1.000000);

    IDCardTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 298.099487, 182.712173, Player_SplitName(playerid, "lastname"));
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][7], 0.215000, 0.884444);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][7], 1);

    IDCardTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 299.099487, 194.713241, "IME");
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][8], 0.160500, 0.523555);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][8], 1);

    IDCardTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 299.099487, 177.112167, "PREZIME");
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][9], 0.160500, 0.523555);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][9], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][9], 1);

    IDCardTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 298.099487, 200.713272, Player_SplitName(playerid, "name"));
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][10], 0.215000, 0.884444);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][10], 1);

    IDCardTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 299.099487, 212.614334, "DATUM_RODJENJA");
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][11], 0.160500, 0.523555);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][11], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][11], 1);

    IDCardTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 298.099487, 219.314407, Account_GetDOB(playerid));
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][12], 0.215000, 0.884444);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][12], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][12], 1);

    IDCardTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 299.299438, 231.471115, "POL");
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][13], 0.160500, 0.523555);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][13], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][13], 1);

    IDCardTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 298.099487, 238.515579, Account_GetGender(playerid) == 1 ? "M" : "Z");
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][14], 0.215000, 0.884444);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][14], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][14], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][14], 1);

    IDCardTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 372.400207, 161.177520, "LD_SPAC:WHITE");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][15], 26.000000, 31.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][15], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][15], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][15], 0);

    IDCardTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 376.500122, 190.055419, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][16], 16.000000, -25.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][16], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][16], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][16], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][16], 0);

    IDCardTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 376.500122, 190.055419, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][17], 16.000000, -25.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][17], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][17], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][17], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][17], 0);

    IDCardTextDraw[playerid][18] = CreatePlayerTextDraw(playerid, 376.500122, 190.055419, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][18], 16.000000, -25.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][18], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][18], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][18], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][18], 0);

    IDCardTextDraw[playerid][19] = CreatePlayerTextDraw(playerid, 379.000122, 175.744293, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][19], 13.000000, -12.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][19], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][19], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][19], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][19], 0);

    IDCardTextDraw[playerid][20] = CreatePlayerTextDraw(playerid, 379.000122, 175.744293, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][20], 13.000000, -12.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][20], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][20], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][20], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][20], 0);

    IDCardTextDraw[playerid][21] = CreatePlayerTextDraw(playerid, 376.500122, 180.722076, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][21], 13.000000, -12.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][21], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][21], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][21], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][21], 0);

    IDCardTextDraw[playerid][22] = CreatePlayerTextDraw(playerid, 379.500122, 182.588745, "PARTICLE:CLOUDHIGH");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][22], 13.000000, -12.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][22], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][22], 112);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][22], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][22], 0);

    IDCardTextDraw[playerid][23] = CreatePlayerTextDraw(playerid, 386.200134, 150.877838, "ZATVORI");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][23], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][23], 0.206999, 0.567110);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][23], 2);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, IDCardTextDraw[playerid][23], 1);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][23], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, IDCardTextDraw[playerid][23], true);

    IDCardTextDraw[playerid][24] = CreatePlayerTextDraw(playerid, 373.800079, 256.777770, ReturnPlayerName(playerid));
    PlayerTextDrawLetterSize(playerid, IDCardTextDraw[playerid][24], 0.244500, 0.753777);
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][24], 0.000000, 214.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][24], 2);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][24], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][24], 0);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][24], 1);

    IDCardTextDraw[playerid][25] = CreatePlayerTextDraw(playerid, 224.099822, 208.378005, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, IDCardTextDraw[playerid][25], 187.000000, 62.000000);
    PlayerTextDrawAlignment(playerid, IDCardTextDraw[playerid][25], 1);
    PlayerTextDrawColor(playerid, IDCardTextDraw[playerid][25], 64);
    PlayerTextDrawSetShadow(playerid, IDCardTextDraw[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, IDCardTextDraw[playerid][25], 255);
    PlayerTextDrawFont(playerid, IDCardTextDraw[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, IDCardTextDraw[playerid][25], 0);

    for (new i = 0; i < 26; i++)
        PlayerTextDrawShow(playerid, IDCardTextDraw[playerid][i]);

    SelectTextDraw(playerid, X11_LIGHTBLUE);
    uiIDCardStatus[playerid] = true;
    return 1;
}