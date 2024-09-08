#include <bits/stdc++.h>
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

void solve() {
  unordered_map<int, pair<int, char>> item;
  unordered_map<int, bool> denied;
  int trid, itid;
  char mode;

  string line;
  while (getline(cin, line)) {
    if (line[0] == '#') {
      return;
    }

    istringstream ss(line);
    ss >> mode >> trid >> itid;

    if (denied[trid]) {
      cout << "IGNORED" << el;
      continue;
    }

    if (item[itid].first != trid && item[itid].second != mode) {
      cout << "DENIED" << el;
      denied[trid] = true;
      continue;
    }

    item[itid] = {trid, mode};
    cout << "GRANTED" << el;
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  cin >> t;
  cin.ignore(); // Ignore newline after the number of test cases

  while (t--) {
    solve();
    if (t > 0) {
      cout << el;
    }
  }

  return 0;
}
