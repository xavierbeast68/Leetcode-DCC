//* https://leetcode.com/problems/fruit-into-baskets/description/
//* https://leetcode.com/problems/fruit-into-baskets/submissions/893188024/
//* https://www.youtube.com/watch?v=yYtaV0G3mWQ
//* https://www.geeksforgeeks.org/maximum-no-of-apples-that-can-be-kept-in-a-single-basket/
//* https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1?problemStatus=unsolved&page=1&sortBy=newest&query=problemStatusunsolvedpage1sortBynewest

class Solution {
public:
    // void debug(map<int,int> mp){
    //     map<int, int>::iterator it = mp.begin();
    //     while (it != mp.end())
    //     {
    //         cout << "Key: " << it->first << ", Value: " << it->second << endl;
    //         ++it;
    //     }
    // }

    int currFruitsInBasket(map<int,int>& mp){
        return (accumulate
                (begin(mp), end(mp), 0, 
                [] (int value, const map<int, int>::value_type& p)
                { return value + p.second; }));
    }

    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int> mp;
        mp[fruits[0]]++;
        int currElement = fruits[0], currIndex = 0;
        int i = 1;

        int maxFruits = currFruitsInBasket(mp);
        // cout<< maxFruits<<endl;
        while(i < n){
            if(fruits[i] == fruits[i-1]){
                mp[fruits[i]]++;
                int fruitsInBasket = currFruitsInBasket(mp);
                maxFruits = max(maxFruits, fruitsInBasket);

                // cout<<"#1"<<endl;
                // cout<<"accumulate->"<<fruitsInBasket<<endl;
                // debug(mp);
            }

            else{
                if(mp.size()<2 || mp.find(fruits[i]) != mp.end()){
                    mp[fruits[i]]++;

                    int fruitsInBasket = currFruitsInBasket(mp);
                    maxFruits = max(maxFruits, fruitsInBasket);
                    currElement = fruits[i];
                    currIndex = i;

                    // cout<<"#2"<<endl;
                    // cout<<"accumulate->"<<fruitsInBasket<<endl;
                    // debug(mp);
                }

                else{
                    mp.clear();
                    mp[currElement] = i - currIndex;

                    mp[fruits[i]]++;
                    int fruitsInBasket = currFruitsInBasket(mp);
                    maxFruits = max(maxFruits, fruitsInBasket);
                    currElement = fruits[i];
                    currIndex = i;

                    // cout<<"#3"<<endl;
                    // cout<<"accumulate->"<<fruitsInBasket<<endl;
                    // debug(mp);
                }
            }
            i++;
            // cout<< maxFruits<<endl;
        }

        return maxFruits;
    }
};