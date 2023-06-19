#include <SFML/Graphics.hpp>
#include "player.h"
#include "apple.h"
#include "bomb.h"
#include "textobj.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "game" );
	window.setFramerateLimit(60);
	Player player;
	Apple apple;
	Bomb bomb;
	Texture texture;
	Sprite sprite;
	sf::Font font;
	font.loadFromFile("DS-DIGIB.ttf");
	TextObj scoreText(font, sf::Vector2f(10.f, 10.f), 60);
	int score = 0;

	texture.loadFromFile("stone.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
		}

		player.update();
		apple.update();
		bomb.update();

		sf::FloatRect appleHitBox = apple.getHitBox();
		sf::FloatRect playerHitBox = player.getHitBox();
		sf::FloatRect bombHitBox = bomb.getHitBox();
		if (appleHitBox.intersects(playerHitBox)) {
			apple.sprite.setPosition(rand() % 800, 0);
			score++;
			scoreText.updateScore(1);
			apple.speedy += 0.1;
			bomb.speedy += 0.1;
		}
		if (bombHitBox.intersects(playerHitBox)) {
			break;
		}
		window.clear();
		window.draw(sprite);
		player.draw(window);
		apple.draw(window);
		bomb.draw(window);
		scoreText.draw(window);

		window.display();

	}
	return 0;
}