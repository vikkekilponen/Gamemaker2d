#include "ButtonLoadTexture.h"


ButtonLoadTexture::ButtonLoadTexture(sf::RenderWindow* win, Canvas* c, const char* t, const char* a, const char* aa, int w, int h, int xx, int yy) : Button1(win, c, t, a, aa, w, h, xx, yy) {}


ButtonLoadTexture::~ButtonLoadTexture()
{
}

void ButtonLoadTexture::actionPressed()
{
	if (mouseOnObject()) {
		if (pressed) {
			pressed = false;
		} else { 
			pressed = true;
			sf::RenderStates state;
			this->draw(*window, state);
			window->display();
			std::string address = "";
			//std::cout << std::endl << "The address of texture: " << std::endl;
			//std::cin >> address;
			address = "Textures\\button.png";
			sf::Texture text;
			if (text.loadFromFile(address)) {
				textures.emplace_back(text);
				rectangles.emplace_back(static_cast<sf::Vector2f>(textures.back().getSize()));
				rectangles.back().setPosition(500, 500);
				rectangles.back().setTexture(&textures.back());
			} else { 
				std::cout << "Loading texture(buttonLoadTexture) failed.";
			}
			pressed = false;
		}
	}
}

std::vector<sf::Texture>* ButtonLoadTexture::getTextures() { return &textures; }

std::vector<sf::RectangleShape>* ButtonLoadTexture::getTextureRectangles() { return &rectangles; };

/**sf::VertexArray ButtonLoadTexture::createConvexShapes(std::vector<ControllablePoint>* points)
{
	sf::VertexArray con;
	con.setPointCount(points->size());
	for (int i = 0; i < points->size(); ++i) {
		con.setPoint(i, sf::Vector2f(points->at(i).getPosition().x, points->at(i).getPosition().y));
	}
	//return con;
	std::vector<sf::ConvexShape> c;
	return c;
}
**/

void ButtonLoadTexture::moveTexture()
{ 
	if (movableRect == nullptr) {
		if (prevPoint.x != 0) {
			for (int i = 0; i < rectangles.size(); ++i) {
				if (rectangles[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)))) {
					movableRect = &rectangles[i];
					sf::RectangleShape s(rectangles[i].getSize());
					s.setPosition(rectangles[i].getPosition().x - prevPoint.x + sf::Mouse::getPosition().x, rectangles[i].getPosition().y - prevPoint.y + sf::Mouse::getPosition().y);
					if (!canvas->borderCollides(s)) {
						rectangles[i].setPosition(rectangles[i].getPosition().x - prevPoint.x + sf::Mouse::getPosition().x, rectangles[i].getPosition().y - prevPoint.y + sf::Mouse::getPosition().y);
					}
				}
			}
		}
	} else if(canvas->getRect().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)))) {
		sf::RectangleShape s(*movableRect);
		s.setPosition(movableRect->getPosition().x - prevPoint.x + sf::Mouse::getPosition().x, movableRect->getPosition().y - prevPoint.y + sf::Mouse::getPosition().y);
		if (!canvas->borderCollides(s)) {
			movableRect->setPosition(movableRect->getPosition().x - prevPoint.x + sf::Mouse::getPosition().x, movableRect->getPosition().y - prevPoint.y + sf::Mouse::getPosition().y);
		}
	}
	prevPoint.x = sf::Mouse::getPosition().x;
	prevPoint.y = sf::Mouse::getPosition().y;
}

void ButtonLoadTexture::setPrevPoint() { 
	prevPoint.x = 0;
	prevPoint.y = 0;
}

bool ButtonLoadTexture::getMousePressed() { return mousePressed; }

void ButtonLoadTexture::setMousePressed(bool b) {
	mousePressed = b;
	movableRect = nullptr;
}
