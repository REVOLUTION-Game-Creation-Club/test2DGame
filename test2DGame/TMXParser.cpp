#include "TMXParser.h"


TMXParser::TMXParser(const char* _xmlFileName)
{	
	if (_xmlFileName != nullptr) xmlDoc.LoadFile(_xmlFileName);

	mapData.mapWidth = atoi(xmlDoc.FirstChildElement()->Attribute("width"));
	mapData.mapHeight = atoi(xmlDoc.FirstChildElement()->Attribute("height"));

	mapData.tileWidth = atoi(xmlDoc.FirstChildElement()->Attribute("tilewidth"));
	mapData.tileHeight = atoi(xmlDoc.FirstChildElement()->Attribute("tileheight"));

	mapData.imageWidth = atoi(xmlDoc.RootElement()->FirstChildElement("tileset")->
					   FirstChildElement()->Attribute("width"));
	mapData.imageHeight = atoi(xmlDoc.RootElement()->FirstChildElement("tileset")->
					   FirstChildElement()->Attribute("height"));

	//test
	//ReadCustomProperties();
	// ������ �۾��س����ǵ�, gid���� �� -1�� ���ϴ°ɱ�.
	tileGidOffset = -1;
	ReadMapData();

}


TMXParser::~TMXParser()
{
	mapData.Release();
}

MapData* TMXParser::GetMapData()
{
	return &mapData;
}

void TMXParser::ReadMapData()
{
	tinyxml2::XMLElement* element = xmlDoc.RootElement()->FirstChildElement();
	tinyxml2::XMLElement* originElement = element;
	int layerIdx = 0;
	while (element != nullptr)
	{
		if (strcmp(element->Value(), "layer") == 0)
		{
			originElement = element;
			ReadLayerData(element, layerIdx);
			element = originElement;
			
			layerIdx++;
		}
		element = element->NextSiblingElement();
	}
}
//
// tmx file ���� tile gid ���� ù��° tile�� ����ִ� ���� �׷��� ������쿡 ���̰� �ִ�. - log
//
void TMXParser::ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx)
{
	mapData.layers.push_back(vector<int>());
	while (_element != nullptr)
	{
		if (strcmp(_element->Value(), "tile") == 0)
		{	// tile atrribute gid �� Map witdh , height �� tile size�� ���� ���� �ǹ�. 
			mapData.layers[_layerIdx].push_back(atoi(_element->Attribute("gid")) + tileGidOffset);
			_element = _element->NextSiblingElement();
		}
		else _element = _element->FirstChildElement();
	}
}
//
// test func
//
void TMXParser::ReadCustomProperties()
{
	const char* isFirstTileBlank = xmlDoc.RootElement()->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
	if (strcmp(isFirstTileBlank, "true") == 0) tileGidOffset = 0;
	else tileGidOffset = 0;

}
