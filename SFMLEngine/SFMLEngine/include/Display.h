#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
#include <memory>

namespace Display
{
	extern std::unique_ptr<sf::RenderWindow> window;
	void Start(const std::string& WindowName);
	void Update();
	bool isOpen();
	void Clear();
	void Draw(const sf::Drawable& drawable);
	void pollEvents();
	void Close();
	sf::RenderWindow& GetWindow();

	const int WIDTH = 1280;
	const int HEIGHT = 720;
}

namespace Gui
{
	void ImGuiInit(sf::RenderWindow& window);
}