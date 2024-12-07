#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Display.h"
#include <memory>

class Object
{
private:
	static std::vector<sf::Drawable*> Objects;
public:
	void AddObject(sf::Drawable* object);
	void DeleteObject(sf::Drawable* object);
	void DrawAllObjects();
};
