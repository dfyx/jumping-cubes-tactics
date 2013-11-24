#ifndef JCT_SFML_GAMEDATA_GAME_P_H
#define JCT_SFML_GAMEDATA_GAME_P_H

#include <vector>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;

		class GamePrivate
		{
		public:
			std::vector<Node*> nodes;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_GAME_P_H