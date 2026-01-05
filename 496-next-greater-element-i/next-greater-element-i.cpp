//BRUTE FORCE APPROACH--------------------------------------------
/*class Solution{
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
*/

//OPTIMAL APPROACH------------------------------------
class Solution{
public:
    vector<int> nextGreaterElement(vector<int>&nums1,vector<int>&nums2){
        vector<int>result;
        unordered_map<int,int>m;
        stack<int>s;
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && s.top()<nums2[i]){
                m[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
        m[s.top()]=-1;
        s.pop();
         }
         for(int i=0;i<nums1.size();i++)
           result.push_back(m[nums1[i]]);

        return result;
    }
};
