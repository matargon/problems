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

  // freopen("c_225_nearest_number.in", "r", stdin);
  // freopen("c_225_nearest_number.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }
  int n; 
  cin >> n;
  vector <int> ar(n);
  for (int i = 0; i < ar.size(); i++) {
    cin >> ar[i];
  }
  int x;
  cin >> x;
  int delta = abs(x - ar[0]), ans = ar[0];
  for (int i = 0; i < ar.size(); i++) {
    if (abs(ar[i] - x) < delta) {
      delta = abs(ar[i] - x);
      ans = ar[i];
    }
  }
  cout << ans << endl;
  return 0;
}

