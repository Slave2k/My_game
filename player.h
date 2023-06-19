#pragma once
#include "settings.h"
#include "apple.h"
class Player {
public:

	Texture texture;
	Sprite sprite;
	float speedx = 0.f;
	void draw(sf::RenderWindow& window);
	Player();
	void update();
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::FloatRect bounds;

};
Player::Player() {
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);
	sprite.setPosition(230, 674);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Player::update() {
	bounds = sprite.getGlobalBounds();
	speedx = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		speedx = -PLAYER_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		speedx = PLAYER_SPEED;
	}
	sprite.move(speedx, 0.f);
	sf::Vector2f playerPos = sprite.getPosition();
	if (playerPos.x < 0) {
		sprite.setPosition(0.f, playerPos.y);
	}
	else if (playerPos.x > WINDOW_WIDTH - bounds.width) {
		sprite.setPosition(WINDOW_WIDTH - bounds.width, playerPos.y);
	}

}
