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

bool dfs(int start, int prev, vector <vector <int>>& adj_lst, vector <int>& color) {
  color[start] = 1;
  for (auto vert : adj_lst[start]) {
    if (color[vert] == 1 && vert != prev){
      return false;
    }
    if (color[vert] == 0) {
      if (!dfs(vert, start, adj_lst, color)) {
        return false;
      }
    }
  }
  color[start] = 2;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vector <int> > adj_lst(n);
  vector <int> color(n, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int el;
      cin >> el;
      if (el == 1) {
        adj_lst[i].push_back(j);
      }
    }
  }
  int cnt = 0;
  
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      ++cnt;
      if (!dfs(i, -1, adj_lst, color)) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (cnt <= 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

