//using namespace std;
//#include <iostream>
////#include <string>
////#include <vector>
////#include <algorithm>
////#include <fstream>
////#include "myfuncs.h"
////#include "ForwardIndex.h"
////#include "InvertedIndex.h"
////
////
////
//int main() {
////
////	/*set<string *> x;
////	string a = "avx"; string b = "zx"; string a1 = "dvx"; string b2 = "fx";
////	x.insert(&b); x.insert(&a); x.insert(&b2); x.insert(&a1);*/
////	//x.insert(&string("abc")); x.insert(&string("edq")); x.insert(&string("avx")); x.insert(&string("xzz")); x.insert(&string("trs"));
////
////	vector<string> webpages;
////	GetReqDirs("WebPages/", webpages);
////	//webpages.push_back("WebPages\\A.txt");
////
////	ForwardIndex FwdIndex;
////	InvertedIndex InvIndex;
////
////	ifstream webpage;
////	//WebPage_t webpageURL("WebPages\\A.txt");
////	//webpage.open(webpageURL);
////
////	for (auto webpages_itr = webpages.begin(); webpages_itr != webpages.end(); ++webpages_itr) {
////		webpage.open(*webpages_itr);
////		for (int i = 0; !webpage.eof(); ++i) {
////			string token;
////			token = getToken(webpage);
////			Word * word = new Word(token);
////			//cout << token << " ";
////
////			//InvIndex.push(*word, *webpages_itr);
////			FwdIndex.push(*webpages_itr, *word, i);
////		} //EnD FOR
////		webpage.close();
////	}
////
////	//*************************************************************
////
////	{
////		//Word * x;
////		//set <WordLoc_t> temp = { 7 };
////		////_webpage_itr->keywords.insert(make_pair(_word, temp));
////		//struct ForwardIndex_Node xx;
////		//xx.keywords.insert(make_pair(x, {7}));
////	}
////
////
////	/*string a = "";
////	string b = "";
////	if (compareStrings("test", "TEst")) cout << "TEST";*/
////
////	//map<int, int> x;
////	//x.insert(make_pair(1, 2));
////	///*x[1] = 5;
////	//x[1]++;*/
////	//cout << x[1];
////
////	//set<int> x = { 1, 3, 7, -2 };
////	//x.insert(4);
////	//x.insert(1);
////	//for (auto itr = x.begin(); itr != x.end(); ++itr) {
////	//	cout << *itr;
////	//}
////
////	//int n = 10;
////	////list<int> lis;
////	////lis.insert(lis.begin(), n);
////
////	////myobj XX;
////	////XX.l.insert(XX.l.begin(), n);
////
////	//set<myobj> x;
////	////x.front().l.insert(x.front().l.begin(), n);
////	//auto itr = x.begin();
////	//advance(itr, 2);
////	//itr->l.insert(n);
////
////
////	//map<int, int> x;
////	//x.insert(make_pair(1, 1));
////	//x.insert(make_pair(2, 2));
////	//x.insert(make_pair(3, 3));
////	//cout << x[30]++ << endl;
////
////
////
//	{system("pause"); return  0; }
//}