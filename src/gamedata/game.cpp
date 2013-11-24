#include "game.h"
#include "game_p.h"
#include "node.h"
#include "player.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Game::Game()
		{
			d = new GamePrivate();
		}

		Game::~Game()
		{
			delete d;
		}

		void Game::addPlayer(const std::string &name)
		{
			Player *player = new Player(this, name);
			d->players.push_back(player);
		}

		unsigned int Game::nodeCount() const
		{
			return d->nodes.size();
		}
	}
}