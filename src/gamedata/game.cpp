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
			d->neutralPlayer = new Player(this, "Neutral");
			d->neutralPlayer->setColor(0xCC, 0xCC, 0xCC);
		}

		Game::~Game()
		{
			delete d->neutralPlayer;
			delete d;
		}

		const Player *Game::neutralPlayer() const
		{
			return d->neutralPlayer;
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
			node->setOwner(d->neutralPlayer);
			d->nodes.push_back(node);
		}

		unsigned int Game::nodeCount() const
		{
			return d->nodes.size();
		}
	}
}