#pragma once

#include "ControllablePoint.h"
#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "Button1.h"

class ButtonNewPoint : public Button1 {


private:
	std::vector<ControllablePoint> points;
	std::vector<ControllablePoint> erasedPoints;
	ControllablePoint* prevPoint;
	bool modifiablePoint = false;
	bool finalPoint = false;
	std::vector<LastAction> lastAction;

public:
	ButtonNewPoint(sf::RenderWindow*, Canvas*, const char* textt, const char* address, const char* addressPressed, int w, int h, int xx = 0, int yy = 0);
	std::vector<ControllablePoint>* getPoints();
	void actionPressed();
	void actionReleased();
	~ButtonNewPoint();
	void setModifiablePoint(bool);
	bool getModifiablePoint();
	bool overlappingPoint(double);
	void drawLines(sf::RenderWindow*);
	bool getFinalPoint();
	void setFinalPoint(bool);
	void actionPressedRight();
	void cancelLastAction();
	sf::VertexArray createConvexSet();
};

