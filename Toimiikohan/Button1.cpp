#include "Button1.h"

	Button1::Button1(sf::RenderWindow* win, Canvas* c, const char* textt, const char* address, const char* addressPressed, int w, int h, int xx = 0, int yy = 0) 
	{
		window = win;
		canvas = c;
		height = h;
		width = w;
		x = xx;
		y = yy;
		if (!texture.loadFromFile(address)) std::cout << "Loading texture(button) failed." << std::endl;
		if (!texturePressed.loadFromFile(addressPressed)) std::cout << "Loading texture(button) failed." << std::endl;
		if (!font.loadFromFile("Fonts/arial.ttf")) std::cout << "Loading font(button) failed." << std::endl;
		text = sf::Text::Text(textt, font, 14);
		text.setFillColor(sf::Color::Black);
		setTextPosition();
		rect = sf::RectangleShape::RectangleShape(sf::Vector2f(width, height));
		rectPressed = sf::RectangleShape::RectangleShape(sf::Vector2f(width, height));
		rect.setPosition(xx, yy);
		rect.setTexture(&texture);
		rectPressed.setPosition(xx, yy);
		rectPressed.setTexture(&texturePressed);

	}

	void Button1::draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		if (pressed == false) {
			target.draw(rect);
		}
		else {
			target.draw(rectPressed);
		}
		target.draw(text);
	}

	void Button1::setTextPosition() 
	{
		sf::FloatRect bounds = text.getGlobalBounds();
		text.setPosition((float)x + (width - bounds.width) / 2, (float)y + ((height - bounds.height) / 3));
	}

	bool Button1::getPressed() { return pressed; }

	void Button1::actionPressed() { pressed = true; }

	void Button1::actionReleased() { pressed = false; }

	Button1::~Button1() {}


