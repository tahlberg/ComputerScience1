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
    int pAtkChance = 0;
    int bAtkChance = 0;
    int pDamage = 0;
    int bDamage = 0;
    bool crit = false;
    bool parry = false;
    bool pMiss = 0;
    bool bMiss = 0;
};

//General Information
struct Info
{
    int encounters = 0;
    int numPotions = 0;
    int numPrint = 0;
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


//The Game
void PlayGame(GraphicsWindow & gameWindow, Game & game);

//Functions used in PlayGame
void StartGame(GraphicsWindow & win, Game & g);
void MenuGraphic(GraphicsWindow & win, Game game);
int ButtonMenu(GraphicsWindow & win);
void DeathScreen(GraphicsWindow & w, Game g);
bool DeathMenu(GraphicsWindow & w, Game g);

//Text wheel functions in Main
void FeedLevelUp(GraphicsWindow  & w, Game & g);
void FeedNewEncounter(GraphicsWindow & w, Game & g);
void FeedPotionDrop(GraphicsWindow & w, Game & g, int p);
void FeedSlashAttack(GraphicsWindow & w, Game & g);
void FeedStabAttack(GraphicsWindow & w, Game & g);
void FeedSmashAttack(GraphicsWindow & w, Game & g);
void FeedParryAttack(GraphicsWindow & w, Game & g);
void FeedPDamage(GraphicsWindow & w, Game & g);
void FeedBDamage(GraphicsWindow & w, Game & g);
void FeedPlayerMiss(GraphicsWindow & w, Game & g);
void FeedBossMiss(GraphicsWindow & w, Game & g);
void FeedNoPotion(GraphicsWindow & w, Game & g);
void FeedPotion(GraphicsWindow & w, Game & g, int h);
void TextCheck(GraphicsWindow & w, Game & g);

//Stat Generating
void NewEncounter(GraphicsWindow & win, Game & game);
void LevelPlayer(GraphicsWindow & win, Game & g);
void DropPotions(GraphicsWindow & win, Game & g);
void GenNewBoss(GraphicsWindow & win, Game & g);
string BossNameGen();

//Potion Use
void HealthPotion(GraphicsWindow & win, Game & g);

//Damage Resolution
void ResolvePDamage(GraphicsWindow & win, Game & g);
void ResolveBDamage(GraphicsWindow & win, Game & g);

//Player Attacks
void SlashAttack(Game & g);
void StabAttack(Game & g);
void SmashAttack(Game & g);
void ParryAttack(Game & g);

#endif // GAMEHEADER_H_INCLUDED
