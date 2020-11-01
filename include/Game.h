/**
	The Game framework class
	By default, it just contains 1 player and no enemies (v1.0)
*/
#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
	private:
		sf::RenderWindow* window;
		sf::Event event;
		sf::VideoMode videoMode;
		Player* player;
		bool isPaused;

		void initVariables();
		void initWindow();
		void init();

		void pollEvent();
		void update();
		void render();

	public:

		Game();
		virtual ~Game();


		void run();

	protected:


};

#endif // GAME_H
