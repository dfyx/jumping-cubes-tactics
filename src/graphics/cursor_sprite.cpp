#include "cursor_sprite.h"
#include "cursor_sprite_p.h"
#include "../gamedata/player.h"

namespace JCT_SFML
{
	namespace Graphics
	{
		CursorSprite::CursorSprite()
		{
			d = new CursorSpritePrivate();

			d->shape.setPointCount(3);
			d->shape.setPoint(0, sf::Vector2f(0, 0));
			d->shape.setPoint(1, sf::Vector2f(20, 0));
			d->shape.setPoint(2, sf::Vector2f(14, 14));
			d->shape.setFillColor(sf::Color::Black);
			d->shape.setOutlineThickness(2);

			setPlayer(NULL);
		}

		CursorSprite::~CursorSprite()
		{
			delete d;
		}

		void CursorSprite::setPlayer(Gamedata::Player *player)
		{
			d->player = player;
			if(player == NULL)
			{
				d->shape.setOutlineColor(sf::Color(0xCC, 0xCC, 0xCC));
			}
			else
			{
				d->shape.setOutlineColor(sf::Color(player->red(), player->green(), player->blue()));
			}
		}

		void CursorSprite::setPosition(const sf::Vector2f &position)
		{
			d->shape.setPosition(position);
		}

		void CursorSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
		    target.draw(d->shape);
		}
	}
}