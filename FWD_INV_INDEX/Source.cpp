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
	
	GetReqDirs("WebPages/", webpages);
	for (auto webpages_itr = webpages.begin(); webpages_itr != webpages.end(); ++webpages_itr) {
		webpage.open(*webpages_itr);
		for (int i = 0; !webpage.eof(); ++i) {
			string token;
			token = getToken(webpage);
			Word & word = *new Word(token);
			
			InvIndex.push(word, *webpages_itr);
			FwdIndex.push(*webpages_itr, word, i);
		} //EnD FOR
		webpage.close();
	}


	{system("pause"); return  0; }
}