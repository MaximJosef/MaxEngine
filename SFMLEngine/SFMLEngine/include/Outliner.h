#pragma once
#include "Object.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "ObjectSettings.h"
#include <iostream>

class Outliner
{
private:
	Object object;
	ObjectSettings objectSettings;
public:
	void DrawOutliner();
	GameObject* currentGameObject = nullptr;
};

