#include "GameHeader.h"

using namespace std;

int main()
{
    GraphicsWindow gameWindow(1024, 768, "CS Honors");
    Game game;
    game = StartGame(game);
    int buttonChoice;
    int numPrint = 0;
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
                    game = SlashAttack(game);
                    FeedSlashAttack(gameWindow, numPrint);
                    break;
                }
            case 2:
                {
                    game = StabAttack(game);
                    FeedStabAttack(gameWindow, numPrint);
                }
                break;
            case 3:
                {
                    game = SmashAttack(game);
                    FeedSmashAttack(gameWindow, numPrint);
                }
                break;
            case 4:
                {
                    game = ParryAttack(game);
                    FeedParryAttack(gameWindow, numPrint);
                }
                break;
            }
            game = ResolvePDamage(game);
            FeedPDamage(gameWindow, numPrint, game);
            game = ResolveBDamage(game);
            FeedBDamage(gameWindow, numPrint, game);
            if(game.player.alive == false)
            {
                break;
            }
        }
        game = GenNewBoss(game);
    }
    DeathScreen(gameWindow, game);
}
