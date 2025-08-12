class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1; //start from the last
        int j=n-1;
        int k=m+n-1;
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){ //agar pahle array kaa last element bada hai dusre element ke toh wo sabse last me jaayega new sorted array ke.. kyoki array sorted hai..aur aakri index kam kar di jaayegi 
                nums1[k]=nums1[i];
                i--;
                k--;    
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
                
            }
        }
    }
};