#include "names.h"
#include<iostream>
#include<string>
#include<fstream>    // file precompiler

using namespace std;

void getdata();    // functions
void menu();
bool play();
bool help();
bool exit();
bool highScore();

int countgood = 0;
int countbad = 0;
int u;
char g;
int answer;
int num;
naming rite;
string wname;
string user;
string reword;
ofstream count2;


int main()
{
	int input;


	system("color f4");

	do
	{
		menu();
		cin >> input;

		switch (input)
		{
		case 1:

			play();
			break;
		case 2:
			help();
			break;
		case 3:
			highScore();
			break;
		case 4:
			exit();
			break;
		default:
			cout << "You did not choose a command" << endl;
		}

	} while (input != 4);


	system("pause");
	return 0;

}

bool play()
{

	int countgood = 0;

	getdata();
	_sleep(5500);
	system("CLS");
	_sleep(700);

	cout << "...............LEVEL 1....................." << endl << endl;

	cout << "This game tests your level on how to read " << endl << endl;

	cout << "Enter a number between 0 and 50\n" << endl;

	cin >> u;
	if (cin.good())
	{

		{
			if (u > 0 && u < 50)
			{

				cout << "\nGood! You entered the number " << u << endl;
				countgood++;
			}
			else
			{

				cout << "\nWrong, you entered a number not in the range\n" << endl;
				countbad++;
			}

		}
	}
	else
	{

		cin.clear(0);
		cin.ignore(256, '\n');
		countbad++;
		cout << "Wrong, you entered a character" << endl;
	}

	cout << "\n....................................................\n" << endl;

	cout << "\nEnter an Alphabet\n\n";
	cin >> g;
	if (cin.good())
	{
		{
			if (((g >= 'A') && (g <= 'Z')) || ((g >= 'a') && (g <= 'z')))
			{

				cout << "\nYou entered the letter " << g << endl;
				countgood++;
			}

			else
			{

				cin.clear(0);
				cin.ignore(256, '\n');
				cout << "\nYour entry is not correct\n";
				countbad++;

			}
		}
	}
	else
	{

		cin.clear(0);
		cin.ignore(256, '\n');
		cout << "You entered a number\n" << endl;
		countbad++;
	}

	_sleep(1000);
	system("CLS");
	_sleep(1000);


	cout << "................WELCOME TO LEVEL 2.................." << endl;

	_sleep(1000);
	system("CLS");
	_sleep(1000);

	cout << "\n Time to guess\n" << endl;

	do
	{
		answer = 1 + (rand() % 10);
		cout << "\nI have a number between 1 and 10\nCan you guess the number\n" << endl;

		cin >> num;
		if (cin.good())
		{

			if (num == answer)
			{

				cout << "\nYou got the number\n";
				countgood++;
			}
			else
			{


				cout << "\nWrong guess\n";
				countbad++;

			}
		}

		else
		{
			cin.clear(0);
			cin.ignore(256, '\n');

			cout << "\nYou didn't enter a number\n";
			countbad++;

		}
		_sleep(3000);
		system("CLS");
		_sleep(3000);

	} while (!(num == answer));

	_sleep(1000);
	system("CLS");
	_sleep(1000);


	count2.open("count.txt");
	{
		count2 << countgood;
	}
	count2.close();

	highScore();

	return 1;

}
void getdata()
{


	cout << "\nPLEASE REGISTER TO START THE GAME\n";
	cin.clear(0);
	cin.ignore(256, '\n');
	cout << "\nEnter your name" << endl;
	getline(cin, wname);
	rite.setname(wname);
	cout << "\nChoose a Username\n";
	cin >> user;
	rite.setusername(user);
	cout << "\nChoose your Password\n";
	cin >> reword;
	rite.setpassword(reword);
	system("CLS");
	cout << "\nWELCOME TO MEMORY GAME" << endl;
	cout << "\nHello " << rite.getname() << ". \n\nYour USERNAME is " << rite.getusername() << ". \n\nAnd your PASSWORD is " << rite.getpassword() << endl;
	cout << endl;

}
void menu()
{
	cout << "Choose an option" << endl;
	cout << "1 - Play" << endl << "2 - Help" << endl << "3 - Highscore" << endl << "4 - Exit" << endl << endl;
}


bool help()
{
	cout << "\nPress 1 to Play the game" << endl << "Press 2 for Help\n" << "Press 3 for Highscore\n" << "Press 4 to exit the game\n" << endl;
	return 1;
}

bool exit()
{
	exit(1);
	return 1;
}

bool highScore()
{
	fstream count;

	count.open("count.txt");
	{
		count >> countgood;
		cout << "\nHighScore = " << countgood << endl << endl;
	}
	count.close();

	return 1;
}