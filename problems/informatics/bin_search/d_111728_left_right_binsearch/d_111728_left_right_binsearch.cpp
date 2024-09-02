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

int bin_l(vector <int>& ar, int el) {
  int l = 0, r = ar.size();
  while (l + 1 != r) {  
    int m = (l + r) / 2;
    if (ar[m] > el) {
      r = m;
    } else {
      l = m;
    }
  }
  if (ar[l] != el) {
    return -1;
  }
  return l+1;
}

int bin_r(vector <int>& ar, int el) {
  int l = -1, r = ar.size() - 1;
  while (l + 1 != r) {
    int m = (l + r) / 2;
    if (ar[m] < el) {
      l = m;
    } else {
      r = m;
    }
  }
  return r+1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("d_111728_left_right_binsearch.in", "r", stdin);
  // freopen("d_111728_left_right_binsearch.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector <int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < m; i++) {
    int el;
    cin >> el;
    int ans1 = bin_l(ar, el);
    if (ans1 == -1) {
      cout << 0 << endl;
      continue;
    }
    cout << bin_r(ar, el) << ' ' << ans1 << endl;
  }
  return 0;
}

