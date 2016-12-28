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
	typedef set<WebPage_t *> webpages_t;
	typedef webpages_t::iterator webpages_itr;
	//typedef forward_list < pair <WebPage_t *, WordCount_t> >::iterator webpages_itr;

	InvertedIndex_Node(Word &, WebPage_t &);
	Keyword_t keyword;
	webpages_t Webpages;
};

//************************************				InvertedIndex List
/* A container (LIST) to contain the nodes of Inverted Index.*/
class InvertedIndex {
public:
	typedef vector<struct InvertedIndex_Node> invNode_t;
	typedef vector<struct InvertedIndex_Node>::iterator invNode_itr;

	invNode_t Inverted_Vec;
	void push(Word &, WebPage_t &);
	invNode_itr WordPos(Word &);
};