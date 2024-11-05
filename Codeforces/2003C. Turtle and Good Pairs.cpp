#include <algorithm>
#include <bits/stdc++.h>
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
  cin >> n;

  string s;
  cin >> s;

  map<char, int> count_repetition;
  for (int i = 0; i < s.size(); i++) {
    count_repetition[s[i]]++;
  }

  bool done = false;
  while (!done) {
    done = true;
    for (char i = 'a'; i <= 'z'; i++) {
      if (count_repetition[i] != 0) {
        done = false;
        count_repetition[i]--;
        cout << i;
      }
    }
  }
  cout << el;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
