#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll collected = 0;
  while (collected < n) {
    //  Qué pasa si preguntan desde (x+1, y) y (x, y+1) con (x, y) un punto
    //  cualquiera
    ll dist = -1;
    ll x = 0;
    ll y = 0;
    while (dist != 0) {
      cout << x << " " << y << endl;
      cin >> dist;  // leer la distancia
      ll dx1;
      ll dy1;
      cout << x + 1 << " " << y << endl;
      cin >> dx1;
      if (dx1 == 0) {
        break;
      }
      cout << x << " " << y + 1 << endl;
      cin >> dy1;
      if (dy1 == 0) {
        break;
      }

      if (dx1 > dist) {
        // mover a la izq
        x -= dist / 2;
      } else {
        x += dist / 2;
      }
      cout << x << " " << y << endl;
      cin >> dist;
      if (dist == 0) {
        break;
      }

      if (dy1 > dist) {
        // mover hacia abajo
        y -= dist / 2;
      } else {
        y += dist / 2;
      }
      cout << x << " " << y << endl;
      cin >> dist;
      if (dist == 0) {
        break;
      }
    }
    collected++;
  }

  return 0;
}
