#ifndef JCT_SFML_GAMEDATA_PLAYER_H
#define JCT_SFML_GAMEDATA_PLAYER_H

#include <string>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Player
		{
		private:
			class PlayerPrivate* d;
		public:
			Player(const std::string &name);
			~Player();

			const std::string &name() const;

			unsigned int score() const;
			void setScore(unsigned int score);
		};
	}
}
#endif // JCT_SFML_GAMEDATA_PLAYER_H