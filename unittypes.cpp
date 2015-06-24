#include "unittypes.h"

std::vector<int> UnitTypes::Units = {
                            Protoss_Probe,
                            Protoss_Zealot,
                            Protoss_Dragoon,
                            Protoss_High_Templar,
                            Protoss_Dark_Templar,
                            Protoss_Reaver,
                            Protoss_Arbiter,
                            Protoss_Shuttle,
                            Protoss_Scout,
                            Protoss_Corsair,
                            Protoss_Carrier,
                            Protoss_Observer
                          };

std::vector<int> UnitTypes::Buildings = {
                                Protoss_Nexus,
                                Protoss_Gateway,
                                Protoss_Assimilator,
                                Protoss_Forge,
                                Protoss_Cybernetics_Core,
                                Protoss_Robotics_Facility,
                                Protoss_Robotics_Support_Bay,
                                Protoss_Stargate,
                                Protoss_Fleet_Beacon,
                                Protoss_Templar_Archives,
                                Protoss_Arbiter_Tribunal,
                                Protoss_Citadel_of_Adun,
                                Protoss_Photon_Cannon,
                                Protoss_Observatory,
                                Protoss_Shield_Battery
                             };

char* UnitTypes::ToString(int unit)
{
    switch(unit)
    {
        case 60:
            return "Corsair";
        case 61:
            return "Dark Templar";
        case 64:
            return "Probe";
        case 65:
            return "Zealot";
        case 66:
            return "Dragoon";
        case 67:
            return "High Templar";
        case 69:
            return "Shuttle";
        case 70:
            return "Scout";
        case 71:
            return "Arbitrer";
        case 72:
            return "Carrier";
        case 83:
           return "Reaver";
        case 84:
           return "Observer";
        case 154:
            return "Nexus";
        case 155:
            return "Robotics Facility";
        case 157:
            return "Assimilator";
        case 159:
            return "Observatory";
        case 160:
            return "Gateway";
        case 162:
            return "Photon Cannon";
        case 163:
            return "Citadel of Adun";
        case 164:
            return "Cybernetics Core";
        case 165:
            return "Templar Archives";
        case 166:
            return "Forge";
        case 167:
            return "Stargate";
        case 169:
            return "Fleet Beacon";
        case 170:
            return "Arbitrer Tribunal";
        case 171:
            return "Robotics Support Bay";
        case 172:
            return "Shield Battery";
        default:
           return "None";
    }
}


int UnitTypes::ToUnitType(const char* name)
{
    if(!strcmp(name, "Corsair"))
        return 60;
    else if(!strcmp(name, "Dark Templar"))
        return 61;
    else if(!strcmp(name, "Probe"))
        return 64;
    else if(!strcmp(name, "Zealot"))
        return 65;
    else if(!strcmp(name, "Dragoon"))
        return 66;
    else if(!strcmp(name, "High Templar"))
        return 67;
    else if(!strcmp(name, "Shuttle"))
        return 69;
    else if(!strcmp(name, "Scout"))
        return 70;
    else if(!strcmp(name, "Arbitrer"))
        return 71;
    else if(!strcmp(name, "Carrier"))
        return 72;
    else if(!strcmp(name, "Reaver"))
        return 83;
    else if(!strcmp(name, "Observer"))
        return 84;
    else if(!strcmp(name, "Nexus"))
        return 154;
    else if(!strcmp(name, "Robotics Facility"))
        return 155;
    else if(!strcmp(name, "Assimilator"))
        return 157;
    else if(!strcmp(name, "Observatory"))
        return 159;
    else if(!strcmp(name, "Gateway"))
        return 160;
    else if(!strcmp(name, "Photon Cannon"))
        return 162;
    else if(!strcmp(name, "Citadel of Adun"))
        return 163;
    else if(!strcmp(name, "Cybernetics Core"))
        return 164;
    else if(!strcmp(name, "Templar Archives"))
        return 165;
    else if(!strcmp(name, "Forge"))
        return 166;
    else if(!strcmp(name, "Stargate"))
        return 167;
    else if(!strcmp(name, "Fleet Beacon"))
        return 169;
    else if(!strcmp(name, "Arbitrer Tribunal"))
        return 170;
    else if(!strcmp(name, "Robotics Support Bay"))
        return 171;
    else if(!strcmp(name, "Shield Battery"))
        return 172;
    else
        return 0;
}
