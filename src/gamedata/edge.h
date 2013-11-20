#ifndef JCT_SFML_GAMEDATA_EDGE_H
#define JCT_SFML_GAMEDATA_EDGE_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;

		class Edge
		{
		private:
			class EdgePrivate* d;
		public:
			Edge(const Node* sourceNode, const Node* targetNode);
			~Edge();

			const Node* sourceNode() const;
			const Node* targetNode() const;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_EDGE_H