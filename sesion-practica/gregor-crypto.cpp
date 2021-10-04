#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  int prime;
  do {
    cin >> prime;
    string next = to_string(prime - 1);
    cout << "2 " + next << endl;
    cnt++;
  } while (cnt < n);
  return 0;
}
