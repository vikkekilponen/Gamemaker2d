#pragma once
#include "Canvas.h"
#include "Button1.h"
#include <SFML/Graphics.hpp>
#include "ControllablePoint.h"
#include <string>
#include <iostream>

class ButtonLoadTexture : public Button1
{

private:
	std::vector<sf::Texture> textures;
	std::vector<sf::RectangleShape> rectangles;
	sf::VertexArray convex;
	sf::Vector2i prevPoint = sf::Vector2i(0,0);
	bool mousePressed = false;
	sf::RectangleShape* movableRect = nullptr;

public:
	ButtonLoadTexture(sf::RenderWindow*, Canvas*, const char* textt, const char* address, const char* addressPressed, int w, int h, int xx = 0, int yy = 0);
	~ButtonLoadTexture();
	void actionPressed();
	//sf::VertexArray createConvexShapes(std::vector<ControllablePoint>*);
	std::vector<sf::Texture>* getTextures();
	std::vector<sf::RectangleShape>* getTextureRectangles();
	void moveTexture();
	void setPrevPoint();
	bool getMousePressed();
	void setMousePressed(bool);
};

