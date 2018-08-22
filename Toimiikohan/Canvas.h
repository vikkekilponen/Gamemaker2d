#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HoverableBox.h"

class Canvas : public sf::Drawable, public HoverableBox
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape border[4];

public:
	Canvas();
	Canvas(sf::RenderWindow*,const char*,int,int,int,int);
	bool borderCollides(sf::RectangleShape);
	~Canvas();
};

