// https://leetcode.com/problems/find-in-mountain-array/
// https://leetcode.com/problems/find-in-mountain-array/editorial
// https://youtu.be/BGgYC-YkGvc?si=o7A9GtbLRul4Jb6i

// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// https://leetcode.com/problems/peak-index-in-a-mountain-array/editorial/
// https://youtu.be/cXxmbemS6XM

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakInd = findPeakElement(mountainArr);

        int n = mountainArr.length();

        int firstInd = firstHalf(mountainArr, 0, peakInd, target);
        
        if(firstInd != n){
            return firstInd;
        }

        int secondInd = secondHalf(mountainArr, peakInd, n-1, target);

        return (secondInd == n? -1 : secondInd);
    }

    int findPeakElement(MountainArray &arr) {
        int n = arr.length();

        // corner cases
        if(n == 1) return 0;
        if(arr.get(0) > arr.get(1)) return 0;
        if(arr.get(n-1) > arr.get(n-2)) return n-1;

        int low = 1, high = n-2;
        
        while(low <= high){
            int mid = high - (high-low)/2;
            
            if(arr.get(mid) > arr.get(mid-1) && arr.get(mid) > arr.get(mid+1)){
                return mid;
            }
            else if(arr.get(mid) > arr.get(mid-1)){
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }
        return -1;
    }

    int firstHalf(MountainArray &arr, int low, int high, int target){
        while(low <= high){
            int mid = (low + high)/2;

            if(arr.get(mid) == target){
                return mid;
            }
            else if(arr.get(mid) > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return arr.length();
    }
    int secondHalf(MountainArray &arr, int low, int high, int target){
        while(low <= high){
            int mid = (low + high)/2;

            if(arr.get(mid) == target){
                return mid;
            }
            else if(arr.get(mid) > target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return arr.length();
    }
};