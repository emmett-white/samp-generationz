#if defined _INC_anims_movement_inc
    #endinput
#endif
#define _INC_anims_movement_inc

// Credits to: Southclaws

#include <YSI_Coding\y_hooks>

enum E_MOVEMENT_TYPE
{
	E_MOVEMENT_TYPE_UNKNOWN,
	E_MOVEMENT_TYPE_IDLE,
	E_MOVEMENT_TYPE_SITTING,
	E_MOVEMENT_TYPE_CROUCHING,
	E_MOVEMENT_TYPE_JUMPING,
	E_MOVEMENT_TYPE_WALKING,
	E_MOVEMENT_TYPE_RUNNING,
	E_MOVEMENT_TYPE_SPRINTING,
	E_MOVEMENT_TYPE_FALLING,
	E_MOVEMENT_TYPE_LANDING,
	E_MOVEMENT_TYPE_SWIMMING,
	E_MOVEMENT_TYPE_DIVING,
};

static
	E_MOVEMENT_TYPE:MovementType[MAX_PLAYERS],
	PlayerText:movementTextDraw[MAX_PLAYERS];

// static MovementTypeName[][] =
// {
// 	"Unknown",
// 	"Idle",
// 	"Sitting",
// 	"Crouching",
// 	"Jumping",
// 	"Walking",
// 	"Running",
// 	"Stopping",
// 	"Sprinting",
// 	"Climbing",
// 	"Falling",
// 	"Landing",
// 	"Swimming",
// 	"Diving"
// };

stock Movement_CreateUI(const playerid, bool:status)
{
	if (!status)
	{
		PlayerTextDrawDestroy(playerid, movementTextDraw[playerid]);
		movementTextDraw[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
	}

	movementTextDraw[playerid] = CreatePlayerTextDraw(playerid, 21.799997, 418.600036, "_");
	PlayerTextDrawLetterSize(playerid, movementTextDraw[playerid], 0.165500, 0.710222);
	PlayerTextDrawAlignment(playerid, movementTextDraw[playerid], 2);
	PlayerTextDrawColor(playerid, movementTextDraw[playerid], -1);
	PlayerTextDrawSetShadow(playerid, movementTextDraw[playerid], 0);
	PlayerTextDrawSetOutline(playerid, movementTextDraw[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, movementTextDraw[playerid], 255);
	PlayerTextDrawFont(playerid, movementTextDraw[playerid], 1);
	PlayerTextDrawSetProportional(playerid, movementTextDraw[playerid], 1);

	PlayerTextDrawShow(playerid, movementTextDraw[playerid]);
	return 1;
}

PTASK__ movementUpdate[100](playerid)
{
	new
		animidx = GetPlayerAnimationIndex(playerid),
		k,
		ud,
		lr;

	GetPlayerKeys(playerid, k, ud, lr);

	if(animidx == 1231)
	{
		if(k & KEY_WALK)
			MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;

		else if(k & KEY_SPRINT)
			MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;

		else if(k & KEY_JUMP)
			MovementType[playerid] = E_MOVEMENT_TYPE_JUMPING;

		else
			MovementType[playerid] = E_MOVEMENT_TYPE_RUNNING;
	}

	switch (animidx)
	{
		case 1189: MovementType[playerid] = E_MOVEMENT_TYPE_IDLE;
		case 43: MovementType[playerid] = E_MOVEMENT_TYPE_SITTING;
		case 875: MovementType[playerid] = E_MOVEMENT_TYPE_SITTING;
		case 876: MovementType[playerid] = E_MOVEMENT_TYPE_SITTING;
		case 877: MovementType[playerid] = E_MOVEMENT_TYPE_SITTING;
		case 878: MovementType[playerid] = E_MOVEMENT_TYPE_SITTING;
		case 1274: MovementType[playerid] = E_MOVEMENT_TYPE_CROUCHING;
		case 1195: MovementType[playerid] = E_MOVEMENT_TYPE_JUMPING;
		case 1197: MovementType[playerid] = E_MOVEMENT_TYPE_JUMPING;
		case 1198: MovementType[playerid] = E_MOVEMENT_TYPE_JUMPING;
		case 1458: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 462: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 663: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 910: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 1247: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 1246: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 1248: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 1196: MovementType[playerid] = E_MOVEMENT_TYPE_SPRINTING;
		case 463: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 465: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 466: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 467: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 468: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 469: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 470: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1217: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1257: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1256: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1258: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1259: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1260: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1261: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1262: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1263: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1264: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1265: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1266: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1267: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1268: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1269: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1270: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1271: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1272: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1273: MovementType[playerid] = E_MOVEMENT_TYPE_WALKING;
		case 1130: MovementType[playerid] = E_MOVEMENT_TYPE_FALLING;
		case 1132: MovementType[playerid] = E_MOVEMENT_TYPE_FALLING;
		case 1250: MovementType[playerid] = E_MOVEMENT_TYPE_FALLING;
		case 1129: MovementType[playerid] = E_MOVEMENT_TYPE_LANDING;
		case 1133: MovementType[playerid] = E_MOVEMENT_TYPE_LANDING;
		case 1208: MovementType[playerid] = E_MOVEMENT_TYPE_LANDING;
		case 1538: MovementType[playerid] = E_MOVEMENT_TYPE_SWIMMING;
		case 1539: MovementType[playerid] = E_MOVEMENT_TYPE_SWIMMING;
		case 1542: MovementType[playerid] = E_MOVEMENT_TYPE_SWIMMING;
		case 1540: MovementType[playerid] = E_MOVEMENT_TYPE_DIVING;
		case 1541: MovementType[playerid] = E_MOVEMENT_TYPE_DIVING;
		case 1544: MovementType[playerid] = E_MOVEMENT_TYPE_DIVING;
		default: MovementType[playerid] = E_MOVEMENT_TYPE_UNKNOWN;
	}

	va_PlayerTextDrawSetString(playerid, movementTextDraw[playerid], "%s", GetMovementTypeName(playerid));
	return;
}

stock GetMovementTypeName(const playerid)
{
	static tmpString[24];
	switch (_:MovementType[playerid])
	{
		case E_MOVEMENT_TYPE_UNKNOWN: tmpString = "Unknown";
		case E_MOVEMENT_TYPE_IDLE: tmpString = "Idle";
		case E_MOVEMENT_TYPE_SITTING: tmpString = "Sitting";
		case E_MOVEMENT_TYPE_CROUCHING: tmpString = "Crouching";
		case E_MOVEMENT_TYPE_JUMPING: tmpString = "Jumping";
		case E_MOVEMENT_TYPE_WALKING: tmpString = "Walking";
		case E_MOVEMENT_TYPE_RUNNING: tmpString = "Running";
		case E_MOVEMENT_TYPE_SPRINTING: tmpString = "Sprinting";
		case E_MOVEMENT_TYPE_FALLING: tmpString = "Falling";
		case E_MOVEMENT_TYPE_LANDING: tmpString = "Landing";
		case E_MOVEMENT_TYPE_SWIMMING: tmpString = "Swimming";
		case E_MOVEMENT_TYPE_DIVING: tmpString = "Diving";
	}
	return tmpString;
}

stock GetPlayerMovementState(const playerid, &E_MOVEMENT_TYPE:type)
{
	if(!IsPlayerConnected(playerid))
		return 1;

	type = MovementType[playerid];

	return 0;
}