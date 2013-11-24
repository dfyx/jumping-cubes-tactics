#ifndef JCT_SFML_GAMELOGIC_TURNCONTROLLER_H
#define JCT_SFML_GAMELOGIC_TURNCONTROLLER_H

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Node;
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

			bool increaseNode(Gamedata::Node* node);
		};
	}
}
#endif // JCT_SFML_GAMELOGIC_TURNCONTROLLER_H