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

int find_min(vector <vector <int>> &ar, int row) {
  int mn = ar[row][0];
  for (int i = 0; i < ar[row].size(); ++i) {
    mn = min(mn, ar[row][i]);
  }
  return mn;
}

int find_max(vector <vector <int>> &ar, int col) {
  int mx = ar[0][col];
  for (int i = 0; i < ar.size(); ++i) {
    mx = max(mx, ar[i][col]);
  }
  return mx;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("i_1427_matrix.in", "r", stdin);
  // freopen("i_1427_matrix.out", "w", stdout);
  // int k;
  // cin >> k;

  // for (int i = 0; i < k; i++) {
  //   solve();
  // }

  int n, m;
  cin >> n >> m;
  vector <vector <int>> ar(n, vector <int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ar[i][j];
    }
  }
  vector <int> ans_row(n);
  for (int i = 0; i < ar.size(); i++) {
    ans_row[i] = find_min(ar, i);
  }

  vector <int> ans_col(m);
  for (int i = 0; i < m; i++) {
    ans_col[i] = find_max(ar, i);
  }
  int ans=0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ar[i][j] == ans_col[j] && ar[i][j] == ans_row[i]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

