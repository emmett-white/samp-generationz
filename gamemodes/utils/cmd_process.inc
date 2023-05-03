#if defined _INC_cmd_process_inc
    #endinput
#endif
#define _INC_cmd_process_inc

#if defined CMD
    #undef CMD
#endif

// #define acmd:[%0]%1(%2,%3) cmd:%1(%2,%3) if (Admin_GetLevel(%2) < %0) return
	// SendErrorMsg(%2,"Niste ovlasceni!"); else

#define cmd:%1(%2) forward cmd_%1(%2); public cmd_%1(%2)
#define acmd:[%0]%1(%2,%3) cmd:%1(%2,%3) if (Admin_GetLevel(%2) < %0) return 0; else

stock Admin_GetLevel(const playerid) return playerid;

public OnPlayerCommandText(playerid, cmdtext[])
{
	new
		cmd[30],
		params[127],
		cmdfunction[64],
		result = 1;

	sscanf(cmdtext, "s[30]s[127]", cmd, params);

	for (new i, j = strlen(cmd); i < j; i++) {
		cmd[i] = tolower(cmd[i]);
	}

	format(cmdfunction, 64, "cmd_%s", cmd[1]);

	if(funcidx(cmdfunction) == -1) {
		new
			iLvl = Admin_GetLevel(playerid),
			iLoop = 5;

		while(iLoop > 0) {
			format(cmdfunction, 64, "acmd_%s_%d", cmd[1], iLoop);

			if(funcidx(cmdfunction) != -1) {
				break;
			}

			iLoop--;
		}

		if(iLoop == 0) {
			result = 0;
		}

		if(iLvl < iLoop) {
			result = 5;
		}
	}

	if(result == 1) {
		if(isnull(params)) {
			result = CallLocalFunction(cmdfunction, "is", playerid, "\1");
		}

		else {
			result = CallLocalFunction(cmdfunction, "is", playerid, params);
		}
	}
	
	return 1;
}