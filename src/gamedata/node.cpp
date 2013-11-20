#include "node.h"
#include "node_p.h"
#include "edge.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Node::Node()
		{
			d = new NodePrivate();
		}

		Node::~Node()
		{
			delete d;
		}

		void Node::addEdge(const Node* targetNode)
		{
			addEdge(new Edge(this, targetNode));
		}

		void Node::addEdge(const Edge* edge)
		{
			d->edges.push_back(edge);
		}

		const std::list<const Edge*> &Node::edges() const
		{
			return d->edges;
		}
	}
}