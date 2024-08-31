#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
const int INF = 1e9;
const double EPS = 1e-9;
using namespace std;

inline void solve() {
  cout << endl;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("g_1409_revision.in", "r", stdin);
  // freopen("g_1409_revision.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }

  int n;
  cin >> n;
  vector <int> ar(n);
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  int mn1 = min(ar[0], ar[1]), mn2 = max(ar[0], ar[1]);
  for (int i = 2; i < n; ++i) {
    if (ar[i] < mn1) {
      mn2 = mn1;
      mn1 = ar[i];
      continue;
    }
    if (ar[i] < mn2) {
      mn2 = ar[i];
    }
  }
  cout << mn1 << ' ' << mn2 << endl;
  return 0;
}

