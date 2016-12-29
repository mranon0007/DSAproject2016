#include "myfuncs.h"

//*********************************************************************				

bool isArticle(string token) {
	vector <string> articles = { "a","an" "is", "the", "are", "if", "it" }; //Populate it from the database
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

//*********************************************************************				TESTING UNIT


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