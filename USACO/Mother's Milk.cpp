/*
ID: mehranh1
TASK: milk3
LANG: C++
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

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

int capacity[3];
int current_state[3];
vector<tuple<int, int, int>> states;
set<int> ans;

void search() {
  tuple<int, int, int> state =
      make_tuple(current_state[0], current_state[1], current_state[2]);

  // cout << get<0>(state) << " " << get<1>(state) << " " << get<2>(state) <<
  // el;

  if (find(states.begin(), states.end(), state) != states.end()) {
    return;
  }

  states.pb(state);

  if (current_state[0] == 0) {
    ans.insert(current_state[2]);
  }

  int save_state[] = {current_state[0], current_state[1], current_state[2]};

  for (int start = 0; start < 3; start++) {
    if (current_state[start] != 0) {
      for (int pos = (start + 1) % 3, cnt = 0; cnt < 2;
           pos += (pos + 1) % 3, cnt++) {
        if (current_state[pos] < capacity[pos]) {
          current_state[pos] +=
              ((capacity[pos] - current_state[pos]) > current_state[start])
                  ? current_state[start]
                  : (capacity[pos] - current_state[pos]);
          current_state[start] -= current_state[pos] - save_state[pos];
          // cout << current_state[0] << " " << current_state[1] << " "
          //      << current_state[2] << el;

          search();

          current_state[start] = save_state[start];
          current_state[pos] = save_state[pos];
        }
      }
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  ifstream fin("milk3.in");
  ofstream fout("milk3.out");

  fin >> capacity[0] >> capacity[1] >> capacity[2];
  fin.close();

  current_state[2] = capacity[2];

  search();

  int len = 0;
  for (int var : ans) {
    fout << var;
    len++;

    if (len < (int)ans.size())
      fout << " ";
  }
  fout << el;
  fout.close();

  return 0;
}
