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

struct Game
{
    struct Player player;
    struct Boss boss;
    struct Combat combat;
};

struct Info
{
    int encounters;
    vector<Boss> killed;
};


int main();
void MenuGraphic(GraphicsWindow & win, Game game);

//Boss Generating
Boss GenNewBoss(Game g);
string BossNameGen();

//Core Functions
Game StartGame(Game g);
void EndScreen();

//Damage Resolution
void ResolvePDamage(Combat c, Player p, Boss & b);
void ResolveBDamage(Combat c, Player & p, Boss b);

//Menus
void CombatMenu(Combat com, Player play, Boss boss);
void AttackMenu(Combat com, Player play, Boss boss);
void MagicMenu(Combat com, Player play, Boss boss);
void BagMenu(Combat com, Player play, Boss boss);
void OptionsMenu(Combat com, Player pay, Boss boss);

//Player Attacks
void SlashAttack(Combat & c, Player p);
void StabAttack(Combat & c, Player p);
void SmashAttack(Combat & c, Player p);
void ParryAttack(Combat & c, Player p);


#endif // GAMEHEADER_H_INCLUDED
