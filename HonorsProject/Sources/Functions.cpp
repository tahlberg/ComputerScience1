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
    g.boss.name = BossNameGen();
    g.boss.totalHealth = (rand()%31)+100;
    g.boss.atk = (rand()%6)+10;
    g.boss.def = (rand())%6+10;
    g.boss.health = g.boss.totalHealth;
}

//Generates the next boss
Boss GenNewBoss(Game g)
{
    Boss b;
    b.name = BossNameGen();
    b.totalHealth += rand()%31+1;
    b.atk += rand()%6+1;
    b.def += rand()%6+1;
    b.health = b.totalHealth;
    cout << "You encountered " << b.name << "!" << endl;
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
void SlashAttack(Combat & c, Player p)
{
    c.pAtkChance = rand()%9;
    c.pDamage = rand()%10+10+p.atk;
}

//Stab attack calculations - Medium Damage, Medium Accuracy
void StabAttack(Combat & c, Player p)
{
    c.pAtkChance = rand()%4;
    c.pDamage = rand()%10+20+p.atk;
}

//Smash attack calculations - High Damage, Low Accuracy
void SmashAttack(Combat & c, Player p)
{
    c.pAtkChance = rand()%2;
    c.pDamage = rand()%10+35+p.atk;
}

//Blocks nex8t boss attack - WIP
void ParryAttack(Combat & c, Player p)
{
    c.pAtkChance = rand()%3;
    if(c.pAtkChance != 0)
    {
        c.bAtkChance = 0;
    }
    c.pDamage = rand()%10+25+p.atk;
}

//Calculation for damage dealt to boss
void ResolvePDamage(Combat c, Player p, Boss & b)
{
    c.pDamage -= (b.def / 2);
    if(c.pAtkChance == 0)
    {
        c.pMiss = true;
        c.pDamage = 0;
    }
    else
    {
        b.health -= c.pDamage;
        if(b.health <= 0)
        {
            b.alive = false;
        }
    }
}

//Calculation for damage dealt to player
void ResolveBDamage(Combat c, Player & p, Boss b)
{
    c.bAtkChance = rand()%8;
    c.bDamage = rand()%10+b.atk;
    c.bDamage -= (p.def / 2);
    if(c.bAtkChance == 0)
    {
        c.bMiss = 0;
        c.bDamage = 0;
    }
    else
    {
        p.health -= c.bDamage;
        if(p.health <= 0)
        {
            p.alive = false;
        }
    }
}
