#include "Display.h"

namespace Display
{
	std::unique_ptr<sf::RenderWindow> window = nullptr;

	void Start(const std::string& WindowName)
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT),
			WindowName,
			sf::Style::Close);
		std::cout << "Initializing window" << std::endl;
		if (!window->isOpen())
			std::cout << "Window is not open!" << std::endl;
		else
			std::cout << "Window is open!" << std::endl;
	}

	void checkForClose(const sf::Event& e)
	{
		if (e.type == sf::Event::Closed)
		{
			if (window) 
				window->close();
		}
	}

	void Update()
	{
		if (window) window->display();
	}

	bool isOpen()
	{
		if (window) return window->isOpen();
	}

	void Draw(const sf::Drawable& drawable)
	{
		if (window) window->draw(drawable);
	}

	void Clear()
	{
		if (window) window->clear();
	}

	void pollEvents()
	{
		sf::Event e;

		while (window != nullptr && Display::window->pollEvent(e))
		{
			Display::checkForClose(e);
			ImGui::SFML::ProcessEvent(e);
		}
	}

	void Close()
	{
		if (window)
		{
			window->close();
			window.reset();
		}
	}

	sf::RenderWindow& GetWindow()
	{
		if(window !=  nullptr)
		{
			return *window;
		}
	}
}

namespace Gui
{
	void ImGuiInit(sf::RenderWindow& window)
	{
		ImGui::SFML::Init(window);
	}
}
