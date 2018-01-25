#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <assert.h>
using namespace std;
class kojeomDebugLogger
{
public:
	static void MessageBoxLog(LPCWSTR logStr);
	static void ConsoleLog(string logStr);
};

