#include "edge.h"
#include "edge_p.h"
#include "node.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Edge::Edge(Node* sourceNode, Node* targetNode)
		{
			d = new EdgePrivate();
			d->sourceNode = sourceNode;
			d->targetNode = targetNode;
		}

		Edge::~Edge()
		{
			delete d;
		}

		Node* Edge::sourceNode() const
		{
			return d->sourceNode;
		}

		Node* Edge::targetNode() const
		{
			return d->targetNode;
		}
	}
}