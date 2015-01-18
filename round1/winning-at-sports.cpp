#include <cstdlib>
#include <iostream>

#define MAXG 2000
#define MOD 1000000007

using namespace std;

int ga, gb;

int dp[MAXG + 1][MAXG + 1];

bool stressFree(int i, int j) { return i > j; }
bool stressful(int i, int j) { return i <= j || j == gb; }

int countDp(bool (*validState)(int, int)) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  for(int i = 0; i <= ga; i++) {
    for(int j = (i == 0 ? 1 : 0); j <= gb; j++) {
      if(!validState(i, j)) continue;
      if(i > 0) dp[i][j] += dp[i - 1][j];
      if(j > 0) dp[i][j] += dp[i][j - 1];
      dp[i][j] %= MOD;
    }
  }
  return dp[ga][gb];
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    char sep; cin >> ga >> sep >> gb;

    cout << "Case #" << tc << ": " << countDp(stressFree) <<
      " " << countDp(stressful) << endl;
  }
  return 0;
}
