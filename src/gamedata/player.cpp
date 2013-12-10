#include "player.h"
#include "player_p.h"
#include "game.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Player::Player(Game *game, const std::string &name)
		{
			d = new PlayerPrivate();
			d->game = game;
			d->name = name;
			d->score = 0;

			d->red = 255;
			d->green = 0;
			d->blue = 0;
		}

		Player::~Player()
		{
			delete d;
		}

		const std::string &Player::name() const
		{
			return d->name;
		}

		unsigned int Player::score() const
		{
			return d->score;
		}

		void Player::setScore(unsigned int score)
		{
			d->score = score;
		}

		bool Player::hasWon() const
		{
			return score() >= d->game->nodeCount();
		}

		unsigned char Player::red() const
		{
			return d->red;
		}

		unsigned char Player::green() const
		{
			return d->green;
		}

		unsigned char Player::blue() const
		{
			return d->blue;
		}

		void Player::setColor(unsigned char red, unsigned char green, unsigned char blue)
		{
			d->red = red;
			d->green = green;
			d->blue = blue;
		}
	}
}