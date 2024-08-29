#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <unordered_set>
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

void solve(int t) {
  int n;
  scanf("%d", &n);

  vector<unordered_set<int>> stamps(n);
  mii count;

  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);

    for (int j = 0; j < l; j++) {
      int x;
      scanf("%d", &x);

      stamps[i].insert(x);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int var : stamps[i]) {
      count[var]++;
    }
  }

  int unique_stamps[n], total = 0;
  for (int i = 0; i < n; i++) {
    unique_stamps[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int u : stamps[i]) {
      if (count[u] == 1) {
        unique_stamps[i]++;
        total++;
      }
    }
  }

  printf("Case %d:", t);
  for (int i = 0; i < n; i++) {
    printf(" %lf%%", unique_stamps[i] * 100 / (total * 1.0));
  }
  printf("\n");
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
