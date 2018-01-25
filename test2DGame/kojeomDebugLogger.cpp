#include "kojeomDebugLogger.h"

void kojeomDebugLogger::MessageBoxLog(LPCWSTR logStr) {
	MessageBox(0, logStr, 0, 0);
}

void kojeomDebugLogger::ConsoleLog(string logStr)
{
	// to do
}

