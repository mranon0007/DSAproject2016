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

//	ifstream webpage;
	WebPage_t webpageURL("WebPages\\A.txt");
	webpage.open(webpageURL);

	for (int i = 0; !webpage.eof(); ++i) {
		string token;
		token = getToken(webpage);
		Word * word = new Word(token);
		//cout << token << " ";

		if (token.length() > 2) {
			if (token != "the" && token != "The" && token != "and" && token != "his" && token != "her" && token != "was") {
				InvIndex.push(*word, webpageURL);
				FwdIndex.push(webpageURL, *word, i);
			}
		}
		else continue;
	} //EnD FOR

	InvIndex.displayInverted();
	//FwdIndex.displayForward();

	{system("pause"); return  0; }
}