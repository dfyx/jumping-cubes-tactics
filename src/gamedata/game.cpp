#include "game.h"
#include "game_p.h"
#include "node.h"

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

		unsigned int Game::nodeCount() const
		{
			return d->nodes.size();
		}
	}
}