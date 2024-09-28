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


bool dfs(int start, vector <vector <int>>& adj_lst, vector <int>& color, vector <int>& ans) {
  color[start] = 1;
  for (auto vert : adj_lst[start]) {
    if (color[vert] == 1) {
      return false;
    }
    if (color[vert] == 0) {
      if (!dfs(vert, adj_lst, color, ans)) {
        return false;
      }
    }
  }
  ans.push_back(start);
  color[start] = 2;
  return true;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("postroenie.in", "r", stdin);
  // freopen("postroenie.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector <vector <int>> adj_lst(n);
  for (int i = 0; i < m; ++i) {
    int s, f;
    cin >> s >> f;
    --s, --f;
    adj_lst[s].push_back(f);
  }
  vector <int> color(n, 0);
  vector <int> ans;
  
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      if (!dfs(i, adj_lst, color, ans)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = int(ans.size()) - 1; i > -1; --i) {
    cout << ans[i] + 1 << ' ';
  }
  cout << endl;
  return 0;
}

