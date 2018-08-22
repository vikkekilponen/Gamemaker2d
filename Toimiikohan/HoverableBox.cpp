#include "HoverableBox.h"
#include <iostream>
#include <SFML/Graphics.hpp>
HoverableBox::HoverableBox() {}

HoverableBox::~HoverableBox() {}

bool HoverableBox::mouseOnObject()
{
	if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)))) {
		return true;
	}
	return false;
}

bool HoverableBox::mouseOnObject(sf::Window* w)
{
	if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*w)))) {
		return true;
	}
	return false;
}

sf::RectangleShape HoverableBox::getRect(){ return rect; }

