// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here

#include "d3dUtility.h"
#include "GameMap.h"
#include "TMXParser.h"
#include "tinyxml2.h"
#include "Animation.h"
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Player.h"
#include "PlayerFactory.h"
#include "Simple2DCamera.h"
#include "WorldMap.h"
#include "KojeomGameUI.h"
// 2d sprite
#include "Player2DSprite.h"

//gui lib - test
#include "AntTweakBar.h"
// SoundManager.
#include "GameSoundManager.h"
