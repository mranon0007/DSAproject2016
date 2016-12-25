#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <forward_list>
#include <set>
#include <iterator>
#include "myfuncs.h"

//*********************************************************************				WORD
/*This class is used to store a word and it's properties.*/
class Word {
public:
	string keyword;
	int location;
	int heading;
	bool uppercase;
	bool italics;

	Word(string);
	Word(string, int, bool, bool);

	friend bool operator==(const Word &, const Word &);
	friend bool operator<(const Word &, const Word &);
};

