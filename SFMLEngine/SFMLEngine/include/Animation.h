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
	bool isLooping;
	sf::Sprite *target;

public:
    Animation(sf::Sprite& target, bool isLooping);

    void addFrame(Frame&& frame);

	void update(double elapsed);

	bool isFinished() { return totalProgress >= totalLength; };
	void reset();

};

