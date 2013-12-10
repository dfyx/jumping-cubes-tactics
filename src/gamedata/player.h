#ifndef JCT_SFML_GAMEDATA_PLAYER_H
#define JCT_SFML_GAMEDATA_PLAYER_H

#include <string>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Game;

		class Player
		{
		private:
			class PlayerPrivate* d;
		public:
			Player(Game *game, const std::string &name);
			~Player();

			const std::string &name() const;

			unsigned int score() const;
			void setScore(unsigned int score);

			bool hasWon() const;

			unsigned char red() const;
			unsigned char green() const;
			unsigned char blue() const;
			void setColor(unsigned char red, unsigned char green, unsigned char blue);
		};
	}
}
#endif // JCT_SFML_GAMEDATA_PLAYER_H