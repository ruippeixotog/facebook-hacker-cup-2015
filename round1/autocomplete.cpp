#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Dict {
  int count;
  map<char, Dict> children;

  Dict(): count(0) {}

  int add(string& word, int idx) {
    count++;
    if(idx >= word.length()) return 0;
    int childRes = children[word[idx]].add(word, idx + 1);
    return count == 1 ? 0 : childRes + 1;
  }
};

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    Dict dict;
    int cnt = 0;
    while(n--) {
      string word; cin >> word;
      cnt += max(1, dict.add(word, 0));
    }

    cout << "Case #" << tc << ": " << cnt << endl;
  }
  return 0;
}
