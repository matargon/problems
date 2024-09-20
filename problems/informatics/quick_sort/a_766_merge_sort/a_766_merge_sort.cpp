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

void print(vector <int>& ar) {
  for (int i = 0; i < ar.size(); i++) {
    cout << ar[i] << ' ';
  }
  cout << endl;
}

void merge_sort(vector <int>& ar, int l, int r);
void merge(vector <int>& ar, int l, int m, int r);

void merge_sort(vector <int>& ar, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = (l + r) / 2;
  merge_sort(ar, l, m);
  merge_sort(ar, m + 1, r);
  merge(ar, l, m, r);
}

void merge(vector <int>& ar, int l, int m, int r){
  vector <int> tmp(r - l + 1);
  int i1 = l, i2 = m + 1, nw = 0;
  while (i1 <= m && i2 <= r) {
    if (ar[i1] < ar[i2]) {
      tmp[nw] = ar[i1];
      ++i1;
    } else {
      tmp[nw] = ar[i2];
      ++i2;
    }
    ++nw;
  }
  while(i1 <= m) {
    tmp[nw] = ar[i1];
    ++i1;
    ++nw;
  }
  while(i2 <= r) {
    tmp[nw] = ar[i2];
    ++i2;
    ++nw;
  }
  for (int i = l; i <= r; ++i){
    ar[i] = tmp[i-l];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("a_766_merge_sort.in", "r", stdin);
  // freopen("a_766_merge_sort.out", "w", stdout);
  int n;
  cin >> n;
  vector <int> ar(n);
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  merge_sort(ar, 0, int(ar.size()) - 1);
  for (int i = 0; i < ar.size(); ++i) {
    cout << ar[i] << ' ';
  }
  cout << endl;
  return 0;
}

