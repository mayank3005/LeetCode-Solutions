//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
int result(int mid ) {

            int res = 0;

            while(mid) {

                // count no of 5 in any n factorial 

                res = res + mid/5;

                mid = mid / 5;

            } 

 

            return res;

 
}
 

 

int findNum(int n)

        {   

            // ans between 1 and n*5 becoz 1 <= n <= 10^4

            int s = 1;

            int e = n*5;

            int ans;

            while(s <= e) {

                int mid =  s + (e-s)/2;

                if(result(mid) >= n) {

                    e = mid - 1;

                    ans = mid;

                }

                else {

                    s = mid + 1;

                }

            }

            return ans;

 

        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends