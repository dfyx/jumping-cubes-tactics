#ifndef JCT_SFML_GRAPHICS_GAME_OBJECT_H
#define JCT_SFML_GRAPHICS_GAME_OBJECT_H

#include <SFML/Graphics.hpp>

namespace JCT_SFML
{
	namespace Graphics
	{
		class GameObject : public sf::Drawable
		{
		protected:
			const sf::RenderWindow &window;
		public:
			GameObject(const sf::RenderWindow &window) : window(window) {}
			virtual void update() {};

			virtual bool collides(const sf::Vector2f position) const {return false;}
		};
	}
}
#endif // JCT_SFML_GRAPHICS_GAME_OBJECT_H