#pragma once
#include <Windows.h>
#include <string>
class StringUtil
{
public:
	StringUtil();
	~StringUtil();
	static wchar_t* ConvertCharToWchar(std::string* str);
	static char * ConvertWcharToChar(wchar_t* str);
};

