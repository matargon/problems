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

  // freopen("g_1426_ecspedition.in", "r", stdin);
  // freopen("g_1426_ecspedition.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector <int> cap(n*m);
  for (int i = 0; i < n * m; ++i) {
    cin >> cap[i];
  }
  sort(cap.rbegin(), cap.rend());
  int k;
  cin >> k;
  vector <int> weight(k);
  for (int i = 0; i < k; ++i) {
    cin >> weight[i];
  }
  sort(weight.rbegin(), weight.rend());
  
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    if (ans < cap.size() && cap[ans] >= weight[i]) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}

