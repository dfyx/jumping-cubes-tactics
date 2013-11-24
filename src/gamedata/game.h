#ifndef JCT_SFML_GAMEDATA_GAME_H
#define JCT_SFML_GAMEDATA_GAME_H

#include <string>

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

			void addPlayer(const std::string &name);

			unsigned int nodeCount() const;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_GAME_H