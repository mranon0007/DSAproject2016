#include "InvertedIndex.h"

bool operator<(const struct InvertedIndex_Node & l, const struct InvertedIndex_Node & r) {
	return *l.keyword < *r.keyword;
}

//*********************************************************************				InvertedIndex

InvertedIndex_Node::InvertedIndex_Node(Word & word, WebPage_t & webpage) {
	this->keyword = &word.keyword;
	this->Webpages.insert(&webpage);
}

//******************************************************************				InvertedIndex List

InvertedIndex::invNode_itr InvertedIndex::WordPos(Word & _word) {
	InvertedIndex::invNode_itr itr;
	for (itr = Inverted_Vec.begin(); itr != Inverted_Vec.end(); ++itr) {
		if (compareStrings(*itr->keyword, _word.keyword)) {
			return itr;
		}
	}
	return Inverted_Vec.end();
}

void InvertedIndex::push(Word & word, WebPage_t & webpage) {
	InvertedIndex::invNode_itr wordpos = WordPos(word);
	//If IN LIST
	if (wordpos != Inverted_Vec.end()) { 
		wordpos->Webpages.insert(&webpage);
	}
	//If NOT IN LIST
	else {
		Inverted_Vec.insert(InvertedIndex_Node(word, webpage));
	}
}

void InvertedIndex::displayInverted() {
	invNode_itr itr = Inverted_Vec.begin();
	for (itr = Inverted_Vec.begin(); itr != Inverted_Vec.end(); itr++) {
		cout <<"\n\n\n" <<*itr->keyword << "  :  " ;
		for(auto iter = itr->Webpages.cbegin(); iter != itr->Webpages.cend(); iter++){
			cout << **iter << " , ";
		}
	}
}
