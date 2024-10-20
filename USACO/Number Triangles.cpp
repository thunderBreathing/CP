/*
ID: mehranh1
TASK: numtri
LANG: C++
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

#define el "\n"
#define pb push_back
#define mp make_pair

const int INF = 1e9;
const ll LINF = 4e18;
const double EPS = 1e-9;

bool debug = true;

int solve(int r, vector<vi> &tri) {
  if (r == 1) {
    return tri[0][0];
  }

  int mx = 0;

  for (int i = 1; i < r; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j == 0) {
        tri[i][j] += tri[i - 1][j];
      } else if (j == i) {
        tri[i][j] += tri[i - 1][j - 1];
      } else {
        tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
      }

      mx = max(mx, tri[i][j]);
    }
  }

  return mx;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  ifstream fin("numtri.in");
  ofstream fout("numtri.out");

  int r;
  // cin >> r;
  fin >> r;
  vector<vi> tri(r);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < i + 1; j++) {
      int e;
      // cin >> e;
      fin >> e;
      tri[i].pb(e);
    }
  }

  fin.close();

  fout << solve(r, tri) << el;
  // cout << solve(r, tri) << el;

  fout.close();

  return 0;
}
