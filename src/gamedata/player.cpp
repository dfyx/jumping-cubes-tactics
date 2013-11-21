#include "player.h"
#include "player_p.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Player::Player(const std::string &name)
		{
			d = new PlayerPrivate();
			d->name = name;
		}

		Player::~Player()
		{
			delete d;
		}

		const std::string &Player::name() const
		{
			return d->name;
		}
	}
}