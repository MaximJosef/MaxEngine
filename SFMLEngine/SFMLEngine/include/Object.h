#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Display.h"
#include "GameObject.h"

class Object
{
private:
	static std::vector<sf::Drawable*> Objects;
	static std::vector<GameObject*> GameObjects;
public:
	void AddObject(sf::Drawable* object);
	void AddObject(GameObject* gameObject);
	void DeleteObject(sf::Drawable* object);
	void DeleteObject(GameObject* gameObject);
	void DrawAllObjects();
	std::vector<sf::Drawable*> GetObjects() { return Objects; }
	std::vector<GameObject*> GetGameObjects() { return GameObjects; }
};
