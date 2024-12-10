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
		outliner.DrawOutliner();
		objectSettings.DrawObjectSettings(outliner.currentGameObject);
		console.Draw();
		ImGui::SFML::Render(Display::GetWindow());
		Display::Update();
	}
	ImGui::SFML::Shutdown();
	Display::Close();
}

