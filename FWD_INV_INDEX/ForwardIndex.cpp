#include "ForwardIndex.h"

bool operator<(const struct ForwardIndex_Node & l, const struct ForwardIndex_Node & r) {
	return l.WebPage < r.WebPage;
}

ForwardIndex_Node::ForwardIndex_Node(WebPage_t & _webpage, Word & _word, WordLoc_t & _wordLoc) {
	this->WebPage = _webpage;
	this->keywords.insert(make_pair(&_word.keyword, set < WordLoc_t > {_wordLoc}));
}
//*********************************************************************				ForwardIndex
void ForwardIndex::push(WebPage_t & _webpage, Word & _word, WordLoc_t & _wordLoc) {
	ForwardIndex::fwdNode_itr _webpage_itr = findWebpageInList(_webpage);// = Forward_Vec.begin();

	//*********************************************IF WEBPAGE EXISTS.
	if (_webpage_itr != Forward_Vec.end()) {

		//ForwardIndex::fwdNode_insert_itr _webpage_insert_itr(Forward_Vec, _webpage_itr);
		auto _word_itr = _webpage_itr->keywords.find(&_word.keyword);
		//*****************************************IF WEBPAGE & WORD EXISTS.
		if (_word_itr != _webpage_itr->keywords.end()) {
			_word_itr->second.insert(_wordLoc);
		}

		//*****************************************IF WEBPAGE, BUT NO KEYWORD.
		else {
			_webpage_itr->keywords.insert(make_pair(&_word.keyword, set < WordLoc_t > { _wordLoc }));
			{//set <WordLoc_t> temp = { *_wordLoc };
				//_webpage_insert_itr->keywords.insert(make_pair(_word, set < WordLoc_t > { *_wordLoc }));
				//pair <Word *, set <WordLoc_t>> temp();
				//set <WordLoc_t> temp = { *_wordLoc };
				//_webpage_itr->keywords.insert(make_pair(_word, temp));
			}
		}
	}

	//*********************************************IF WEbpage DOESNT EXISTS.
	else {
		Forward_Vec.insert(ForwardIndex_Node(_webpage, _word, _wordLoc));
	}
}

ForwardIndex::fwdNode_itr ForwardIndex::findWebpageInList(WebPage_t & _webpage) {
	fwdNode_itr itr = Forward_Vec.begin();
	for (itr = Forward_Vec.begin(); itr != Forward_Vec.end(); ++itr) {
		if (itr->WebPage == _webpage) return itr;
	}
	return itr;
}

//ForwardIndex_Node::keywords_itr ForwardIndex::wordLocInList(Word *) {
//	for (ForwardIndex_Node::keywords_itr itr = ((Forward_Vec.end() - 1))->keywords.front.s;; ++itr) {
//
//	}
//}
