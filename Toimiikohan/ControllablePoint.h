#pragma once
#include <SFML/Graphics.hpp>
#include "HoverableBox.h"
class ControllablePoint : public sf::Drawable, HoverableBox
{
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape get();
	bool movable = false;
	sf::Vector2i position_CP;

public:
	ControllablePoint(int, int,sf::Color*);
	~ControllablePoint();
	void set(int , int );
	sf::Vector2i getPosition();
	void movePoint( sf::Vector2i*);
	bool setMovable(sf::Window*, bool);
	bool getMovable();
	bool equals(ControllablePoint*);
	bool pointsAligned(sf::Vector2i, sf::Vector2i);

};

