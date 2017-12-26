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
	//tmx ���� �� layer ������ �����ϸ�, 0 to N ������ tile layer�� �������մϴ�. ( 0�� ���� ���� �׷���. )
	vector<MapLayerInfo> layers;
	// tmx ���� ���� �ݸ��� ������Ʈ�� ������ ������ �ִ�.
	vector<MapColliderObject> collObjects;
	void Release()
	{
		layers.clear();
		collObjects.clear();
	}
};

//
//Tiled Map Editor Version 1.0.3 �� tmx file �� test �Ǿ����� �˸��ϴ�. 
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

