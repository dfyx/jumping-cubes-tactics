#ifndef JCT_SFML_GAMEDATA_NODE_P_H
#define JCT_SFML_GAMEDATA_NODE_P_H

#include <list>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Edge;
		class NodePrivate
		{
		public:
			std::list<const Edge*> edges;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_NODE_P_H