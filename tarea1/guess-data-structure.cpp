#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    stack<int> st;
    priority_queue<int> pq;
    queue<int> qe;

    bool isStack = true;
    bool is_pq = true;
    bool is_queue = true;
    for (int i = 0; i < n; i++) {
      int instruction;
      int x;
      cin >> instruction;
      cin >> x;
      if (instruction == 1) {
        if (isStack) {
          st.push(x);
        }
        if (is_pq) {
          pq.push(x);
        }
        if (is_queue) {
          qe.push(x);
        }
      }
      if (instruction == 2) {
        // stack
        if (st.size() == 0) {
          isStack = false;
        } else if (isStack) {
          isStack = st.top() == x;
          st.pop();
        }
        // queue
        if (qe.size() == 0) {
          is_queue = false;
        } else if (is_queue) {
          is_queue = qe.front() == x;
          qe.pop();
        }
        // priority
        if (pq.size() == 0) {
          is_pq = false;
        } else if (is_pq) {
          is_pq = pq.top() == x;
          pq.pop();
        }
      }
    }
    if ((int)(isStack + is_pq + is_queue) == 0) {
      cout << "impossible"
           << "\n";
    } else if ((int)(isStack + is_pq + is_queue) > 1) {
      cout << "not sure"
           << "\n";
    } else {
      if (is_queue) {
        cout << "queue"
             << "\n";
      }
      if (isStack) {
        cout << "stack"
             << "\n";
      }
      if (is_pq) {
        cout << "priority queue"
             << "\n";
      }
    }
  }
  return 0;
}
