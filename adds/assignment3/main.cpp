#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "Toolbox.h"
#include "Bureaucrat.h"
#include "Avalanche.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"
#include "Tournament.h"
#include "RandomComputer.h"
#include "Referee.h"
#include "Human.h"

using namespace std;


int main(int argc, char* argv[])
{
    string players;
    getline(cin, players);
    istringstream playTeam(players);
    Tournament newTeam;
    do
    {
        string word;
        playTeam >> word;
        
        if(word =="Human")
        {
            Player * newhum= new Human();
            newTeam.addPlayers(newhum);
        }
        
        if(word == "Avalanche")
        {
            Player * newLanche = new Avalanche();
            newTeam.addPlayers(newLanche);
        }
       
        if(word == "Bureaucrat")
        {
            Player * newCrat = new Bureaucrat();
            newTeam.addPlayers(newCrat);
        }
        if(word == "Toolbox")
        {
            Player * newBox = new Toolbox();
            newTeam.addPlayers(newBox);
            
        }
        if(word == "Crescendo")
        {
            Player * newCres = new Crescendo();
            newTeam.addPlayers(newCres);
        }
        if(word == "PaperDoll")
        {
            Player * newDoll = new PaperDoll();
            newTeam.addPlayers(newDoll);
        }
        if(word == "FistfullODollars")
        {
            Player * newFist = new FistfullODollars();
            newTeam.addPlayers(newFist);
        }
        if(word == "RandomComputer")
        {
            Player * newRan = new RandomComputer();
            newTeam.addPlayers(newRan);
        }
    } while (playTeam);
    
    
    cout << newTeam.against();
    
    
}


