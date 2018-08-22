#pragma once
#include "SFML/Graphics.hpp"

class Hoverable
{
protected:
	int x;
	int y;
	virtual bool mouseOnObject(sf::Window *window);

public:
	Hoverable();
	virtual ~Hoverable();
};
