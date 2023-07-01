bool possible(int mid,vector<int>&stalls,int k){
    int cnt=0;
    int cow=stalls[0];
    cnt++;
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-cow>=mid){
            cnt++;
            cow=stalls[i];
        }
    }
    if(cnt>=k) return true;
    else return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-low;
    int ans=high;
    while(low<=high){
        int mid=(low+high)>>1;
        if(possible(mid,stalls,k)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

