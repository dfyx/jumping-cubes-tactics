#include "edge.h"
#include "edge_p.h"
#include "node.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		Edge::Edge(const Node* sourceNode, const Node* targetNode)
		{
			d = new EdgePrivate();
			d->sourceNode = sourceNode;
			d->targetNode = targetNode;
		}

		Edge::~Edge()
		{
			delete d;
		}
	}
}