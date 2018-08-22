#include "ButtonNewPoint.h"
#include <vector>
#include <iostream>
#include <cmath>

sf::Color color(0, 0, 0, 255);

ButtonNewPoint::ButtonNewPoint(sf::RenderWindow* win, Canvas* c, const char* t, const char* a, const char* aa, int w, int h, int xx, int yy) : Button1(win, c, t, a, aa, w, h, xx, yy) {}

std::vector<ControllablePoint>* ButtonNewPoint::getPoints() { return &points; }

void ButtonNewPoint::actionPressed()
{
	if (mouseOnObject()) {
		if (pressed) { pressed = false;
		} else { pressed = true; }
	}
	if (!finalPoint && pressed && (*canvas).mouseOnObject() && !overlappingPoint(5)) {
		sf::Vector2i v = sf::Mouse::getPosition(*window);
		points.emplace_back(ControllablePoint { v.x,v.y,&color });
		lastAction.emplace_back(LastAction::NEWPOINT_NBP);
	} 
	if (!finalPoint && points.size() > 1) {
		sf::Vector2i v = sf::Mouse::getPosition(*window);
		if (std::pow(points.front().getPosition().x - v.x, 2) + std::pow(points.front().getPosition().y - v.y, 2) < 10) {
			finalPoint = true;
			lastAction.emplace_back(LastAction::COMBINELASTPOINT_NBP);
		}
	}
}

void ButtonNewPoint::actionPressedRight() {
	 if ((*canvas).mouseOnObject()) {
		sf::Vector2i v = sf::Mouse::getPosition(*window);
		for (auto i = points.begin(); i != points.end(); ++i) {
			int x = std::pow(v.x - i->getPosition().x, 2);
			int y = std::pow(v.y - i->getPosition().y, 2);
			if (std::sqrt(x + y) < 5) {
				erasedPoints.emplace_back(*i);
				points.erase(i);
				lastAction.emplace_back(LastAction::ERASEPOINT_NBP);
				break;
			}
		}
	}
}

void ButtonNewPoint::cancelLastAction() {
	if (!lastAction.empty()) {
		switch (*(lastAction.erase(lastAction.end() - 1)))
		{
		case Button1::LastAction::NEWPOINT_NBP:
			points.erase(points.end() - 1);
			break;
		case Button1::LastAction::COMBINELASTPOINT_NBP:
			setFinalPoint(false);
			break;
		case Button1::LastAction::ERASEPOINT_NBP:
			points.emplace_back(erasedPoints.back());
			erasedPoints.pop_back();
			break;
		}
	}
}
sf::VertexArray ButtonNewPoint::createConvexSet()
{
	sf::VertexArray array;

}
void ButtonNewPoint::actionReleased() {}

void ButtonNewPoint::setModifiablePoint(bool t) { modifiablePoint = t; }

bool ButtonNewPoint::getModifiablePoint() { return modifiablePoint; }

bool ButtonNewPoint::overlappingPoint(double d)
{
	sf::Vector2i v = sf::Mouse::getPosition(*window);
	for (int i = 0; i < points.size(); ++i) {
		int x = std::pow(v.x - points.at(i).getPosition().x, 2);
		int y = std::pow(v.y - points.at(i).getPosition().y, 2);
		if (std::sqrt(x + y) < d) return true;
	}
	return false;
}

void ButtonNewPoint::drawLines(sf::RenderWindow* w)
{
	for (int i = 0; i < points.size(); ++i) {
		w->draw(points.at(i));
		if (i < points.size() - 1) {
			sf::VertexArray line(sf::LinesStrip, 2);
			line[0].color = sf::Color::Red;
			line[1].color = sf::Color::Red;
			line[0].position = static_cast<sf::Vector2f>(points.at(i).getPosition());
			line[1].position = static_cast<sf::Vector2f>(points.at(i + 1).getPosition());
			w->draw(line);
		}
	}
	if(finalPoint && !points.empty()) {
		sf::VertexArray line(sf::LinesStrip, 2);
		line[0].color = sf::Color::Red;
		line[1].color = sf::Color::Red;
		line[0].position = static_cast<sf::Vector2f>(points.back().getPosition());
		line[1].position = static_cast<sf::Vector2f>(points.front().getPosition());
		w->draw(line);
	}
}
bool ButtonNewPoint::getFinalPoint(){return finalPoint;}

void ButtonNewPoint::setFinalPoint(bool b) { finalPoint = b; }

ButtonNewPoint::~ButtonNewPoint(){}