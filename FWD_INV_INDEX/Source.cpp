using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <Windows.h>
#include <fstream>
#include "myfuncs.h"
#include "ForwardIndex.h"
#include "InvertedIndex.h"

class myobj {
public:
	list<int> l;
};

int main() {

	/*vector <ForwardIndex_Node> FwdIndex;
	vector <InvertedIndex_Node> InvIndex;*/

	ForwardIndex FwdIndex;
	InvertedIndex InvIndex;

	ifstream webpage;
	WebPage_t webpageURL("WebPages\\A.txt");
	webpage.open(webpageURL);

	for (int i = 0; !webpage.eof(); ++i) {
		string token;
		token = getToken(webpage);
		Word * word = new Word(token);
		//cout << token << " ";

		if (token.length() > 2) {
			if (token != "the" && token != "The" && token != "and" && token != "was" && token != "his" && token != "her" && token != "they") {
				InvIndex.push(*word, webpageURL);
			}
		}
		//FwdIndex.push(webpageURL, *word, i);

	} //EnD FOR

	//FwdIndex.displayForward();		//forward index display function
	InvIndex.displayInverted();

	{
		//Word * x;
		//set <WordLoc_t> temp = { 7 };
		////_webpage_itr->keywords.insert(make_pair(_word, temp));
		//struct ForwardIndex_Node xx;
		//xx.keywords.insert(make_pair(x, {7}));
	}


	/*string a = "";
	string b = "";
	if (compareStrings("test", "TEst")) cout << "TEST";*/

	//map<int, int> x;
	//x.insert(make_pair(1, 2));
	///*x[1] = 5;
	//x[1]++;*/
	//cout << x[1];

	//set<int> x = { 1, 3, 7, -2 };
	//x.insert(4);
	//x.insert(1);
	//for (auto itr = x.begin(); itr != x.end(); ++itr) {
	//	cout << *itr;
	//}

	//int n = 10;
	////list<int> lis;
	////lis.insert(lis.begin(), n);

	////myobj XX;
	////XX.l.insert(XX.l.begin(), n);

	//set<myobj> x;
	////x.front().l.insert(x.front().l.begin(), n);
	//auto itr = x.begin();
	//advance(itr, 2);
	//itr->l.insert(n);
	

	//map<int, int> x;
	//x.insert(make_pair(1, 1));
	//x.insert(make_pair(2, 2));
	//x.insert(make_pair(3, 3));
	//cout << x[30]++ << endl;



	{system("pause"); return  0; }
}