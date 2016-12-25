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
#include "Word.h"

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