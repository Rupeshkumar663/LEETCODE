class Solution{
public:
    vector<int> nextGreaterElement(vector<int>&nums1,vector<int>&nums2){
        vector<int>result;
        for(int i=0;i<nums1.size();i++){
            int x=nums1[i];
            int ans=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==x){
                    for(int k=j+1;k<nums2.size();k++){
                        if(nums2[k]>x){
                            ans=nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};
