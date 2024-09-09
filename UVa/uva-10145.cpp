#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/types.h>
#include <unordered_map>
#include <unordered_set>

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
  unordered_map<int, unordered_set<int>> item;
  unordered_map<int, unordered_set<int>> exclusive;
  unordered_set<int> denied;
  int trid, item_id;
  char mode;

  string gr = "GRANTED";
  string dn = "DENIED";
  string ig = "IGNORED";

  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    if (line[0] == '#') {
      return;
    }

    istringstream ss(line);
    ss >> mode >> trid >> item_id;

    if (denied.find(trid) != denied.end()) {
      cout << ig << el;
      continue;
    }

    bool is_denied = false;
    if (mode == 'X') {
      for (int var : item[item_id]) {
        if (trid != var) {
          is_denied = true;
          cout << dn << el;
          denied.insert(trid);
          break;
        }
      }
    } else {
      for (int var : exclusive[item_id]) {
        if (trid != var) {
          is_denied = true;
          cout << dn << el;
          denied.insert(trid);
          break;
        }
      }
    }

    if (!is_denied) {
      cout << gr << el;
      if (mode == 'X') {
        exclusive[item_id].insert(trid);
        item[item_id].insert(trid);
      } else {
        item[item_id].insert(trid);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    solve();
    if (t > 0) {
      cout << el;
    }
  }

  return 0;
}
