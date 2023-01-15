#include<bits/stdc++.h>
using namespace std;

void process(vector<string> &lines, int iter) {
  if(lines.empty()) return;

  string fname="parsed/page_"+to_string(iter);
  ofstream fout(fname);

  for (auto line : lines) {
    if(line.empty()) continue;
    fout<<line<<endl;
  }

  lines.clear();
}

int main() {
  string line;
  vector<string> lines;
  int iter=0;
  while(getline(cin,line)) {
    lines.push_back(line);

    // new page
    if(line.find("7-CD") != std::string::npos) {
      lines.pop_back(), lines.pop_back();
      process(lines, iter++);
    }

    // terminating condition
    if(line.find("zodiac") != std::string::npos) {
      break;
    }
  }
  if(!lines.empty()) {
    process(lines, iter++);
  }
  return 0;
}
