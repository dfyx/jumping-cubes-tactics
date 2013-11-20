#ifndef JCT_SFML_GAMEDATA_NODE_H
#define JCT_SFML_GAMEDATA_NODE_H

#include <list>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Edge;

		class Node
		{
		private:
			class NodePrivate *d;

		public:
			Node();
			~Node();

			void addEdge(const Node *targetNode);
			void addEdge(const Edge *edge);

			const std::list<const Edge*> &edges() const;
			std::list<const Node*> neighbors() const;
		};
	}
}

#endif // JCT_SFML_GAMEDATA_NODE_H