#pragma once
#include "TMXParser.h"
#include <string>
class GameMapUtil {
public:
	static TMX_MAP_TYPE MapNameToType(std::string mapName) {
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

	static WayOutToDirection DirNameToEnum(std::string dirName) {
		WayOutToDirection type;
		if (dirName.compare("NORTH") == 0) {
			type = WayOutToDirection::NORTH;
		}
		else if (dirName.compare("SOUTH") == 0) {
			type = WayOutToDirection::SOUTH;
		}
		else if (dirName.compare("EAST") == 0) {
			type = WayOutToDirection::EAST;
		}
		else if (dirName.compare("WEST") == 0) {
			type = WayOutToDirection::WEST;
		}
		return type;
	}
};