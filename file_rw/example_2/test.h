#pragma once
#include <vector>

class Core{
private:
    struct APU{
        uint64_t apu_id;
        uint64_t apu_start_addr;
        uint64_t apu_end_addr;
        uint64_t apu_perm;

        //Constructor for the structure "APU"
        APU (uint64_t id, uint64_t start_addr, uint64_t end_addr, uint64_t perm):
        apu_id(id), apu_start_addr(start_addr), apu_end_addr(end_addr), apu_perm(perm) {}
    };

private:
    //Id of the core
    uint64_t core_id;
    //Message Addr requested by Core
    uint64_t core_msg_addr;
    //Type of message Read/Write
    uint64_t core_msg_perm;

public:
    //Constructor for Class "Core"
    Core(uint64_t id, uint64_t addr, uint64_t perm):
    core_id(id), core_msg_addr(addr), core_msg_perm(perm) {}

    static void print_apu_policy();

    bool test() const;

private:
    //A static member variable of Class Core
    static std::vector<APU> APU_policy;
    //A static member function used to initialize the
    //static member variable "APU_policy" only once
    static std::vector<APU> apu_policy_init();
};
