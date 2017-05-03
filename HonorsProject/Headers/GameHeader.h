#ifndef GAMEHEADER_H_INCLUDED
#define GAMEHEADER_H_INCLUDED

#include "lpcgraphics.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Player
{
    int health;
    int totalHealth;
    int def;
    int atk;
    int defMod;
    int atkMod;
    bool alive;
};

struct Boss
{
    string name;
    int totalHealth;
    int health;
    int atk;
    int def;
    bool alive;
};

struct Combat
{
    int pAtkChance;
    int bAtkChance;
    int pDamage;
    int bDamage;
    bool pMiss;
    bool bMiss;
};

struct Info
{
    int encounters = 0;
    vector<Boss> killed;
};

struct Game
{
    Player player;
    Boss boss;
    Combat combat;
    Info info;
};


int main();
void MenuGraphic(GraphicsWindow & win, Game game);
int ButtonMenu(GraphicsWindow & win);
void DeathScreen(GraphicsWindow & w, Game g);

void FeedSlashAttack(GraphicsWindow & w, int & n);
void FeedStabAttack(GraphicsWindow & w, int & n);
void FeedSmashAttack(GraphicsWindow & w, int & n);
void FeedParryAttack(GraphicsWindow & w, int & n);
void FeedPDamage(GraphicsWindow & w, int & n, Game g);
void FeedBDamage(GraphicsWindow & w, int & n, Game g);
void TextCheck(GraphicsWindow & w, int & n);

//Boss Generating
Game GenNewBoss(Game g);
string BossNameGen();

//Core Functions
Game StartGame(Game g);
void EndScreen();

//Damage Resolution
Game ResolvePDamage(Game g);
Game ResolveBDamage(Game g);

//Player Attacks
Game SlashAttack(Game g);
Game StabAttack(Game g);
Game SmashAttack(Game g);
Game ParryAttack(Game g);


#endif // GAMEHEADER_H_INCLUDED
