#pragma once
#include "TMXParser.h"
class GameMapUtil {
public:
	static TMX_MAP_TYPE MapNameToType(string mapName) {
		TMX_MAP_TYPE type;
		if (mapName.compare("maintown") == 0) {
			type = TMX_MAP_TYPE::MAIN_TOWN;
		}
		else if (mapName.compare("town0") == 0) {
			type = TMX_MAP_TYPE::TOWN_0;
		}
		else if (mapName.compare("town1") == 0) {
			type = TMX_MAP_TYPE::TOWN_1;
		}
		else if (mapName.compare("NONE") == 0) {
			type = TMX_MAP_TYPE::NONE;
		}
		return type;
	}
};