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

bool check_sum(vector <vector <int>>& ar, int x, int y) {
  int sm = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (x+i < ar.size() && y+j < ar[0].size() && x+i>=0 && y+j >= 0) {
        sm += ar[x+i][y+j];
      }
    }
  }
  if (sm == 9) {
    return true;
  }
  return false;
}

bool check(vector <vector <int>>& ar, int x, int y){
  --x, --y;
  ar[x][y] = 1;
  for (int i = -2; i <= 0; ++i) {
    for (int j = -2; j <= 0; ++j){
      if (check_sum(ar, x+i, y+j)){
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("b.in", "r", stdin);
  // freopen("b.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> ar(n, vector <int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (check(ar, x, y)) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;;
  return 0;
}

