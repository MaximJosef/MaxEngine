#pragma once
#include <functional>
#include <iostream>
#include "Console.h"
#include "Object.h"
#include "AssetManager.h"
#include "Animation.h"
#include "ObjectSettings.h"
#include "Outliner.h"
#include "Display.h"
#include <functional>
#include "imgui.h"
#include "imgui-SFML.h"

class Engine
{
public:
	Engine();
	void mainLoop(std::function<void()> FunctionForRender);
	Console console;
	AssetManager assetManager;
	ObjectSettings objectSettings;
	Outliner outliner;
	Object object;
};
