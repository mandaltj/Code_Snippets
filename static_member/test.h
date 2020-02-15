#pragma once
#include <iostream>
#include <vector>

class Core{
private:
	int core_id;
	int value;

	Core(int core_id_arg, int value_arg);

	struct check{
		int id;
		int start;
		int stop;
	}

	static std::vector<check> core_check;

}
