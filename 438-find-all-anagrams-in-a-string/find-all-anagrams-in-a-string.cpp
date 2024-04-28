class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      unordered_map<char,int> mp;
      int k = p.size();
      int n = s.size();

    for(auto it:p) mp[it]++;
      int count = mp.size();
      vector<int>ans;

      int i=0,j=0;

      while(j<n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;

        if(mp[s[j]]==0){
            count--;
        }
        }

        if(j-i+1<k){
            j++;
        }
        else if(j-i+1 ==k){
            if(count==0){
                ans.push_back(i);
            }
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1) count++;
            }
        i++;
        j++;
      }
      }
        return ans;
    }
};

// class Solution {
// public:
// vector<int>findAnagrams(string s, string p) {
// int k=p.length();
// unordered_map<char,int> mp;
// for(auto i: p) mp[i]++;

// vector<int> ans;
// int n=s.length();
// int i=0;
// int j=0;
// int count=mp.size();

// while(j<n){
// if(mp.find(s[j])!=mp.end()) {
// mp[s[j]]--;
// if(mp[s[j]]==0) count--;

//         }
//         if((j-i+1)<k) j++;
//         else if((j-i+1)==k) {
//             if(count==0) ans.push_back(i);
//                 if(mp.find(s[i])!=mp.end()){
//                     mp[s[i]]++;
//                     if(mp[s[i]]==1) count++;
//             }i++;
//             j++;
//         }
//     }
// return ans;
// }
// };