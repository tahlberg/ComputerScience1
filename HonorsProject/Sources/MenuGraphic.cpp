#include "GameHeader.h"

//Struct that contains button information
struct Button
{
    string name;
    int x;
    int y;
    int num;
};
//Drawing Display
void EraseDisplay(GraphicsWindow & win);
void DrawDisplay(GraphicsWindow & w);
void DrawData(GraphicsWindow & w, Game g);
void DrawButton(GraphicsWindow & win, string str, int x, int y, int w, int h, Color c);

void MenuGraphic(GraphicsWindow & win, Game game)
{
    EraseDisplay(win);
    DrawDisplay(win);
    DrawData(win, game);
}

//Button use detection for the four attack functions
int ButtonMenu(GraphicsWindow & win)
{
    Button stab = {"Slash", 100, ((win.GetHeight()/3)*2)+25, 1};
    Button slash = {"Stab", (win.GetWidth()/2)+200, ((win.GetHeight()/3)*2)+25, 2};
    Button smash = {"Smash", 100, ((win.GetHeight()/3)*2)+135, 3};
    Button parry = {"Parry", (win.GetWidth()/2)+200, ((win.GetHeight()/3)*2)+135, 4};
    Button buttons[4] = {stab, slash, smash, parry};
    bool buttonPress = false;
    while(buttonPress == false)
    {
        for(int i = 0; i < 4; i++)
        {
            DrawButton(win, buttons[i].name, buttons[i].x, buttons[i].y, 200, 100, Color(255, 255, 255));
        }
        win.WaitForMouseDown();
        win.WaitForMouseUp();
        for(int n = 0; n < 4; n++)
        {
            if(win.MouseX() >= buttons[n].x && win.MouseX() <= (buttons[n].x + 200) && win.MouseY() >= buttons[n].y && win.MouseY() <= (buttons[n].y + 100))
            {
                return buttons[n].num;
            }
        }
    }
}

void DeathScreen(GraphicsWindow & w, Game g)
{
    w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight(), Color(0, 0, 0), true);
    w.DrawString("You Died", 400, 300, Color(255, 0, 0), 64);
    w.Refresh();
    w.WaitForKeyPress();
}

void EraseDisplay(GraphicsWindow & w)
{
    Color black(0, 0, 0);
    w.DrawRectangle(0, 0, w.GetWidth()/3, w.GetHeight()/5, black, true);
    w.DrawRectangle((w.GetWidth()/3)*2, 0, w.GetWidth()/3, w.GetHeight()/5, black, true);
    w.DrawRectangle(w.GetWidth()/3, 0, w.GetWidth()/3, w.GetHeight()/5, black, true);
    w.DrawRectangle(0, (w.GetHeight()/3)*2, w.GetWidth(), w.GetHeight()/3, black, true);
}

//Draws the UI framework
void DrawDisplay(GraphicsWindow & w)
{
    Color white(255, 255, 255);
    w.DrawRectangle(0, 0, w.GetWidth()/3, w.GetHeight()/5, white, false);
    w.DrawRectangle((w.GetWidth()/3)*2, 0, w.GetWidth()/3, w.GetHeight()/5, white, false);
    w.DrawRectangle(w.GetWidth()/3, 0, w.GetWidth()/3, w.GetHeight()/5, white, false);
    w.DrawRectangle(0, (w.GetHeight()/3)*2, w.GetWidth(), w.GetHeight()/3, white, false);
    w.Refresh();
}

//Draws all the printed information in the UI
void DrawData(GraphicsWindow & w, Game g)
{
    Color white(255, 255, 255);
    string playerHealth = "Player Health: ";
    playerHealth += IntToString(g.player.health);
    playerHealth += " / ";
    playerHealth += IntToString(g.player.totalHealth);
    string bossHealth = "Boss Health: ";
    bossHealth += IntToString(g.boss.health);
    bossHealth += " / ";
    bossHealth += IntToString(g.boss.totalHealth);
    w.DrawString(playerHealth, 10, 10, white, 24);
    w.DrawString("Encounter", (w.GetWidth()/3)+75, 10, white, 48);
    w.DrawString(IntToString(g.info.encounters), (w.GetWidth()/3)+150, 60, white, 72);
    w.DrawString(g.boss.name, ((w.GetWidth()/3)*2)+10, 10, white, 28);
    w.DrawString(bossHealth, ((w.GetWidth()/3)*2)+10, 50, white, 24);
    w.Refresh();
}

//Draws a button
void DrawButton(GraphicsWindow & win, string str, int x, int y, int w, int h, Color c)
{
    Color blue(0, 0, 255);
    win.DrawRectangle(x, y, w, h, c, false);
    win.DrawString(str, x+10, y+10, c, sqrt(w)+w/3);
    win.Refresh();
}

//Prints the use of Slash
void FeedSlashAttack(GraphicsWindow & w, int & n)
{
    TextCheck(w, n);
    w.DrawString("You used Slash!", 10, (w.GetHeight()/5)+10+(20*n), Color(255, 255, 255), 24);
    n++;
}

//Prints the use of Stab
void FeedStabAttack(GraphicsWindow & w, int & n)
{
    TextCheck(w, n);
    w.DrawString("You used Stab!", 10, (w.GetHeight()/5)+10+(20*n), Color(255, 255, 255), 24);
    n++;
}

//Prints the use of Smash
void FeedSmashAttack(GraphicsWindow & w, int & n)
{
    TextCheck(w, n);
    n++;
    w.DrawString("You used Smash!", 10, (w.GetHeight()/5)+10+(20*n), Color(255, 255, 255), 24);
    n++;
}

//Prints the use of Parry
void FeedParryAttack(GraphicsWindow & w, int & n)
{
    TextCheck(w, n);
    w.DrawString("You used Parry!", 10, (w.GetHeight()/5)+10+(20*n), Color(255, 255, 255), 24);
    n++;
}

//Prints the damage done by player
void FeedPDamage(GraphicsWindow & w, int & n, Game g)
{
    TextCheck(w, n);
    string pDamageTxt = g.boss.name;
    pDamageTxt += " took ";
    pDamageTxt += IntToString(g.combat.pDamage);
    pDamageTxt += " damage!";
    w.DrawString(pDamageTxt, 10, (w.GetHeight()/5)+10+(20*n), Color(255, 255, 255), 24);
    n++;
}

//Prints the damage done by boss
void FeedBDamage(GraphicsWindow & w, int & n, Game g)
{
    TextCheck(w, n);
    string bDamageTxt = "You took ";
    bDamageTxt += IntToString(g.combat.bDamage);
    bDamageTxt += " damage!";
    w.DrawString(bDamageTxt, 10, (w.GetHeight()/5)+10+(20*n), Color(255, 255, 255), 24);
    n++;
}

//Checks if the text window is full and clears it if it is.
void TextCheck(GraphicsWindow & w, int & n)
{
    if(n >= 12)
    {
        n = 0;
        w.DrawRectangle(0, (w.GetHeight()/5)+1, w.GetWidth(), ((w.GetHeight()/5)*2)-2, Color(0, 0, 0), true);
        w.Refresh();
    }
}
