bool ispossible(vector<int> &stalls , int k , int mid){
    int cowcount = 1;
    int lastposition = stalls[0];
    
    for(int i=0 ; i<stalls.size() ; i++){
        if(stalls[i] - lastposition >= mid){
            cowcount++;
            if(cowcount == k){
                return true;
            }
            lastposition = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    
    sort(stalls.begin() , stalls.end());
    
    int start = 0;
    int maxi = -1;
    for(int i=0 ; i<stalls.size() ; i++){
        maxi = max(maxi , stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        if(ispossible(stalls , k , mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
