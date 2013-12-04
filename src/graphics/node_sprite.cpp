#include "node_sprite.h"
#include "node_sprite_p.h"
#include "../gamedata/node.h"
#include <cmath>
#include <sstream>

namespace JCT_SFML
{
	namespace Graphics
	{
		const float NODE_SPRITE_RADIUS = 20;

		NodeSprite::NodeSprite(const sf::RenderWindow &window, Gamedata::Node *node)
			: GameObject(window)
		{
			d = new NodeSpritePrivate();

			d->node = node;

			d->circle.setRadius(NODE_SPRITE_RADIUS);
			d->circle.setFillColor(sf::Color::Black);
			d->circle.setOutlineThickness(2);
			d->circle.setOrigin(NODE_SPRITE_RADIUS, NODE_SPRITE_RADIUS);

			d->font.loadFromFile("/Library/Fonts/Arial.ttf");

			d->text.setCharacterSize(NODE_SPRITE_RADIUS);
			d->text.setFont(d->font);

			setPosition(sf::Vector2f(0, 0));
		}

		NodeSprite::~NodeSprite()
		{
			delete d;
		}

		const sf::Vector2f &NodeSprite::position() const
		{
			return d->circle.getPosition();
		}

		void NodeSprite::setPosition(const sf::Vector2f &position)
		{
			d->circle.setPosition(position);
			d->text.setPosition(position);
		}

		void NodeSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			// TODO: Do this depending on the node's owner
			sf::Color playerColor = sf::Color(0xCC, 0xCC, 0xCC);

			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			sf::Vector2f ownPosition = d->circle.getPosition();
			sf::Vector2f diff = sf::Vector2f(mousePosition.x - ownPosition.x,
											 mousePosition.y - ownPosition.y);
			float dist = sqrt(diff.x * diff.x + diff.y * diff.y);

			// Set colors
			d->circle.setOutlineColor(playerColor);
			if(dist <= NODE_SPRITE_RADIUS)
			{
				d->circle.setFillColor(playerColor);
				d->text.setColor(sf::Color::Black);
			}
			else
			{
				d->text.setColor(playerColor);
				d->circle.setFillColor(sf::Color::Black);
			}

			target.draw(d->circle);

			// Show current value
			std::ostringstream stream;
			stream << d->node->value();
			d->text.setString(stream.str());

			// Update text position
			sf::FloatRect localBounds = d->text.getLocalBounds();
			d->text.setOrigin(localBounds.width / 2, localBounds.height * 0.8);
			target.draw(d->text);
		}
	}
}