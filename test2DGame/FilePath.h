#pragma once
class FilePath
{
public:
	
	static FilePath* GetInstance()
	{
		if (instance == nullptr) instance = new FilePath();
		return instance;
	}
private:
	static FilePath* instance;
	FilePath()
	{
		mainmenu_bg = "";
		mainmenu_foregroundTrees = "";
		mainmenu_backgroundTrees = "";
		mainmenu_mountainFar = "";
		mainmenu_mountains = "";
	};
	char* mainmenu_bg;
	char* mainmenu_foregroundTrees;
	char* mainmenu_backgroundTrees;
	char* mainmenu_mountainFar;
	char* mainmenu_mountains;
};
FilePath* FilePath::instance = nullptr;
