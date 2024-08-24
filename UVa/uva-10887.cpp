#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
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

void solve(int test) {
  int m, n;
  scanf("%d %d", &m, &n);
  vector<string> a, b;
  set<string> c;

  string r;
  getline(cin, r);

  for (int i = 0; i < m; i++) {
    string str;
    getline(cin, str);
    a.pb(str);
  }
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    b.pb(str);
  }

  for (auto u : a) {
    for (auto v : b) {
      string str = u + v;
      c.insert(str);
    }
  }

  printf("Case %d: %d\n", test, (int)c.size());
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}
