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

  // freopen("k_1447_controperation.in", "r", stdin);
  // freopen("k_1447_controperation.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }
  int n;
  cin >> n;
  vector <int> ar(n);
  int mx=-INF, mn=INF;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    mx = max(mx, ar[i]);
    mn = min(mn, ar[i]);
  }
  for (int i = 0; i < n; i++) {
    if (ar[i] == mx) {
      cout << mn << ' ';
    } else {
      cout << ar[i] << ' ';
    }
  }
  cout << endl;
  return 0;
}

