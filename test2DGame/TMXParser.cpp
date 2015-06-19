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

void TMXParser::ReadLayerData(tinyxml2::XMLElement* _element, int _layerIdx)
{
	mapData.vec_layers.push_back(vector<int>());
	while (_element != nullptr)
	{
		if (strcmp(_element->Value(), "tile") == 0)
		{
			mapData.vec_layers[_layerIdx].push_back(atoi(_element->Attribute("gid")));
			_element = _element->NextSiblingElement();
		}
		else _element = _element->FirstChildElement();
	}
}
