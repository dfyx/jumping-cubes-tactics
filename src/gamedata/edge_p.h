#ifndef JCT_SFML_GAMEDATA_EDGE_P_H
#define JCT_SFML_GAMEDATA_EDGE_P_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;

		class EdgePrivate
		{
		public:
			const Node* sourceNode;
			const Node* targetNode;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_EDGE_P_H