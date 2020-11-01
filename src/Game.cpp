#include "Game.h"

//Constructor/Destructor
Game::Game()
{
	this->init();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->isPaused = true;
}

void Game::initWindow()
{
	this->videoMode.width = SCREEN_WIDTH;
	this->videoMode.height = SCREEN_HEIGHT;
	this->window = new sf::RenderWindow(this->videoMode, GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(FRAMERATE);
	this->window->setVerticalSyncEnabled(false);
}

void Game::init()
{
	this->initVariables();
	this->initWindow();
	this->player = new Player();
}

void Game::pollEvent()
{
	while(this->window->pollEvent(this->event))
	{
		if(this->event.type == sf::Event::Closed || (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape))
			this->window->close();
		if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Space)
			isPaused = !isPaused;

	}
}

void Game::update()
{
	this->pollEvent();

	if(!isPaused)
	{
		//run the game if not paused
	}
}

void Game::render()
{
	this->window->clear();
	this->player->render(*this->window);
	this->window->display();
}

//Public funcions
void Game::run()
{
	 while(this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
