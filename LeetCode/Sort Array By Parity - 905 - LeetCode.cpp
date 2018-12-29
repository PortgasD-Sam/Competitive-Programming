class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> required;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]%2)
                required.push_back(A[i]);
            else
                required.insert(required.begin(),A[i]);
        }
        return required;
    }
};
