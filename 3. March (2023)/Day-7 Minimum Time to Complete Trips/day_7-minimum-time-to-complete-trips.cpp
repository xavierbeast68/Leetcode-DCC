//* https://leetcode.com/problems/minimum-time-to-complete-trips/
//* https://www.youtube.com/watch?v=WXrNKPqSOUg
//* https://www.youtube.com/watch?v=nOfq3MgbFQI

typedef long long ll;
class Solution {
public:
    bool check(vector<int>& time, ll givenTime, ll t){
        ll maxTrips = 0;
        for(auto& i : time){
            maxTrips += (givenTime / i);

            if(maxTrips >= t){
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // number of buses available
        int n = time.size();

        sort(begin(time), end(time));

        // minimum time to complete totalTrips can't be time[0]*totalTrips, bcoz there can be simultanously running buses other than bus(time[0]) that will eventually decrease minimum time from time[0]*totalTrips to something else
        ll l = (ll) time[0];
        // maximum time to complete totalTrips
        ll r = (ll)time[n-1] * (ll)totalTrips;

        while(l < r){
            ll mid = l + (r - l)/2;

            if(check(time, mid, (ll)totalTrips)){
                // if maximum trips that are possible in mid time are > totalTrips 
                r = mid;
            }
            else{
                 l = mid + 1;
            }
        }
        return l;
    }
};