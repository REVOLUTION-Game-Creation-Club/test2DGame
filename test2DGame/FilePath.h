#pragma once
class FilePath
{
public:
	static FilePath* GetInstance();
	// mainmenu
	char* mainmenu_bg;
	char* mainmenu_foregroundTrees;
	char* mainmenu_backgroundTrees;
	char* mainmenu_mountainFar;
	char* mainmenu_mountains;
	char* mainmenu_title;
	// test
	char* chacracter01;
	// test
	char* tileMapSprite;
	// test
	char* mainTown;
	char* town0;
	char* town1;
	~FilePath();
private:
	static FilePath* instance;
	FilePath();
}; 
