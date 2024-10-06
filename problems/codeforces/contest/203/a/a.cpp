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

  // freopen("a.in", "r", stdin);
  // freopen("a.out", "w", stdout);
  int x, t, a, b, da, db;
  cin >> x >> t >> a >> b >> da >> db;
  for (int t1 = 0; t1 < t; ++t1) {
    for (int t2 = 0; t2 < t; ++t2) {
      if (a - t1*da + b - t2*db == x || a - t1*da == x || b - t2*db == x || x == 0) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}

