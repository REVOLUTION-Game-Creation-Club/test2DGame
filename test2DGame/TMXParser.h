#pragma once
#include "TinyXML-2\tinyxml2.h"
#include <iostream>
#include <vector>
using namespace std;

struct MapColliderObject
{
public:
	int id;
	string name;
	int x, y;
	int width, height;
};

struct MapLayerInfo
{
public:
	string name;
	vector<int> tileGIDs;
	void Release()
	{
		tileGIDs.clear();
	}
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
	//tmx 파일 맵 layer 정보를 저장하며, 0 to N 순서로 tile layer를 렌더링합니다. ( 0이 가장 먼저 그려짐. )
	vector<MapLayerInfo> layers;
	// tmx 파일 맵의 콜리터 오브젝트의 정보를 가지고 있다.
	vector<MapColliderObject> collObjects;
	void Release()
	{
		layers.clear();
		collObjects.clear();
	}
};

//
//Tiled Map Editor Version 1.0.3 의 tmx file 로 test 되었음을 알립니다. 
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
	void ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx, string _layerName);
	void ReadColliderData(tinyxml2::XMLElement* _element);
};

