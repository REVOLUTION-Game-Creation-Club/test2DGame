#pragma once
#include "TinyXML-2\tinyxml2.h"
#include <iostream>
#include <vector>

using namespace std;

struct MapData
{
public:
	int tileWidth;
	int tileHeight;
	int mapWidth;
	int mapHeight;
	int imageWidth;
	int imageHeight;
	//tmx 파일 맵 layer 정보를 저장하며, 0 to N 순서로 tile layer를 렌더링합니다. ( 0이 가장 먼저 그려짐. )
	vector<vector<int>> layers;
	void Release()
	{
		layers.clear();
	}
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
	int tileGidOffset;

	void ReadMapData();
	void ReadCustomProperties();
	void ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx);
	
};

