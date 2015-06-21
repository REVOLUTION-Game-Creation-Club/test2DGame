#pragma once
#include "tinyxml2.h"
#include <iostream>
#include <vector>

using namespace std;

struct MapData
{
	int tileWidth;
	int tileHeight;
	int mapWidth;
	int mapHeight;
	int imageWidth;
	int imageHeight;
	vector<vector<int>> vec_layers;
};

//
//Tiled Map Editor Version 0.12.1 의 tmx file 로 test 되었음을 알립니다. 
//
class TMXParser
{
public:
	TMXParser(const char* _xmlFileName);
	~TMXParser();

	MapData* GetMapData();

private:
	tinyxml2::XMLDocument xmlDoc;
	MapData mapData;

	int tileOffset;

	void ReadMapData();
	void ReadCustomProperties();
	void ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx);
	
};

