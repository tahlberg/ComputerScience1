#include "GameHeader.h"

using namespace std;

int main()
{
    GraphicsWindow gameWindow(1024, 768, "CS Honors");
    Game game;
    game = StartGame(game);
    cout << game.player.totalHealth << endl;
    MenuGraphic(gameWindow, game);
}
