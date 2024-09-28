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


bool dfs(int start, vector <vector <int>>& adj_lst, vector <int>& color, int flag) {
  color[start] = flag + 1;
  for (auto vert : adj_lst[start]) {
    if (color[vert] == color[start]) {
      return false;
    }
    if (color[vert] == 0) {
      if (!dfs(vert, adj_lst, color, (flag + 1) % 2)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("banket.in", "r", stdin);
  // freopen("banket.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> adj_lst(n);
  for (int i = 0; i < m; ++i) {
    int s, f;
    cin >> s >> f;
    --s, --f;
    adj_lst[s].push_back(f);
    adj_lst[f].push_back(s);
  }
  vector <int> color(n, 0);
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      if (!dfs(i, adj_lst, color, 0)) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 1) {
      cout << i + 1 << ' ';
    }
  }
  cout << endl;
  return 0;
}

