#if defined _INC_map_mowerjob_inc
    #endinput
#endif
#define _INC_map_mowerjob_inc

stock Mower_RemoveObjects(const playerid)
{
    RemoveBuildingForPlayer(playerid, 727, 867.367, -1125.781, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 5872, 879.570, -1092.875, 26.156, 0.250);
    RemoveBuildingForPlayer(playerid, 5983, 820.367, -1102.906, 28.335, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 880.140, -1058.851, 23.796, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 914.359, -1125.781, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 853.054, -1125.781, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 830.242, -1123.132, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 885.218, -1113.578, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 826.968, -1078.539, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 941.687, -1094.687, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 945.734, -1126.765, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 853.226, -1084.289, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 727, 948.343, -1072.304, 22.695, 0.250);
    RemoveBuildingForPlayer(playerid, 728, 848.562, -1127.664, 22.765, 0.250);
    RemoveBuildingForPlayer(playerid, 732, 890.703, -1127.773, 22.820, 0.250);
    RemoveBuildingForPlayer(playerid, 732, 910.750, -1062.406, 22.820, 0.250);
    RemoveBuildingForPlayer(playerid, 728, 826.273, -1084.781, 22.765, 0.250);
    RemoveBuildingForPlayer(playerid, 728, 904.632, -1126.898, 22.765, 0.250);
    RemoveBuildingForPlayer(playerid, 728, 879.132, -1127.351, 22.765, 0.250);
    RemoveBuildingForPlayer(playerid, 728, 925.937, -1095.781, 22.765, 0.250);
    RemoveBuildingForPlayer(playerid, 732, 949.226, -1060.359, 25.335, 0.250);
    RemoveBuildingForPlayer(playerid, 5712, 814.414, -1100.671, 26.476, 0.250);
    RemoveBuildingForPlayer(playerid, 5710, 820.367, -1102.906, 28.335, 0.250);
    RemoveBuildingForPlayer(playerid, 717, 836.890, -1081.804, 23.007, 0.250);
    RemoveBuildingForPlayer(playerid, 5714, 856.171, -1076.757, 25.257, 0.250);
    RemoveBuildingForPlayer(playerid, 5713, 863.492, -1107.804, 28.757, 0.250);
    RemoveBuildingForPlayer(playerid, 717, 903.242, -1113.609, 23.156, 0.250);
    RemoveBuildingForPlayer(playerid, 717, 904.679, -1090.828, 23.281, 0.250);
    RemoveBuildingForPlayer(playerid, 5715, 905.148, -1092.828, 32.789, 0.250);
    RemoveBuildingForPlayer(playerid, 717, 924.257, -1091.671, 23.257, 0.250);
    RemoveBuildingForPlayer(playerid, 700, 948.523, -1110.835, 23.296, 0.250);
    RemoveBuildingForPlayer(playerid, 700, 948.679, -1095.945, 23.609, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 950.648, -1083.312, 23.296, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 950.648, -1117.304, 22.789, 0.250);
    return 1;
}

stock Mower_CreateObjects()
{
    new lawnmowerobj;
    lawnmowerobj = CreateDynamicObject(18762, 952.127990, -1110.164916, 25.081899, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.125427, -1109.196044, 30.048900, -0.041999, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.141723, -1096.481567, 25.081899, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.140380, -1096.478759, 30.072099, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18766, 952.133728, -1103.299926, 30.058799, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.129882, -1110.181274, 30.048900, 0.252000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.126525, -1108.775146, 30.048900, -0.041999, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.145629, -1097.446044, 30.069900, -0.041999, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(18762, 952.143127, -1098.169067, 30.069900, -0.041999, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    lawnmowerobj = CreateDynamicObject(7914, 952.202148, -1103.225830, 30.193439, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 7530, "vgngebuild", "vgngewall3_256", 0x00000000);
    SetDynamicObjectMaterialText(lawnmowerobj, 0, "KOSAC TRAVE", 80, "Ariel", 25, 1, 0xFF000000, 0x00000000, 1);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.311523, 28.722732, 90.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1106.873291, 28.722732, 90.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1104.451538, 28.722732, 89.999992, 89.999992, -89.999992, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1102.013305, 28.722732, 89.999992, 89.999992, -89.999992, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1104.451538, 31.732749, 89.999992, 89.999992, -89.999977, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1102.013305, 31.732749, 89.999992, 89.999992, -89.999977, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.322265, 31.732749, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1106.884033, 31.732749, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1099.603149, 31.732749, 89.999992, 89.999992, -89.999977, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1099.603149, 28.722751, 89.999992, 89.999992, -89.999977, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1097.152709, 31.172752, 180.000000, 180.000000, -89.999977, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1097.152709, 31.752756, 180.000000, 180.000000, -89.999977, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.303466, 31.172752, 0.000000, 360.000000, 90.000030, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.303466, 31.752756, 0.000000, 360.000000, 90.000030, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1104.451538, 31.612747, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1102.013305, 31.612747, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1106.884033, 31.612747, 89.999992, 90.000015, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1099.603149, 31.612747, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.322265, 31.612747, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18757, "vcinteriors", "dts_elevator_carpet3", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1104.451538, 31.692749, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1102.013305, 31.692749, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.322265, 31.692749, 89.999992, 90.000015, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1106.884033, 31.692749, 89.999992, 90.000015, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1099.603149, 31.692749, 89.999992, 90.000000, -89.999969, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1104.451538, 31.652748, 89.999992, 90.000015, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1102.013305, 31.652748, 89.999992, 90.000015, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1109.322265, 31.652748, 89.999992, 90.000030, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1106.884033, 31.652748, 89.999992, 90.000030, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    lawnmowerobj = CreateDynamicObject(19087, 952.637878, -1099.603149, 31.652748, 89.999992, 90.000015, -89.999961, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterial(lawnmowerobj, 0, 18901, "matclothes", "hatmancblk", 0x00000000);
    return 1;
}