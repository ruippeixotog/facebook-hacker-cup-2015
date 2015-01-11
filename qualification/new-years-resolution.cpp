#include <iostream>

#define MAXN 20

using namespace std;

int gp, gc, gf;
int ps[MAXN], cs[MAXN], fs[MAXN];
int n;

bool go(int k, int currP, int currC, int currF) {
  if(k == n) return currP == gp && currC == gc && currF == gf;
  
  return go(k + 1, currP, currC, currF) ||
    go(k + 1, currP + ps[k], currC + cs[k], currF + fs[k]);
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> gp >> gc >> gf >> n;
    for(int i = 0; i < n; i++)
      cin >> ps[i] >> cs[i] >> fs[i];

    cout << "Case #" << tc << ": " << (go(0, 0, 0, 0) ? "yes" : "no") << endl;
  }
  return 0;
}
