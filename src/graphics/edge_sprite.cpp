#include "edge_sprite.h"
#include "edge_sprite_p.h"
#include "node_sprite.h"

namespace JCT_SFML
{
	namespace Graphics
	{
		EdgeSprite::EdgeSprite(const sf::RenderWindow &window, NodeSprite *from, NodeSprite *to)
			: GameObject(window)
		{
			d = new EdgeSpritePrivate();
			d->from = from;
			d->to = to;
		}

		EdgeSprite::~EdgeSprite()
		{
			delete d;
		}

		void EdgeSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
		    sf::VertexArray vertexArray(sf::Lines, 2);
		    vertexArray[0] = sf::Vertex(d->from->position(), sf::Color(0xCC, 0xCC, 0xCC));
		    vertexArray[1] = sf::Vertex(d->to->position(), sf::Color(0xCC, 0xCC, 0xCC));

		    target.draw(vertexArray);
		}
	}
}