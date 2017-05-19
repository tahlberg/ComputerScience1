#include "GameHeader.h"

//Struct that contains button information
struct Button
{
    string name;
    int x;
    int y;
    int w;
    int h;
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
    win.Refresh();
}

//Button use detection for the four attack functions
int ButtonMenu(GraphicsWindow & win)
{
    Button stab = {"Slash", 100, ((win.GetHeight()/3)*2)+25, 200, 100, 1};
    Button slash = {"Stab", (win.GetWidth()/2)+200, ((win.GetHeight()/3)*2)+25, 200, 100, 2};
    Button smash = {"Smash", 100, ((win.GetHeight()/3)*2)+135, 200, 100, 3};
    Button parry = {"Parry", (win.GetWidth()/2)+200, ((win.GetHeight()/3)*2)+135, 200, 100, 4};
    Button heal = {"Heal", (win.GetWidth()/3)+50, ((win.GetHeight()/3)*2)+25, 200, 100, 5};
    Button buttons[5] = {stab, slash, smash, parry, heal};
    bool buttonPress = false;
    while(buttonPress == false)
    {
        for(int i = 0; i < 5; i++)
        {
            DrawButton(win, buttons[i].name, buttons[i].x, buttons[i].y, 200, 100, Color(255, 255, 255));
        }
        win.Refresh();

        win.WaitForMouseDown();
        win.WaitForMouseUp();
        for(int n = 0; n < 5; n++)
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
    string score = "Score: ";
    score += IntToString(g.info.encounters - 1);
    bool retry = false;
    w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight(), Color(0, 0, 0), true);
    w.DrawString(score, 400, 300, Color(255, 255, 255), 72);
    w.DrawString("You Died", 275, 150, Color(255, 0, 0), 150);
    retry = DeathMenu(w, g);
    if(retry == true)
    {
        w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight(), Color(0, 0, 0), true);
        g.info.numPrint = 0;
        PlayGame(w, g);
    }
}

bool DeathMenu(GraphicsWindow & win, Game g)
{
    Button retry = {"Retry", 410, 425, 200, 100, 1};
    Button exit = {"Exit", 410, 550, 200, 100, 2};
    Button dButtons[2] = {retry, exit};
    bool buttonPress = false;
    int bChoice;
    while(buttonPress == false)
    {
        for(int i = 0; i < 2; i++)
        {
            DrawButton(win, dButtons[i].name, dButtons[i].x, dButtons[i].y, dButtons[i].w, dButtons[i].h, Color(255, 255, 255));
        }
        win.Refresh();

        win.WaitForMouseDown();
        win.WaitForMouseUp();
        for(int n = 0; n < 2; n++)
        {
            if(win.MouseX() >= dButtons[n].x && win.MouseX() <= (dButtons[n].x + 200) && win.MouseY() >= dButtons[n].y && win.MouseY() <= (dButtons[n].y + 100))
            {
                bChoice = dButtons[n].num;
            }
        }
        if(bChoice == 1)
        {
            return true;
        }
        else if(bChoice == 2)
        {
            return false;
        }
    }
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
}

//Draws all the printed information in the UI
void DrawData(GraphicsWindow & w, Game g)
{
    Color white(255, 255, 255);
    string playerHealth = "Player Health: ";
    playerHealth += IntToString(g.player.health);
    playerHealth += " / ";
    playerHealth += IntToString(g.player.totalHealth);
    string playerPotions = "Potions: ";
    playerPotions += IntToString(g.info.numPotions);
    string bossHealth = "Boss Health: ";
    bossHealth += IntToString(g.boss.health);
    bossHealth += " / ";
    bossHealth += IntToString(g.boss.totalHealth);
    w.DrawString(playerHealth, 10, 10, white, 24);
    w.DrawString(playerPotions, 10, 50, white, 24);
    w.DrawString("Encounter", (w.GetWidth()/3)+75, 10, white, 48);
    w.DrawString(IntToString(g.info.encounters), (w.GetWidth()/3)+150, 60, white, 72);
    w.DrawString(g.boss.name, ((w.GetWidth()/3)*2)+10, 10, white, 28);
    w.DrawString(bossHealth, ((w.GetWidth()/3)*2)+10, 50, white, 24);
}

//Draws a button
void DrawButton(GraphicsWindow & win, string str, int x, int y, int w, int h, Color c)
{
    Color blue(0, 0, 255);
    win.DrawRectangle(x, y, w, h, c, false);
    win.DrawString(str, x+10, y+10, c, sqrt(w)+w/3);
}

//Prints Level Up

void FeedLevelUp(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    w.DrawString("Your powers increase!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints New Encounter

void FeedNewEncounter(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    string encounterText = "You encountered ";
    encounterText += g.boss.name;
    encounterText += "!";
    w.DrawString(encounterText, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

void FeedPotionDrop(GraphicsWindow & w, Game & g, int p)
{
    TextCheck(w, g);
    string dropText;
    if(p == 1)
    {
        dropText = "You've found ";
        dropText += IntToString(p);
        dropText += " Health Potion!";
        w.DrawString(dropText, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    }
    if(p > 1)
    {
        dropText = "You've found ";
        dropText += IntToString(p);
        dropText += " Health Potions!";
        w.DrawString(dropText, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    }
    g.info.numPrint++;
}

//Prints use of Health Potion

void FeedPotion(GraphicsWindow & w, Game & g, int h)
{
    TextCheck(w, g);
    string healText = "You used a health potion to heal for ";
    healText += IntToString(h);
    healText += " health!";
    w.DrawString(healText, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints failed use of Health Potion

void FeedNoPotion(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    w.DrawString("You are out of Health Potions!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints the use of Slash
void FeedSlashAttack(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    w.DrawString("You used Slash!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints the use of Stab
void FeedStabAttack(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    w.DrawString("You used Stab!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints the use of Smash
void FeedSmashAttack(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    w.DrawString("You used Smash!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints the use of Parry
void FeedParryAttack(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    if(g.combat.parry == true)
    {
        w.DrawString("You parried the attack!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    }
    else if(g.combat.parry == false)
    {
        w.DrawString("You failed to parry the attack!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    }
    g.info.numPrint++;
}

//Prints the damage done by player
void FeedPDamage(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    string pDamageTxt = g.boss.name;
    pDamageTxt += " took ";
    pDamageTxt += IntToString(g.combat.pDamage);
    pDamageTxt += " damage!";
    w.DrawString(pDamageTxt, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

void FeedPlayerMiss(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    w.DrawString("You missed!", 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

void FeedBossMiss(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    string missText = g.boss.name;
    missText += " missed!";
    w.DrawString(missText, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Prints the damage done by boss
void FeedBDamage(GraphicsWindow & w, Game & g)
{
    TextCheck(w, g);
    string bDamageTxt = "You took ";
    bDamageTxt += IntToString(g.combat.bDamage);
    bDamageTxt += " damage!";
    w.DrawString(bDamageTxt, 10, (w.GetHeight()/5)+10+(20*g.info.numPrint), Color(255, 255, 255), 24);
    g.info.numPrint++;
}

//Checks if the text window is full and clears it if it is.
void TextCheck(GraphicsWindow & w, Game & g)
{
    if(g.info.numPrint >= 15)
    {
        g.info.numPrint = 0;
        w.DrawRectangle(0, (w.GetHeight()/5)+1, w.GetWidth(), ((w.GetHeight()/5)*2)+10, Color(0, 0, 0), true);
        w.Refresh();
    }
}
