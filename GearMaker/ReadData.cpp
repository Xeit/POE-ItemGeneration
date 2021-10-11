#include "ReadData.h"
	void readJson::getBaseItems()
	{
		std::ifstream i ("gggData/base_items.json");
		nlohmann::json j;
		i >> j;
	}