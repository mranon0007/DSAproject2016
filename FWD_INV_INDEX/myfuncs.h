#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include "dirent.h"
using namespace std;

//Aliases

typedef string WebPage_t, Keyword_t, FilePath_t;
typedef int WordLoc_t, WordCount_t;
//typedef string FilePath_t;

bool isArticle(string); //Check if keyword is an article 
bool compareStrings(const string &, const string &); //Compare 2 strings, Case INSENSITIVE
//bool compareStrings(const string & a, const string & b);
bool compareStrings(const char * a, const char * b);
string getToken(istream & ss); //Get token from istream

void GetReqDirs(const std::string&, std::vector<string>&, const bool showHiddenDirs = false);