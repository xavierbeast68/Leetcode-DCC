//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

string rec(string str, int start, int end)
{
    if (start == end)
    {
        return str;
    }
    if (start + 1 == end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        return str;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    return rec(str, start + 1, end - 1);
}

string reverseWord(string str)
{

    // Your code here

    // Iterative Approach->
    int start = 0, end = str.length() - 1;
    while (start <= end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++, end--;
    }
    return str;

    // Recursive Approch->
    //   int start=0, end = str.length()-1;
    //   string answer = rec(str, start, end);
    //   return answer;
}