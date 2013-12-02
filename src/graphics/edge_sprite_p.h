#ifndef JCT_SFML_GRAPHICS_EDGE_SPRITE_P_H
#define JCT_SFML_GRAPHICS_EDGE_SPRITE_P_H

namespace JCT_SFML
{
	namespace Graphics
	{
		class NodeSprite;

		class EdgeSpritePrivate
		{
		public:
			NodeSprite *from, *to;
		};
	}
}
#endif // JCT_SFML_GRAPHICS_EDGE_SPRITE_P_H