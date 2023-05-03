#if defined _INC_org_init_inc
    #endinput
#endif
#define _INC_org_init_inc

#include <org_lspd>

static
    orgID[MAX_PLAYERS],
    orgRank[MAX_PLAYERS];

stock Org_GetID(const playerid) return orgID[playerid];
stock Org_SetID(const playerid, const orgid)
{
    orgID[playerid] = orgid;

    if (orgid)
        Org_SetRank(playerid, 1);

    new String: str_query_update = str_format(
        "UPDATE characters SET char_orgid = '%d' WHERE char_id = '%d'",
        Org_GetID(playerid), Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);
    return 1;
}

stock Org_GetRank(const playerid) return orgRank[playerid];
stock Org_SetRank(const playerid, const rankid)
{
    orgRank[playerid] = rankid;
    new String: str_query_update = str_format(
        "UPDATE characters SET char_orgrank = '%d' WHERE char_id = '%d'",
        Org_GetRank(playerid), Account_GetCharID(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);

    SendInfoMsgF(playerid, "Vi ste rank %d u organizaciji %s.", rankid, Org_GetNameByID(Org_GetID(playerid)));
    switch (Org_GetID(playerid))
    {
        case 1:
        {
            switch (rankid)
            {
                case 1:Account_SetSkin(playerid, 300), SetPlayerColor(playerid, X11_BLUE);
                case 2:Account_SetSkin(playerid, 301);
                case 3:Account_SetSkin(playerid, 302);
                case 4:Account_SetSkin(playerid, 310);
                case 5:Account_SetSkin(playerid, 305);
            }
        }
    }

    UI_UpdateInfoTD(playerid);
    return 1;
}

stock Org_GetNameByID(const orgid)
{
    static tmpString[MAX_PLAYER_NAME];
    switch (orgid)
    {
        case 1: tmpString = "Policija";
        case 2: tmpString = "Hitna pomoc";
        case 3: tmpString = "Vatrogasci";
        case 4: tmpString = "Groove Street Family";
        case 5: tmpString = "Ballas";
        case 6: tmpString = "Yakuza";
        case 7: tmpString = "La Cosa Nostra";
    }
    return tmpString;
}