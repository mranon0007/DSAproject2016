#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "myParser.h"
#include "InvertedIndex.h"
#include "XmlWriter.h"

using namespace std;

void generate_xml(list <shared_ptr<Webpage>> & webpage_list); //forward index xml generator
void generate_xml(InvertedIndex & word_webpages_list); //inverted index xml generator

int main(int argc, const char * argv[])
{

	InvertedIndex invertedIndex;
	list <shared_ptr<Webpage>> webpage_list;
	vector <WebPage_t> webpagesList = { "Webpages/24_hour_news_cycle.html" };
	GetReqDirs("WebPages/", webpagesList);

	//shared_ptr<Webpage> _webpage;

	//parsing here
	for (auto itr = webpagesList.begin(); itr != webpagesList.end(); ++itr) {
		//_webpage = make_shared<Webpage>();
		//Webpage * _webpage = new Webpage();
		webpage_list.emplace_back(make_shared<Webpage>());
		shared_ptr<Webpage> _webpage = webpage_list.back();
		get_webpage_data(*itr, *_webpage);

		invertedIndex.push(*_webpage);
	}

	generate_xml(invertedIndex);
	//generate_xml(webpage_list);  //forward index

	cout << "DONE";
	system("pause");
	return 0;
}

//please use this function to CREATE AN XML
void generate_xml(InvertedIndex & word_webpages_list) {
	XmlWriter xml;
	if (xml.open("C:\\Users\\Aasharib\\Desktop\\DSA_Project_Xml\\Dataset.xml")){
		xml.writeOpenTag("key_words");
		for (auto words_itr = word_webpages_list.invList.begin(); words_itr != (word_webpages_list).invList.end(); ++words_itr) {
			string word = *(words_itr->keyword);
			
			if (word.size() < 3 || word.find("'") != string::npos) {
				continue;
			}
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			xml.writeOpenTag(word);

			for (auto webpage_itr = words_itr->Webpages.begin(); webpage_itr != words_itr->Webpages.end(); ++webpage_itr) {
				string URL = (**webpage_itr).URL;
				xml.writeStartElementTag("doc");
				xml.writeString(URL);
				xml.writeEndElementTag();

			}
			xml.writeCloseTag();
		}
		xml.writeCloseTag();
		cout << "Success! ";
	}

	else {
		cout << "Failed";
	}

}

//please use this function to CREATE AN XML
void generate_xml(list <shared_ptr<Webpage>> & webpage_list) {

	for (auto webpage_itr = webpage_list.begin(); webpage_itr != webpage_list.end(); ++webpage_itr) {
		string URL = (**webpage_itr).URL;
		ofstream file(URL);

		for (auto words_itr = (**webpage_itr).Words.begin(); words_itr != (**webpage_itr).Words.end(); ++words_itr) {
			if (*words_itr != NULL) {
				string word = (**words_itr).keyword;
				//cout << word << " ";
				file << word << " ";
			}
	
		}
		file.close();
	}

}
