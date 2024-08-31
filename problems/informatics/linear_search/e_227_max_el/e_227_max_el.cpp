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

  // freopen("e_227_max_el.in", "r", stdin);
  // freopen("e_227_max_el.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }
  int n;
  cin >> n;
  int mx = -INF;
  for (int i = 0; i < n; ++i) {
    int el;
    cin >> el;
    mx = max(mx, el);
  }
  cout << mx << endl;
  return 0;
}

