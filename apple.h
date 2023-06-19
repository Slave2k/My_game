#pragma once
#include "settings.h"
#include "ctime"
class Apple {
public:
	Texture texture;
	Sprite sprite;
	float speedy = 6;
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::FloatRect bounds;
	Apple();
	void update();
	void draw(sf::RenderWindow& window);
	sf::Vector2f setPosition;
};
Apple::Apple() {
	srand(time(nullptr));
	texture.loadFromFile("apple.png");
	sprite.setTexture(texture);
	sprite.setPosition(rand() % 800, 0);
}

void Apple::update() {
	sprite.move(0, speedy);
	if (sprite.getPosition().y > WINDOW_HEIGHT) {
		sprite.setPosition(rand() % 800, 0);
	}
}
void Apple::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}