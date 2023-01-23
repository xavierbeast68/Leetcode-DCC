class Solution {
public:
    vector<int> arr{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // arr[0] = 0;
    // arr[1] = 1;
    // arr[2] = 1;
    int tribonacci(int n) {
        if(n==0 || n==1 || n==2)
        {
            return arr[n];
        }
        
        if(arr[n]!=0)
        {
            return arr[n];
        }
        else
        {
            arr[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            return arr[n];
        }
    }
};