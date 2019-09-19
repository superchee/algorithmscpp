#include <vector>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(const int& a, const int& b) const{
        return a < b;
    }
};

class Solution{
    public:
    double findMedianSortArrays(vector<int>& nums1, vector<int>& nums2){
        int size1 = nums1.size(), size2 = nums2.size();
        int mid = (size1+size2)>>1;
        vector<int> nums3(size1+size2);

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin(), cmp());

        return (size1+size2)%2 == 0? (nums3[mid]+nums3[mid-1])/2.0:nums3[mid];

    }
};


/*** slow
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        
        int mid = (size1+size2)>>1;

        int nNum = 0, nPre = 0, Idx1 = 0, Idx2 = 0, current;

        while(nNum <= mid){
            if (Idx1 < size1 && Idx2 < size2){
                nPre = current;
                current = nums1[Idx1] < nums2[Idx2] ? nums1[Idx1++]:nums2[Idx2++];
            }else{
                break;
            }
            nNum++;
        }

        while(nNum <= mid){
            nPre = current;
            if (Idx1 < size1){
                current = nums1[Idx1++];
            }else{
                current = nums2[Idx2++];
            }
            nNum++;
        }

        return (size1 + size2)%2 == 0? (nPre + current)/2.0: current;

    }
};
***/