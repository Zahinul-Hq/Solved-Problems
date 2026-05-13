#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4.2")
typedef long long int ll;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1000000007;
const int N = 2e5 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ar[n][n];
        vector<bool> rowok(n, 1),colok(n, 1),rowok1(n, 0),colok1(n, 0);
        vector<int>a(n), b(n);
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
               cin >> ar[i][j];
           }
        }
        for(auto &it : a) cin >> it;
        for(auto &it : b) cin >> it;
        ll mnrow = 1e13, mncol = 1e13;
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
             if(i < n - 1) {
                if(ar[i][j] == ar[i + 1][j]) {
                  rowok1[i] = 1;
                  rowok1[i + 1] = 1;
                  if(i - 1 >= 0) rowok1[i - 1] = 1;
                  if((ar[i + 1][j] - ar[i][j]) == 1)rowok[i] = 0;
                  if(i - 1 >= 0) {
                    if((ar[i - 1][j] - ar[i][j]) == 1)rowok[i] = 0;
                  } 

                  if((ar[i][j] - ar[i + 1][j]) == 1)rowok[i + 1] = 0;
                  if(i + 2 < n) {
                    if((ar[i + 2][j] - ar[i + 1][j]) == 1)rowok[i + 1] = 0;
                  }
                  

                  if((ar[i][j] - ar[i - 1][j]) == 1)rowok[i - 1] = 0;
                  if(i - 2 >= 0) {
                    if((ar[i - 2][j] - ar[i - 1][j]) == 1)rowok[i - 1] = 0;
                  }

                  
                }
             }
             if(j < n - 1) {
                 if(ar[i][j] == ar[i][j + 1]) {
                  colok1[j] = 1;
                  colok1[j + 1] = 1;
                  if(j - 1 >= 0)colok1[j - 1] = 1;
                  if((ar[i][j + 1] - ar[i][j]) == 1)colok[j] = 0;
                  if(j - 1 >= 0) {
                    if((ar[i][j - 1] - ar[i][j]) == 1)colok[j] = 0;
                  } 

                  if((ar[i][j] - ar[i][j + 1]) == 1)colok[j + 1] = 0;
                  if(j + 2 < n) {
                    if((ar[i][j + 2] - ar[i][j + 1]) == 1)colok[j + 1] = 0;
                  }
                  

                  if((ar[i][j] - ar[i][j - 1]) == 1)colok[j - 1] = 0;
                  if(j - 2 >= 0) {
                    if((ar[i][j - 2] - ar[i][j - 1]) == 1)colok[j - 1] = 0;
                  }
                }
             }
          }
        }
        bool ev = 1, od = 1;
        ll mn1 = 0, mn2 = 0;
        for(int i = 0; i < n; i++) {
          if(rowok1[i] & rowok[i]) {
          
            if(i & 1) {
              mn1 += a[i];
            }
            else mn2 += a[i];
          }
          if(rowok1[i] and !rowok[i]) {
            if(i & 1) {
              od = 0;
            }
            else ev = 0;
          }
        }
        if(mn1 and od) mnrow = min(mn1, mnrow);
        if(mn2 and ev) mnrow = min(mn2, mnrow);


        mn1 = 0, mn2 = 0;
        ev = 1, od = 1;
        for(int i = 0; i < n; i++) {
          if(colok[i] and colok1[i]) {
            
            if(i & 1) {
              mn1 += b[i];
                          }
            else mn2 += b[i];
          }
          if(colok1[i] and !colok[i]) {
            if(i & 1) {
              od = 0;
            }
            else ev = 0;
          }
        }
        if(mn1 and od) mncol = min(mn1, mncol);
        if(mn2 and ev) mncol = min(mn2, mncol);
        bool ok1 = 1, ok2 = 1;
        for(auto it: rowok1) ok1 &= (it == 0);
        for(auto it: colok1) ok2 &= (it == 0);
        if(ok1 and ok2) {
          cout << 0 << '\n';
          continue;
        }
        if(mncol == 1e13 or mnrow == 1e13) {
          cout << -1 << '\n';
          continue;
        }
        cout << mncol + mnrow << '\n';

    }
    

    
}