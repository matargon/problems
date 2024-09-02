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

string bin_search(vector <int>& ar, int el) {
  int l = 0, r = ar.size();
  while (l + 1 != r) {
    int m = (l + r) / 2;
    if (ar[m] > el) {
      r = m;
    } else {
      l = m;
    }
  }
  if (ar[l] == el) {
    return "YES";
  } 
  return "NO";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("c_4_bin_search.in", "r", stdin);
  // freopen("c_4_bin_search.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector <int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < k; i++) {
    int el;
    cin >> el;
    cout << bin_search(ar, el) << endl;
  }
  return 0;
}

