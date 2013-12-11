#include "turncontroller.h"
#include "turncontroller_p.h"
#include "../gamedata/node.h"
#include "../gamedata/player.h"
#include "../gamedata/game.h"
#include <queue>
#include <list>

namespace JCT_SFML
{
	namespace Gamelogic
	{
		Turncontroller::Turncontroller(Gamedata::Game *game)
		{
			d = new TurncontrollerPrivate();
			d->game = game;
		}

		Turncontroller::~Turncontroller()
		{
			delete d;
		}

		void Turncontroller::startTurn(Gamedata::Player* currentPlayer)
		{
			d->currentPlayer = currentPlayer;
		}

		bool Turncontroller::increaseNode(Gamedata::Node* node)
		{
			std::queue<Gamedata::Node*> nodesToIncrease;
			Gamedata::Player* currentOwner = node->owner();
			if(currentOwner == d->game->neutralPlayer() || currentOwner == d->currentPlayer)
			{
				nodesToIncrease.push(node);
				while(!d->currentPlayer->hasWon()
					  && !nodesToIncrease.empty())
				{
					Gamedata::Node* currentNode = nodesToIncrease.front();
					nodesToIncrease.pop();
					currentOwner = currentNode->owner();

					// Update owner and scores
					if(currentOwner != d->currentPlayer)
					{
						if(currentOwner != NULL)
						{
							currentOwner->setScore(currentOwner->score() - 1);
						}
						currentNode->setOwner(d->currentPlayer);
						d->currentPlayer->setScore(d->currentPlayer->score() + 1);
					}

					// Update value
					currentNode->setValue(currentNode->value() + 1);
					if(currentNode->edgeCount() != 0)
					{
						while(currentNode->value() > currentNode->edgeCount())
						{
							currentNode->setValue(currentNode->value() - currentNode->edgeCount());
							std::list<Gamedata::Node*> neighbors = currentNode->neighbors();

							// Add neighbors to queue
							std::list<Gamedata::Node*>::iterator iter;
							for(iter = neighbors.begin(); iter != neighbors.end(); ++iter)
							{
								nodesToIncrease.push(*iter);
							}
						}
					}
				}

				return true;
			}
			else
			{
				return false;
			}
		}
	}
}