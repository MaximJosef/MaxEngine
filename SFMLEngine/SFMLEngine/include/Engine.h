#pragma once
#include <functional>
#include <iostream>
#include "Console.h"
#include "Object.h"

class Engine
{
private:
	Object object;
public:
	Engine();
	void mainLoop(std::function<void()> FunctionForRender);
	Console console;

};
