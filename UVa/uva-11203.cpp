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
  char test[55];
  scanf("%s", test);

  int before_M, between_M_and_E, after_E;
  before_M = between_M_and_E = after_E = 0;

  int i = 0;
  while (1) {
    if (test[i] == 'M') {
      break;
    }

    if (test[i] != 'M' && test[i] != 'E' && test[i] != '?') {
      printf("no-theorem\n");
      return;
    }
    if (test[i] == 'E') {
      printf("no-theorem\n");
      return;
    }

    if (test[i] == '?') {
      before_M++;
    }

    i++;
  }
  i++;
  while (1) {
    if (test[i] == 'E') {
      break;
    }

    if (test[i] != 'E' && test[i] != '?') {
      printf("no-theorem\n");
      return;
    }
    if (test[i] == '\0') {
      printf("no-theorem\n");
      return;
    }

    if (test[i] == '?') {
      between_M_and_E++;
    }

    i++;
  }
  i++;
  while (test[i] != '\0') {
    if (test[i] == '\0') {
      break;
    }

    if (test[i] != '?') {
      printf("no-theorem\n");
      return;
    }

    if (test[i] == '?') {
      after_E++;
    }

    i++;
  }

  if (before_M == 0 || between_M_and_E == 0 || after_E == 0) {
    printf("no-theorem\n");
  } else if (before_M + between_M_and_E == after_E) {
    printf("theorem\n");
  } else {
    printf("no-theorem\n");
  }
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
