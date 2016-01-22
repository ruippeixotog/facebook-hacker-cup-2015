#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>

#define ld long double

#define PREC 5000

using namespace std;

ld pmf[PREC];
ld res[PREC];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    ld p; cin >> p;

    res[1] = pmf[1] = p;
    for(int i = 2; i < PREC; i++) {
      res[i] = pmf[i] = pmf[i - 1] * (1.0 - p);
    }

    for(int k = 1; k < 20; k++) {
      ld tmp[PREC];
      memset(tmp, 0, sizeof(tmp));

      for(int i = 0; i < PREC; i++) {
        for(int j = 0; j < PREC; j++) {
          tmp[max(i, j)] += res[i] * pmf[j];
        }
      }
      memcpy(res, tmp, sizeof(res));
    }

    ld avg = 0.0;
    for(int i = 0; i < PREC; i++)
      avg += res[i] * i;

    cout << "Case #" << tc << ": " << fixed << setprecision(5) << avg << endl;
  }
  return 0;
}
