#include "myheader.h"


//*********************************************************************				WORD
bool operator<(const Word & a, const Word & b) {
	return a.keyword < b.keyword;
}

bool operator==(const Word & a, const Word & b) {
	return compareStrings(a.keyword, b.keyword) && (a.location == b.location)
		&& (a.heading == b.heading) && (a.uppercase == b.uppercase) && (a.italics == b.italics);
}

Word::Word(string _keyword) : heading(0), uppercase(false), italics(false) {
	this->keyword = _keyword;
}

Word::Word(string _keyword, int _heading, bool _uppercase, bool _italics)
	: Word(_keyword){
	this->heading = _heading;
	this->uppercase = _uppercase;
	this->italics = _italics;
}

//*********************************************************************				ForwardIndex
//ForwardIndex::fwdNode_itr ForwardIndex::findWebpageInList(WebPage_t * _webpage) {
//	return binary_search(Forward_Vec.begin(), Forward_Vec.end(), _webpage, ForwardIndex::compare);
//}

void ForwardIndex::push(WebPage_t * _webpage, Word * _word, WordLoc_t * _wordLoc) {
	ForwardIndex::fwdNode_itr _webpage_itr;// = Forward_Vec.begin();

	//set <WordLoc_t> temp = { *_wordLoc };
	//_webpage_itr->keywords.insert(make_pair(_word, set < WordLoc_t > { *_wordLoc }));
	//(Forward_Vec.end() - 1);

	if (_webpage_itr != Forward_Vec.end()) { //IF WEBPAGE EXISTS.
		auto _word_itr = _webpage_itr->keywords.find(_word);
		if (_word_itr != _webpage_itr->keywords.end()) {

		}
		else { //IF WEBPAGE, BUT NO KEYWORD.
			//pair <Word *, set <WordLoc_t>> temp();
			set <WordLoc_t> temp = { *_wordLoc };
			//_webpage_itr->keywords.insert(make_pair(_word, temp));
		}
	}

	else { //IF WEbpage DOESNT EXISTS.
		Forward_Vec.insert(ForwardIndex_Node(_webpage, _word, _wordLoc));
	}
}

//ForwardIndex_Node::keywords_itr ForwardIndex::wordLocInList(Word *) {
//	for (ForwardIndex_Node::keywords_itr itr = ((Forward_Vec.end() - 1))->keywords.front.s;; ++itr) {
//
//	}
//}
//*********************************************************************				InvertedIndex
InvertedIndex_Node::InvertedIndex_Node(Word * word, WebPage_t * webpage) {
	this->keyword = word;
	this->Webpages.push_front(make_pair(webpage, 1));
}

//************************************				InvertedIndex List
InvertedIndex::invNode_itr InvertedIndex::WordPos(Word* _word) {
	for (InvertedIndex::invNode_itr itr = Inverted_Vec.begin(); itr != Inverted_Vec.end(); ++itr) {
		//if ((*itr)->keyword->keyword == (_word->keyword));
		if (compareStrings((itr)->keyword->keyword, (_word->keyword))) {
			return itr;
		}
	}
	return Inverted_Vec.end();
}

void InvertedIndex::push(Word * keyword, WebPage_t * webpage) {
	InvertedIndex::invNode_itr wordpos = WordPos(keyword);
	if (wordpos != Inverted_Vec.end()) { //If IN LIST
		InvertedIndex_Node::webpages_itr itr;
		for (itr = wordpos->Webpages.begin(); itr != wordpos->Webpages.end(); ++itr) {
			if (webpage == itr->first) {
				itr->second = itr->second + 1;
			}
		}
	}
	else {
		/*InvertedIndex_Node temp(keyword, webpage); Inverted_Vec.push_back(temp);*/
		Inverted_Vec.push_back(InvertedIndex_Node(keyword, webpage));
	}
}

//*********************************************************************				

bool isArticle(string token) {
	vector <string> articles = { "a", "is", "the", "are", "if", "it" }; //Populate it from the database
	for (auto itr = articles.begin(); itr != articles.end(); itr++)
		if (*itr == token) return true;
	return false;
}

//*********************************************************************				
bool compareStrings(const string & a, const string & b) {
	if (a.length() == b.length()) {
		string::const_iterator itr_a, itr_b;
		//char _a, _b;
		for (itr_a = a.begin(), itr_b = b.begin(); itr_a != a.end(); ++itr_a, ++itr_b) {
			if (*itr_a == *itr_b) continue;
			if ((islower(*itr_a) && isupper(*itr_b)) || (isupper(*itr_a) && islower(*itr_b))) {
				if (islower(*itr_a)) {
					if (*itr_a == tolower(*itr_b)) { continue; }
					else return false;
				}
				else {
					if (tolower(*itr_a) == *itr_b) { continue; }
					else return false;
				}
			}
		}
		if (itr_a == a.end()) return true;
	}

	return false;
};

bool compareStrings(const char * a, const char * b) {
	return compareStrings((string)a, (string)b);
}

//*********************************************************************				Get Token
string getToken(istream & ss){

	string token = "";
	char x = ss.get();

	if (!(x >= 0 && x <= 255)) {
		//ss.get();
		return "\0";
	}

	//Read a char and add it to the token while char is available
	while (isalpha(x) && ss) {
		token += x;
		x = ss.get();
		if (!(x >= 0 && x <= 255)) return token;
	}

	//return the Token
	return token;
}
////
//vector<string> get_all_files_names_within_folder(string folder)
//{
//	//Before building a project, go to the Project Properties > General. 
//	//Switch Character Set to "Use Multi-Byte Character Set". 
//	//This will stop any errors related to "Cannot convert char[] to LPCWSTR"
//	vector<string> names;
//	string search_path = folder + "/*.*";
//	WIN32_FIND_DATA fd;
//	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
//	if (hFind != INVALID_HANDLE_VALUE) {
//		do {
//			// read all (real) files in current folder
//			// , delete '!' read other 2 default folder . and ..
//			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
//				names.push_back(fd.cFileName);
//			}
//		} while (::FindNextFile(hFind, &fd));
//		::FindClose(hFind);
//	}
//	return names;
//
//vector <string> names;
//
//names = get_all_files_names_within_folder("C:\\Users\\Yousuf Khan\\Desktop\\WebPage_ts");
//cout << names[6];
//}