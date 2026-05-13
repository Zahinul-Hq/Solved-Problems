#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin>>t; // Read the number of test cases
    while(t--){
        int n, x;
        cin>>n>>x; // Read the number of elements in the array and the number of operations

        int A[n];
        vector<bool> v(32, false); // A vector to keep track of which bits are toggled

        // Read the array elements
        for(int i=0; i<n; i++){
            cin>>A[i];
            // Check each bit from the 31st to the 0th (most significant to least significant)
            for(int j=31; j>=0; j--){
                // If the j-th bit of A[i] is set
                if((A[i] & (1<<j)) != 0){
                    // If the bit is already toggled
                    if(v[j]){
                        v[j] = false; // Reset the bit toggle state
                        A[i] ^= 1<<j; // Toggle the j-th bit of A[i]
                    }
                    // If the bit is not toggled and we have operations left
                    else if(x > 0 && i != n-1){
                        v[j] = true; // Set the bit toggle state
                        A[i] ^= 1<<j; // Toggle the j-th bit of A[i]
                        x--; // Decrement the number of operations left
                    }
                }
            }
        }

        // Apply any remaining toggles to the last element
        for(int i=31; i>=0; i--){
            if(v[i]) A[n-1] ^= 1<<i;
        }

        // Special case handling: if x is odd and there are exactly 2 elements
        if(x % 2 == 1 && n == 2){
            A[n-1] ^= 1; // Toggle the least significant bit of the last element
            A[n-2] ^= 1; // Toggle the least significant bit of the second-to-last element
        }

        // Output the modified array
        for(int i=0; i<n; i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }

    cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}