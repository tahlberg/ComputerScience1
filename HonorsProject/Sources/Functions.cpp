#include "GameHeader.h"

///Define Functions
//Generates the player and first boss
Game StartGame(Game g)
{
    srand(time(0));
    g.player.totalHealth = (rand()%10) + 80;
    g.player.atk = (rand()%8)+7;
    g.player.def = (rand()%8)+7;
    g.player.health = g.player.totalHealth;
    g.player.alive = true;
    g.boss.name = BossNameGen();
    g.boss.totalHealth = (rand()%31)+100;
    g.boss.atk = (rand()%6)+10;
    g.boss.def = (rand())%6+10;
    g.boss.health = g.boss.totalHealth;
    g.boss.alive = true;
    g.info.encounters = 1;
    return g;
}

//Generates the next boss
Game GenNewBoss(Game g)
{
    g.boss.name = BossNameGen();
    g.boss.totalHealth += rand()%31+1;
    g.boss.atk += rand()%6+1;
    g.boss.def += rand()%6+1;
    g.boss.health = g.boss.totalHealth;
    g.boss.alive = true;
    g.info.encounters++;
    return g;
}

//Generates the name of the boss
string BossNameGen()
{
    int nameGen = rand()%9+1;
    int titleGen = rand()%9+1;
    string name;
    string title;
    string genName;
    switch(nameGen)
    {
    case 1:
        name = "Baruch";
        break;
    case 2:
        name = "Kiumbe";
        break;
    case 3:
        name = "Abaddon";
        break;
    case 4:
        name = "Gilgamesh";
        break;
    case 5:
        name = "Kairan";
        break;
    case 6:
        name = "Zelran";
        break;
    case 7:
        name = "Deimos";
        break;
    case 8:
        name = "Vanthos";
        break;
    case 9:
        name = "Yanthin";
        break;
    case 10:
        name = "Anthum";
        break;
    }
    switch(titleGen)
    {
    case 1:
        title = "Omnipotent";
        break;
    case 2:
        title = "Undead";
        break;
    case 3:
        title = "Archmage";
        break;
    case 4:
        title = "Destroyer";
        break;
    case 5:
        title = "Malevolent";
        break;
    case 6:
        title = "Evil";
        break;
    case 7:
        title = "Defiled";
        break;
    case 8:
        title = "Silent";
        break;
    case 9:
        title = "Ruthless";
        break;
    case 10:
        title = "Legend";
        break;
    }
    genName = name;
    genName += " the ";
    genName += title;
    return genName;
}

// Slash attack calculations - Low Damage, High Accuracy
Game SlashAttack(Game g)
{
    g.combat.pAtkChance = rand()%9;
    g.combat.pDamage = rand()%10+10+g.player.atk;
    return g;
}

//Stab attack calculations - Medium Damage, Medium Accuracy
Game StabAttack(Game g)
{
    g.combat.pAtkChance = rand()%4;
    g.combat.pDamage = rand()%10+20+g.player.atk;
    return g;
}

//Smash attack calculations - High Damage, Low Accuracy
Game SmashAttack(Game g)
{
    g.combat.pAtkChance = rand()%2;
    g.combat.pDamage = rand()%10+35+g.player.atk;
    return g;
}

//Blocks next boss attack - WIP
Game ParryAttack(Game g)
{
    g.combat.pAtkChance = rand()%3;
    if(g.combat.pAtkChance != 0)
    {
        g.combat.bAtkChance = 0;
    }
    g.combat.pDamage = rand()%10+25+g.player.atk;
    return g;
}

//Calculation for damage dealt to boss
Game ResolvePDamage(Game g)
{
    g.combat.pDamage -= (g.boss.def / 2);
    if(g.combat.pAtkChance == 0)
    {
        g.combat.pMiss = true;
        g.combat.pDamage = 0;
    }
    else
    {
        g.boss.health -= g.combat.pDamage;
        if(g.boss.health <= 0)
        {
            g.boss.alive = false;
        }
    }
    return g;
}

//Calculation for damage dealt to player
Game ResolveBDamage(Game g)
{
    g.combat.bAtkChance = rand()%8;
    g.combat.bDamage = rand()%10+g.boss.atk;
    g.combat.bDamage -= (g.player.def / 2);
    if(g.combat.bAtkChance == 0)
    {
        g.combat.bMiss = 0;
        g.combat.bDamage = 0;
    }
    else
    {
        g.player.health -= g.combat.bDamage;
        if(g.player.health <= 0)
        {
            g.player.alive = false;
        }
    }
    return g;
}
