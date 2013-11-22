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
			std::list<Edge*> edges;
			unsigned int value;
			Player *owner;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_NODE_P_H