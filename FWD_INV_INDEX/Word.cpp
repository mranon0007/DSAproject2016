//#include "Word.h"
//
////*********************************************************************				WORD
//bool operator<(const Word & a, const Word & b) {
//	return (a.keyword < b.keyword) && (a.getweight() < b.getweight());
//}
//
//bool operator==(const Word & a, const Word & b) {
//	return compareStrings(a.keyword, b.keyword) && (a.location == b.location)
//		&& (a.heading == b.heading) && (a.uppercase == b.uppercase) && (a.italics == b.italics);
//}
//
//int Word::getweight(void) const {
//	return 1;
//}
//
//Word::Word(string _keyword) : heading(0), uppercase(false), italics(false) {
//	this->keyword = _keyword;
//}
//
//Word::Word(string _keyword, int _heading, bool _uppercase, bool _italics)
//	: Word(_keyword){
//	this->heading = _heading;
//	this->uppercase = _uppercase;
//	this->italics = _italics;
//}
