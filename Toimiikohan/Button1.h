#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HoverableBox.h"
#include "Canvas.h"

class Button1 : public sf::Drawable, public HoverableBox
{

private:
	void setTextPosition();
	sf::RectangleShape rectPressed;
	sf::Texture texture;
	sf::Texture texturePressed;
	sf::Font font;
	sf::Text text;
	sf::Event event;

protected:
	bool pressed;
	Canvas* canvas;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	enum class LastAction { NONE, NEWPOINT_NBP, COMBINELASTPOINT_NBP, ERASEPOINT_NBP};
	Button1(sf::RenderWindow*, Canvas*,const char*, const char*,const char*, int,int, int, int);
	~Button1();
	virtual void actionPressed();
	virtual void actionReleased();
	bool getPressed();
};
