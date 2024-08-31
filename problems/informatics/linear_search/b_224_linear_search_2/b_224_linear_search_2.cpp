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



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("b_224_linear_search_2.in", "r", stdin);
  // freopen("b_224_linear_search_2.out", "w", stdout);

  int n;
  cin >> n;
  vector <int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int x;
  cin >> x;
  auto ans = "NO";
  for (int i = 0; i < ar.size(); i++) {
    if (ar[i] == x) {
      ans = "YES";
    }
  }
  cout << ans << endl;
  return 0;
}

