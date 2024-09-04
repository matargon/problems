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


long double convert_time(string s) {
  int h = atoi(s.substr(0, 2).c_str());
  int m = atoi(s.substr(3, 2).c_str());
  return (long double)(h * 60 + m);
}

vector <vector <long double>> dsts;

bool check(vector<vector <long double>>& dsts, int v, int d, long double el) {
  long double nwdst = 0, t = el;
  for (int i = 0; i < dsts.size(); i++) {
    if (t + (dsts[i][0] - nwdst) / v >= dsts[i][1]) {
      t += d;
    } 
    t += (dsts[i][0] - nwdst) / v;
    nwdst = dsts[i][0];
  }
  return t >= dsts.back()[1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, d;
  cin >> v >> d;
  int k;
  cin >> k;
  vector <vector <long double>> dsts;
  // dsts.resize(k);
  string s;
  long double dst;
  for (int i = 0; i < k; i++) {
    cin >> dst >> s;
    dsts.push_back({dst, convert_time(s)});
  }
  long double l = 0, r = 24 * 60;
  while (l + EPS < r) {
    // cout << l << ' ' << r << endl;
    long double m = (l + r) / 2;
    if (check(dsts, v, d, m)) {
      r = m;
    } else {
      l = m;
    }
  }


  int ans = (int)ceil(k * d + l + dsts.back()[0] / v * 2);
  int ansh = ans / 60;
  int ansm = ans % 60;

  if (ansh < 10) {
    cout << '0';
  }
  cout << ansh << ':';
  if (ansm < 10) {
    cout << '0';
  }
  cout << ansm << endl;
  return 0;
}

