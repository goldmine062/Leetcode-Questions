class Solution {
public:
    long long minCost(vector<int>& a) {
        long long ans = a[0];
        int n = a.size();
        ans += a[n-1];
        if(n==3) return ans ;
        
        vector<int>b;
        for(int i = 1;i<n-1;i++){
            b.push_back(a[i]);
        }

        sort(b.begin(),b.end());
        int maxi = INT_MIN;
        // 0 wale case chudwa denge 
        int pos = 0;
// cout<<b.size()<<endl;
        for(int i = 0;i<b.size();i++){
        if(b[i]>0){
            pos = 1 ;
        // cout<<b[i]<<endl;
            if(i%2==1){
                if(-maxi > b[i]){
                    ans += b[i];
                    break;
                }
                else{
                    ans -= maxi;
                    break;
                }
            }
            else{
                break;
            }
         
        }
        else if(b[i]==0){
            pos =1;
          break;
        }
        else{
            ans += b[i];
            maxi = max(maxi , b[i]);
        }
        }
        if(pos == 0){
            if((n-2)%2==1){
                ans -= maxi;
            }
        }
return ans ;

    }
};