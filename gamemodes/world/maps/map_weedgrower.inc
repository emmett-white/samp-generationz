#if defined _INC_map_weedgrower_inc
    #endinput
#endif
#define _INC_map_weedgrower_inc

stock WeedGrower_RemoveObjects(const playerid)
{
    RemoveBuildingForPlayer(playerid, 3300, 2513.2109, -962.3281, 82.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 3299, 2494.9531, -959.6328, 81.6875, 0.25);
    RemoveBuildingForPlayer(playerid, 1410, 2488.8672, -968.4609, 81.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 1407, 2493.5859, -968.5078, 81.8438, 0.25);
    RemoveBuildingForPlayer(playerid, 1410, 2498.1875, -968.4531, 81.9297, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 2521.3594, -966.9297, 81.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 1410, 2486.6094, -966.0547, 81.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 1407, 2486.6641, -961.3359, 81.8281, 0.25);
    RemoveBuildingForPlayer(playerid, 1410, 2486.6094, -956.7344, 81.8594, 0.25);
    RemoveBuildingForPlayer(playerid, 3283, 2494.9531, -959.6328, 81.6875, 0.25);
    RemoveBuildingForPlayer(playerid, 3285, 2513.2109, -962.3281, 82.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1410, 2486.6563, -952.0859, 81.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 617, 2522.1484, -952.4531, 80.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 1407, 2486.7031, -947.3750, 81.9766, 0.25);
    RemoveBuildingForPlayer(playerid, 1410, 2486.6484, -942.7734, 81.9375, 0.25);
    return 1;
}

stock WeedGrower_CreateObjects()
{
    CreateDynamicObject(3049, 2509.35815, -968.56342, 83.41609,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3049, 2500.43384, -968.47064, 83.41609,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3049, 2496.01123, -968.48383, 83.37410,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(3049, 2491.60449, -968.47638, 83.26910,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(3049, 2487.26758, -968.51001, 83.07310,   0.00000, 2.00000, -90.00000);
    CreateDynamicObject(3049, 2487.26880, -964.04224, 83.07310,   0.00000, 2.00000, -90.00000);
    CreateDynamicObject(3049, 2487.27881, -959.57269, 83.07310,   0.00000, 2.00000, -90.00000);
    CreateDynamicObject(3049, 2487.29370, -955.22552, 83.23910,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3049, 2487.32861, -950.81659, 83.23910,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(3049, 2491.78662, -950.81232, 83.23910,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(3049, 2496.21631, -950.80365, 83.23910,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(3049, 2513.81665, -968.56506, 83.41609,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3049, 2518.21240, -968.31885, 83.41609,   0.00000, 0.00000, 3.00000);
    CreateDynamicObject(3049, 2522.67773, -968.00293, 83.41609,   0.00000, 0.00000, 3.96000);
    CreateDynamicObject(3049, 2522.37671, -963.55249, 83.41610,   0.00000, 0.00000, 92.99995);
    CreateDynamicObject(3049, 2522.17896, -959.14172, 83.41610,   0.00000, 0.00000, 92.99995);
    CreateDynamicObject(3049, 2521.77686, -954.74017, 83.41610,   0.00000, 0.00000, 95.15993);
    CreateDynamicObject(3049, 2500.68433, -950.79541, 83.23910,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(3049, 2505.09155, -950.79492, 83.23910,   0.00000, 0.00000, 179.58003);
    CreateDynamicObject(3049, 2509.49194, -950.81738, 83.23920,   0.00000, 0.00000, 179.58000);
    CreateDynamicObject(3049, 2513.89160, -950.85693, 83.23920,   0.00000, 0.00000, 175.62016);
    CreateDynamicObject(3049, 2518.54053, -951.36096, 83.23920,   0.00000, 0.00000, 136.08032);
    CreateDynamicObject(8168, 2491.54053, -953.99103, 83.05532,   0.00000, 0.00000, 16.61999);
    CreateDynamicObject(19377, 2492.12793, -961.71539, 81.22640,   -1.00000, 90.00000, 90.00000);
    CreateDynamicObject(3041, 2488.30957, -958.40619, 81.20650,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2180, 2488.09497, -960.91577, 81.22790,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(19559, 2488.10376, -960.95703, 81.25299,   -90.00000, 0.00000, -1.08000);
    CreateDynamicObject(19559, 2488.21899, -961.66760, 81.25299,   -90.00000, 0.00000, 58.56000);
    CreateDynamicObject(19559, 2487.89551, -960.86401, 82.00510,   -90.00000, 0.00000, -1.08000);
    CreateDynamicObject(19559, 2488.11523, -961.91803, 82.00510,   -90.00000, 0.00000, 136.08000);
    CreateDynamicObject(19559, 2488.07373, -961.46399, 82.00510,   -90.00000, 0.00000, 126.42008);
    // grass objects
    // CreateDynamicObject(3409, 2514.24731, -956.15710, 80.49080,   0.00000, 0.00000, 0.54000);
    // CreateDynamicObject(3409, 2519.61450, -956.19531, 80.49080,   0.00000, 0.00000, 0.54000);
    // CreateDynamicObject(3409, 2524.19604, -956.06152, 80.49080,   0.00000, 0.00000, 0.54000);
    // CreateDynamicObject(3409, 2524.18213, -962.31818, 80.49080,   0.00000, 0.00000, 0.54000);
    // CreateDynamicObject(3409, 2519.54468, -962.49628, 80.49080,   0.00000, 0.00000, 0.54000);
    // CreateDynamicObject(3409, 2514.50220, -962.61890, 80.49080,   0.00000, 0.00000, 0.54000);

    // new grass objects
    // CreateDynamicObject(823, 2508.31152, -955.77863, 79.10620,   0.00000, 0.00000, 0.00000);
    // CreateDynamicObject(823, 2513.63013, -955.48462, 79.10620,   0.00000, 0.00000, 0.00000);
    // CreateDynamicObject(823, 2517.85278, -956.24628, 79.10620,   0.00000, 0.00000, 57.60000);
    // CreateDynamicObject(823, 2517.80664, -962.90759, 79.10620,   0.00000, 0.00000, 57.60000);
    // CreateDynamicObject(823, 2512.61060, -962.77399, 79.10620,   0.00000, 0.00000, 57.60000);
    // CreateDynamicObject(823, 2508.92529, -962.35120, 79.10623,   0.00000, 0.00000, -15.48000);
    return 1;
}