#include <SFML/Graphics.hpp>
#include "settings.h"
class TextObj {
public:
    TextObj(sf::Font& font, sf::Vector2f position, int fontSize){
        text.setFont(font);
        text.setCharacterSize(fontSize);
        text.setPosition(position);
        score = 0;
    }

    void updateScore(int points) {
        score += points;
        text.setString("Score: " + std::to_string(score));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }

private:
    sf::Text text;
    int score;
};