#include <bits/stdc++.h>
#include <cstring>
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

void solve(int t) {
  unordered_set<string> unique_words;
  vector<string> words;
  unordered_map<string, int> word_count;
  string line;

  while (getline(cin, line)) {
    if (line == "END")
      break;

    for (char &c : line) {
      if (!isalpha(c))
        c = ' ';
    }

    istringstream ss(line);
    string word;

    while (ss >> word) {
      string cleaned_word;

      for (char c : word) {
        if (isalpha(c)) {
          cleaned_word += tolower(c);
        }
      }

      if (!cleaned_word.empty()) {
        words.push_back(cleaned_word);
        unique_words.insert(cleaned_word);
      }
    }
  }

  int start = 0, end = 0, unique_word_count = 0, len = 0;
  int total_words = words.size();
  int total_unique = unique_words.size();
  int min_p = 0, min_q = total_words - 1;
  int min_length = total_words;

  for (end = 0; end < total_words; end++) {
    word_count[words[end]]++;

    if (word_count[words[end]] == 1)
      unique_word_count++;

    while (unique_word_count == total_unique) {
      len = end - start + 1;
      if (len < min_length) {
        min_p = start;
        min_q = end;
      }
      min_length = min(min_length, len);
      word_count[words[start]]--;

      if (word_count[words[start]] == 0)
        unique_word_count--;

      start++;
    }
  }

  cout << "Document " << t << ": " << min_p + 1 << " " << min_q + 1 << el;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve(i + 1);
  }

  return 0;
}
