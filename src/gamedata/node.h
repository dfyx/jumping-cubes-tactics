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

			void addEdge(const Node *targetNode);
			void addEdge(const Edge *edge);

			const std::list<const Edge*> &edges() const;
			std::list<const Node*> neighbors() const;
			unsigned int edgeCount() const;

			unsigned int value() const;
			void setValue(unsigned int value);

			const Player *owner() const;
			void setOwner(const Player *owner);
		};
	}
}

#endif // JCT_SFML_GAMEDATA_NODE_H