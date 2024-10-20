/*
ID: mehranh1
TASK: ariprog
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

bool debug = false;

int n, m;
const int MAX_N = 126002;
bool number[MAX_N + 1];
vector<pair<int, int>> ans;

void solve() {
  // maximum possible difference between consecutive numbers
  int max_dif = ceil((m * m + m * m) / ((n - 1) * 1.0));

  // checking all possible sequences for valid bisquares
  for (int start = 0; start < m * m + m * m + 1; start++) {
    // if start is bisquare
    if (number[start]) {
      // check for different differences
      for (int dif = 1; dif < max_dif + 1; dif++) {
        bool progression_exist = true;

        for (int j = 0; j < n; j++) {
          if ((start + j * dif) > (m * m + m * m) || !number[start + j * dif]) {
            progression_exist = false;
            break;
          }
        }

        if (progression_exist) {
          ans.pb({dif, start});
        }
      }
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");

  // read input
  fin >> n >> m;
  cin >> n >> m;
  fin.close();

  // precalculate all bisquares
  for (int p = 0; p < m + 1; p++) {
    for (int q = 0; q < m + 1; q++) {
      number[p * p + q * q] = true;
    }
  }

  solve();

  // sort the ans vector
  sort(ans.begin(), ans.end());

  // write output
  if (ans.empty()) {
    fout << "NONE\n";
    cout << "NONE\n";
  } else {
    for (auto &[dif, start] : ans) {
      fout << start << " " << dif << el;
      cout << start << " " << dif << el;
    }
  }

  fout.close();

  return 0;
}
