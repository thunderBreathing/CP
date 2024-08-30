#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <sstream>
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

void solve() {
  int p, g;
  scanf("%d %d", &p, &g);

  unordered_map<string, double> party;

  for (int i = 0; i < p; i++) {
    string temp;
    cin >> temp;

    double vote;
    scanf("%lf", &vote);

    party[temp] = vote;
  }

  string str;
  getline(cin, str);

  for (int i = 0; i < g; i++) {
    string line;
    getline(cin, line);

    istringstream ss(line);
    string temp;
    double total = 0;
    bool done = false;
    string comp;
    string result;

    while (ss >> temp) {
      if (temp == "+") {
        continue;
      }
      if (temp == ">" || temp == "<" || temp == "<=" || temp == ">=" ||
          temp == "=") {
        done = true;
        comp = temp;
        continue;
      }
      if (!done)
        total += party[temp];
      if (done) {
        double num = stod(temp.c_str());
        if (comp == ">") {
          if (total > num) {
            result = "correct";
          } else {
            result = "incorrect";
          }
        } else if (comp == "<") {
          if (total < num) {
            result = "correct";
          } else {
            result = "incorrect";
          }
        } else if (comp == ">=") {
          if (total >= num) {
            result = "correct";
          } else {
            result = "incorrect";
          }
        } else if (comp == "<=") {
          if (total <= num) {
            result = "correct";
          } else {
            result = "incorrect";
          }
        } else if (comp == "=") {
          if (total == num) {
            result = "correct";
          } else {
            result = "incorrect";
          }
        }
      }
    }
    cout << "Guess #" << i + 1 << " was " << result << el;
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  solve();

  return 0;
}
