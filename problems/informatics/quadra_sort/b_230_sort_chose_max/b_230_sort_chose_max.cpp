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

int get_max_ind(vector <int>& ar, int start_ind) {
  int ans = start_ind;
  int mx = ar[start_ind];
  for (int i = 0; i <= start_ind; ++i) {
    if (ar[i] > mx) {
      ans = i;
      mx = ar[i];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> ar(n);
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  if (n == 0) {
    return 0;
  }
  int nw = 0;
  for (int i = n-1; i > -1; --i) {
    int ind2 = get_max_ind(ar, i);
    swap(ar[i], ar[ind2]);
  }
  for (int i = 0; i < n; ++i) {
    cout << ar[i] << ' ';
  }
  cout << endl;
  return 0;
}

