//Malcolm Case
//COSC-1437
//Professor McMillan
//Built April 13, 2022

#include <iostream>
#include <iomanip>
#include <string> 
#include "Scoreboard.h"
#include "Input_Validation_Extended.h"
using namespace std; 

class Team
{
  private:
    string name;  //add possession?
    string coach;
    string city;
    bool homeStatus;
    int score;
    int timeoutCount;
  public:
    Team() //default constructor 
    {
      name = "DefaultTeamName";
      coach = "DefaultCoachName";
      city = "DefaultCityName";
      homeStatus = false;
      score = 0;
      timeoutCount = 0;
    }
    void setName(string n) { name = n; }
    void setCoachName(string c) { coach = c; }
    void setCity (string sc) { city = sc; }
    void setHomeStatus(bool hs) { homeStatus = hs; }
    void setScore(int s) { score = s; }
    void setTimeoutCount(int tC) { timeoutCount = tC; }
    string getName() const { return name; }
    string getCoach() const { return coach; }
    string getCity() const { return city; }
    bool getHomeStatus() const { return homeStatus; }
    int getScore() const { return score; }
    int getTimeoutCount () const { return timeoutCount; }
};

class Scoreboard
{
  private:
    int time; 
    int half; 
    int down;
    int togo;
    Team home;
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 1; 
      time = 900;
      down = 1;
      togo = 10;
    }  
    void setHalf(int h) { half = h; }
    void setTime(int t) { time = t; }
    void setDown(int d) { down = d; }
    void setTogo(int tg) { togo = tg; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    int getTime() const { return time; }
    int getDown() const { return down; }
    int getTogo() const { return togo; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string green = "\x1b[32;4m"; //green underlined
      string blue = "\x1b[34m"; //blue bold
      string red = "\x1b[31m"; //red bold
      string reset = "\x1b[0m"; //reset color
      cout << green << "FOOTBALL SCOREBOARD" << reset << "\n\n"; 
      cout << blue << setw(20) << home.getName() << reset << setw(9) << (time/60) << ":";
      if ( time%60 == 0)
      {
        cout << (time%60) << "0";
      }
      else
      {
        cout << (time%60);
      }
      cout << red << setw(28) << visitor.getName() << reset << endl; 
      cout << blue << setw(20) << home.getScore() << reset << red << setw(40) << visitor.getScore() << reset << endl; 
      cout << setw(31) << "Half " << half << endl;
      cout << setw(19) << "Down " << down << setw(38) << "To Go " << togo << endl;
      cout << setw(19) << "Timeouts: " << blue << home.getTimeoutCount() << reset << red << setw(40) << visitor.getTimeoutCount() << reset << endl;
      cout << "------------------------------------------------------------\n";
      cout << blue << setw(20) << home.getCity() << reset << red << setw(40) << visitor.getCity() << reset << endl;
      cout << blue << setw(20) << home.getCoach() << reset << red << setw(40) << visitor.getCoach() << reset << endl << endl;
       
       //proces to show the home team status
       cout << setw(27) << "Home Team = \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << blue << setw(5) << "Team 1: " << home.getName() << reset; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << red << setw(5) << "Team 2: " << visitor.getName() << reset; 
       }
        else
       {
         cout << "Error: "; 
       }

      cout << endl;
      cout << "------------------------------------------------------------\n";
      cout << endl; 
    }
};

void submenu1()
{ 
  cout << "1 = Update Team 1 Name\n";
  cout << "2 = Update Team 1 Coach Name\n";
  cout << "3 = Update Team 1 City\n";
  cout << "4 = Update Team 1 Score\n";
  cout << "5 = Update Team 1 Timeout Count\n";
  cout << "6 = Return to Main Menu...\n";
  cout << ">";
};

void submenu2()
{ 
  cout << "1 = Update Team 2 Name\n";
  cout << "2 = Update Team 2 Coach Name\n";
  cout << "3 = Update Team 2 City\n";
  cout << "4 = Update Team 2 Score\n";
  cout << "5 = Update Team 2 Timeout Count\n";
  cout << "6 = Return to Main Menu...\n";
  cout << ">";
};

int main()
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoach = ""; 
  string newCity = "";
  int homeTeamQuestion = 0; 
  int newScore = 0; 
  int newTimeoutCount = 0;
  int newTime = 0;
  int newHalf = 0;  //add possession?
  int newDown = 0;
  int newTogo = 0;

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  s.setHome(tOne); 
  s.setVisitor(tTwo); 
  
  do 
  {
    system("clear");
    s.showScoreboard();
    cout << "1 = Update Team 1\n" ; 
    cout << "2 = Update Team 2\n" ; 
    cout << "3 = Update Home Status\n" ; 
    cout << "4 = Update Time\n" ; 
    cout << "5 = Update Half\n";
    cout << "6 = Update Down\n";
    cout << "7 = Update Yards Togo\n";
    cout << "0 = Exit\n";
    cout << ">"; 
    cin >> userChoice; 

    if(userChoice == "1")
    {
      do
      {
        system("clear");
        s.showScoreboard();
        submenu1();
        cin >> userChoice;
        if(userChoice == "1")
        {
          cout << "\nEnter new name for team 1: ";
          cin >> newName;
          tOne.setName(newName);
        }
        else if(userChoice == "2")
        {
          cout << "\nEnter new coach name for team 1: ";
          cin >> newCoach;
          tOne.setCoachName(newCoach);
        }
        else if(userChoice == "3")
        {
          cout << "\nEnter new city name for team 1: ";
          cin >> newCity;
          tOne.setCity(newCity);
        }
        else if(userChoice == "4")
        {
          cout << "\nEnter new score for team 1: ";
          newScore = validateInt(newScore);
          tOne.setScore(newScore);
        }
        else if(userChoice == "5")
        {
          cout << "\nEnter new timeout count for team 1: ";
          newTimeoutCount = validateInt(newTimeoutCount);
          tOne.setTimeoutCount(newTimeoutCount);
        }
        else if(userChoice == "6")
        {
          cout << "\nReturning to main menu...\n";
        }
        else
        {
          cout << "\nInvalid input. Try Again.\n";
        }
        s.setHome(tOne); //refresh the data in s to the new updates...
        s.setVisitor(tTwo); //refresh the data
      }while (userChoice != "6");
    }
    else if(userChoice == "2")
    {
      do
      {
        system("clear");
        s.showScoreboard();
        submenu2();
        cin >> userChoice;
        if(userChoice == "1")
        {
          cout << "\nEnter new name for team 2: ";
          cin >> newName;
          tTwo.setName(newName);
        }
        else if(userChoice == "2")
        {
          cout << "\nEnter new coach name for team 2: ";
          cin >> newCoach;
          tTwo.setCoachName(newCoach);
        }
        else if(userChoice == "3")
        {
          cout << "\nEnter new city name for team 2: ";
          cin >> newCity;
          tTwo.setCity(newCity);
        }
        else if(userChoice == "4")
        {
          cout << "\nEnter new score for team 2: ";
          newScore = validateInt(newScore);
          tTwo.setScore(newScore);
        }
        else if(userChoice == "5")
        {
          cout << "\nEnter new timeout count for team 2: ";
          newTimeoutCount = validateInt(newTimeoutCount);
          tTwo.setTimeoutCount(newTimeoutCount);
        }
        else if(userChoice == "6")
        {
          cout << "\nReturning to main menu...\n";
        }
        else
        {
          cout << "\nInvalid input. Try Again.\n";
        }
        s.setHome(tOne); //refresh the data in s to the new updates...
        s.setVisitor(tTwo); //refresh the data
      }while (userChoice != "6");
    }
    else if(userChoice == "3")
    {
      cout << "\nEnter the home team.\n1 = Team 1, 2 = Team 2: "; 
      homeTeamQuestion = validateInt(homeTeamQuestion); 
     // cin >> homeTeamQuestion; 
      if(homeTeamQuestion == 1)
      {
        tOne.setHomeStatus(true); 
        tTwo.setHomeStatus(false); 
      }
      else if(homeTeamQuestion == 2)
      {
        tOne.setHomeStatus(false); 
        tTwo.setHomeStatus(true);
      }
      else
      {
        cout << "\nInvalid Input!" << endl;
      }
    }
    else if(userChoice == "4") //update time
    {
      cout << "\nEnter the time left (in seconds): "; 
      newTime = validateInt(newTime);
      s.setTime(newTime); 
    }
    else if(userChoice == "5") //update half
    {
      cout << "\nEnter the current half: ";
      newHalf = validateInt(newHalf);
      s.setHalf(newHalf);
    }
    else if(userChoice == "6") //update down
    {
      cout << "\nEnter the current down: ";
      newDown = validateInt(newDown);
      s.setDown(newDown);
    }
    else if(userChoice == "7") //yards togo
    {
      cout << "\nEnter the current yards togo: "; 
      newTogo = validateInt(newTogo);
      s.setTogo(newTogo); 
    }
    else if(userChoice == "0")
    {
      cout << "Exit chosen." << endl; 
    }
    else //invalid input
    {
      cout << "\nInvalid input." << endl; 
    }

    s.setHome(tOne); //refresh the data in s to the new updates...
    s.setVisitor(tTwo); //refresh the data

}while(userChoice != "0");
  
  return 0; 
}