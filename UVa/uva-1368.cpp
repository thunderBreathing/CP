#include <algorithm>
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

int min_of_four(int a, int b, int c, int d) {
  b = min(a, b);
  c = min(b, c);
  d = min(c, d);
  return d;
}

void solve() {
  int m, n;
  scanf("%d %d", &m, &n);

  char ara[m + 1][n + 5];

  for (int i = 0; i < m; i++) {
    scanf("%s", ara[i]);
  }

  int stnd[4][n + 5];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      stnd[i][j] = 0;
    }
  }

  char list[] = {'A', 'C', 'G', 'T'};

  for (auto item : list) {
    for (int col = 0; col < n; col++) {
      for (int row = 0; row < m; row++) {
        if (ara[row][col] != item) {
          if (item == 'A') {
            stnd[0][col]++;
          } else if (item == 'C') {
            stnd[1][col]++;
          } else if (item == 'G') {
            stnd[2][col]++;
          } else if (item == 'T') {
            stnd[3][col]++;
          }
        }
      }
    }
  }

  int minsum = 0;
  for (int i = 0; i < n; i++) {
    int sm = min_of_four(stnd[0][i], stnd[1][i], stnd[2][i], stnd[3][i]);
    minsum += sm;

    if (sm == stnd[0][i])
      printf("A");
    else if (sm == stnd[1][i])
      printf("C");
    else if (sm == stnd[2][i])
      printf("G");
    else if (sm == stnd[3][i])
      printf("T");
  }

  printf("\n%d\n", minsum);
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
