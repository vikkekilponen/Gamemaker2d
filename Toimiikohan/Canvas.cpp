#include "Canvas.h"

sf::Texture textureBackground;

void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect);
	for (int i = 0; i < 4; ++i) {
		target.draw(border[i]);
	}
}

Canvas::Canvas() { std::cout << "Using default Canvas constructor"; }

Canvas::Canvas(sf::RenderWindow* win, const char* address, int w, int h, int xx, int yy) {
	x = xx; y = yy; width = w; height = h;
	if (!textureBackground.loadFromFile(address)) std::cout << "Loading canvas texture failed";
	rect = sf::RectangleShape::RectangleShape(sf::Vector2f(width, height));
	rect.setPosition(x, y);
	border[0] = sf::RectangleShape(sf::Vector2f(width+2, 1));
	border[1] = sf::RectangleShape(sf::Vector2f(1, height+2));
	border[2] = sf::RectangleShape(sf::Vector2f(width+2, 1));
	border[3] = sf::RectangleShape(sf::Vector2f(1, height+2));
	border[0].setPosition(x - 1, y - 1);
	border[1].setPosition(x + width+1, y - 1);
	border[2].setPosition(x - 1, y + height);
	border[3].setPosition(x - 1 , y - 1);
	for (int i = 0; i < 4; ++i) border[i].setFillColor(sf::Color::Black);
	window = win;
	rect.setTexture(&textureBackground);
}

bool Canvas::borderCollides(sf::RectangleShape r)
{ 
	for (int i = 0; i < 4; ++i) {
		if (border[i].getGlobalBounds().intersects(r.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

Canvas::~Canvas() {}


