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


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("a_229_max_forward.in", "r", stdin);
  // freopen("a_229_max_forward.out", "w", stdout);
  int n;
  cin >> n;
  int mx = -INF, mxind = 0;
  vector <int> ar(n);
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
    if (ar[i] > mx) {
      mx = ar[i];
      mxind = i;
    }
  }
  swap(ar[0], ar[mxind]);
  for (int i = 0; i < n; ++i) {
    cout << ar[i] << ' ';
  }
  cout << endl;
  return 0;
}

