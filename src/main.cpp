#include <iostream>
#include <memory>
#include "bowling.hpp"


using namespace std;

int main()
{
	string tokens = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
	auto game =	std::make_shared<Bowling>(tokens);
	if(game->validateTokens())
	{	
		int score = game->countPoints();
		cout << "wynik: " << score << endl;
	}

	return 0;
}


