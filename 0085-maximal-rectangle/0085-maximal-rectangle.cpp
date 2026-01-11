class Solution {
public:
int area(vector<int>& heights) {
        stack<int>st;
        int maxi=0;
        int i=1;
        st.push(0);
        while(i<heights.size())
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                int ele=st.top();
                st.pop();
                int total=0;
                int pse=st.empty()?-1:st.top();
                total=heights[ele]*(i-pse-1);
                maxi=max(maxi,total);
            }
            st.push(i);
            i++;
        }
        while(!st.empty())
        {
            int k=st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top(); 
            int area=(heights[k]*(heights.size()-pse-1));
            maxi=max(maxi,area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            int presum=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[j][i]=='0')
                {
                    presum=0;
                    ans[j][i]=0;
                }
                else
                {
                    presum+=matrix[j][i];
                    presum=presum-'0';
                    ans[j][i]=presum;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,area(ans[i]));
        }
        return maxi;
    }
};