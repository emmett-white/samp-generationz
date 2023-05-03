#if defined _INC_rank_init_inc
    #endinput
#endif
#define _INC_rank_init_inc

#include <YSI_Coding\y_hooks>

new rankID[MAX_PLAYERS],
	rankValue[MAX_PLAYERS];

#define Rank_GetUniqueID(%0) rankID[%0]

enum E_RANK_DATA
{
	E_RANK_PLAYER = 1,
	E_RANK_MODERATOR,
	E_RANK_ADMINISTRATOR
};

hook OnPlayerConnect(playerid)
{
	task_await(
		MySQL_QueryS(
			str_format(
				"SELECT * FROM ranks WHERE rank_name = '%e'", ReturnPlayerName(playerid)
			)
		)
	);

	if (!cache_num_rows())
		return Rank_Create(playerid, -1, "igrac");

	static tmpString[MAX_PLAYER_NAME];
	cache_get_value_name_int(0, "rank_id", rankID[playerid]);
	cache_get_value_name(0, "rank_value", tmpString);
	Rank_Set(playerid, -1, tmpString);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerText(playerid, text[])
{
    new tmp_str[128];
    if (Rank_GetID(playerid) == Rank_Player())
        format(tmp_str, sizeof(tmp_str), "{C0C0C0}[%d]"LIGHTGREEN"%s kaze {C0C0C0}{FFFFFF} %s", playerid, ReturnPlayerName(playerid), text);
    
    else if (Rank_GetID(playerid) == Rank_Moderator())
        format(tmp_str, sizeof(tmp_str), "{C0C0C0}[%d]"LIGHTGREEN"%s kaze {C0C0C0}[Moderator]{FFFFFF} %s", playerid, ReturnPlayerName(playerid), text);

    else
        format(tmp_str, sizeof(tmp_str), "{C0C0C0}[%d]"LIGHTGREEN"%s kaze {C0C0C0}[Administrator]{FFFFFF} %s", playerid, ReturnPlayerName(playerid), text);

    Rank_RadiusMessage(20.0, playerid, tmp_str, X11_WHITE, X11_WHITE, X11_WHITE, X11_WHITE, X11_WHITE);
    return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerEnterCheckpoint(playerid)
{
	DisablePlayerCheckpoint(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

forward OnRankCreated(const playerid);
public OnRankCreated(const playerid)
{
    rankID[playerid] = cache_insert_id();
    return 1;
}

stock Rank_Player() return _:E_RANK_PLAYER;
stock Rank_Moderator() return _:E_RANK_MODERATOR;
stock Rank_Administrator() return _:E_RANK_ADMINISTRATOR;
stock Rank_GetID(const playerid) return rankValue[playerid];

stock Rank_Create(const targetid, const playerid, const string: rank[])
{
	rankValue[targetid] = Rank_GetIDByName(rank);

	new String: str_query_update = str_format("INSERT INTO ranks (rank_name, rank_value) VALUES ('%e', '%e')", ReturnPlayerName(targetid), rank);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update, "OnRankCreated", "d", targetid);

	if (IsPlayerConnected(playerid))
	{
		SendInfoMsgF(playerid, "Postavili ste igracu %s rank %s.", ReturnPlayerName(targetid), rank);
		SendInfoMsgF(targetid, "Administrator %s Vam je postavio rank %s.", ReturnPlayerName(playerid), rank);
	}

	else
		SendInfoMsgF(targetid, "Administrator Vam je postavio rank %s.", rank);

	if (!strcmp(rank, "igrac"))
		Account_SetSkin(targetid, Account_GetGender(targetid) == 1 ? 240 : 193);
	else if (!strcmp(rank, "moderator"))
		Account_SetSkin(targetid, Account_GetGender(targetid) == 1 ? 171 : 169);
	else if (!strcmp(rank, "admin"))
		Account_SetSkin(targetid, Account_GetGender(targetid) == 1 ? 217 : 192);
	return 1;
}

stock Rank_Set(const targetid, const playerid, const string: rank[])
{
    rankValue[targetid] = Rank_GetIDByName(rank);

    new String: str_query_update = str_format(
        "UPDATE ranks SET rank_value = '%e' WHERE rank_id = '%d'",
        rank, Rank_GetUniqueID(targetid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);

    if (IsPlayerConnected(playerid))
	{
		SendInfoMsgF(playerid, "Postavili ste igracu %s rank %s.", ReturnPlayerName(targetid), rank);
		SendInfoMsgF(targetid, "Administrator %s Vam je postavio rank %s.", ReturnPlayerName(playerid), rank);
	}

	else
		SendInfoMsgF(targetid, "Administrator Vam je postavio rank %s.", rank);

	if (!strcmp(rank, "igrac"))
		Account_SetSkin(targetid, Account_GetGender(targetid) == 1 ? 240 : 193);
	else if (!strcmp(rank, "moderator"))
		Account_SetSkin(targetid, Account_GetGender(targetid) == 1 ? 171 : 169);
	else if (!strcmp(rank, "admin"))
		Account_SetSkin(targetid, Account_GetGender(targetid) == 1 ? 217 : 192);
    return 1;
}

stock Rank_GetIDByName(const string: rank[])
{
	static tmpInt;
	if (!strcmp(rank, "igrac", false))
		return tmpInt = _:E_RANK_PLAYER;
	else if (!strcmp(rank, "moderator", false))
		return tmpInt = _:E_RANK_MODERATOR;
	else if (!strcmp(rank, "admin", false))
		return tmpInt = _:E_RANK_ADMINISTRATOR;
	return tmpInt;
}

stock Rank_GetNameByID(const rankid)
{
	static tmpString[MAX_PLAYER_NAME];
	switch (rankid)
	{
		case 1: tmpString = "Igrac";
		case 2: tmpString = "Moderator";
		case 3: tmpString = "Admin";
	}
	return tmpString;
}

stock Rank_StaffMessage(const colour, const string: msg[], va_args<>)
{
	foreach (new i: Player)
		if (Rank_GetID(i) == Rank_Moderator() || Rank_GetID(i) == Rank_Administrator())
			return va_SendClientMessage(i, colour, va_return(msg, va_start<2>));
	return 0;
}

stock Rank_RadiusMessage(Float: radi, playerid, const string: string[], c1, c2, c3, c4, c5)
{
	if (IsPlayerConnected(playerid))
    {
		new
            Float: pPosX, Float: pPosY, Float: pPosZ,
		    Float: oldpPosX, Float: oldpPosY, Float: oldpPosZ,
		    Float: tmpPosX, Float: tmpPosY, Float: tmpPosZ;

		GetPlayerPos(playerid, oldpPosX, oldpPosY, oldpPosZ);
		foreach(new i: Player)
        {
            if (GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i))
            {
                GetPlayerPos(i, pPosX, pPosY, pPosZ);
                
                tmpPosX = (oldpPosX -pPosX);
                tmpPosY = (oldpPosY -pPosY);
                tmpPosZ = (oldpPosZ -pPosZ);
                
                if(((tmpPosX < radi/16) && (tmpPosX > -radi/16)) && ((tmpPosY < radi/16) && (tmpPosY > -radi/16)) && ((tmpPosZ < radi/16) && (tmpPosZ > -radi/16)))
                    SendClientMessage(i, c1, string);

                else if(((tmpPosX < radi/8) && (tmpPosX > -radi/8)) && ((tmpPosY < radi/8) && (tmpPosY > -radi/8)) && ((tmpPosZ < radi/8) && (tmpPosZ > -radi/8)))
                    SendClientMessage(i, c2, string);

                else if(((tmpPosX < radi/4) && (tmpPosX > -radi/4)) && ((tmpPosY < radi/4) && (tmpPosY > -radi/4)) && ((tmpPosZ < radi/4) && (tmpPosZ > -radi/4)))
                    SendClientMessage(i, c3, string);

                else if(((tmpPosX < radi/2) && (tmpPosX > -radi/2)) && ((tmpPosY < radi/2) && (tmpPosY > -radi/2)) && ((tmpPosZ < radi/2) && (tmpPosZ > -radi/2)))
                    SendClientMessage(i, c4, string);

                else if(((tmpPosX < radi) && (tmpPosX > -radi)) && ((tmpPosY < radi) && (tmpPosY > -radi)) && ((tmpPosZ < radi) && (tmpPosZ > -radi)))
                    SendClientMessage(i, c5, string);
            }
		}
	}
    
	return 1;
}

PTASK__ FIX_StaffVehicle[1500](playerid)
{
    if ((Rank_GetID(playerid) == Rank_Moderator()) || (Rank_GetID(playerid) == Rank_Administrator()) && IsPlayerInAnyVehicle(playerid))
    {
        RepairVehicle(GetPlayerVehicleID(playerid));
        SetVehicleHealth(GetPlayerVehicleID(playerid), 1000.00);
    }
}

// Include other module
#include <rank_commands>
#include <player/player_functions>