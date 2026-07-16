class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return arr;
        vector<int> temp(arr);
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mp;
        mp.reserve(n);
        mp[temp[0]]=1;
        int rank = 1;
        for(int i = 1; i < n; ++i){
            if(temp[i] == temp[i-1]) mp[temp[i]] = rank;
            else mp[temp[i]] = ++rank;
        }
        for(int i = 0; i < n; ++i){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};