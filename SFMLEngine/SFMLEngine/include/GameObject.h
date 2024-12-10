#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class GameObject
{
private:
	sf::Sprite Sprite;
	std::string ObjectName;
	std::vector<std::string> scripts;

public:
	sf::Vector2f GetObjectScale() { return Sprite.getScale(); }
	void SetObjectScale(const sf::Vector2f& newObjectScale) { Sprite.setScale(newObjectScale); }

	sf::Vector2f GetObjectPosition() { return Sprite.getPosition(); }
	void SetObjectPosition(sf::Vector2f& newObjectPosition) { Sprite.setPosition(newObjectPosition); }

	float GetObjectRotation() { return Sprite.getRotation(); }
	void SetObjectRotation(float newObejctRotation) { Sprite.setRotation(newObejctRotation); }

	std::string GetObjectName() { return ObjectName; }
	void SetObjectName(std::string newObjectName) { ObjectName = newObjectName; }

	const sf::Texture* GetObjectTexture() { return Sprite.getTexture(); }
	void SetObjectTexture(sf::Texture& newObjectTexture) { Sprite.setTexture(newObjectTexture); }

	//void AddScript();

	sf::Transform GetObjectTransform() { return Sprite.getTransform(); }

	sf::Sprite& GetSprite() { return Sprite; }
	void SetSprite(sf::Sprite& newShape) { Sprite = newShape; }
};

