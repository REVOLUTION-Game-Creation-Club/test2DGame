#pragma once
#include "TinyXML-2\tinyxml2.h"
#include "FilePath.h"
#include <iostream>
#include <vector>
using namespace std;

struct MapColliderObject{
public:
	int id;
	string name;
	int x, y;
	int width, height;
};

struct MapLayerInfo{
public:
	string name;
	vector<int> tileGIDs;
	~MapLayerInfo() {
		tileGIDs.clear();
	}
};

struct WayOut {
public:
	int id;
	string name;
	int x, y;
	int width, height;
	string next_map_name;
};

struct MapWayOutInfo {
public:
	vector<WayOut> wayouts;
};

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
	vector<MapLayerInfo> layers;
	// tmx ���� ���� �ݸ��� ������Ʈ�� ������ ������ �ִ�.
	vector<MapColliderObject> collObjects;
	// ���� �������� wayout ����.
	MapWayOutInfo wayoutInfo;
	void Release()
	{
		layers.clear();
		collObjects.clear();
	}
	
};

enum TMX_MAP_TYPE
{
	MAIN_TOWN = 0,
	GAME_MAP_0 = 1,
	GAME_MAP_1 = 2,
	MAP_TOTAL_NUM
};
//
//Tiled Map Editor Version 1.0.3 �� tmx file �� test �Ǿ����� �˸��ϴ�. 
//
class TMXParser
{
public:
	~TMXParser();
	MapData GetMapData(TMX_MAP_TYPE mapType);
	MapData* GetMapDataArray();
	static TMXParser* GetInstance();
private:
	TMXParser();
	MapData mapData[TMX_MAP_TYPE::MAP_TOTAL_NUM];
	int tileGidOffset;
	static TMXParser* instance;

	void ReadMapData(const char* _xmlFileName, TMX_MAP_TYPE mapType);
	void ReadCustomProperties(tinyxml2::XMLDocument xmlDoc);
	void ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx, string _layerName, TMX_MAP_TYPE mapType);
	void ReadColliderData(tinyxml2::XMLElement* _element, TMX_MAP_TYPE mapType);
	void ReadWayOutInfo(tinyxml2::XMLElement* _element, TMX_MAP_TYPE mapType);
};

