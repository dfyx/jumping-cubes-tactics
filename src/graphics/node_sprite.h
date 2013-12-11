#ifndef JCT_SFML_GRAPHICS_NODE_SPRITE_H
#define JCT_SFML_GRAPHICS_NODE_SPRITE_H

#include "game_object.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
	}

	namespace Graphics
	{
		class NodeSprite : public GameObject
		{
		private:
			class NodeSpritePrivate *d;

		public:
			NodeSprite(const sf::RenderWindow &window, Gamedata::Node *node);
			~NodeSprite();

			const sf::Vector2f &position() const;
			void setPosition(const sf::Vector2f &position);

			sf::Color color() const;

			virtual bool collides(const sf::Vector2f &position) const;

		protected:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_NODE_SPRITE_H