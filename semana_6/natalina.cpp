#include <iostream>
#include <cstring>

using namespace std;

int cur;

void foo(string pre, string inf, int i, int j) {
  if(i <= j) {
    cur++;
    int pos = inf.find(pre[cur]);
    foo(pre, inf, i, pos - 1);
    foo(pre, inf, pos + 1, j);
    cout << inf[pos];
  }
}

int main(int argc, char const *argv[]) {
  string pre, in;

  while(cin >> pre >> in) {
    cur = -1;
    foo(pre, in, 0, pre.size() - 1);
    cout << "\n";
  }

  return 0;
}
