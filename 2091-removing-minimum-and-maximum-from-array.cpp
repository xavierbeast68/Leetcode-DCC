class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int len = nums.size();

        if(len==1 || len==2){
            return len;
        }

        int maxElement = *(max_element(nums.begin(),nums.end()));
        int minElement = *(min_element(nums.begin(),nums.end()));
        int index_max=0,index_min=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==maxElement) {index_max=i;}
            if(nums[i]==minElement) {index_min=i;}
        }
        // cout<< maxElement << " " << minElement << " " << index_max << " " << index_min << endl;
        int maxE_left = index_max + 1, minE_left = index_min + 1;
        int maxE_right = len - index_max, minE_right = len - index_min;

        int rightmost = min(maxE_right, minE_right);
        int leftmost = min(maxE_left, minE_left);
        int first_delete = min(leftmost, rightmost);
        // cout<< first_delete << endl;
        int second_delete=0;

        if(first_delete == leftmost)
        {
            if(leftmost==minE_left)
            {
                maxE_left -= leftmost;
                second_delete = min(maxE_left, maxE_right);
            }
            else
            {
                minE_left -= leftmost;
                second_delete = min(minE_left, minE_right);
            }
        }
        else
        {
            if(rightmost==minE_right)
            {
                maxE_right -= rightmost;
                second_delete = min(maxE_left, maxE_right);
            }
            else
            {
                minE_right -= rightmost;
                second_delete = min(minE_left, minE_right);
            }
        }
        // cout<< second_delete << endl;
        return first_delete + second_delete;
    }
};