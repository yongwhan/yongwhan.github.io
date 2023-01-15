#include<bits/stdc++.h>
using namespace std;

int main() {
  srand(time(NULL));

  auto current_path = std::filesystem::current_path();
  auto parent_path = current_path.parent_path();
  auto parsed_path = parent_path / "parsed";

  cout<<"enter page number: ";
  string x; cin>>x;
  string fname=parsed_path.string()+"/page_"+x;
  ifstream fin(fname);

  string line;
  vector<string> words, defs;
  vector<int> perm;
  int iter=0;
  while(getline(fin,line)) {
    perm.push_back(iter++);
    stringstream ss(line);
    string word, part, def;
    ss>>word>>part;
    def=line.substr(word.size()+1);
    word+=" "+part;
    words.push_back(word);
    defs.push_back(def);
  }

  cout<<"option"<<endl;
  cout<<"[0] word => def"<<endl;
  cout<<"[1] def => word"<<endl;
  string option; cin>>option;

  int y=0, n=0;
  map<int,int> wrong_freq_table;
  random_shuffle(perm.begin(), perm.end());
  while(1) {
    random_shuffle(perm.begin(), perm.end());
    int idx=perm.front();

    cout<<(option=="0" ? words[idx] : defs[idx])<<" (y/n): ";
    char ch; cin>>ch;
    cout<<"answer = "<<(option!="0" ? words[idx] : defs[idx])<<endl;

    if(tolower(ch)=='y') y++;
    else if(tolower(ch)=='n') n++, wrong_freq_table[idx]++;
    else break;
    cout<<"[accuracy] "<<y<<"/"<<y+n<<" ("<<int(1000.*y/(y+n)+.5)/10.<<"%)"<<endl;
  }

  map<int,vector<int>> mp;
  for (auto it : wrong_freq_table)
    mp[it.second].push_back(it.first);

  ofstream fout("wrong_freq_table_desc.txt");
  fout<<"<<short list>>"<<endl;
  for (auto it=mp.rbegin(); it!=mp.rend(); it++) {
    fout<<"[wrong count = "<<it->first<<"]"<<endl;
    for (auto idx : it->second)
      fout<<words[idx]<<" "<<defs[idx]<<endl;
    fout<<endl;
  }

  vector<int> idxs;
  for (auto it : wrong_freq_table)
    idxs.push_back(it.first);

  sort(idxs.begin(),idxs.end(), [&](int x, int y) {
    string s=words[x], t=words[y];
    s[0]=tolower(s[0]);
    t[0]=tolower(t[0]);
    return s<t;
  });

  ofstream fout2("wrong_list.txt");
  for (auto idx : idxs)
    fout2<<words[idx]<<" "<<defs[idx]<<endl;
  return 0;
}
