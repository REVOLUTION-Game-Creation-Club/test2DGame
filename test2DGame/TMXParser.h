#pragma once
#include "tinyxml2.h"
#include <iostream>

class TMXParser
{
public:
	TMXParser(const char* _xmlFileName);
	~TMXParser();

	void TestFunc();

private:
	tinyxml2::XMLDocument xmlDoc;
};

