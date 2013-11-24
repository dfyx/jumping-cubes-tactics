#ifndef JCT_SFML_GAMEDATA_GAME_H
#define JCT_SFML_GAMEDATA_GAME_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Game
		{
		private:
			class GamePrivate* d;
		public:
			Game();
			~Game();

			unsigned int nodeCount() const;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_GAME_H