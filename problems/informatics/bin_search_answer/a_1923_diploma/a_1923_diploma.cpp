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

long long min(long long lhs, long long rhs) {
  return lhs < rhs ? lhs: rhs;
}

bool check(int w, int h, int n, long long el) {
  auto cntw = (el/w), cnth = (el/h);
  return min((long long)(1e9),(el / w)) * min((long long)(1e9),(el / h)) >= n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("a_1923_diploma.in", "r", stdin);
  // freopen("a_1923_diploma.out", "w", stdout);
  int w, h, n;
  scanf("%d%d%d", &w, &h, &n);
  long long l = 0, r = 1e18;
  while (l + 1 != r) {
    long long m = (l + r) / 2;
    if (check(w, h, n, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%lld\n", r);
  return 0;
}

