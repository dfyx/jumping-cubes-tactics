#ifndef JCT_SFML_GRAPHICS_NODE_SPRITE_H
#define JCT_SFML_GRAPHICS_NODE_SPRITE_H

#include <SFML/Graphics.hpp>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
	}

	namespace Graphics
	{
		class NodeSprite : public sf::Drawable
		{
		private:
			class NodeSpritePrivate *d;

		public:
			NodeSprite(Gamedata::Node *node);
			~NodeSprite();

			void setPosition(const sf::Vector2f &position);

		protected:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_NODE_SPRITE_H