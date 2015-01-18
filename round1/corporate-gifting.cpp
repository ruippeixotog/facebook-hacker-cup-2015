#include <cstdlib>
#include <iostream>
#include <vector>

#define MAXN 200000
#define MAXC 20
#define INF 1e9

using namespace std;

vector<int> subs[MAXN];

int dp[MAXN][MAXC];

void calcDp(int k) {
  for(int i = 0; i < subs[k].size(); i++)
    calcDp(subs[k][i]);

  for(int c = 1; c < MAXC; c++) {
    int cost = c;
    for(int i = 0; i < subs[k].size(); i++)
      cost += dp[subs[k][i]][c];

    for(int c2 = 1; c2 < MAXC; c2++) {
      if(c2 != c) dp[k][c2] = min(dp[k][c2], cost);
    }
  }
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    for(int i = 0; i < n; i++)
      subs[i].clear();

    for(int i = 0; i < n; i++) {
      int m; cin >> m;
      if(m > 0) subs[--m].push_back(i);
    }

    memset(dp, 0x3f, sizeof(dp));
    calcDp(0);

    int best = min(dp[0][1], dp[0][2]);
    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
