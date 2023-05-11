#if defined _INC_settings_inc
    #endinput
#endif
#define _INC_settings_inc

#define MAIN_COLOR          "{0f802c}"
#define MAIN_COLOR_HEX      0x0f802cFF
#define ADMIN_CHAT_COLOR    0xb5b04aFF
#define PURPLE_COLOR_HEX    0xC2A2DAAA

const
    MIN_PASSWORD_LENGTH =       6,
    MAX_PASSWORD_LENGTH =       24,
    MAX_LOGIN_ATTEMPTS =        3,
    MAX_ADMIN_LEVEL =           3,
    MAX_COMMANDS_PER_LEVEL =    15,
    ASKQ_TIMER_MIN =            2;
    
#define MAX_REASON_LENGTH       64
#define minmaxrandom(%0,%1) (random(%1) % (%1 - %0 + 1)) + %0

// Keys
#define KEY_AIM KEY_HANDBRAKE
#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define HOLDING(%0) ((newkeys & (%0)) == (%0))
#define RELEASED(%0) (((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

native Text3D:fmt_Create3DTextLabel(ConstString: text, colour, Float:position_x, Float:position_y, Float:position_z, Float:drawDistance, virtualWorld, testlos = 0) = Create3DTextLabel;
native STREAMER_TAG_3D_TEXT_LABEL:fmt_CreateDyn3DTextLabel(ConstString: text, color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0) = CreateDynamic3DTextLabel;

stock SendServerMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "GENERATIONZ: "WHITE"%s", message);

    return SendClientMessage(playerid, MAIN_COLOR_HEX, str);
}

stock SendServerMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "GENERATIONZ: "WHITE"%s", message);

    return va_SendClientMessage(playerid, MAIN_COLOR_HEX, va_return(str, va_start<2>));
}

stock SendCustomMsgF(const playerid, const color, const string: message[], va_args<>)
{
    return va_SendClientMessage(playerid, color, va_return(message, va_start<3>));
}

stock SendCustomMsgToAllF(const color, const string: message[], va_args<>)
{
    return va_SendClientMessageToAll(color, va_return(message, va_start<2>));
}

stock SendServerMsgToAllF(const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "GENERATIONZ: "WHITE"%s", message);

    return va_SendClientMessageToAll(MAIN_COLOR_HEX, va_return(str, va_start<1>));
}

stock SendErrorMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "("RED"Greska"WHITE"!): %s", message);

    return SendClientMessage(playerid, -1, str);
}

stock SendErrorMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "("RED"Greska"WHITE"!): %s", message);

    return va_SendClientMessage(playerid, X11_RED, va_return(str, va_start<2>));
}

stock SendSyntaxMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "KORISTI: "WHITE"%s", message);

    return SendClientMessage(playerid, X11_YELLOW, str);
}

stock SendInfoMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "INFO: "LIGHTGRAY"%s", message);

    return SendClientMessage(playerid, X11_ORANGE, str);
}

stock SendInfoMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "INFO: "LIGHTGRAY"%s", message);

    return va_SendClientMessage(playerid, X11_ORANGE, va_return(str, va_start<2>));
}

stock SendInfoMsgToAll(const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "INFO: "LIGHTGRAY"%s", message);

    return SendClientMessageToAll(X11_ORANGE, str);
}

stock SendInfoMsgToAllF(const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "INFO: "LIGHTGRAY"%s", message);

    return va_SendClientMessageToAll(X11_ORANGE, va_return(str, va_start<1>));
}

// Helpful function that converts integer into string
stock itos(num)
{
    new
        str[128],
        rem,
        len = 0,
        n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }

    for (new i = 0; i < len; i++)
    {
        rem = num % 10;
        num /= 10;
        str[len - (i + 1)] = rem + '0';
    }

    str[len] = '\0';
    return str;
}