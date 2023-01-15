#include<map>
#include<cctype>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string title; cin>>title;
	title+=".txt";

	srand (time(NULL));
	ifstream fin(title.c_str());

	vector<string> list;
	string s;
	while(fin>>s) list.push_back(s);

 int sz=list.size(), y=0, n=0;

	map<string,int> mp;
	int idx=0;
	while(1) {
		if(idx==0) random_shuffle(list.begin(), list.end());
		cout << list[idx] << ": ";

		char ch;
		cin>>ch;
		if(tolower(ch)=='y') y++;
		else if(tolower(ch)=='n') n++, mp[list[idx]]++;
		else break;
		cout << y << "/" << y+n << " (" <<100* y/(y+n)<< "%)" << endl;

		idx++;
  if(idx==sz) idx=0;
	}

	for (map<string,int>::iterator it=mp.begin(); it!=mp.end(); it++)
		cout << (*it).first << " " << (*it).second << endl;
	return 0;
}
