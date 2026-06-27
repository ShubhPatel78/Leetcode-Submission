class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        int n=arr.size();
        while(r<k){
           sum=sum+arr[r];
           r++;
        }
        if(sum>=threshold*k){
            count++;
        }
        while(r<n){
            sum=sum+arr[r];
            sum=sum-arr[l];
            l++;
            r++;
            if(sum>=threshold*k){
                count++;
            }
        }
        return count;
    }
};