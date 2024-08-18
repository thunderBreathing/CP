#include <bits/stdc++.h>
#include <cstdio>
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

void solve() {
  int al, ar, bl, br;
  scanf("%d %d", &al, &ar);
  scanf("%d %d", &bl, &br);
  int ans;

  if (ar < bl || br < al)
    ans = 1;
  else if (al >= bl && ar <= br)
    ans = (al != bl) + (ar != br) + ar - al;
  else if (bl >= al && br <= ar)
    ans = (al != bl) + (ar != br) + br - bl;
  else if (bl >= al && br >= ar)
    ans = ar - bl + (bl != al) + (br != ar);
  else if (al >= bl && ar >= br)
    ans = br - al + (al != bl) + (ar != br);

  printf("%d\n", ans);
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
