#pragma once
#include "settings.h"
#include "ctime"
class Bomb {
public:
	Texture texture;
	Sprite sprite;
	float speedy = 6;
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::FloatRect bounds;
	Bomb();
	void update();
	void draw(sf::RenderWindow& window);
	sf::Vector2f setPosition;
};
Bomb::Bomb() {
	srand(time(nullptr));
	texture.loadFromFile("bomb.png");
	sprite.setTexture(texture);
	sprite.setPosition(rand() % 800, 0);
}

void Bomb::update() {
	sprite.move(0, speedy);
	if (sprite.getPosition().y > WINDOW_HEIGHT) {
		sprite.setPosition(rand() % 800, 0);
	}
}
void Bomb::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}