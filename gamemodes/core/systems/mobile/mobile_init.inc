#if defined _INC_mobile_init_inc
	#endinput
#endif
#define _INC_mobile_init_inc

#include <YSI_Coding\y_hooks>

/*
	MOBILE OPTIONS
	1. View number
	2. Call player
	3. Message player
	4. Credit status
	5. Sms ad
	6. Drop mobile
*/

static
	mobileStatus[MAX_PLAYERS],
	mobileNumber[MAX_PLAYERS],
	mobileCredit[MAX_PLAYERS],
	mobilePower[MAX_PLAYERS];

stock Mobile_Get(const playerid) return mobileStatus[playerid];
stock Mobile_Set(const playerid, const status)
{
	mobileStatus[playerid] = status;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobile = '%d' WHERE char_id = '%d'",
		Mobile_Get(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_GetNumber(const playerid) return mobileNumber[playerid];
stock Mobile_SetNumber(const playerid, const number)
{
	mobileNumber[playerid] = number;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobilenum = '%d' WHERE char_id = '%d'",
		Mobile_GetNumber(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_GetCredit(const playerid) return mobileCredit[playerid];
stock Mobile_SetCredit(const playerid, const value)
{
	mobileNumber[playerid] = value;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobilecredit = '%d' WHERE char_id = '%d'",
		Mobile_GetCredit(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}

stock Mobile_GetPower(const playerid) return mobilePower[playerid];
stock Mobile_SetPower(const playerid, const status)
{
	mobileNumber[playerid] = status;
	new String:str_query_update = str_format(
		"UPDATE characters SET char_mobilepower = '%d' WHERE char_id = '%d'",
		Mobile_GetPower(playerid), Account_GetCharID(playerid)
	);
	mysql_tquery_s(MySQL_GetHandle(), str_query_update);
	return 1;
}