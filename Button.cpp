#include "Button.h"

void Timer(float countOfSeconds)
{

	sf::Clock clock;
	clock.restart();
	while (clock.getElapsedTime().asSeconds() <= float(countOfSeconds));

}

Button::Button(string buttonPass, string buttonPressedPass, sf::Color color, string text)
{
	setButton(buttonPass, buttonPressedPass);
	setPressColor(color);
	setText(text);
	this->pressed = false;
}

bool Button::onClick(sf::RenderWindow& window, sf::Mouse::Button button)
{
	int vidX = sf::Mouse::getPosition().x - window.getPosition().x - 8;
	int vidY = sf::Mouse::getPosition().y - window.getPosition().y - 31;

	if (sf::Mouse::isButtonPressed(button) && !pressed)
	{
		if (vidX >= this->button.getPosition().x - this->texture.getSize().x / 2
			&& vidX <= this->button.getPosition().x + this->texture.getSize().x / 2
			&& vidY >= this->button.getPosition().y - this->texture.getSize().y / 2
			&& vidY <= this->button.getPosition().y + this->texture.getSize().y / 2)
		{
			this->button.setColor(this->pressColor);
			this->button.setTexture(pressTexture);
			this->pressed = true;
		}
	}
	else if (!sf::Mouse::isButtonPressed(button) && pressed)
	{
		this->button.setColor(sf::Color::White);
		this->button.setTexture(texture);
		this->pressed = false;

		return true;
	}

	return false;
}

Button::~Button()
{

}

void Button::setPosition(float x, float y)
{
	this->button.setPosition(x, y);
	this->text.setPosition(x, y);
}

void Button::setPressColor(sf::Color color)
{
	this->pressColor = color;
}

void Button::setFont(string pass)
{
	if (!this->font.loadFromFile(pass))
		throw "eror: texture" + pass + "not found\n";

	this->text.setFont(this->font);
}

const sf::Sprite& Button::get()
{
	return this->button;
}

sf::Text& Button::getText()
{
	return this->text;
}

void Button::setText(string text)
{
	if (!this->font.loadFromFile("arial.ttf"))
		throw "eror: texture arial.ttf not found\n";

	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setCharacterSize(size_t(texture.getSize().y / 1.5));

	float width = this->text.getLocalBounds().width;
	float heigth = this->text.getLocalBounds().height;

	this->text.setOrigin(float(width / 2), float(heigth));
}

void Button::setButton(string buttonPass, string buttonPressPass)
{
	if (!this->texture.loadFromFile(buttonPass))
		throw "eror: texture" + buttonPass + "not found\n";

	if (!this->pressTexture.loadFromFile(buttonPressPass))
		throw "eror: texture" + buttonPass + "not found\n";

	this->button.setTexture(this->texture);
	this->button.setOrigin(float(texture.getSize().x / 2), float(texture.getSize().y / 2));
}
