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
	ReadMapData();

}


TMXParser::~TMXParser()
{
	
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
// tmx file 에서 tile gid 값은 첫번째 tile이 비어있는 경우와 그렇지 않은경우에 차이가 있다. - log
//
void TMXParser::ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx)
{
	mapData.vec_layers.push_back(vector<int>());
	while (_element != nullptr)
	{
		if (strcmp(_element->Value(), "tile") == 0)
		{	// tile atrribute gid 는 Map witdh , height 를 tile size로 나눈 값을 의미. 
			mapData.vec_layers[_layerIdx].push_back(atoi(_element->Attribute("gid")) - 1);
			_element = _element->NextSiblingElement();
		}
		else _element = _element->FirstChildElement();
	}
}
//
// test
//
void TMXParser::ReadCustomProperties()
{
	const char* isFirstTileBlank = xmlDoc.RootElement()->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
	if (strcmp(isFirstTileBlank, "true") == 0) tileOffset = 0;
	else tileOffset = 0;

}
