#include <bits/stdc++.h>
#include <queue>
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

void solve(int n) {
  int ara[n][n], min_sum = 0;
  priority_queue<int> pq;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &ara[i][j]);
    }
    sort(ara[i], ara[i] + n);
    min_sum += ara[i][0];
    pq.push(ara[i][1] - ara[i][0]);
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  while (scanf("%d", &n)) {
    solve(n);
  }

  return 0;
}
