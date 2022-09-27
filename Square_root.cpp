#include <bits/stdc++.h> 
using namespace std;

long long int binarySearch(long long int n){
    
    long long int start = 0;
    long long int end = n;
    unsigned long long int mid = start + (end - start)/2;
    long long ans = -1;
    
    while(start <= end){

        unsigned long long int square = mid * mid;

        if(square == n){
            return mid;
        }
        if(square < n){
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

int sqrtN(long long int N)
{
    // Write your code here.
    return binarySearch(N);
}
