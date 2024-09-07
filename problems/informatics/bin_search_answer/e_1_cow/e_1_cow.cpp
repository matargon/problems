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


bool check(vector <int>& ar, int el, int k) {
  int cnt = 1;
  int lst = 0;
  for (int i = 1; i < ar.size(); i++) {
    if (ar[i] - ar[lst] >= el) {
      cnt++;
      lst = i;
    }
  }
  if (cnt >= k) {
    return true;
  }
  return false;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int l = 0, r = ar.back();
  while (l + 1 != r) {
    int m = (l + r) / 2;
    if (check(ar, m, k)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}

