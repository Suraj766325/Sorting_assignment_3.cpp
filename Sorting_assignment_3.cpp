// Q1) What is an in-place sorting algorithm?
a) It needs O(1) or O(logn) memory to create auxiliary locations
b) The input is already sorted and in-place
c) It requires additional storage
d) It requires additional space
    ANSWER= a


// Q2) In the following scenarios, when will you use selection sort?
a) The input is already sorted
b) A large file has to be sorted
c) Large values need to be sorted with small keys
d) Small values need to be sorted with large keys
    ANSWER= c


// Q3) Given an integer array and an integer k where k<=size of array, We need to return the kth smallest element of the array.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int>v={2,3,1,0,5,4};
    int k=3,n=v.size(),i,j,m,t,x;
    for(i=0;i<k;i++)
    {
        m=INT_MAX;
        for(j=i;j<n;j++)
        {
            if(v[j]<m)
            {
                m=v[j];
                x=j;
            }
        }
        t=v[x];
        v[x]=v[i];
        v[i]=t;
    }
    cout<<k<<"th smallest element = "<<v[k-1];
}



// Q4) Given an array, arr[] containing n integers, the task is to find an integer (say K) such that after replacing each and every index of the array by |ai – K| where ( i ∈ [1, n]), results in a sorted
array. If no such integer exists that satisfies the above condition then return -1.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int> v={5,3,7};
    int n=v.size(),i,kmax=INT_MAX,kmin=INT_MIN,s;
    for(i=0;i<n-1;i++)
    {
        if(v[i]-v[i+1]>=0)
        {
              if((v[i]+v[i+1])%2==0) s=(v[i]+v[i+1])/2;
              else                   s=(v[i]+v[i+1]+1)/2;
              kmin=max(kmin,s);
        }
        else
        {
              if((v[i]+v[i+1])%2==0) s=(v[i]+v[i+1])/2-1;
              else                   s=(v[i]+v[i+1]-1)/2;
              kmax=min(kmax,s);
        }
    }
    if(kmax>kmin) cout<<"range = ["<<kmin<<","<<kmax<<"]";
    else if(kmax==kmin) cout<<"range = ["<<kmax<<"]";
    else                cout<<"not possible";
}