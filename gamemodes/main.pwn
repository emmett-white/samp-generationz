#define YSI_YES_HEAP_MALLOC
#define YSI_NO_VERSION_CHECK
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE

#define CGEN_MEMORY 50000
#define FOREACH_NO_BOTS
#define FOREACH_NO_STREAMED
#define PP_SYNTAX_AWAIT

#include <a_samp>
#include <a_mysql>
#include <crashdetect>
#include <PawnPlus>
#include <pp-mysql>
#include <Pawn.Regex>
#include <chrono>
#include <streamer>
#include <sscanf2>
#include <winteredition>
#include <progress2>
#include <strlib>

#include <YSI_Coding\y_malloc>
#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_iterate>
#include <YSI_Server\y_colours>
#include <YSI_Data\y_jaggedarray>
#include <YSI_Data\y_bit>

#undef X11_RED
#define X11_RED 0xFF0000FF

#include <jit>
#include <easy-dialog>
#include <altchat>
#include <FCNPC>

#include <database>
#include <settings>
#include <world_init>
#include <account_main>
#include <rank_init>
#include <player_init>
#include <job_init>
#include <we_main>
#include <rent_main>
#include <house_main>
#include <vehicle_main>
// #include <bench_main>
#include <hunger_main>
#include <kiosk_main>
#include <selection_main>
#include <org_main>
#include <gps_main>
#include <wanted_main>

main()
{
	printf("[INFO]: JIT %s", (IsJITPresent() ? ("nije prisutan.") : ("je prisutan.")));
	OnJITCompile();
	
	new
		Timestamp: ts = Timestamp: Now(),
		string: ts_fmt[24];

	TimeFormat(Timestamp: ts, ISO6801_TIME, string: ts_fmt, sizeof(ts_fmt));
	printf("[INFO]: Mod se uspesno ucitao u %s", string: ts_fmt);
}

forward OnJITCompile();
forward Bind_OnPlayerDisconnect(
	CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid
);

public OnJITCompile()
{
	printf("[INFO]: OnJITCompile->JIT %s", (IsJITPresent() ? ("nije prisutan.") : ("je prisutan.")));
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_ACTION)
	{
		new Float:vx, Float:vy, Float:vz;
		GetVehicleVelocity(GetPlayerVehicleID(playerid), vx, vy, vz);
		SetVehicleVelocity(GetPlayerVehicleID(playerid), vx * 1.2, vy *1.2, vz * 1.2);
    }
    return 1;
}