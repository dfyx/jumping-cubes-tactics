#ifndef JCT_SFML_GRAPHICS_CURSOR_SPRITE_P_H
#define JCT_SFML_GRAPHICS_CURSOR_SPRITE_P_H

#include <SFML/Graphics.hpp>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Player;
	}

	namespace Graphics
	{
		class CursorSpritePrivate
		{
		public:
			Gamedata::Player *player;
			sf::ConvexShape shape;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_CURSOR_SPRITE_P_H