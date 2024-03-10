#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

enum enChoice {Stone = 1 , Paper = 2 , Scissors = 3};


struct stGameresults 
{
	string RoundWinner = "h";
	string FinalWinner = "f";
	int UserScore = 1;
	int ComputerScore = 2;
	int AllMatches = 3;
	int DrawTimes = 3;
	enChoice PlayerChoice = Stone;
	enChoice Computer_Choice = Stone;
};

int RandNumber(int From, int To)
{
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int ReadNumber(int From , int To)
{
	int Number = 0;
	cin >> Number;
	return Number;
}

stGameresults AllChoices()
{
	srand((unsigned)time(NULL));
	stGameresults Score;
	int Number = ReadNumber(1, 3);
	Score.PlayerChoice = (enChoice)Number;
	int Number2 = RandNumber(1, 3);
	Score.Computer_Choice = (enChoice)Number2;
	return Score;
}

static stGameresults RulesOfTheGame(stGameresults results)
{
	if (results.PlayerChoice == enChoice::Stone && results.Computer_Choice == enChoice::Stone)
	{
		cout << "Player1  Choice: " << "Stone" << endl;
		cout << "Computer Choice: " << "Stone" << endl;
		results.RoundWinner = "[No Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 6F");
		results.AllMatches++;
		results.DrawTimes++;
	}
	else if (results.PlayerChoice == enChoice::Paper && results.Computer_Choice == enChoice::Paper)
	{
		cout << "Player1  Choice: " << "Paper" << endl;
		cout << "Computer Choice: " << "Paper" << endl;
		results.RoundWinner = "[No Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 6F");
		results.AllMatches++;
		results.DrawTimes++;
	}
	else if (results.PlayerChoice == enChoice::Scissors && results.Computer_Choice == enChoice::Scissors)
	{
		cout << "Player1  Choice: " << "Scissors" << endl;
		cout << "Computer Choice: " << "Scissors" << endl;
		results.RoundWinner = "[No Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 6F");
		results.AllMatches++;
		results.DrawTimes++;
	}
	else if (results.PlayerChoice == enChoice::Stone && results.Computer_Choice == enChoice::Paper)
	{
		cout << "Player1  Choice: " << "Stone" << endl;
		cout << "Computer Choice: " << "Paper" << endl;
		results.RoundWinner = "[Computer Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 4F");
		cout << "\a";
		results.AllMatches++;
		results.ComputerScore++;
	}
	else if (results.PlayerChoice == enChoice::Paper && results.Computer_Choice == enChoice::Stone)
	{
		cout << "Player1  Choice: " << "Paper" << endl;
		cout << "Computer Choice: " << "Stone" << endl;
		results.RoundWinner = "[Player Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 2F");
		results.AllMatches++;
		results.UserScore++;
	}
	else if (results.PlayerChoice == enChoice::Stone && results.Computer_Choice == enChoice::Scissors)
	{
		cout << "Player1  Choice: " << "Stone" << endl;
		cout << "Computer Choice: " << "Scissors" << endl;
		results.RoundWinner = "[Player Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 2F");
		results.AllMatches++;
		results.UserScore++;
	}
	else if (results.PlayerChoice == enChoice::Scissors && results.Computer_Choice == enChoice::Stone)
	{
		cout << "Player1  Choice: " << "Scissors" << endl;
		cout << "Computer Choice: " << "Stone" << endl;
		results.RoundWinner = "[Computer Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 4F");
		cout << "\a";
		results.AllMatches++;
		results.ComputerScore++;
	}
	else if (results.PlayerChoice == enChoice::Scissors && results.Computer_Choice == enChoice::Paper)
	{
		cout << "Player1  Choice: " << "Scissors" << endl;
		cout << "Computer Choice: " << "Paper" << endl;
		results.RoundWinner = "[Player Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 2F");
		results.AllMatches++;
		results.UserScore++;
	}
	else if (results.PlayerChoice == enChoice::Paper && results.Computer_Choice == enChoice::Scissors)
	{
		cout << "Player1  Choice: " << "Paper" << endl;
		cout << "Computer Choice: " << "Scissors" << endl;
		results.RoundWinner = "[Computer Winner]";
		cout << "Round Winner   :" << results.RoundWinner;
		system("color 4F");
		cout << "\a";
		results.AllMatches++;
		results.ComputerScore++;
	}

	if (results.ComputerScore > results.UserScore)
		results.RoundWinner = "Player 1";
    
	else if (results.ComputerScore < results.UserScore)
		results.RoundWinner = "Computer";

	else if(results.ComputerScore == results.UserScore)
		results.RoundWinner = "No Winner";

	return results;
}

void GameResults(stGameresults results , int N )
{

	cout << "                                 ------------------------------------------------------------";
	cout << endl;
	cout << "                                                    +++ G a m e  O v e r +++                 ";
	cout << endl;
	cout << "                                 ------------------------------------------------------------";
	cout << endl;
	cout << "                                 ------------------------------------------------------------";
}

void StartingGame()
{

	cout << "How many rounds do you want to play?" << endl;
	stGameresults results;
	results.DrawTimes = 0;
	results.AllMatches = 0;
	results.ComputerScore = 0;
	results.UserScore = 0;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		cout << endl;
		cout << "Round [" << i + 1 << "] begins:\n";
		cout << "___________________Round [" << i + 1 << "]_________________________";
		cout << endl;
		cout << endl;
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
		RulesOfTheGame(AllChoices());
		cout << endl;
		cout << "_____________________________________________________";
		
		cout << endl;
	}
	GameResults(RulesOfTheGame(AllChoices()) , N);	
}

bool AfterChoicing()
{
	cout << endl;
	char Type = 'p';
	cout << "Do you want to play again? Y/N?";
	cin >> Type;
	if (Type == 'y' || Type == 'Y')
	{
		return true;
	}
	else
		return false;

}

int main()
{
	srand((unsigned)time(NULL));


	StartingGame();

	while (AfterChoicing())
	{
		system("color 0F");
		StartingGame();
	}
	

	return 0;
}