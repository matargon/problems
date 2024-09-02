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
const long long INF = 1e9;
const double EPS = 1e-9;
using namespace std;

long long bin_search(vector<long long>& ar, long long el) {
  long long l = 0, r = ar.size();
  while (l + 1 != r) {
    long long m = (l + r) / 2;
    if (ar[m] > el) {
      r = m;
    } else {
      l = m;
    }
  }
  long long ans = ar[l];
  if (l + 1 < ar.size()) {
    if (abs(ans - el) > abs(ar[l + 1] - el)) {
      ans = ar[l + 1];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vector <long long> ar(n);
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (long long i = 0; i < k; i++) {
    long long el;
    cin >> el;
    cout << bin_search(ar, el) << endl;
  }
  return 0;
}

