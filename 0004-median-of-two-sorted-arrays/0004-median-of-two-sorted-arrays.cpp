class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int current = 0, previous = 0;

        int i = 0, j = 0;

        int middle = (n+m) / 2;
        // cout << middle << endl;

        for(int count = 0; count <= middle; count++){
            previous = current;
            // cout << current << endl;
            if(i < n && j < m){
                if(nums1[i] <= nums2[j]){
                    current = nums1[i];
                    i++;
                }
                else{
                    current = nums2[j];
                    j++;
                }
            }
            else if(i < n){
                current = nums1[i];
                i++;
            }
            else{
                current = nums2[j];
                j++;
            }
        }

        // cout << current << endl;


        // cout << previous << current << endl;
        if((n+m)%2 == 1)
            return (double)current;
        else{
            return ((double)previous+(double)current)/2.0;
        }
    }
};