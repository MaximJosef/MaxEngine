//#     #    #    #     # ####### #     #  #####  ### #     # ####### 
//##   ##   # #    #   #  #       ##    # #     #  #  ##    # #
//# # # #  #   #    # #   #       # #   # #        #  # #   # #       
//#  #  # #     #    #    #####   #  #  # #  ####  #  #  #  # #####   
//#     # #######   # #   #       #   # # #     #  #  #   # # #       
//#     # #     #  #   #  #       #    ## #     #  #  #    ## #       
//#     # #     # #     # ####### #     #  #####  ### #     # ####### 
// 
//v1.0

#include "Engine.h"
#include "Display.h"
#include <functional>
#include <iostream>
#include "Object.h"
#include "Console.h"
#include "imgui.h"
#include "imgui-SFML.h"

Engine::Engine()
{
	Display::Start("MaxEngine");
	Gui::ImGuiInit(Display::GetWindow());
}

void Engine::mainLoop(std::function<void()> FunctionForRender)
{
	sf::Clock deltaClock;

	while (Display::isOpen())
	{
		Display::pollEvents();
		ImGui::SFML::Update(Display::GetWindow(), deltaClock.restart());
		Display::Clear();
		FunctionForRender();
		object.DrawAllObjects();
		console.Draw();
		ImGui::SFML::Render(Display::GetWindow());
		Display::Update();
	}
	ImGui::SFML::Shutdown();
	Display::Close();
}

