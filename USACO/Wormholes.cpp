/*
ID: mehranh1
TASK: wormhole
LANG: C++
*/

#include <bits/stdc++.h>
#include <iostream>

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

const int MAX_N = 12;
int x[MAX_N + 1], y[MAX_N + 1];
int partner[MAX_N + 1];
int n;
int next_to_i[MAX_N + 1];

bool cycle_exist() {
  for (int start = 1; start < n + 1; start++) {
    int pos = start;
    for (int count = 0; count < n; count++) {
      pos = next_to_i[partner[pos]];
    }
    if (pos != 0) {
      return true;
    }
  }
  return false;
}

int solve() {
  int i, total = 0;
  for (i = 1; i < n + 1; i++) {
    if (partner[i] == 0)
      break;
  }

  if (i > n) {
    if (cycle_exist())
      return 1;
    else
      return 0;
  }

  for (int j = i + 1; j < n + 1; j++) {
    if (partner[j] == 0) {
      partner[i] = j;
      partner[j] = i;

      total += solve();
      partner[i] = partner[j] = 0;
    }
  }

  return total;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  ofstream fout("wormhole.out");
  ifstream fin("wormhole.in");

  fin >> n;
  // cin >> n;

  for (int i = 1; i < n + 1; i++) {
    fin >> x[i] >> y[i];
    // cin >> x[i] >> y[i];
  }

  fin.close();

  x[0] = y[0] = INF + 1;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (y[i] == y[j] && x[j] < x[next_to_i[i]] && x[j] > x[i]) {
        next_to_i[i] = j;
      }
    }
  }

  fout << solve() << el;
  // cout << solve() << el;

  fout.close();

  return 0;
}
