#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
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

void solve() {}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  char st[1000000];
  while (scanf("%d %s", &n, st) != EOF) {
    int best = 0;

    string s = st;

    unordered_map<string, int> m;
    for (int i = 0; i <= s.length() - n; i++) {
      string str = s.substr(i, n);
      m[str]++;
      best = max(best, m[str]);
    }

    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end()) {
      if (it->second == best) {
        cout << it->first << el;
        break;
      }
      it++;
    }
  }

  return 0;
}
