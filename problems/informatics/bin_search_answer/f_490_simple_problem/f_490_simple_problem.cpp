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

bool check(int n, int x, int y, int el) {
  el -= min(x, y);
  n--;
  if (el >= 0 && n <= 0) {
    return true;
  }
  double cntx = double(el)/x, cnty = double(el)/y;
  if (int(cntx) + int(cnty) >= n && el >= 0) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int l = -1, r = 2 * INF + 5;
  while (l + 1 != r) {
    int m = (l + r) / 2;
    if (check(n, x, y, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;
  return 0;
}

