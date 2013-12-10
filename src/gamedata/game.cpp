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

		Node *Game::node(unsigned int id) const
		{
			return d->nodes[id];
		}

		void Game::addNode(Node *node)
		{
			node->setId(nodeCount());
			d->nodes.push_back(node);
		}

		unsigned int Game::nodeCount() const
		{
			return d->nodes.size();
		}
	}
}