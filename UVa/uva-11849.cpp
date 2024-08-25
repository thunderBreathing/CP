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

void solve(int n, int m) {
  unordered_set<int> a;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.insert(x);
  }

  int count = 0;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    if (a.find(x) != a.end()) {
      count++;
    }
  }

  printf("%d\n", count);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n, m;
  while (scanf("%d %d", &n, &m), (n | m)) {
    solve(n, m);
  }

  return 0;
}
