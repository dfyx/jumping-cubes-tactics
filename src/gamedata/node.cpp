#include "node.h"
#include "node_p.h"
#include "edge.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Node::Node(unsigned int value)
		{
			d = new NodePrivate();
			d->value = value;
			d->owner = NULL;
		}

		Node::~Node()
		{
			delete d;
		}

		void Node::addEdge(Node* targetNode)
		{
			addEdge(new Edge(this, targetNode));
		}

		void Node::addEdge(Edge* edge)
		{
			d->edges.push_back(edge);
		}

		const std::list<Edge*> &Node::edges() const
		{
			return d->edges;
		}

		std::list<Node*> Node::neighbors() const
		{
			std::list<Edge*>::iterator iter;
			std::list<Node*> result;
			for(iter = d->edges.begin(); iter != d->edges.end(); iter++)
			{
				result.push_back((*iter)->targetNode());
			}
			return result;
		}

		unsigned int Node::edgeCount() const
		{
			return d->edges.size();
		}

		unsigned int Node::value() const
		{
			return d->value;
		}

		void Node::setValue(unsigned int value)
		{
			d->value = value;
		}

		Player *Node::owner() const
		{
			return d->owner;
		}

		void Node::setOwner(Player *owner)
		{
			d->owner = owner;
		}
	}
}