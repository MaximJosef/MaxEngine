#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "imgui.h"
#include "imgui-SFML.h"
#include <memory>
#include "GameObject.h"
#include "Display.h"
#include "ImGuiFileDialog.h"
#include "AssetManager.h"
#include <iostream>
#include <fstream>

class ObjectSettings
{
public:
	void DrawObjectSettings(GameObject* GameObject);
};

