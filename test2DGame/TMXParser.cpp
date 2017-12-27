#include "TMXParser.h"

TMXParser* TMXParser::instance = nullptr;

TMXParser::TMXParser()
{	
	// ������ �۾��س����ǵ�, gid���� �� -1�� ���ϴ°ɱ�.
	tileGidOffset = -1;
	// ���� �� �ε�.
	ReadMapData(FilePath::GetInstance()->tmxFile_0, TMX_MAP_TYPE::GAME_MAP_0);
	ReadMapData(FilePath::GetInstance()->tmxFile_1, TMX_MAP_TYPE::GAME_MAP_1);
}


TMXParser::~TMXParser()
{
	for each (auto data in mapData)
	{
		data.Release();
	}
}

MapData TMXParser::GetMapData(TMX_MAP_TYPE mapType)
{
	return mapData[mapType];
}

TMXParser * TMXParser::GetInstance()
{
	if (instance == nullptr) instance = new TMXParser();
	return instance;
}

void TMXParser::ReadMapData(const char* _xmlFileName, TMX_MAP_TYPE mapType)
{

	tinyxml2::XMLDocument xmlDoc;
	if (_xmlFileName != nullptr) xmlDoc.LoadFile(_xmlFileName);

	mapData[mapType].mapWidth = atoi(xmlDoc.FirstChildElement()->Attribute("width"));
	mapData[mapType].mapHeight = atoi(xmlDoc.FirstChildElement()->Attribute("height"));

	mapData[mapType].tileWidth = atoi(xmlDoc.FirstChildElement()->Attribute("tilewidth"));
	mapData[mapType].tileHeight = atoi(xmlDoc.FirstChildElement()->Attribute("tileheight"));

	mapData[mapType].imageWidth = atoi(xmlDoc.RootElement()->FirstChildElement("tileset")->
		FirstChildElement()->Attribute("width"));
	mapData[mapType].imageHeight = atoi(xmlDoc.RootElement()->FirstChildElement("tileset")->
		FirstChildElement()->Attribute("height"));

	tinyxml2::XMLElement* element = xmlDoc.RootElement()->FirstChildElement();
	tinyxml2::XMLElement* originElement = element;
	int layerIdx = 0;
	while (element != nullptr)
	{
		if (strcmp(element->Value(), "layer") == 0)
		{
			originElement = element;
			ReadLayerData(element, layerIdx, element->Attribute("name"), mapType);
			element = originElement;
			
			layerIdx++;
		}
		else if (strcmp(element->Value(), "objectgroup") == 0)
		{
			originElement = element;
			ReadColliderData(element, mapType);
			element = originElement;
		}
		element = element->NextSiblingElement();
	}
}
//
// tmx file ���� tile gid ���� ù��° tile�� ����ִ� ���� �׷��� ������쿡 ���̰� �ִ�. - log
//
void TMXParser::ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx, string _layerName, TMX_MAP_TYPE mapType)
{
	mapData[mapType].layers.push_back(MapLayerInfo());
	while (_element != nullptr)
	{
		if (strcmp(_element->Value(), "tile") == 0)
		{	// tile atrribute gid �� Map witdh , height �� tile size�� ���� ���� �ǹ�. 
			mapData[mapType].layers[_layerIdx].tileGIDs.push_back(atoi(_element->Attribute("gid")) + tileGidOffset);
			mapData[mapType].layers[_layerIdx].name = _layerName;
			_element = _element->NextSiblingElement();
		}
		else _element = _element->FirstChildElement();
	}
}
void TMXParser::ReadColliderData(tinyxml2::XMLElement * _element, TMX_MAP_TYPE mapType)
{
	while (_element != nullptr)
	{
		if (strcmp(_element->Value(), "object") == 0)
		{
			MapColliderObject mapCollObj;
			mapCollObj.id = atoi(_element->Attribute("id"));
			mapCollObj.name = _element->Attribute("name");
			mapCollObj.x = atoi(_element->Attribute("x"));
			mapCollObj.y = atoi(_element->Attribute("y"));
			mapCollObj.width = atoi(_element->Attribute("width"));
			mapCollObj.height = atoi(_element->Attribute("height"));
			mapData[mapType].collObjects.push_back(mapCollObj);
			_element = _element->NextSiblingElement();
		}
		else _element = _element->FirstChildElement();
	}
}
//
// test func
//
void TMXParser::ReadCustomProperties(tinyxml2::XMLDocument xmlDoc)
{
	const char* isFirstTileBlank = xmlDoc.RootElement()->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
	if (strcmp(isFirstTileBlank, "true") == 0) tileGidOffset = 0;
	else tileGidOffset = 0;

}
