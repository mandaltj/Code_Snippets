#include <vector>
#include "test.h"

std::vector<Core::APU> Core::APU_policy = apu_policy_init();

std::vector<Core::APU> Core::apu_policy_init(){
    std::cout<<"Initializing APU structure\n";

    std::vector<APU> APU_temp;

    std::string filename = "apu_init.txt";
    std::ifstream infile(filename);
    if(!infile) {
        infile.close();
        throw std::runtime_error("Could not load file: " + filename);
    }

    uint64_t id;
    uint64_t start_addr;
    uint64_t end_addr;
    uint64_t perm;

    while(infile >> id >> start_addr >> end_addr >> perm){
        APU_temp.emplace_back(id, start_addr, end_addr, perm);
    }

    return APU_temp;
}

void Core::print_apu_policy(){
    for(auto apu: APU_policy){
        std::cout<<"ID: "<<apu.apu_id;
        std::cout<<" Start_addr: "<<apu.apu_start_addr;
        std::cout<<" End_addr: "<<apu.apu_end_addr;
        std::cout<<" Perm: "<<apu.apu_perm<<'\n';
    }
}

bool Core::test() const {
    for (auto apu: APU_policy){
        if ((apu.apu_id == core_id) && (core_msg_perm == apu.apu_perm)){
            if(core_msg_addr>=apu.apu_start_addr && core_msg_addr<=apu.apu_end_addr){
                return true;
            }
        }
    }
    return false;
}
