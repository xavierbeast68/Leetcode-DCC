//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    void rec(vector<long long>& arr, int start, int end){
        if(start==end){
            return;
        }
        if(start+1 == end){
            long long temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            return;
        }
        
        long long temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        rec(arr, start+1, end-1);
        return;
    }
    
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        
        // Recursive Approach->
        int i=0;
        while(i<n)
        {
            if((i+k-1) <=n-1){
                rec(arr, i, i+k-1);
            }
            else{
                rec(arr, i, n-1);
            }
            i += k;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends