#include "ControllablePoint.h"
#include <iostream>

ControllablePoint::ControllablePoint(int xx, int yy, sf::Color* color)
{
	rect = sf::RectangleShape(sf::Vector2f(5, 5));
	rect.setFillColor(*color);
	rect.setPosition(xx - 2, yy - 2);
	position_CP = sf::Vector2i(xx, yy);
}

void ControllablePoint::set(int x, int y) { 
	rect.setPosition(x-2, y-2);
	position_CP.x = x;
	position_CP.y = y;
}

bool ControllablePoint::getMovable() { return movable; }

void ControllablePoint::movePoint( sf::Vector2i *v)
{
	position_CP = *v;
	rect.setPosition((*v).x - 2,(*v).y - 2);
}

bool ControllablePoint::equals(ControllablePoint *p)
{
	if ((*p).getPosition().x == getPosition().x && (*p).getPosition().x == getPosition().y) return true;
	return false;
}

bool ControllablePoint::pointsAligned(sf::Vector2i u, sf::Vector2i v)
{
	int x = std::pow(u.x - v.x, 2);
	int y = std::pow(u.y - v.y, 2);
	if (x + y < 5) return true;
	return false;
}

bool ControllablePoint::setMovable(sf::Window* w, bool m)
{
	if (mouseOnObject(w)) {
		movable = true;
		return true;
	} else if (!m) {
		movable = false;
	}
	return false;
}

sf::RectangleShape ControllablePoint::get() { return rect; }

sf::Vector2i ControllablePoint::getPosition(){ return position_CP; }

void ControllablePoint::draw(sf::RenderTarget& target, sf::RenderStates states) const { target.draw(rect);  }

ControllablePoint::~ControllablePoint() {}
