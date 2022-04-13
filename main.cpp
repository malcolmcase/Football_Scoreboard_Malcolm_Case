//Malcolm Case
//COSC-1437
//Professor McMillan
//Built April 13, 2022

#include <iostream>
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
      half = 0; 
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
      string color = ""; 
      string reset = "\x1b[0m";
      string teamColor = "\x1b[31;1m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color
      cout << color << "FOOTBALL SCOREBOARD" << reset << "\n"; 
      cout << home.getName() << "\t\t" << (time/60) << ":" << (time%60) <<  "\t\t" << visitor.getName() << "\t\t" << endl; 
      cout << "\t" << home.getScore() << "\t\t" << half << "\t\t" << visitor.getScore() << endl; 
      cout << "\t" << down << "down" << "\t\t\t\t\t\t" << togo << "to go";
      cout << "Timeouts: " << home.getTimeoutCount() << "\t\t\t\t\t\t\t\t" << visitor.getTimeoutCount();
      cout << "-----------------------------------";
      cout << home.getCity() << "\t\t" << visitor.getCity() << "\t\t" << endl;
      cout << home.getCoach() << "\t\t" << visitor.getCoach() << "\n";
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
        else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
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

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  do 
  {
    system("clear"); //clear the screen of previous content 
    s.showScoreboard(); //show the current scoreboard data
    //menu choices 
    cout << "A = Update Team 1\n" ; 
    cout << "B = Update Team 2\n" ; 
    cout << "C = Update Home Status\n" ; 
    cout << "D = Update Time\n" ; 
    cout << "E = Update Half\n";
    cout << "F = Update Down\n";
    cout << "G = Update Yards Togo\n";
    cout << "X = Exit\n";
    cout << ">"; 
    cin >> userChoice; 

    if(userChoice == "A" || userChoice == "a")
    {
      do
      {
        system("clear");
        
      }
      //Dr_T challenge Accept a new name for s's home team
      cout << "****Update Home Team Score module*** " << endl; 
      cout << "\nPlease enter a new name for the home team: ";
      cin >> newName; 
      //change that home team's default name
      tOne.setName(newName); //set tOne's data to the new desired name
    }
    else if(userChoice == "B" || userChoice == "b")
    {
      cout << "\nUpdate Home Score Module****" << endl; 
      cout << "\nPlease enter a new score for the home team: "; 
      cin >> newScore; 
      tOne.setScore(newScore);  //set the new score for tOne        
    }
    else if(userChoice == "C" || userChoice == "c")
    {
      cout << "\nUpdate Home Status Module****" << endl; 
      cout << "\nWho is the home team: 1 = T1, 2 = T2, 3 = T3: "; 
      homeTeamQuestion = validateInt(homeTeamQuestion); 
     // cin >> homeTeamQuestion; 
      if(homeTeamQuestion == 1)
      {
        tOne.setHomeStatus(true); 
        tTwo.setHomeStatus(false); 
        tThree.setHomeStatus(false);
      }
      else if(homeTeamQuestion == 2)
      {
        tOne.setHomeStatus(false); 
        tTwo.setHomeStatus(true);
        tThree.setHomeStatus(false);
      }
      else if(homeTeamQuestion == 3)
      {
        tOne.setHomeStatus(false); 
        tTwo.setHomeStatus(false);
        tThree.setHomeStatus(true);
      }
      else
      {
        cout << "\nInvalid Input!" << endl;
        sleep(2); 
      }
    }
    else if(userChoice == "D" || userChoice == "d")
    {
        cout << "\nUpdate Visitor Coach Module****" << endl; 
        cout << "\nPlease enter the visitor coach Name: "; 
        cin >> newCoachName; 
        tTwo.setCoachName(newCoachName); 
    }
    else if(userChoice == "E" || userChoice == "e")
    {
      cout << "****Update Team 3 name module*** " << endl; 
      cout << "\nPlease enter a new name for Team 3: ";
      cin >> newName; 
      tThree.setName(newName);
    }
    else if(userChoice == "F" || userChoice == "f")
    {
      cout << "****Update Team 3 city module\n";
      cout << "\nPlease enter a city name for Team 3: ";
      cin >> newCity;
      tThree.setCity(newCity);
    }
    else if(userChoice == "G" || userChoice == "g")
    {
        cout << "\nUpdate Team 3 Coach Module****" << endl; 
        cout << "\nPlease enter the Team 3 coach Name: "; 
        cin >> newCoachName; 
        tThree.setCoachName(newCoachName); 
    }
    else if(userChoice == "H" || userChoice == "h")
    {
      cout << "\nUpdate Team 3 Score Module****" << endl; 
      cout << "\nPlease enter a new score for Team 3: "; 
      cin >> newScore; 
      tThree.setScore(newScore);      
    }
    else if(userChoice == "I" || userChoice == "i")
    {
      cout << "\nUpdate Team 3 Foul Count Module****\n";
      cout << "\nPlease enter a new foul count for Team 3\n";
      cin >> newFoul;
      tThree.setFoul(newFoul);
    }
    else if(userChoice == "X" || userChoice == "x")
    {
      cout << "Exit chosen." << endl; 
    }
    else //invalid input: default clause
    {
      cout << "\nInvalid input." << endl; 
      sleep(2); //wait two seconds, go to the next process 
    }

    s.setHome(tOne); //refresh the data in s to the new updates...
    s.setVisitor(tTwo); //refresh the data
    s.setThree(tThree);

}while(userChoice != "X" && userChoice != "x");
  
  return 0; 
}