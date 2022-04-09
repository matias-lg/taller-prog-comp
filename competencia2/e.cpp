#include <bits/stdc++.h>

using namespace std;
const double eps = 10E-4;

typedef long long ll;
typedef long double ld;

vector<pair<ld, ld>> trips;
ld largo_total = 0;
ld n, real_time, fake_time = 0;

int f(ld d){
    ld vel_real = largo_total/real_time;
    for (int i=0; i<n; i++){
        pair<ld, ld> q = trips[i];
        fake_time += q.first/(q.second-d);
    }
    ld vel_fake = largo_total/fake_time;
    return vel_fake<vel_real;
}

int main(){
    cin >> n >> real_time;
    ld fake_time = 0;


    for(int i=0; i<n; i++){
        ld l, v;
        cin >> l >> v;
        pair<ld, ld> p;
        largo_total += l;
        p.first = l;
        p.second = v;
        trips.push_back(p);
    }

    //Busqueda Binaria
    ld left, right, mid;
    left = -1000;
    right = 1000;
    while(right - left > eps){
        mid = (left+right)/2.0;
        if(f(mid)){
            left = mid + 1;
        }else{
            right = mid;
        }
        cout << right;
    }
    cout << left << endl;
    return 0;
}