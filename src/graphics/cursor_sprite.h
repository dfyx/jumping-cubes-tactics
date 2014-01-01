#ifndef JCT_SFML_GRAPHICS_CURSOR_SPRITE_H
#define JCT_SFML_GRAPHICS_CURSOR_SPRITE_H

#include "game_object.h"

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Player;
	}

	namespace Graphics
	{
		class CursorSprite : public GameObject
		{
		private:
			class CursorSpritePrivate *d;

		public:
			CursorSprite();
			~CursorSprite();

			void setPlayer(Gamedata::Player *player);
			void setPosition(const sf::Vector2f &position);

		protected:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_CURSOR_SPRITE_H