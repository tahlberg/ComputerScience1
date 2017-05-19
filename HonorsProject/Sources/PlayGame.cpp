#include "GameHeader.h"

///Game Logic

void PlayGame(GraphicsWindow & gameWindow, Game & game)
{
    StartGame(gameWindow, game);
    int buttonChoice;
    while(game.player.alive == true)
    {
        while(game.boss.alive == true)
        {
            MenuGraphic(gameWindow, game);
            buttonChoice = ButtonMenu(gameWindow);
            switch(buttonChoice)
            {
            case 1:
                {
                    SlashAttack(game);
                    FeedSlashAttack(gameWindow, game);
                }
                break;
            case 2:
                {
                    StabAttack(game);
                    FeedStabAttack(gameWindow, game);
                }
                break;
            case 3:
                {
                    SmashAttack(game);
                    FeedSmashAttack(gameWindow, game);
                }
                break;
            case 4:
                {
                    ParryAttack(game);
                    FeedParryAttack(gameWindow, game);
                }
                break;
            case 5:
                {
                    HealthPotion(gameWindow, game);
                }
                break;
            }
            ResolvePDamage(gameWindow, game);
            ResolveBDamage(gameWindow, game);
            if(game.player.alive == false)
            {
                break;
            }
        }
        NewEncounter(gameWindow, game);
    }
    DeathScreen(gameWindow, game);
}
