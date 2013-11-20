#ifndef JCT_SFML_GAMEDATA_EDGE_H
#define JCT_SFML_GAMEDATA_EDGE_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;

		class Edge
		{
		public:
			Edge(const Node* sourceNode, const Node* targetNode);
		};
	}
}
#endif // JCT_SFML_GAMEDATA_EDGE_H