#ifndef JCT_SFML_GAMEDATA_PLAYER_P_H
#define JCT_SFML_GAMEDATA_PLAYER_P_H

#include <string>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Game;

		class PlayerPrivate
		{
		public:
			Game *game;
			std::string name;
			unsigned int score;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_PLAYER_P_H