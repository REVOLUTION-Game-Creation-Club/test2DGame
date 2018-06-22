#pragma once
#include "ft2build.h"
#include "kojeomDebugLogger.h"
#include FT_FREETYPE_H
class GameFontLoader {
public:
	static GameFontLoader * GetInstance() {
		if (instance == nullptr) {
			instance = new GameFontLoader();
		}
		return instance;
	}
	~GameFontLoader() {
	}
private:
	static GameFontLoader* instance;
	FT_Library  library;   /* handle to library     */
	FT_Face     face;      /* handle to face object */
	GameFontLoader() {
		auto initlib = FT_Init_FreeType(&library);
		auto createNewFace = FT_New_Face(library,
			"GameResources//font//gamefont_Minecraft.ttf",
			0,
			&face);
		if (createNewFace == FT_Err_Unknown_File_Format){
			kojeomDebugLogger::MessageBoxLog(L"FT_Err_Unknown_File_Format");
		}
	}
};
GameFontLoader* GameFontLoader::instance = nullptr;