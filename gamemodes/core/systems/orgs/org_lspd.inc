#if defined _INC_org_lspd_inc
    #endinput
#endif
#define _INC_org_lspd_inc

#include <YSI_Coding\y_hooks>

const MAX_LSPD_VEHICLES = 20;

static
    orgLSPDVehicle[MAX_LSPD_VEHICLES],
    Text3D:orgLSPDVehicleLabel[MAX_LSPD_VEHICLES],
    gate,
    bool:gateOpened = false;

new const Float:orgLSPDVehiclePos[][] =
{
    {1585.8138, -1667.5682, 5.6124, 269.6341},
    {1586.1342, -1671.5498, 5.6149, 270.3614},
    {1600.8561, -1684.0271, 5.6121, 89.6965},
    {1601.8967, -1688.0548, 5.6129, 89.2968},
    {1601.1495, -1692.0717, 5.6111, 89.4897},
    {1601.0521, -1696.0532, 6.0838, 89.9306},
    {1600.9519, -1700.2362, 6.0807, 90.1589},
    {1600.6193, -1704.2057, 6.0722, 89.2907},
    {1595.3018, -1709.7445, 6.0807, 0.4107},
    {1591.5648, -1709.8982, 6.0778, 0.9885},
    {1587.4550, -1710.1848, 5.4625, 357.7576},
    {1583.5645, -1709.1079, 5.4536, 356.5591},
    {1578.8094, -1709.2782, 5.4604, 359.9132},
    {1574.6569, -1709.4816, 5.4624, 1.0403},
    {1570.3330, -1709.5872, 5.4625, 359.8868},
    {1564.7301, -1709.7600, 5.6493, 359.9646},
    {1558.8654, -1709.2574, 5.6494, 359.1368},
    {1530.2482, -1687.9132, 5.6513, 269.8409},
    {1530.0527, -1684.0535, 5.6483, 270.3431},
    {1542.4298, -1706.6858, 5.6495, 226.6171}
};

hook OnGameModeInit()
{
    gate = CreateDynamicObject(980, 1588.25378, -1638.13855, 14.81186, 0.00000, 0.00000, -0.36000);
    
    CreateDynamic3DTextLabel("[POLICIJA]\n"WHITE"Da udjete u garazu pritisnite "BLUE"'F/Enter'", X11_BLUE, -5.1969, 2657.3135, -49.2784, 10.00);
    CreateDynamic3DTextLabel("[POLICIJA]\n"WHITE"Da udjete u stanicu pritisnite "BLUE"'F/Enter'", X11_BLUE, 1524.7751, -1677.7384, 5.8906, 10.00);
    CreateDynamicPickup(1247, 1, -6.0318, 2661.6643, -49.2784);
    CreateDynamicPickup(19134, 1, -5.1969, 2657.3135, -49.2784);
    CreateDynamicPickup(19134, 1, 1524.7751, -1677.7384, 5.8906);
    CreateDynamic3DTextLabel("[POLICIJA]\n"WHITE"Da uzmete duznost kucajte "BLUE"/pdduznost\n\
        "WHITE"Da uzmete opremu kucajte "BLUE"/pdoprema", X11_BLUE, -6.0318, 2661.6643, -49.2784, 10.00
    );

    for (new i = 0; i < 5; i++)
        orgLSPDVehicle[i] = AddStaticVehicleEx(596, orgLSPDVehiclePos[i][0], orgLSPDVehiclePos[i][1], orgLSPDVehiclePos[i][2], orgLSPDVehiclePos[i][3], 1, 1, 120, true);
    
    for (new j = 5; j < 10; j++)
        orgLSPDVehicle[j] = AddStaticVehicleEx(599, orgLSPDVehiclePos[j][0], orgLSPDVehiclePos[j][1], orgLSPDVehiclePos[j][2], orgLSPDVehiclePos[j][3], 1, 1, 120, true);
    
    for (new k = 10; k < 15; k++)
        orgLSPDVehicle[k] = AddStaticVehicleEx(523, orgLSPDVehiclePos[k][0], orgLSPDVehiclePos[k][1], orgLSPDVehiclePos[k][2], orgLSPDVehiclePos[k][3], 1, 1, 120, true);
    
    for (new l = 15; l < 20; l++)
        orgLSPDVehicle[l] = AddStaticVehicleEx(601, orgLSPDVehiclePos[l][0], orgLSPDVehiclePos[l][1], orgLSPDVehiclePos[l][2], orgLSPDVehiclePos[l][3], 1, 1, 120, true);

    for (new m = 0; m < MAX_LSPD_VEHICLES; m++)
    {
        orgLSPDVehicleLabel[m] = CreateDynamic3DTextLabel("[POLICIJA]", X11_BLUE, 0.0, 0.0, 0.0, 30.00, .attachedvehicle = orgLSPDVehicle[m]);
        Vehicle_SetFuel(orgLSPDVehicle[m], 50);
        Vehicle_SetColor(orgLSPDVehicle[m], 1, 1);
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

TIMER__ ORG_LSPDCloseGate[5000]()
{
    MoveDynamicObject(gate, 1588.25378, -1638.13855, 14.81186, 7.00, 0.00000, 0.00000, -0.36000);
    gateOpened = false;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SECONDARY_ATTACK))
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, -5.1969, 2657.3135, -49.2784))
        {
            if (!Org_IsLSPDMember(playerid))
                return SendErrorMsg(playerid, "Samo clanovi organizacije policija!");

            Streamer_UpdateEx(playerid, 1524.7751, -1677.7384, 5.8906, .compensatedtime = 2000);
        }
        
        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 1524.7751, -1677.7384, 5.8906))
        {
            if (!Org_IsLSPDMember(playerid))
                return SendErrorMsg(playerid, "Samo clanovi organizacije policija!");

            Streamer_UpdateEx(playerid, -5.1969, 2657.3135, -49.2784, .compensatedtime = 2000);
        }
    }

    else if (PRESSED(KEY_CROUCH))
    {
        if (Org_GetID(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 10.00, 1588.25378, -1638.13855, 14.81186))
        {
            if (gateOpened)
                return SendErrorMsg(playerid, "Kapija je vec otvorena!");

            MoveDynamicObject(gate, 1588.25378, -1638.13855, 9.41313, 7.00, 0.00000, 0.00000, -0.36000);
            SendInfoMsg(playerid, "Otvorili ste kapiju, zatvorice se sama za 5 sekundi.");
            gateOpened = true;

            DEFER__ ORG_LSPDCloseGate();
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (Org_LSPDVehicle(vehicleid))
    {
        if (Org_GetID(playerid) != 1)
        {
            GameTextForPlayer(playerid, "~r~SAMO CLANOVI ORGANIZACIJE POLICIJA!", 2000, 3);
            return ClearAnimations(playerid);
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock Org_LSPDVehicle(const vehid)
{
    for (new i = 0; i < MAX_LSPD_VEHICLES; i++)
        if (vehid == orgLSPDVehicle[i])
            return 1;
    return 0;
}

stock Org_IsLSPDMember(const playerid)
    return ((Org_GetID(playerid) == 1) ? 1 : 0);