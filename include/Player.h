/**
	The Player pattern class
	A very standard player that have a sprite, a texture, a speed and his classic methods
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "constants.h"

class Player
{
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		float moveSpeed;

		void init();
		void initTexture();
		void initSprite();

	public:
		Player();
		virtual ~Player();

		sf::FloatRect getGlobalBounds();
		sf::Vector2f getPosition();

		void setScore(unsigned int score);
		void move(const float dirX, const float dirY);
		void update();
		void render(sf::RenderTarget& target);


	protected:


};

#endif // PLAYER_H
