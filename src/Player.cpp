#include "Player.h"

//Constructor/Destructor
Player::Player()
{
	this->moveSpeed = 7.f; //Replace by the speed you want
	this->init(player);
}

Player::~Player()
{
}

//Private function
void Player::initTexture()
{
	//Load Texture from file
	this->texture.loadFromFile(PLAYER_SPRITE);
}

void Player::initSprite()
{
	//set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.scale(PLAYER_SPRITE_SCALE);
}

void Player::init()
{
	initTexture();
	initSprite();
	this->sprite.setPosition(PLAYER_POSX, PLAYER_POSY);

}

//Public functions
sf::FloatRect Player::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
