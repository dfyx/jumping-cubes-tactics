#ifndef JCT_SFML_GAMEDATA_NODE_P_H
#define JCT_SFML_GAMEDATA_NODE_P_H

#include <list>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Edge;
		class Player;

		class NodePrivate
		{
		public:
			std::list<const Edge*> edges;
			unsigned int value;
			const Player *owner;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_NODE_P_H