#include "TMXParser.h"


TMXParser::TMXParser(const char* _xmlFileName)
{	
	if (_xmlFileName != nullptr) xmlDoc.LoadFile(_xmlFileName);
}


TMXParser::~TMXParser()
{
	
}

void TMXParser::TestFunc()
{
	const char* test = xmlDoc.FirstChildElement()->Value();
	const char* test1 = xmlDoc.FirstChildElement()->Attribute("version");
	
	// map to image element
	tinyxml2::XMLElement* element = xmlDoc.FirstChildElement();
	while (element != nullptr)
	{
		const char* test = element->Value();
		element = element->FirstChildElement();
	}

	element = xmlDoc.RootElement()->FirstChildElement("layer");
	while (element != nullptr)
	{
		const char* test = element->Value();
		element = element->FirstChildElement();
	}

	

	int c = 100;
}