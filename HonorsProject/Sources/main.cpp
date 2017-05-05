#include "GameHeader.h"

using namespace std;

int main()
{
    srand(time(0));
    GraphicsWindow gameWindow(1024, 768, "CS Honors");
    Game game;
    PlayGame(gameWindow, game);
    return 0;
}
