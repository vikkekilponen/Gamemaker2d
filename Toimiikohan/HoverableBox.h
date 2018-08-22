#pragma once
#include "Hoverable.h"
#include "SFML/Graphics.hpp"

class HoverableBox : public Hoverable
{
protected:
	int height, width, x, y;
	sf::RectangleShape rect;
	sf::RenderWindow* window;

public:
	HoverableBox();
	virtual ~HoverableBox();
	virtual bool mouseOnObject();
	virtual bool mouseOnObject(sf::Window*);
	sf::RectangleShape getRect();
};

