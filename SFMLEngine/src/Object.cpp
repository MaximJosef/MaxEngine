#include "Object.h"
#include <memory>

std::vector<sf::Drawable*> Object::Objects;

void Object::AddObject(sf::Drawable* object)
{
	Objects.push_back(std::move(object));
}
void Object::DeleteObject(sf::Drawable* object)
{
	Objects.erase(std::remove(Objects.begin(), Objects.end(), object));
}
void Object::DrawAllObjects()
{
	for (auto& objectsForRender : Objects)
	{
		Display::Draw(*objectsForRender);

	}

}