#include <bits/stdc++.h>
#include <cmath>
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

unordered_set<int> all = {
    1,        64,       729,      4096,     15625,    46656,    117649,
    262144,   531441,   1000000,  1771561,  2985984,  4826809,  7529536,
    11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};

void solve(int n) {
  if (all.find(n) == all.end()) {
    printf("Ordinary\n");
  } else {
    printf("Special\n");
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  while (scanf("%d", &n), n) {
    solve(n);
  }

  return 0;
}
