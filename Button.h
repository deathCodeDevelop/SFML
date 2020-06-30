#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using std::string;
using std::cout;

void Timer(float countOfSeconds);

class Button
{
public:
	Button(string buttonPass, string buttonPressedPass, sf::Color color, string text);

	/*getters*/

	const sf::Sprite& get();
	sf::Text& getText();

	/*setters*/

	void setText(string text);
	void setButton(string buttonPass, string buttonPressPass);
	void setPressColor(sf::Color color);
	void setPosition(float x, float y);
	void setFont(string pass);

	//on click event
	bool onClick(sf::RenderWindow& window, sf::Mouse::Button button);

	~Button();

private:
	sf::Texture texture;
	sf::Texture pressTexture;
	sf::Sprite button;
	sf::Font font;
	sf::Text text;
	sf::Color pressColor;
	
	bool pressed = false;
};

