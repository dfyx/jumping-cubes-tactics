#ifndef JCT_SFML_GAMELOGIC_TURNCONTROLLER_H
#define JCT_SFML_GAMELOGIC_TURNCONTROLLER_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
		class Player;
	}

	namespace Gamelogic
	{

		class Turncontroller
		{
		private:
			class TurncontrollerPrivate* d;
		public:
			Turncontroller();
			~Turncontroller();

			void startTurn(Gamedata::Player* currentPlayer);
			bool increaseNode(Gamedata::Node* node);
		};
	}
}
#endif // JCT_SFML_GAMELOGIC_TURNCONTROLLER_H