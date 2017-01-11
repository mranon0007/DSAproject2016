//#pragma once
//using namespace std;
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <list>
//#include <map>
//#include <forward_list>
//#include <set>
//#include <iterator>
//#include "Word.h"
//#include "myfuncs.h"
//
////*********************************************************************				ForwardIndex
///*A node (1 row) which contains the webpage, and the list of words
//and their positions in the document*/
//struct ForwardIndex_Node {
//	//map key comparison function
//	struct map_cmp {
//		bool operator() (const Keyword_t * l, const Keyword_t * r) { return *l < *r; }
//	};
//
//	typedef map <Keyword_t *, set <WordLoc_t>, map_cmp> keywords_t;
//	typedef keywords_t::iterator keywords_itr;
//
//	ForwardIndex_Node(WebPage_t &, Word &, WordLoc_t &);
//	WebPage_t WebPage;
//	mutable keywords_t keywords;
//
//	friend bool operator<(const struct ForwardIndex_Node &, const struct ForwardIndex_Node &);
//
//
//};
//
///*A Container (LIST) to contain all the nodes of
//forward index.*/
//class ForwardIndex {
//public:
//	typedef set <struct ForwardIndex_Node> fwdNode_t;
//	typedef fwdNode_t::iterator fwdNode_itr;
//	//typedef insert_iterator<fwdNode_t> fwdNode_insert_itr;
//
//	fwdNode_t Forward_Vec;
//	void push(WebPage_t &, Word &, WordLoc_t &);
//	fwdNode_itr findWebpageInList(WebPage_t &);
//	void displayForward();
//};