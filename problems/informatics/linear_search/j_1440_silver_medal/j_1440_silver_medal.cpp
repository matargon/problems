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

  // freopen("j_1440_silver_medal.in", "r", stdin);
  // freopen("j_1440_silver_medal.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }
  int n;
  cin >> n;
  int mx1, mx2;
  int el1, el2;
  cin >> el1 >> el2;
  mx1 = max(el1, el2), mx2 = min(el1, el2);
  for (int i = 2; i < n; i++) {
    int el;
    cin >> el;
    if (el == mx1) {
      continue;
    }
    if (el > mx1) {
      mx2 = mx1;
      mx1 = el;
      continue;
    }
    if (el > mx2 || mx2 == mx1) {
      mx2 = el;
    }
  }
  cout << mx2 << endl;
  return 0;
}

