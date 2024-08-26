#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_set>
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

void solve() {
  unordered_multiset<int> a, b, c, d;
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.insert(x);
    b.insert(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    c.insert(x);
    d.insert(x);
  }

  int result = 0;
  int current = -1;

  for (auto u : a) {
    int x = a.count(u);
    int y = c.count(u);
    if (current == u) {
      continue;
    }
    current = u;

    if (x > y) {
      result += (x - y);
    }
  }
  current = -1;
  for (auto u : c) {
    int x = a.count(u);
    int y = c.count(u);
    if (current == u) {
      continue;
    }
    current = u;

    if (y > x) {
      result += (y - x);
    }
  }

  printf("%d\n", result);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  scanf("%d", &t);

  while (t--) {
    solve();
  }

  return 0;
}
