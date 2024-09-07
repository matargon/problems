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

long double a, b, c, d;
long double a1, b1, c1;
long double x1;

inline long double f(long double x) {
  return ((a*x+b)*x+c)*x+d;
}

inline long double f_s(long double x) {
  return (a1*x+b1)*x + c1;
}

long double sqrt1(long double x) {
  long double l = 0, r = x+1;
  while (l + EPS <= r) {
    long double m = (l+r)/2;
    if (m*m <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

inline vector <long double> solve_f_s() {
  printf("%.8Lf %.8Lf %.8Lf\n", a1, b1, c1);
  auto k = a1;
  a1/=k, b1/=k, c1/=k;
  long double disk = b1*b1 - 4*a1*c1;
  if (disk < -EPS) {
    return {};
  }
  long double x2 = (-b1 + sqrt1(abs(disk))) / (2 );
  if (disk < EPS) {
    return {x2};
  } 
  long double x3 = (-b1 - sqrt1(abs(disk))) / (2);
  return {x2, x3};
}

inline int sign(long double x) {
  if (x < 0) {
    return -1;
  }
  return 1;
}

inline long double first_root() {
  long double l = -1001, r = 1001;
  while (abs(r-l) > EPS) {
    long double m = (l + r) / 2;
    if (sign(f(m))*sign(f(l)) < 0) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}

void print_roots(vector <long double>& roots) {
  sort(roots.begin(), roots.end());
  printf("%.7Lf\n", abs(roots[0] - roots[1])) ;
  if (roots.size() >= 2) {
    if (abs(roots[0] - roots[1]) < 1e-6) {
      roots.erase(roots.begin());
    }
  }
  if (roots.size() >= 2) {
    if (abs(roots[0] - roots[1]) < 1e-6) {
      roots.erase(roots.begin());
    }
  }
  for (int i = 0; i < roots.size(); i++) {
    printf("%.7Lf ", roots[i]);
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(9);
  cin >> a >> b >> c >> d;
  if (a < EPS && b < EPS) {
    printf("%.7Lf\n", -d/c);
    return 0;
  }

  if (a < EPS) {
    a1 = b, b1 = c, c1 = d;
    vector<long double> roots = solve_f_s();
    print_roots(roots);
    return 0;
  }

  x1 = first_root();
  a1 = a;
  b1 = b+a1*x1;
  c1 = c+b1*x1;
  vector <long double> roots = solve_f_s();
  roots.push_back(x1);
  print_roots(roots);
  return 0;
}

