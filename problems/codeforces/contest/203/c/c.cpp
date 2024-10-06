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

  // freopen("c.in", "r", stdin);
  // freopen("c.out", "w", stdout);
  int n, d, a, b;
  cin >> n >> d >> a >> b;
  vector <vector<int>> ar(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ar[i] = {x*a+y*b, i+1};
  }
  sort(ar.begin(), ar.end());
  vector <int> ans;
  for (int i = 0; i < ar.size(); ++i) {
    if (d - ar[i][0] >= 0) {
      ans.push_back(ar[i][1]);
      d -= ar[i][0];
      continue;
    }
    break;
  }
  // for (int i = 0; i< ar.size(); ++i) {
  //   cout << ar[i][0] << ' ';
  // }
  // cout << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}

