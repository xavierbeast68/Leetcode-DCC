//* https://leetcode.com/problems/can-place-flowers/description/
//* https://www.youtube.com/watch?v=ZGxqqjljpUI
//* https://www.youtube.com/watch?v=0y480nJVzHs

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        // Optimized 2->
        if(n==0){
            return true;
        }
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; ++i){
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                n--;
                flowerbed[i] = 1;
            }
            if(n==0){
                return true;
            }
        }
        return (n==0? true : false);



        // Optimized 1->
        // if(n==0){
        //     return true;
        // }
        // int l = flowerbed.size();
        // for(int i = 0; i < l; ++i){
        //     if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1] == 0) && (i==l-1 || flowerbed[i+1] == 0)){
        //         n--;
        //         flowerbed[i] = 1;
        //     }
        //     if(n==0){
        //         return true;
        //     }
        // }
        // return (n==0? true : false);



        // Brute Force->
        // if(n==0){
        //     return true;
        // }

        // int l = flowerbed.size();
        // if(l == 1){
        //     if(n>1){
        //         return false;
        //     }

        //     else if(flowerbed[0] == 1){
        //         false;
        //     }

        //     else{
        //         return true;
        //     }
        // }

        // if(l==2){
        //     if(n>1){
        //         return false;
        //     }

        //     if(flowerbed[0] == 1 || flowerbed[1] == 1){
        //         return false;
        //     }

        //     return true;
        // }

        // if(flowerbed[0] == 0 && flowerbed[1] == 0){
        //     n--;
        //     flowerbed[0] = 1;
        //     if(n==0){
        //         return true;
        //     }
        // }
        // if(flowerbed[l-1] == 0 && flowerbed[l-2] == 0){
        //     n--;
        //     flowerbed[l-1] = 1;
        //     if(n==0){
        //         return true;
        //     }
        // }

        // for(int i = 1; i < l-1; ++i){
        //     if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
        //         n--;
        //         flowerbed[i] = 1;
        //     }

        //     if(n==0){
        //         return true;
        //     }
        // }

        // if(n==0){
        //     return true;
        // }
        // else{
        //     return false;
        // }
    }
};