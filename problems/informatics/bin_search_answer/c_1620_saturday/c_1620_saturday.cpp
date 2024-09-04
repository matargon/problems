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

bool check(vector<int> &ar, int el, int cntbr, int cntp) {
  int cnt = 0;
  int l = 0, r = 0;
  while (cnt < cntbr && r < int(ar.size())) {
    if (ar[r] - ar[l] > el) {
      l++, r++;
      continue;
    }
    if (r - l + 1 >= cntp) {
      r++;
      l = r;
      cnt++;
      continue;
    }
    r++;
  }
  if (cnt >= cntbr) {
    return true;
  }
  return false;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, cntbr, cntp;
  cin >> n >> cntbr >> cntp;
  vector <int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar.begin(), ar.end());
  int l = -1, r = INF;
  while (l + 1 != r) {
    int m = (l + r) / 2;
    if (check(ar, m, cntbr, cntp)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;
  return 0;
}

