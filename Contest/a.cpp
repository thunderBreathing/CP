#include <bits/stdc++.h>
#include <cstdio>
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
  int n;
  scanf("%d", &n);
  int ara[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &ara[i]);
  }

  if (n > 2)
    printf("NO\n");
  else if (ara[1] - ara[0] == 1)
    printf("NO\n");
  else
    printf("YES\n");
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
