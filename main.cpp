#include <iostream>
#include "Time.h"

using namespace std;

int Commander(Time timeMan);


int main()
{
    Time testTime;
    Commander(testTime);
}

//Command line function:
/**
The idea is you would input a string and the compiler would scan the string for a command it recongize
**/
int Commander(Time timeMan){
    string cmd;
    cout << " Command: ";
    getline(cin, cmd);
    int blackspace = cmd.find_first_of(" ");

    if(cmd == "Quit" || cmd == "quit"){
        return 0; //Exits cleanly
    }else if(cmd == "Time" || cmd=="time"){
        cout << "Hour: " << timeMan.getHour() << " Minute: " << timeMan.getMinute() << endl; //Prints out time
        Commander(timeMan); //Returns to command line
    }else if(cmd.substr(0, blackspace) == "setTime"){
        blackspace = cmd.find_first_of(":"); //
        timeMan.setTime(stoi(cmd.substr(blackspace-3, blackspace-1)), stoi(cmd.substr(blackspace+1, blackspace+3)));
        Commander(timeMan);
    } else{
    Commander(timeMan);
    }
}
