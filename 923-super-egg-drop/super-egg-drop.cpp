// class Solution {
// public:
//     int t[1001][1001];

//     int solve(int e,int f){
//         if(f==0 || f==1) return f;

//         if(e==1) return f;

//         if(t[e][f]!=-1) return t[e][f];
//         int mn = INT_MAX;
//         for(int k=1;k<=f;k++){
//             int low,high;

//             if(t[e-1][k-1]!=-1){
//             low = t[e-1][k-1];
//             }
//             else {
//                 low = solve(e-1,k-1);
//             }

//             if(t[e][f-k]!=-1){
//                 high = t[e][f-k];
//             }
//             else {
//                 high = solve(e,f-k);
//                 t[e][f-k] = high;
//             }

//             int temp = 1 + max(low,high);
//             mn = min(mn,temp);
//         }
//         return t[e][f] = mn;
//     }

//     int superEggDrop(int k, int n) {
//         memset(t,-1,sizeof(t));
//         return solve(k,n);    
//     }
// };

class Solution {
public:

    int t[101][10001];

    int rec(int e, int f)
    {
        if(e==1) return f;
        if(f==0 || f==1) return f;
        if(t[e][f] != -1) return t[e][f];
        int mn = INT_MAX;
        int l = 1, h = f;
        while(l<=h) 
        {
            int mid=l+(h-l)/2;
            // int a=rec(e-1,mid-1);
            int a = (t[e-1][mid-1]!=-1)? t[e-1][mid-1]: rec(e-1,mid-1);
            int b = (t[e][f-mid]!=-1)? t[e][f-mid]: rec(e,f-mid);
            // int b=rec(e,f-mid);
            int x=max(a,b) + 1;
            mn=min(mn,x);
            if(a>b) h=mid-1;
            else l=mid+1;
        }
        return t[e][f] = mn;
    }

    int superEggDrop(int e, int f) {
        memset(t,-1,sizeof(t));
        return rec(e,f);
    }
};

