#include "Object.h"

std::vector<sf::Drawable*> Object::Objects;
std::vector<GameObject*> Object::GameObjects;

void Object::AddObject(sf::Drawable* object)
{
	Objects.push_back(std::move(object));
}
void Object::AddObject(GameObject* gameObject)
{
	GameObjects.push_back(gameObject);
}
void Object::DeleteObject(sf::Drawable* object)
{
	Objects.erase(std::remove(Objects.begin(), Objects.end(), object));
}
void Object::DeleteObject(GameObject* gameObject)
{
	GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), gameObject));
}
void Object::DrawAllObjects()
{
	for (auto& objectsForRender : Objects)
	{
		Display::Draw(*objectsForRender);
	}
	for (auto& objectsForRender : GameObjects)
	{
		Display::Draw(objectsForRender->GetSprite());
	}
}