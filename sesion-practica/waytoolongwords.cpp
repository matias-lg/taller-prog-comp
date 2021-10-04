#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  string word;
  do {
    cin >> word;
    if(word.length() > 10) {
      cout << word[0] + to_string(word.length() - 2) + word.back() << endl;
    }
    else {
      cout << word << endl; 
    }
    cnt++;
  } while (cnt < n);
  return 0;
}
