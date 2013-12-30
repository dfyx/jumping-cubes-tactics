#ifndef JCT_SFML_GAMEDATA_GAME_H
#define JCT_SFML_GAMEDATA_GAME_H

#include <string>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
		class Player;

		class Game
		{
		private:
			class GamePrivate* d;
		public:
			Game();
			~Game();

			const Player *neutralPlayer() const;
			Player *player(unsigned int id) const;
			void addPlayer(const std::string &name);
			unsigned int playerCount() const;

			Node *node(unsigned int id) const;
			void addNode(Node *node);

			unsigned int nodeCount() const;
		};
	}
}
#endif // JCT_SFML_GAMEDATA_GAME_H