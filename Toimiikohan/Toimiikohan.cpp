// Toimiikohan.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "string"
#include "Canvas.h"
#include "ButtonNewPoint.h"
#include "ButtonLoadTexture.h"


int main()
{    // Textures\\canvas.png"
	sf::RenderWindow window(sf::VideoMode(902, 902), "kekkonen");
	Canvas canvas(&window,"", 500, 400, 400, 500);
	ButtonNewPoint buttonNew(&window, &canvas,"NewPoint", "Textures\\button.png","Textures\\buttonPressed.png", 100, 40,200,150);
	ButtonLoadTexture buttonLoad(&window, &canvas, "LoadTexture", "Textures\\button.png", "Textures\\buttonPressed.png", 100, 40, 200, 250);
	std::vector<ControllablePoint> *newButtonPoints = buttonNew.getPoints();
	ControllablePoint* movablePoint = nullptr;
	sf::VertexArray *shapeTextureArray = nullptr;
	std::vector<sf::Texture>* textures = buttonLoad.getTextures();
	std::vector<sf::RectangleShape>* textureRectangles = buttonLoad.getTextureRectangles();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					buttonNew.actionReleased();
					buttonLoad.setMousePressed(false);
					if (movablePoint != nullptr) {
						(*movablePoint).setMovable(&window, false);
						buttonNew.setModifiablePoint(false);
					}
					break;
				}
			case sf::Event::MouseMoved:
				if (movablePoint != nullptr && (*movablePoint).getMovable() && buttonNew.getModifiablePoint() && canvas.mouseOnObject()) {
					(*movablePoint).movePoint(&sf::Mouse::getPosition(window));
					break;
				}
				if(buttonLoad.getMousePressed()) buttonLoad.moveTexture();
				else buttonLoad.setPrevPoint();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					buttonNew.actionPressed();
					buttonLoad.actionPressed();
					buttonLoad.setMousePressed(true);
					if (!buttonNew.getModifiablePoint()) {
						for (int k = 0; k < (*newButtonPoints).size(); ++k) {
							if ((*newButtonPoints).at(k).setMovable(&window, true)) {  
								movablePoint = &(*newButtonPoints).at(k);
								buttonNew.setModifiablePoint(true);
							}
						}
					}
					break;
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					buttonNew.actionPressedRight();
					break;
				}		
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					buttonNew.cancelLastAction();
				}
			}
		}
		window.clear(sf::Color::White);
		window.draw(canvas);
		window.draw(buttonNew);	
		window.draw(buttonLoad);
		for (int i = 0; i < textureRectangles->size(); i++) {
			window.draw(textureRectangles->at(i));
			//window.draw((textureRectangles->at(i)), &(textures->at(i)));
		}
		buttonNew.drawLines(&window);
		window.display();
	}
	return 0;
}
