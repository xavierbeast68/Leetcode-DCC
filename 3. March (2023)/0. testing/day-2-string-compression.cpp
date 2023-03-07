/*
    ▄  ██       ▄   ▄█ ▄███▄   █▄▄▄▄ ███   ▄███▄   ██      ▄▄▄▄▄      ▄▄▄▄▀ 
▀▄   █ █ █       █  ██ █▀   ▀  █  ▄▀ █  █  █▀   ▀  █ █    █     ▀▄ ▀▀▀ █    
  █ ▀  █▄▄█ █     █ ██ ██▄▄    █▀▀▌  █ ▀ ▄ ██▄▄    █▄▄█ ▄  ▀▀▀▀▄       █    
 ▄ █   █  █  █    █ ▐█ █▄   ▄▀ █  █  █  ▄▀ █▄   ▄▀ █  █  ▀▄▄▄▄▀       █     
█   ▀▄    █   █  █   ▐ ▀███▀     █   ███   ▀███▀      █              ▀      
 ▀       █     █▐               ▀                    █                      
        ▀      ▐                                    ▀                       
*/
/**
 * xavierbeast68
 * URL : https://leetcode.com/problems/different-ways-to-add-parentheses/
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#pragma GCC optimize("O3,Ofast,unroll-loops")

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio                                      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl                                        '\n'
#define int                                         long long
using ll                                            = long long;
using ull                                           = unsigned long long;
using lld                                           = long double;
#define vi                                          vector<int>

constexpr lld EPS                                   = 1e-9;
constexpr ll MOD                                    = 1e9 + 7; //1000000007
constexpr ll mod1                                   = 998244353;

#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)

#define pb                                          push_back
#define ppb                                         pop_back
#define sz(x)                                       (int)(x).size()
#define all(x)                                      begin(x), end(x)
#define mp(x,y)                                     make_pair(x,y)
#define lb(arr, x)                                  lower_bound(arr.begin(), arr.end(), x) - arr.begin();
#define ub(arr, x)                                  upper_bound(arr.begin(), arr.end(), x) - arr.begin();


/*------------------------------------------------------Read & Print Methods------------------------------------------------------*/

#define read(x)                                     int x; cin >> x; // reads long long
#define readstr(x)                                  string s; cin >> s; // reads string(word)
#define readLine(x)                                 string s; getline(cin,s); // reads string(sentence)
#define print(x)                                    cout<<(x)
#define println(x)                                  cout<<(x)<<endl

// Vector Read & Print ->
template <class T> vector<T> readvector(T n) { vector<T> arr(n); for (int i = 0; i < n; i++) {cin >> arr[i];} return arr;}   // vector<ll> arr = readvector(n);
template <class T> void printvector(vector<T> arr, T n) {for (int i = 0; i < n; i++) {cout << arr[i] << " ";} cout << endl;}   // printvector(arr, n);

//InputOutputError_From/To_File ->
void file_io()
{
// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


/*----------------------------------------------------------------PBDS----------------------------------------------------------------*/

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;     // ordered_set <T> a; (work as ordered_set) // ordered_set <pair<T, T>> a; (ordered set of pairs (can also work as ordered_map))
template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;      // multi_ordered_set <T> a; // multi_ordered_set <pair<T,T>> a;
// order_of_key(k): Returns the number of elements strictly smaller than k.
// find_by_order(k): Returns the address of the element at kth index in the set while using zero-based indexing, i.e the first element is at index zero.


/*--------------------------------------------------------------Debugger--------------------------------------------------------------*/
//            [di:b^b-ing]
// -Being the detective in a crime
//  where you are also the murderer.

#define test(i)                                     cout << "(#" << i << ")" << endl

// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
#define dbg(x)                                      cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

// void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
// void _print(auto t) {cerr << *t;} // for ordered_set

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(ordered_set v) {cerr << "[ "; for (int i=0 ; i<(int)v.size();i++) {_print(v.find_by_order(i)); cerr << " ";} cerr << "]";}


/*------------------------------------------------------Functions------------------------------------------------------*/

ll gcd(ll a, ll b)                                  {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                                  {return a / gcd(a, b) * b;}
ll countDigit(ll n)                                 {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b)                      {return log2(a) / log2(b);}
ll isPowerof2(ll x)                                 {return (x && !(x & (x - 1)));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a)                                 {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)
ll factorial(const int& p)                          {if (p <= 1) {return 1;} return p * factorial(p - 1);}
bool isPrime(ll n)                                  {if (n == 2 || n == 3) {return true;} if (n <= 1 || n % 2 == 0 || n % 3 == 0) {return false;} for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) {return false;}} return true;}
ll binpow(ll a , ll b)                              {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % MOD, b / 2);} else {return (a * binpow((a * a) % MOD, b / 2)) % MOD;}}    // binary exponentiation

ll mod(ll x)                                        {return (((x) % MOD + MOD) % MOD);}
ll mod_add(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a+b));}
ll mod_mul(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a*b)); }
ll mod_sub(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a-b));}

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r)                      {return uniform_int_distribution<ll>(l, r)(rng); }


/*-------------------------------------------------------||||||||||-----------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
                                        |H| |e| |r| |e|   |w| |e|   |g| |o| |!| |!| |!|
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------||||||||||------------------------------------------------------------------------*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1){
            return 1;
        }
        int count = 1;
        string ans = "";
        for(int i =  0; i <= n - 2; ++i){
            if(i == n-2){
                if(chars[i] == chars[i+1]){
                    count++ ;
                    ans += chars[i] + to_string(count);
                }
                else{
                    if(count == 1){
                        ans = ans + chars[i] + chars[i+1];
                        break;
                    }
                    else{
                        ans = ans + chars[i] + to_string(count) + chars[i+1];
                        break;
                    }
                }
            }

            else if(chars[i] == chars[i+1]){
                count++;
            }
            else{
                if(count == 1){
                    ans = ans + chars[i];
                }
                else{
                    ans = ans + chars[i] + to_string(count);
                    count = 1;
                }
            }
        }
        
        chars.clear();
        for(char ch : ans){
            chars.push_back(ch);
        }

        return ans.length();
    }
};


void solve()
{
    /*--Let's Code--*/
    read(n);
    vector<char> chars(n);
    for(int i = 0 ; i < n ; i++){
        cin >> chars[i];
    }
    Solution obj = Solution();
    int ans = obj.compress(chars);
    println(ans);
    for(char ch : chars){
        cout << ch << " ";
    }
    cout << endl;
}

signed main()
{
    fastio;

    cout << fixed << setprecision(10);
    // file_io();
    auto start = high_resolution_clock::now();

    /*testcases=1: default value for single test case*/
    int testcases = 1;
    // cin >> testcases;
    while (testcases--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    #ifdef XAVIERBEAST
        cerr << endl << "Time: " << (float)duration.count()/1000000 << " s" << endl;
    #endif

    return 0;
}