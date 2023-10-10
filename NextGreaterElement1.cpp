class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int s=nums2.size();
        vector<int> nge;
        for(int i=s-1;i>=0;i--){
            if(st.size()==0){
                nge.push_back(-1);
            }
            else if(st.size()>0 && st.top()<nums2[i]){
                while(st.size()>0 && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.size()==0){
                    nge.push_back(-1);
                }
                else{
                    nge.push_back(st.top());
                }
            }
            else if(st.size()>0 && st.top()>nums2[i]){
                nge.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(nge.begin(),nge.end());
        unordered_map<int,int> mpp;
        int k=0;
        for(auto it:nums2){
            mpp[it]=k;
            k++;
        }
        vector<int> ans;
        for(auto it:nums1){
            auto e=mpp.find(it);
            ans.push_back(nge[e->second]);
        }
        return ans;
    }
};
