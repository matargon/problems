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
  // return a*x*x*x + b*x*x + c*x+ d;
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
  // printf("%.8Lf %.8Lf %.8Lf\n", a1, b1, c1);
  auto k = a1;
  // a1/=k, b1/=k, c1/=k;
  long double disk = b1*b1 - 4*a1*c1;
  if (disk < -EPS) {
    return {};
  }
  long double x2 = (-b1 + sqrt(abs(disk))) / (2 * a1);
  long double x3 = (-b1 - sqrt(abs(disk))) / (2 * a1);
  return {x2, x3};
}


inline int sign(long double x) {
  if (x < 0) {
    return -1;
  }
  return 1;
}

inline int triple_sign(long double x) {
  int a = 0;
  a += sign(f(x - EPS - EPS)) + sign(f(x - EPS)) + sign(f(x)) + sign(f(x + EPS)) + sign(f(x + EPS + EPS));
  if (a > 0) {
    return 1;
  }
  return -1;
}

inline long double first_root() {
  long double l = -1001, r = 1001;
  while (l + EPS < r) {
    long double m = (l + r) / 2;
    // printf("%.9Lf %.9Lf %.9Lf %d %.20Lf \n", l, r, m, sign(f(m)), f(m));
    // printf("%.9Lf %.9Lf %.9Lf %d %.20Lf \n", l, r, m, triple_sign(m), f(m));
    // if (f(m) > 0) {
    if (abs(f(m)) < 1e-8) {
      r = m;
      break;
    }
    if (triple_sign(m) > 0) {
      r = m;
    } else {
      l = m;
    }
  }
  // printf("%.10Lf kekek\n", r);
  return r;
}

void print_roots(vector <long double>& roots) {
  sort(roots.begin(), roots.end());
  // printf("%.7Lf\n", abs(roots[0] - roots[1])) ;
  if (roots.size() >= 2) {
    if (abs(roots[0] - roots[1]) < 1e-6) {
      roots.erase(roots.begin());
    }
  }
  // for (int i = 0; i < roots.size(); i++) {
  //   cout << roots[i] << ' ';
  // }
  // cout << endl;
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
  if (a < 0) {
    a *= -1;
    b *= -1;
    c *= -1;
    d *= -1;
  }
  // if (abs(a) < 100 ||abs(b) < 100 ||abs(c) < 100 ||abs(d) < 100){
  //   a*=100, b*=100, c*=100,d*=100;
  // }
  if (abs(a) < EPS && abs(b) < EPS && abs(c) < EPS) {
    return 0;
  }
  if (abs(a) < EPS && abs(b) < EPS) {
    printf("%.7Lf\n", -d/c);
    return 0;
  }

  if (abs(a) < EPS) {
    a1 = b, b1 = c, c1 = d;
    vector<long double> roots = solve_f_s();
    print_roots(roots);
    return 0;
  }

  x1 = first_root();
  a1 = a;
  b1 = b+a1*x1;
  c1 = c+b1*x1;
  // printf("%.20Lf\n", x1);
  vector <long double> roots = solve_f_s();
  roots.push_back(x1);
  print_roots(roots);
  printf("%.10Lf %.10Lf\n", f(4.9998474), f(5.0001526));
  return 0;
}

