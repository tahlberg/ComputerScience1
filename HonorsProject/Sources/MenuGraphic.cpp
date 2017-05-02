#include "GameHeader.h"

void DrawDisplay(GraphicsWindow & w);
void DrawData(GraphicsWindow & w, Game g);

void MenuGraphic(GraphicsWindow & win, Game game)
{
    DrawDisplay(win);
    DrawData(win, game);
    win.WaitForKeyPress();
}

//Draws the framework for the display
void DrawDisplay(GraphicsWindow & w)
{
    Color white(255, 255, 255);
    w.DrawRectangle(0, 0, w.GetWidth()/3, w.GetHeight()/5, white, false);
    w.DrawRectangle((w.GetWidth()/3)*2, 0, w.GetWidth()/3, w.GetHeight()/5, white, false);
    w.DrawRectangle(w.GetWidth()/3, 0, w.GetWidth()/3, w.GetHeight()/5, white, false);
    w.DrawRectangle(0, (w.GetWidth()/4)*2, w.GetWidth(), w.GetHeight()/3, white, false);
    w.Refresh();
}

void DrawData(GraphicsWindow & w, Game g)
{
    Color white(255, 255, 255);
    w.DrawString(IntToString(g.player.totalHealth), 5, 5, white, 18);
}
