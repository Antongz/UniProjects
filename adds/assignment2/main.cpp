#include"human.h"
#include"computer.h"
#include"referee.h"
using namespace std;
#include <cstdio>
#include <cctype>

int main()
{
puts("first input number for game times then input [R]ock,[P]aper or[S]cissors in order ,example:4 R R R");
 string s;
 getline(cin,s);


    Human player;
    player.setHMove();
    player.getHMove();

    player.setNumGames();
    player.getNumGames();

    int games;
    games = player.getNumGames();

    Computer comp(games);
    comp.getCMove();
    
    
    Referee ref(games);
    ref.play(s);
    ref.results();

    return 0;
}

