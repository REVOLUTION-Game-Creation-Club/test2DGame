#include "FilePath.h"

FilePath* FilePath::GetInstance()
{
	if (instance == nullptr) instance = new FilePath();
	return instance;
}
FilePath* FilePath::instance = nullptr;

FilePath::~FilePath()
{
}

FilePath::FilePath()
{
	//
	mainmenu_bg = "GameResources//textures//mainmenu//bg.png";
	mainmenu_foregroundTrees = "GameResources//textures//mainmenu//foreground-trees.png";
	mainmenu_backgroundTrees = "GameResources//textures//mainmenu//background-trees.png";
	mainmenu_mountainFar = "GameResources//textures//mainmenu//montain-far.png";
	mainmenu_mountains = "GameResources//textures//mainmenu//mountains.png";
	mainmenu_title = "GameResources//textures//mainmenu//title.png";
	//
	chacracter01 = "GameResources//textures//character//ch01.png";
	//
	tileMap = "GameResources//textures//tilemap//tileb.png";
	//
	tmxFile_0 = "GameResources//test00.tmx";
	tmxFile_1 = "GameResources//test01.tmx";
	//
	
};