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

//Aliases
typedef string WebPage_t, FilePath_t;
typedef int WordLoc_t, WordCount_t;
//typedef string FilePath_t;

bool isArticle(string); //Check if keyword is an article 
bool compareStrings(const string &, const string &); //Compare 2 strings, Case INSENSITIVE
//bool compareStrings(const string & a, const string & b);
bool compareStrings(const char * a, const char * b);
string getToken(istream & ss); //Get token from istream

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

//*********************************************************************				ForwardIndex
/*A node (1 row) which contains the webpage, and the list of words 
and their positions in the document*/
struct ForwardIndex_Node {
	typedef map <Word *, set <WordLoc_t>> keywords_t;
	typedef keywords_t::iterator keywords_itr;

	ForwardIndex_Node(WebPage_t *, Word *, WordLoc_t *);
	ForwardIndex_Node();
	WebPage_t WebPage;
	mutable keywords_t keywords;

	//forward_list <pair <Word *, vector<WordLoc_t>>> keywords;
	//ForwardIndex(vector <FilePath_t *>);
};

/*A Container (LIST) to contain all the nodes of
forward index.*/
class ForwardIndex {
public:
	typedef set <struct ForwardIndex_Node> fwdNode_t;
	typedef fwdNode_t::iterator fwdNode_itr;
	typedef insert_iterator<fwdNode_t> fwdNode_insert_itr;

	fwdNode_t Forward_Vec;
	void push(WebPage_t *, Word*, WordLoc_t *);
	fwdNode_itr findWebpageInList(WebPage_t *);
	//bool compare(WebPage_t * y, struct ForwardIndex_Node * x) { return x.WebPage < *y; };
	//ForwardIndex_Node::keywords_itr wordLocInList(Word *);

	//struct Comp {
	//	// important: we need two overloads, because the comparison
	//	// needs to be done both ways to check for equality

	//	bool operator()(struct ForwardIndex_Node p, WebPage_t s) const
	//	{
	//		return p.first < s;
	//	}
	//	bool operator()(sizeWebPage_t_t s, struct ForwardIndex_Node p) const
	//	{
	//		return s < p.first;
	//	}
	//};
};

//*********************************************************************				InvertedIndex
/*A node to store a word, and a list of docs it
appears in with number of appearences.*/
struct InvertedIndex_Node {
	typedef forward_list < pair <WebPage_t *, WordCount_t> >::iterator webpages_itr;
	InvertedIndex_Node(Word *, WebPage_t *);
	Word * keyword;
	forward_list < pair <WebPage_t *, WordCount_t> > Webpages;
};

//************************************				InvertedIndex List
/* A container (LIST) to contain the nodes of Inverted Index.*/
class InvertedIndex {
public:
	typedef vector<struct InvertedIndex_Node>::iterator invNode_itr;

	vector <struct InvertedIndex_Node> Inverted_Vec;
	void push(Word*, WebPage_t *);
	invNode_itr WordPos(Word*);
};