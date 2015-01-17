#include <iostream>

#define MAXB 10000000

using namespace std;

int factors[MAXB + 1];

void preprocess() {
  for(int i = 2; i * i < MAXB; i++) {
    if(factors[i] > 0) continue;
    for(int j = 2 * i; j <= MAXB; j += i) {
      if(j % i == 0) factors[j]++;
    }
  }

  for(int i = 2; i <= MAXB; i++) {
    if(factors[i] == 0) factors[i] = 1;
  }
}

int main() {
  preprocess();

  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int a, b, k; cin >> a >> b >> k;

    int cnt = 0;
    for(int i = a; i <= b; i++) {
      if(factors[i] == k) cnt++;
    }

    cout << "Case #" << tc << ": " << cnt << endl;
  }
  return 0;
}
