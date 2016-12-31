#include "myfuncs.h"

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
string getToken(istream & ss) {

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

void GetReqDirs(const std::string& path, std::vector<string>& files, const bool showHiddenDirs) {

	/*
	source: http://stackoverflow.com/questions/13129340/recursive-function-for-listing-all-files-in-sub-directories
	note: include dirent.h file from https://github.com/tronkko/dirent
	usage in main: { vector <string> x; GetReqDirs("WebPages/", x); }
	*/

	//Before building a project, go to the Project Properties > General. 
	//	//Switch Character Set to "Use Multi-Byte Character Set". 
	//	//This will stop any errors related to "Cannot convert char[] to LPCWSTR"

	DIR *dpdf;
	struct dirent *epdf;
	dpdf = opendir(path.c_str());
	if (dpdf != NULL) {
		while ((epdf = readdir(dpdf)) != NULL) {
			bool flag = showHiddenDirs ? (epdf->d_type == DT_DIR && string(epdf->d_name) != ".." && string(epdf->d_name) != ".") : (epdf->d_type == DT_DIR && strstr(epdf->d_name, "..") == NULL && strstr(epdf->d_name, ".") == NULL);
			if (flag)
			{
				GetReqDirs(path + epdf->d_name + "/", files, showHiddenDirs);
			}
			if (epdf->d_type == DT_REG) {
				files.push_back(path + epdf->d_name);
			}
		}
	}
	closedir(dpdf);
}