#ifndef JCT_SFML_GRAPHICS_NODE_SPRITE_P_H
#define JCT_SFML_GRAPHICS_NODE_SPRITE_P_H

#include <SFML/Graphics.hpp>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
	}

	namespace Graphics
	{
		class NodeSpritePrivate
		{
		public:
			Gamedata::Node *node;
			sf::CircleShape circle;
			sf::Text text;
			sf::Font font;
			bool highlighted;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_NODE_SPRITE_P_H