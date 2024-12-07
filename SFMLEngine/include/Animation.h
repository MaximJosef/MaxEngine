#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Frame
{
	sf::IntRect rect;
	float duration;
};

class Animation
{
private:
	std::vector<Frame> frames;
	double totalLength;
	double totalProgress;
	sf::Sprite *target;

public:
    Animation(sf::Sprite& target);

    void addFrame(Frame&& frame);

	void update(double elapsed);

};

