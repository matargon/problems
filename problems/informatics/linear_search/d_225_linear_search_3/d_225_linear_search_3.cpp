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

  // freopen("d_225_linear_search_3.in", "r", stdin);
  // freopen("d_225_linear_search_3.out", "w", stdout);
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
  for (int i = 0; i < n; i++) {
    if (ar[i] == x) {
      cout << i + 1 << ' ';
    }
  }
  cout << endl;
  return 0;
}

