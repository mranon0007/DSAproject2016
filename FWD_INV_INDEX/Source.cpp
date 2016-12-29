using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "myfuncs.h"
#include "ForwardIndex.h"
#include "InvertedIndex.h"

int main() {

	vector<string> webpages;
	ifstream webpage;
	
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

		InvIndex.push(*word, webpageURL);
		FwdIndex.push(webpageURL, *word, i);
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

		
	} //EnD FOR

	{
		//Word * x;
		//set <WordLoc_t> temp = { 7 };
		////_webpage_itr->keywords.insert(make_pair(_word, temp));
		//struct ForwardIndex_Node xx;
		//xx.keywords.insert(make_pair(x, {7}));
	}


	{system("pause"); return  0; }
}