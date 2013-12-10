#ifndef JCT_SFML_GAMEDATA_NODE_H
#define JCT_SFML_GAMEDATA_NODE_H

#include <list>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Edge;
		class Player;

		class Node
		{
		private:
			class NodePrivate *d;

		public:
			Node(unsigned int value = 1);
			~Node();

			unsigned int id() const;
			void setId(unsigned int id);

			void addEdge(Node *targetNode);
			void addEdge(Edge *edge);

			const std::list<Edge*> &edges() const;
			std::list<Node*> neighbors() const;
			unsigned int edgeCount() const;

			unsigned int value() const;
			void setValue(unsigned int value);

			Player *owner() const;
			void setOwner(Player *owner);
		};
	}
}

#endif // JCT_SFML_GAMEDATA_NODE_H