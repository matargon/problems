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
const long double EPS = 1e-9;
using namespace std;

inline void solve() {
  cout << endl;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long double a, n;
  cin >> a >> n;
  long double l = 0, r = 10000;
  while (l + EPS < r) {
    long double mid = (l + r) / 2;
    if (pow(mid, n) > a) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.7Lf\n", l);
  return 0;
}

