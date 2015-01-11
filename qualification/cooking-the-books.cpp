#include <iostream>
#include <string>

using namespace std;

string bestStr(string str, bool findMax) {
  for(int startIdx = 0; startIdx < str.length() - 1; startIdx++) {
    int bestIdx = startIdx;

    for(int i = str.length() - 1; i >= startIdx + 1; i--) {
      if(startIdx == 0 && str[i] == '0') continue;

      if((!findMax && str[i] < str[bestIdx]) ||
        (findMax && str[i] > str[bestIdx])) {
        bestIdx = i;
      }
    }

    if(bestIdx != startIdx) {
      char tmp = str[startIdx];
      str[startIdx] = str[bestIdx];
      str[bestIdx] = tmp;
      break;
    }
  }
  return str;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    string str; cin >> str;

    cout << "Case #" << tc << ": " << bestStr(str, false) <<
      " " << bestStr(str, true) << endl;
  }
  return 0;
}
