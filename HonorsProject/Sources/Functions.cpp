#include "GameHeader.h"

///Define Functions
//Generates the player and first boss
void StartGame(GraphicsWindow & win, Game & g)
{
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
    g.info.numPotions = 1;
    g.info.encounters = 1;
    FeedNewEncounter(win, g);
}

void PlayGame(GraphicsWindow & gameWindow, Game & game)
{
    StartGame(gameWindow, game);
    int buttonChoice;
    while(game.player.alive == true)
    {
        while(game.boss.alive == true)
        {
            MenuGraphic(gameWindow, game);
            buttonChoice = ButtonMenu(gameWindow);
            switch(buttonChoice)
            {
            case 1:
                {
                    SlashAttack(game);
                    FeedSlashAttack(gameWindow, game);
                }
                break;
            case 2:
                {
                    StabAttack(game);
                    FeedStabAttack(gameWindow, game);
                }
                break;
            case 3:
                {
                    SmashAttack(game);
                    FeedSmashAttack(gameWindow, game);
                }
                break;
            case 4:
                {
                    ParryAttack(game);
                    FeedParryAttack(gameWindow, game);
                }
                break;
            case 5:
                {
                    HealthPotion(gameWindow, game);
                }
                break;
            }
            ResolvePDamage(game);
            FeedPDamage(gameWindow, game);
            ResolveBDamage(game);
            FeedBDamage(gameWindow, game);
            if(game.player.alive == false)
            {
                break;
            }
        }
        NewEncounter(gameWindow, game);
    }
    DeathScreen(gameWindow, game);
}

void NewEncounter(GraphicsWindow & win, Game & game)
{
    LevelPlayer(win, game);
    DropPotions(win, game);
    GenNewBoss(win, game);
}

void LevelPlayer(GraphicsWindow & win, Game & g)
{
    int healthIncrease;
    healthIncrease = rand()%15+20;
    g.player.totalHealth += healthIncrease;
    g.player.health += healthIncrease;
    g.player.atk += rand()%8+1;
    g.player.def += rand()%8+1;
    FeedLevelUp(win, g);
}

//Generates the next boss
void GenNewBoss(GraphicsWindow & win, Game & g)
{
    g.boss.name = BossNameGen();
    g.boss.totalHealth += rand()%10+31;
    g.boss.atk += rand()%6+1;
    g.boss.def += rand()%6+1;
    g.boss.health = g.boss.totalHealth;
    g.boss.alive = true;
    g.info.encounters++;
    FeedNewEncounter(win, g);
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

void DropPotions(GraphicsWindow & win, Game & g)
{
    int numDropped;
    int dropNum = rand()%100+1;
    if(dropNum  >= 90)
    {
        numDropped = 4;
    }
    if(dropNum >= 75)
    {
        numDropped = 3;
    }
    if(dropNum >= 50)
    {
        numDropped = 2;
    }
    else
    {
        numDropped = 1;
    }

    g.info.numPotions += numDropped;
    FeedPotionDrop(win, g, numDropped);
}

void HealthPotion(GraphicsWindow & win, Game & g)
{
    if(g.info.numPotions == 0)
    {
        FeedNoPotion(win, g);
    }
    else
    {
        int healthHealed = g.player.totalHealth/2;
        g.player.health += healthHealed;
        g.info.numPotions--;
        FeedPotion(win, g, healthHealed);
    }
}

// Slash attack calculations - Low Damage, High Accuracy
void SlashAttack(Game & g)
{
    g.combat.pAtkChance = rand()%9;
    g.combat.pDamage = rand()%10+10+g.player.atk;
}

//Stab attack calculations - Medium Damage, Medium Accuracy
void StabAttack(Game & g)
{
    g.combat.pAtkChance = rand()%4;
    g.combat.pDamage = rand()%10+20+g.player.atk;
}

//Smash attack calculations - High Damage, Low Accuracy
void SmashAttack(Game & g)
{
    g.combat.pAtkChance = rand()%2;
    g.combat.pDamage = rand()%10+35+g.player.atk;
}

//Blocks nex8t boss attack - WIP
void ParryAttack(Game & g)
{
    g.combat.pAtkChance = rand()%3;
    if(g.combat.pAtkChance != 0)
    {
        g.combat.bAtkChance = 0;
    }
    g.combat.pDamage = rand()%10+25+g.player.atk;
}

//Calculation for damage dealt to boss
void ResolvePDamage(Game & g)
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
}

//Calculation for damage dealt to player
void ResolveBDamage(Game & g)
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
}
