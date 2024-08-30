#include <bits/stdc++.h>
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

void solve(unordered_map<string, int> code) {
  string ch;

  while (cin >> ch) {
    cout << code[ch] << el;
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  unordered_map<string, int> code;

  char i, j, k, l, m;
  int n;
  for (i = 'a', n = 1; i <= 'z'; i++, n++) {
    string str;
    str += i;
    code[str] = n;
  }
  for (i = 'a'; i <= 'z'; i++) {
    for (j = i + 1; j <= 'z'; j++, n++) {
      string str;
      str += i;
      str += j;
      code[str] = n;
    }
  }
  for (i = 'a'; i <= 'z'; i++) {
    for (j = i + 1; j <= 'z'; j++) {
      for (k = j + 1; k <= 'z'; k++, n++) {

        string str;
        str += i;
        str += j;
        str += k;
        code[str] = n;
      }
    }
  }
  for (i = 'a'; i <= 'z'; i++) {
    for (j = i + 1; j <= 'z'; j++) {
      for (k = j + 1; k <= 'z'; k++) {
        for (l = k + 1; l <= 'z'; l++, n++) {
          string str;
          str += i;
          str += j;
          str += k;
          str += l;
          code[str] = n;
        }
      }
    }
  }
  for (i = 'a'; i <= 'z'; i++) {
    for (j = i + 1; j <= 'z'; j++) {
      for (k = j + 1; k <= 'z'; k++) {
        for (l = k + 1; l <= 'z'; l++) {
          for (m = l + 1; m <= 'z'; m++, n++) {
            string str;
            str += i;
            str += j;
            str += k;
            str += l;
            str += m;
            code[str] = n;
          }
        }
      }
    }
  }

  solve(code);

  return 0;
}
