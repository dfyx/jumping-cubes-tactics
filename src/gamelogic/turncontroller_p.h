#ifndef JCT_SFML_GAMELOGIC_TURNCONTROLLER_P_H
#define JCT_SFML_GAMELOGIC_TURNCONTROLLER_P_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Player;
	}

	namespace Gamelogic
	{
		class TurncontrollerPrivate
		{
		public:
			Gamedata::Player *currentPlayer;
			Gamedata::Game *game;
		};
	}
}
#endif // JCT_SFML_GAMELOGIC_TURNCONTROLLER_P_H