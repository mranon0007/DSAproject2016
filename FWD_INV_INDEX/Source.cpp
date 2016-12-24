using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include "myheader.h"
#include <Windows.h>
#include <fstream>
//#include "WebPages\A.txt"

int main() {

	vector <ForwardIndex_Node> FwdIndex;
	vector <InvertedIndex_Node> InvIndex;

	ifstream webpage;
	WebPage_t webpageURL("WebPages\\A.txt");
	webpage.open(webpageURL);

	for (int i = 0; !webpage.eof(); ++i) {
		string token;
		token = getToken(webpage);
		Word * word = new Word(token);
		//cout << token << " ";

		//Insert into invindex. STILL WORKING ON THIS ONE
		{
			/*	InvertedIndex_Node tempNode;
			tempNode.keyword = new Word(token);
			tempNode.Webpages.push_front(make_pair(&webpageURL, 0));*/
		}


		////Insert into fwdindex
		//{
		//	ForwardIndex_Node tempNode;
		//	tempNode.WebPage = webpageURL;
		//	tempNode.keywords.push_front(make_pair(word, i));
		//	FwdIndex.push_back(tempNode);
		//}

		
	}

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

	map<int, int> x;
	x.insert(make_pair(1, 2));
	/*x[1] = 5;
	x[1]++;*/
	cout << x[1];

	{system("pause"); return  0; }
}