//#include "InvertedIndex.h"
//
////*********************************************************************				InvertedIndex
//InvertedIndex_Node::InvertedIndex_Node(Word * word, WebPage_t * webpage) {
//	this->keyword = word;
//	this->Webpages.push_front(make_pair(webpage, 1));
//}
//
////************************************				InvertedIndex List
//InvertedIndex::invNode_itr InvertedIndex::WordPos(Word* _word) {
//	for (InvertedIndex::invNode_itr itr = Inverted_Vec.begin(); itr != Inverted_Vec.end(); ++itr) {
//		//if ((*itr)->keyword->keyword == (_word->keyword));
//		if (compareStrings((itr)->keyword->keyword, (_word->keyword))) {
//			return itr;
//		}
//	}
//	return Inverted_Vec.end();
//}
//
//void InvertedIndex::push(Word * keyword, WebPage_t * webpage) {
//	InvertedIndex::invNode_itr wordpos = WordPos(keyword);
//	if (wordpos != Inverted_Vec.end()) { //If IN LIST
//		InvertedIndex_Node::webpages_itr itr;
//		for (itr = wordpos->Webpages.begin(); itr != wordpos->Webpages.end(); ++itr) {
//			if (webpage == itr->first) {
//				itr->second = itr->second + 1;
//			}
//		}
//	}
//	else {
//		/*InvertedIndex_Node temp(keyword, webpage); Inverted_Vec.push_back(temp);*/
//		Inverted_Vec.push_back(InvertedIndex_Node(keyword, webpage));
//	}
//}
