#include <cstring>
#include <iostream>
#include <map>
#include <string>

#define MAXK 100

using namespace std;

int k;

struct Node {
  map<char, Node> children;
  bool isWord;
  int costs[MAXK + 1];

  Node(): isWord(false) {}

  void add(const char* str) {
    if(*str == 0) isWord = true;
    else children[*str].add(str + 1);
  }

  void calcCosts() {
    memset(costs, 0x3F, sizeof(costs));
    costs[0] = 0;
    if(isWord) costs[1] = 1;

    for(auto it = children.begin(); it != children.end(); it++) {
      int newCosts[MAXK + 1];
      memcpy(newCosts, costs, sizeof(costs));

      it->second.calcCosts();
      for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k - i; j++) {
          newCosts[i + j] = min(
            newCosts[i + j],
            costs[i] + j + it->second.costs[j]);
        }
      }
      memcpy(costs, newCosts, sizeof(costs));
    }
    costs[1] = 1;
  }
};

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n >> k;

    Node trie;
    for(int i = 0; i < n; i++) {
      string str; cin >> str;
      trie.add(str.c_str());
    }

    trie.calcCosts();
    int res = k == 1 ? 1 : trie.costs[k] - k;
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
