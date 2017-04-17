#pragma once
#include<string>
#include<vector>
using namespace std;
class Puzzle
{
private:
	string question;
	vector<string> answers;
public:
	Puzzle();
	virtual ~Puzzle();
};

