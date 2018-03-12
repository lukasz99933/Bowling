#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class Bowling {
public:
  bool fillTokens(const string s);
  bool validateTokens() const;
  void translate();
  void count();
  void bonuses();
  int score(const string s) const;
private:
  string data = "";
  vector<string> tokens;
  vector<tuple<int,int,int>> scores;
};





