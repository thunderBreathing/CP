#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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

bool even(int num) {
  if (num % 2 == 0)
    return true;
  return false;
}

void solve(string pattern) {
  int sum = 0;

  for (int i = 0; i < pattern.length(); i++) {
    sum += pattern[i] - '0';
  }

  int rem = sum % pattern.length();

  if (rem != 0) {
    cout << pattern << ": invalid # of balls\n";
    return;
  }

  int balls = sum / pattern.length();
  priority_queue<int> left, right;

  for (int i = 0; i < balls; i++) {
    int ball = pattern[i % pattern.length()] - '0';
    int fall = ball + i + 1;

    if (i % 2 == 0) {
      if (even(ball)) {
        left.push(fall * -1);
      } else {
        right.push(fall * -1);
      }
    } else {
      if (even(ball)) {
        right.push(fall * -1);
      } else {
        left.push(fall * -1);
      }
    }
  }

  while (!left.empty()) {
    int ball = left.top();
    left.pop();
    if (ball == left.top()) {
      cout << pattern << ": invalid pattern\n";
      return;
    }
  }
  while (!right.empty()) {
    int ball = right.top();
    right.pop();
    if (ball == right.top()) {
      cout << pattern << ": invalid pattern\n";
      return;
    }
  }

  cout << pattern << ": valid with " << balls << " balls\n";
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  string pattern;
  while (cin >> pattern) {
    solve(pattern);
  }

  return 0;
}
