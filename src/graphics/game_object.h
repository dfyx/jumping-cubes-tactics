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
		};
	}
}
#endif // JCT_SFML_GRAPHICS_GAME_OBJECT_H