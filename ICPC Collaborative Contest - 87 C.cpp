#include<bits/stdc++.h>

using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second


int main()
{
    


    int n, m;

    cin >> n >> m;

    vector<ll>arr(n, 0);

    arr.push_back(inf);


    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //sort(arr.begin(), arr.end());


    int pos = 0, ans = 0;

    while(1){
        int n_pos = lower_bound(arr.begin(), arr.end(), arr[pos] + m) - arr.begin();
        ans += ((n_pos  - pos) - 1);

        if(n_pos >= n)
            break;


        pos = n_pos;

    }

    cout << ans << endl;
    return 0 ;

}
