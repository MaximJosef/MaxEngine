#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "imgui.h"
#include "imgui-SFML.h"
#include <memory>
#include "GameObject.h"

class Console
{
public:
	std::vector<std::unique_ptr<std::string>> messages;
	void AddMessage(const std::string& message);
	std::unique_ptr<std::string> ptr = std::make_unique<std::string>();
	void Draw();
};


