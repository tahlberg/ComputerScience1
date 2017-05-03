#ifndef GAMEHEADER_H_INCLUDED
#define GAMEHEADER_H_INCLUDED

#include "lpcgraphics.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

///Structs
//Player Data
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

//Boss Data
struct Boss
{
    string name;
    int totalHealth;
    int health;
    int atk;
    int def;
    bool alive;
};

//Combat Data
struct Combat
{
    int pAtkChance;
    int bAtkChance;
    int pDamage;
    int bDamage;
    bool pMiss;
    bool bMiss;
};

//General Information
struct Info
{
    int encounters = 0;
    vector<Boss> killed;
};

//Structure that contains all the structures for easy passing
struct Game
{
    Player player;
    Boss boss;
    Combat combat;
    Info info;
};

///Functions
//Main declaration to allow reference by external source files
int main();

//Functions used in Main
void MenuGraphic(GraphicsWindow & win, Game game);
int ButtonMenu(GraphicsWindow & win);
void DeathScreen(GraphicsWindow & w, Game g);

//Text wheel functions in Main
void FeedSlashAttack(GraphicsWindow & w, int & n);
void FeedStabAttack(GraphicsWindow & w, int & n);
void FeedSmashAttack(GraphicsWindow & w, int & n);
void FeedParryAttack(GraphicsWindow & w, int & n);
void FeedPDamage(GraphicsWindow & w, int & n, Game g);
void FeedBDamage(GraphicsWindow & w, int & n, Game g);
void TextCheck(GraphicsWindow & w, int & n);

//Encounter Generating
Game StartGame(Game g);
Game GenNewBoss(Game g);
string BossNameGen();

//Damage Resolution
Game ResolvePDamage(Game g);
Game ResolveBDamage(Game g);

//Player Attacks
Game SlashAttack(Game g);
Game StabAttack(Game g);
Game SmashAttack(Game g);
Game ParryAttack(Game g);


#endif // GAMEHEADER_H_INCLUDED
