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

  // freopen("h_1412_columns.in", "r", stdin);
  // freopen("h_1412_columns.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }
  int x;
  cin >> x;
  int n;
  cin >> n;
  vector <vector <int>> ar(n, vector <int> (n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> ar[i][j];
    }
  }
  for (int j = 0; j < n; ++j) {
    auto ans = "NO";
    for (int i = 0; i < n; ++i) {
      if (ar[i][j] == x) {
        ans = "YES";
      }
    }
    cout << ans << endl;
  }
  return 0;
}

