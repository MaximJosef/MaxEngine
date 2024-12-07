#include "Animation.h"

Animation::Animation(sf::Sprite& target)
{
    this->target = &target;
    totalProgress = 0.0;
}

void Animation::addFrame(Frame&& frame)
{
    frames.push_back(std::move(frame));
    totalLength += frame.duration;
}

void Animation::update(double elapsed)
{
    totalProgress += elapsed;
    double progress = totalProgress;
    for (auto frame : frames) {
        progress -= (frame).duration;

        if (progress <= 0.0 || &(frame) == &frames.back())
        {
            target->setTextureRect((frame).rect);
            break; 
        }
    }
}