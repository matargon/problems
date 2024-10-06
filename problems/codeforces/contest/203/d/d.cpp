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

  // freopen("d.in", "r", stdin);
  // freopen("d.out", "w", stdout);
  long double a, b, m, x, y, z;
  cin >> a >> b >> m >> x >> y >> z;
  // x *= -1; y *= -1; z *= -1;
  long double t = abs(m / y);
  long double x1 = a/2 + x*t, z1 = z*t;
  while (x1 < -a) {
    x1 += 2*a;
  }
  while (x1 > 2*a) {
    x1 -= 2*a;
  }
  if (x1 < 0) {
    x1 = abs(x1);
  }
  if (x1 > a) {
    x1 = 2*a - x1;
  }
  while (z1 < -b) {
    z1 += 2*b;
  }
  while (z1 > 2 * b) {
    z1 -= 2*b;
  }
  if (z1 < 0) {
    z1 = abs(z1);
  }
  if (z1 > b) {
    z1 = 2*b - z1;
  }
  cout.precision(10);
  cout << x1 << ' ' << z1 << endl;
  return 0;
}

