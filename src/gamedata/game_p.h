#ifndef JCT_SFML_GAMEDATA_GAME_P_H
#define JCT_SFML_GAMEDATA_GAME_P_H

#include <vector>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Player;
		class Node;

		class GamePrivate
		{
		public:
			std::vector<Player*> players;
			std::vector<Node*> nodes;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_GAME_P_H