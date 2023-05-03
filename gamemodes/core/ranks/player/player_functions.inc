#if defined _INC_player_functions_inc
    #endinput
#endif
#define _INC_player_functions_inc

stock Player_ClearChat(const playerid, const adminid = INVALID_PLAYER_ID, const lines)
{
	new hour, minute, second, day, month, year;
	gettime(hour, minute, second);
	getdate(year, month, day);

	for (new j = 0; j < lines; j++)
		SendClientMessage(playerid, -1, " ");

	if (adminid == INVALID_PLAYER_ID)
		SendInfoMsg(playerid, "Chat je ociscen.");
	else
		SendInfoMsgF(playerid, "%s je ocistio chat.", ReturnPlayerName(adminid));

	SendServerMsgF(playerid, "Trenutno je [ "MAIN_COLOR"%02d:%02d:%02d - %d/%d/%d "WHITE"].", hour, minute, second, day, month, year);
	return 1;
}

stock Player_SplitName(const playerid, const part[] = "name" /* part = name/lastname */)
{
	new
		name[MAX_PLAYER_NAME],
		option;

	GetPlayerName(playerid, name, sizeof(name));
	option = (!strcmp(part, "name", false) ? 1 : !strcmp(part, "lastname", false) ? 2 : 0xFFFF);

	for (new i = 0; i < sizeof(name); i++)
	{
		if (name[i] == '_')
			strdel(name, option == 1 ? i : -1, option == 1 ? sizeof(name) - 1 : i);
	}
	return name;
}