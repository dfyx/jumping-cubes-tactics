#ifndef JCT_SFML_GAMELOGIC_TURNCONTROLLER_H
#define JCT_SFML_GAMELOGIC_TURNCONTROLLER_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
		class Player;
		class Game;
	}

	namespace Gamelogic
	{

		class Turncontroller
		{
		private:
			class TurncontrollerPrivate* d;
		public:
			Turncontroller(Gamedata::Game *game);
			~Turncontroller();

			void startNextTurn();
			Gamedata::Player *currentPlayer() const;

			bool increaseNode(Gamedata::Node* node);
			bool canIncreaseNode(Gamedata::Node* node);
		};
	}
}
#endif // JCT_SFML_GAMELOGIC_TURNCONTROLLER_H