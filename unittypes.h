#ifndef UNITTYPES
#define UNITTYPES
#include <vector>
class UnitTypes
{
public:
    enum Types
    {
        Protoss_Corsair = 60,
        Protoss_Dark_Templar = 61,
        Protoss_Probe = 64,
        Protoss_Zealot = 65,
        Protoss_Dragoon = 66,
        Protoss_High_Templar = 67,
        Protoss_Shuttle = 69,
        Protoss_Scout = 70,
        Protoss_Arbiter = 71,
        Protoss_Carrier = 72,
        Protoss_Reaver = 83,
        Protoss_Observer = 84,
        Protoss_Nexus = 154,
        Protoss_Robotics_Facility = 155,
        Protoss_Pylon = 156,
        Protoss_Assimilator = 157,
        Protoss_Observatory = 159,
        Protoss_Gateway = 160,
        Protoss_Photon_Cannon = 162,
        Protoss_Citadel_of_Adun = 163,
        Protoss_Cybernetics_Core = 164,
        Protoss_Templar_Archives = 165,
        Protoss_Forge = 166,
        Protoss_Stargate = 167,
        Protoss_Fleet_Beacon = 169,
        Protoss_Arbiter_Tribunal = 170,
        Protoss_Robotics_Support_Bay = 171,
        Protoss_Shield_Battery = 172
    };
    static std::vector<int> Units;
    static std::vector<int> Buildings;
    static char* ToString(int);
    static int ToUnitType(const char*);
};
#endif // UNITTYPES

