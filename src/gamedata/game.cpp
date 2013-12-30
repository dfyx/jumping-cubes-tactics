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

		Player *Game::player(unsigned int id) const
		{
			return d->players[id];
		}

		void Game::addPlayer(const std::string &name)
		{
			addPlayer(name, 0xFF, 0x00, 0x00);
		}

		void Game::addPlayer(const std::string &name,
							 unsigned char red,
							 unsigned char green,
							 unsigned char blue)
		{
			Player *player = new Player(this, name);
			player->setColor(red, green, blue);
			d->players.push_back(player);
		}

		unsigned int Game::playerCount() const
		{
			return d->players.size();
		}

		Node *Game::node(unsigned int id) const
		{
			return d->nodes[id];
		}

		void Game::addNode(Node *node)
		{
			node->setId(nodeCount());
			node->setOwner(d->neutralPlayer);
			d->neutralPlayer->setScore(d->neutralPlayer->score() + 1);
			d->nodes.push_back(node);
		}

		unsigned int Game::nodeCount() const
		{
			return d->nodes.size();
		}
	}
}