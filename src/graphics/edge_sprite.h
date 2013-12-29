#ifndef JCT_SFML_GRAPHICS_EDGE_SPRITE_H
#define JCT_SFML_GRAPHICS_EDGE_SPRITE_H

#include "game_object.h"

namespace JCT_SFML
{
	namespace Graphics
	{
		class NodeSprite;

		class EdgeSprite : public GameObject
		{
		private:
			class EdgeSpritePrivate *d;

		public:
			EdgeSprite(NodeSprite *from, NodeSprite *to);
			~EdgeSprite();

		protected:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_EDGE_SPRITE_H