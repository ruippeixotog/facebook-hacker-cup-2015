#include <algorithm>
#include <iostream>

#define MAXN 50000

using namespace std;

int n;
int arr[MAXN];

bool canSort(int min, int max, int i, int j) {
  while(min != 1 || max != n) {
    if(arr[i] == min - 1) { min--; i++; }
    else if(arr[i] == max + 1) { max++; i++; }
    else if(arr[j] == min - 1) { min--; j--; }
    else if(arr[j] == max + 1) { max++; j--; }
    else return false;
  }
  return true;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> arr[i];

    bool res =
      canSort(arr[0], arr[0], 1, n - 1) ||
      canSort(arr[n - 1], arr[n - 1], 0, n - 2);

    cout << "Case #" << tc << ": " << (res ? "yes" : "no") << endl;
  }
  return 0;
}
