#pragma once
#include <Windows.h>
class StringUtil
{
public:
	StringUtil();
	~StringUtil();
	static wchar_t* ConvertCharToWchar(char* str);
	static char * ConvertWcharToChar(wchar_t* str);
};

