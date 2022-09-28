#include <bits/stdc++.h> 

bool ispossible(vector<int> &rank , int m , int mid){
    int time = 0;
    int dishes = 0;
    for(int i = 0 ; i < rank.size() ; i++){
        for(int j = 1 ; j<=m ; j++){
            time += rank[i]*j;
            if(time <= mid){
                dishes++;
                if(dishes == m){
                    return true;
                }
            }  
        }
        time = 0;
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    int start = 0;
    int end = 0;
    for(int i = 0  ; i <= m ; i++){
        end += rank[rank.size() - 1]*i;
    }
    int ans = -1;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        
        if(ispossible(rank , m , mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
