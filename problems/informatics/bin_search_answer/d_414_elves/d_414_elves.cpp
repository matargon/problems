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


bool check(vector <vector<int>>& deers, vector <vector<int>>& elfs, int mid) {
  int cnt = 0;
  int j = 0;
  for (int i = 0; i < deers.size(); i++) {
    if (
      j < (int)elfs.size() && (int)elfs.size() - mid + j < elfs.size() &&
      elfs[j][0] < deers[i][0] && 
      elfs[elfs.size() - mid + j][0] > deers[i][0]) {
        j++, cnt++;
    }
  }
  if (cnt >= mid) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector <vector<int>> deers(m);
  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    deers[i] = {d, i};
  }
  vector <vector <int>> elfs(n);
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    elfs[i] = {e, i};
  }
  sort(deers.begin(), deers.end());
  sort(elfs.begin(), elfs.end());

  int l = 0, r = min(m+1, (n+2)/2);
  while (l + 1 != r) {
    int mid = (l + r) / 2;
    if (check(deers, elfs, mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  int j = 0;
  for (int i = 0; i < deers.size(); i++) {
    if (
      j < (int)elfs.size() && (int)elfs.size() - l + j < elfs.size() &&
      elfs[j][0] < deers[i][0] && 
      elfs[elfs.size() - l + j][0] > deers[i][0]) {
        cout << deers[i][1]+1 << ' ' <<  elfs[j][1]+1 << ' ' << elfs[elfs.size() - l + j][1]+1 << endl;
        j++;
    }
  }
  return 0;
}

