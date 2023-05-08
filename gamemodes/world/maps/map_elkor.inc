#if defined _INC_map_elkor_inc
	#endinput
#endif
#define _INC_map_elkor_inc

static elkorActor[5];

stock Elkor_RemoveObjects(const playerid)
{
	RemoveBuildingForPlayer(playerid, 5957, 1278.468, -1189.507, 11.898, 0.250);
	RemoveBuildingForPlayer(playerid, 5740, 1278.468, -1189.507, 11.898, 0.250);
	return 1;
}

stock Elkor_DestroyActors()
{
	for (new i = 0; i < sizeof(elkorActor); i++)
		DestroyDynamicActor(elkorActor[i]);
	return 1;
}

stock Elkor_CreateObjects()
{
	// Init actors
	elkorActor[0] = CreateDynamicActor(11, 1307.5400,-1194.3821,23.7049,315.0105);
	elkorActor[1] = CreateDynamicActor(29, 1312.7983,-1193.9840,23.6849,264.4381);
	elkorActor[2] = CreateDynamicActor(12, 1314.5245,-1188.8625,23.7329,204.6535);
	elkorActor[3] = CreateDynamicActor(20, 1311.5276,-1191.7567,23.7329,244.1339);
	elkorActor[4] = CreateDynamicActor(26, 1311.6807,-1184.5551,23.7049,93.5679);

	for (new i = 0; i < sizeof(elkorActor); i++)
		ApplyActorAnimation(elkorActor[i], "MISC","Idle_Chat_02",4.0,1,0,0,1,1);

	new elkorext;
	elkorext = CreateDynamicObject(5740,1278.468,-1189.507,11.898,0.000,0.000,0.000);
	SetDynamicObjectMaterial(elkorext, 0, 6863, "vgsnbuild07", "vgndwntwn2_256_256", 0);
	SetDynamicObjectMaterial(elkorext, 2, 6863, "vgsnbuild07", "vgndwntwn2_256_256", 0);
	SetDynamicObjectMaterial(elkorext, 3, 6863, "vgsnbuild07", "vgndwntwn2_256_256", 0);
	SetDynamicObjectMaterial(elkorext, 4, 1649, "wglass", "carshowwin2", 0);
	elkorext = CreateDynamicObject(18762,1311.837,-1182.191,24.159,0.000,0.000,63.474);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1319.069,-1189.347,24.210,0.000,0.000,23.066);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1318.619,-1188.391,26.202,0.000,90.000,115.126);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1315.327,-1183.823,24.165,0.000,0.000,54.942);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1317.744,-1186.357,24.188,0.000,0.000,23.066);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1312.887,-1182.720,26.150,0.000,90.000,156.533);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1312.887,-1182.720,22.460,0.000,90.000,156.533);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(18762,1318.619,-1188.391,22.480,0.000,90.000,113.631);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(19375,1305.529,-1195.745,22.619,0.000,90.000,61.465);
	SetDynamicObjectMaterial(elkorext, 0, 14651, "ab_trukstpd", "Bow_bar_flooring", 0);
	elkorext = CreateDynamicObject(19375,1311.013,-1187.386,22.619,0.000,90.000,330.253);
	SetDynamicObjectMaterial(elkorext, 0, 14651, "ab_trukstpd", "Bow_bar_flooring", 0);
	elkorext = CreateDynamicObject(19375,1313.722,-1191.557,22.599,0.000,90.000,9.868);
	SetDynamicObjectMaterial(elkorext, 0, 14651, "ab_trukstpd", "Bow_bar_flooring", 0);
	elkorext = CreateDynamicObject(19376,1305.648,-1195.749,26.435,0.000,90.000,317.465);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19376,1309.535,-1188.618,26.455,0.000,90.000,317.465);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19377,1315.939,-1192.392,21.281,0.000,0.000,317.237);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(19377,1312.612,-1195.661,21.281,0.000,0.000,300.456);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(19377,1305.263,-1195.233,21.281,0.000,0.000,231.905);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(19377,1308.056,-1185.545,21.281,0.000,0.000,130.050);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(19377,1304.446,-1189.818,21.281,0.000,0.000,158.366);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -16763905);
	elkorext = CreateDynamicObject(19361,1313.792,-1184.828,26.470,0.000,90.000,63.277);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19361,1315.775,-1186.250,26.450,0.000,90.000,46.439);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19361,1316.462,-1188.714,26.450,0.000,90.000,25.740);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19365,1316.708,-1184.667,24.907,0.000,0.000,44.996);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19365,1316.425,-1185.229,25.348,0.000,0.000,47.942);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19365,1316.694,-1184.682,21.496,0.000,0.000,44.996);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19365,1316.425,-1185.229,21.867,0.000,0.000,47.942);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19376,1312.178,-1188.895,26.435,0.000,90.000,317.465);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19379,1308.015,-1185.612,18.848,0.000,0.000,130.050);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19379,1306.095,-1195.854,18.848,0.000,0.000,231.859);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19379,1303.550,-1192.116,18.848,0.000,0.000,158.366);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19379,1311.264,-1196.407,18.848,0.000,0.000,300.456);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19379,1315.536,-1192.774,18.848,0.000,0.000,317.237);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2208,1306.902,-1192.752,22.495,0.000,0.000,-41.499);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(18762,1309.153,-1194.666,21.390,0.000,0.000,320.361);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -6750208);
	elkorext = CreateDynamicObject(19454,1311.531,-1189.934,22.647,0.000,90.000,315.580);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -3407821);
	elkorext = CreateDynamicObject(19454,1312.895,-1188.556,22.627,0.000,90.000,315.580);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -3407821);
	elkorext = CreateDynamicObject(18762,1306.483,-1192.319,21.390,0.000,0.000,320.361);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", -6750208);
	elkorext = CreateDynamicObject(19482,1316.155,-1183.997,27.100,0.000,0.000,45.599);
	SetDynamicObjectMaterialText(elkorext, 0, "Elkor ", 50, "Ariel", 40, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(2439,1312.325,-1186.149,22.687,0.000,0.000,225.124);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1309.990,-1184.441,22.687,0.000,0.000,39.084);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1309.755,-1188.725,22.687,0.000,0.000,225.124);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1311.637,-1186.848,22.687,0.000,0.000,225.124);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1309.065,-1189.431,22.687,0.000,0.000,225.124);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1307.177,-1186.857,22.687,0.000,0.000,39.084);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1307.876,-1186.299,22.687,0.000,0.000,39.084);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1315.079,-1189.284,22.687,0.000,0.000,45.289);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1312.006,-1192.424,22.687,0.000,0.000,45.289);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1312.669,-1191.770,22.687,0.000,0.000,45.289);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1314.420,-1189.951,22.687,0.000,0.000,45.289);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1309.239,-1185.058,22.687,0.000,0.000,39.084);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1316.927,-1190.874,22.687,0.000,0.000,228.375);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(2439,1314.161,-1193.950,22.687,0.000,0.000,227.321);
	SetDynamicObjectMaterial(elkorext, 0, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 2, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 3, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 4, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 5, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 6, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 7, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 8, 10765, "airportgnd_sfse", "white", 0);
	SetDynamicObjectMaterial(elkorext, 9, 10765, "airportgnd_sfse", "white", 0);
	elkorext = CreateDynamicObject(19482,1306.462,-1191.646,21.893,0.000,0.000,48.099);
	SetDynamicObjectMaterialText(elkorext, 0, "Dobrodosli", 120, "Ariel", 24, 1, -10066329, 0, 0);
	elkorext = CreateDynamicObject(19482,1305.372,-1195.165,24.133,0.000,0.000,51.700);
	SetDynamicObjectMaterialText(elkorext, 0, "Elkor", 60, "Ariel", 40, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19482,1308.890,-1184.969,23.655,0.000,0.000,-49.999);
	SetDynamicObjectMaterialText(elkorext, 0, "By Dre", 120, "Ariel", 40, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19482,1312.681,-1195.879,23.555,0.000,0.000,139.099);
	SetDynamicObjectMaterialText(elkorext, 0, "ASUS", 120, "Ariel", 30, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19482,1311.098,-1183.091,23.505,0.000,0.000,-48.499);
	SetDynamicObjectMaterialText(elkorext, 0, "Samsung", 120, "Ariel", 30, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19482,1308.835,-1185.040,24.603,0.000,0.000,-49.199);
	SetDynamicObjectMaterialText(elkorext, 0, "Niske cene!", 90, "Ariel", 40, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19482,1315.850,-1192.344,23.384,0.000,0.299,137.099);
	SetDynamicObjectMaterialText(elkorext, 0, "Toshiba", 100, "Ariel", 30, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19482,1315.675,-1192.516,24.373,0.000,0.000,137.000);
	SetDynamicObjectMaterialText(elkorext, 0, "Samo kod nas!", 100, "Ariel", 40, 1, -1, 0, 0);
	elkorext = CreateDynamicObject(19375,1300.451,-1234.201,13.126,0.000,0.000,92.500);
	SetDynamicObjectMaterial(elkorext, 0, 6863, "vgsnbuild07", "vgndwntwn1_256_256", 0);
	elkorext = CreateDynamicObject(19375,1309.437,-1234.462,12.986,0.000,0.000,89.399);
	SetDynamicObjectMaterial(elkorext, 0, 6863, "vgsnbuild07", "vgndwntwn1_256_256", 0);
	elkorext = CreateDynamicObject(19375,1314.173,-1234.412,13.006,0.000,0.000,92.499);
	SetDynamicObjectMaterial(elkorext, 0, 6863, "vgsnbuild07", "vgndwntwn1_256_256", 0);
	elkorext = CreateDynamicObject(1536,1315.746,-1184.718,22.666,0.000,0.000,318.493);
	elkorext = CreateDynamicObject(19362,1315.441,-1185.881,22.570,0.000,90.000,42.212);
	elkorext = CreateDynamicObject(1536,1316.169,-1184.193,22.506,0.000,0.000,315.135);
	elkorext = CreateDynamicObject(1536,1316.275,-1184.194,22.506,0.000,0.000,315.135);
	elkorext = CreateDynamicObject(1671,1306.890,-1194.651,23.117,0.000,0.000,119.050);
	elkorext = CreateDynamicObject(19893,1307.780,-1193.445,23.345,0.000,0.000,343.484);
	elkorext = CreateDynamicObject(18873,1312.714,-1191.792,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18873,1311.997,-1192.465,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18873,1312.351,-1192.182,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(19893,1313.995,-1193.870,23.708,0.000,0.000,239.048);
	elkorext = CreateDynamicObject(18872,1315.169,-1189.397,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18872,1314.470,-1190.002,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18872,1314.856,-1189.668,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(19894,1316.791,-1190.834,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18874,1312.223,-1186.448,23.712,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18874,1311.593,-1186.909,23.712,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18874,1311.866,-1186.358,23.712,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(19422,1307.461,-1186.459,23.732,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(19422,1307.054,-1186.996,23.732,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(19422,1307.476,-1186.895,23.732,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(19422,1307.886,-1186.436,23.732,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18870,1309.927,-1188.581,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18870,1309.571,-1188.757,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18870,1309.312,-1189.203,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18870,1308.937,-1189.351,23.711,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(14699,1316.435,-1189.215,24.955,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(14699,1310.655,-1190.101,24.955,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(14699,1309.722,-1195.133,24.955,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(14699,1314.622,-1194.120,24.955,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18874,1310.037,-1184.596,23.715,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18874,1309.342,-1184.918,23.705,0.000,0.000,0.000);
	elkorext = CreateDynamicObject(18874,1309.051,-1185.184,23.712,0.000,0.000,0.000);

	CreateDynamicMapIcon(1317.6239,-1183.9794,23.5906, 56, X11_WHITE);

	CreateDynamic3DTextLabel("["WHITE"ELKOR"MAIN_COLOR"]\n\
        "WHITE"Za ulaz pritisnite \n"MAIN_COLOR"F/Enter", MAIN_COLOR_HEX, 1317.6239,-1183.9794,23.5906, 15.00
    );
    CreateDynamicPickup(19132, 1, 1317.6239,-1183.9794,23.5906, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("["WHITE"ELKOR"MAIN_COLOR"]\n\
        "WHITE"Za izlaz pritisnite \n"MAIN_COLOR"F/Enter", MAIN_COLOR_HEX, 1315.5989,-1185.9348,23.7129, 5.00
    );
    CreateDynamicPickup(19132, 1, 1315.5989,-1185.9348,23.7129, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("["WHITE"ELKOR"MAIN_COLOR"]\n\
        "WHITE"Da kupite mobilni kucajte\n"MAIN_COLOR"/kupimobilni", MAIN_COLOR_HEX, 1310.2061,-1189.7286,23.7329, 5.00
    );
    CreateDynamicPickup(1239, 1, 1310.2061,-1189.7286,23.7329, .streamdistance = 30.00);

    CreateDynamic3DTextLabel("["WHITE"ELKOR"MAIN_COLOR"]\n\
        "WHITE"Da kupite mp3 player kucajte\n"MAIN_COLOR"/kupimp3", MAIN_COLOR_HEX, 1308.2550,-1187.2788,23.7049, 5.00
    );
    CreateDynamicPickup(1239, 1, 1308.2550,-1187.2788,23.7049, .streamdistance = 30.00);
	return 1;
}