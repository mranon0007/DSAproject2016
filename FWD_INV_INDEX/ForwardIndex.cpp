//#include "ForwardIndex.h"
//
//bool operator<(const struct ForwardIndex_Node & l, const struct ForwardIndex_Node & r) {
//	return l.WebPage < r.WebPage;
//}
//
//ForwardIndex_Node::ForwardIndex_Node(WebPage_t & _webpage, Word & _word, WordLoc_t & _wordLoc) {
//	this->WebPage = _webpage;
//	this->keywords.insert(make_pair(&_word.keyword, set < WordLoc_t > {_wordLoc}));
//}
//
////*********************************************************************				ForwardIndex
//void ForwardIndex::push(WebPage_t & _webpage, Word & _word, WordLoc_t & _wordLoc) {
//	ForwardIndex::fwdNode_itr _webpage_itr = findWebpageInList(_webpage);// = Forward_Vec.begin();
//
//	//*********************************************IF WEBPAGE EXISTS.
//	if (_webpage_itr != Forward_Vec.end()) {
//		auto _word_itr = _webpage_itr->keywords.find(&_word.keyword);
//		//*****************************************IF WEBPAGE & WORD EXISTS.
//		if (_word_itr != _webpage_itr->keywords.end()) {
//			_word_itr->second.insert(_wordLoc);
//		}
//
//		//*****************************************IF WEBPAGE, BUT NO KEYWORD.
//		else {
//			_webpage_itr->keywords.insert(make_pair(&_word.keyword, set < WordLoc_t > { _wordLoc }));
//		}
//	}
//
//	//*********************************************IF WEbpage DOESNT EXISTS.
//	else {
//		Forward_Vec.insert(ForwardIndex_Node(_webpage, _word, _wordLoc));
//	}
//}
//
//ForwardIndex::fwdNode_itr ForwardIndex::findWebpageInList(WebPage_t & _webpage) {
//	fwdNode_itr itr = Forward_Vec.begin();
//	for (itr = Forward_Vec.begin(); itr != Forward_Vec.end(); ++itr) {
//		if (itr->WebPage == _webpage) return itr;
//	}
//	return itr;
//}
//
//void ForwardIndex::displayForward() {
//	fwdNode_itr itr = Forward_Vec.begin();
//	for (itr = Forward_Vec.begin(); itr != Forward_Vec.end(); ++itr) {
//		cout  <<"WebPage : " << itr->WebPage <<endl;
//		cout << "KeyWords occuring in this webpage are:" << endl;
//		for (auto iter = itr->keywords.cbegin(); iter != itr->keywords.cend(); iter++) {
//			cout << *iter->first << " , ";
//		}
//		cout << "\n\n\n";
//	}
//}
//
//
