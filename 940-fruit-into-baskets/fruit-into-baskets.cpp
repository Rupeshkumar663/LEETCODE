//Time Compleixty: O(n*n)
//Space Complexity: O(1)
//brute force Approach-----
//Give TLE
/*class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi=0;
        for(int i=0;i<fruits.size();i++){
            unordered_set<int>s;
            for(int j=i;j<fruits.size();j++){
                s.insert(fruits[j]);
                if(s.size()>2){
                    break;
                }
                maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits){
        int n=fruits.size();
        int i= 0,j=0;
        int maxi=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};