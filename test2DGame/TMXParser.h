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
	//tmx ���� �� layer ������ �����ϸ�, 0 to N ������ tile layer�� �������մϴ�. ( 0�� ���� ���� �׷���. )
	vector<vector<int>> layers;
	void Release()
	{
		layers.clear();
	}
};

//
//Tiled Map Editor Version 0.12.1 �� tmx file �� test �Ǿ����� �˸��ϴ�. 
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

