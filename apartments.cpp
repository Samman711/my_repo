#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for ( i = a; i <b; i++)
int main()
{
    int i,j,count=0;
  vector <int> demand;
  vector <int> available;
    int x,m,k;
    cin>>x;cin>>m;cin>>k;
    int temp;
    REP(i,0,x)
    {
        cin>>temp;
        demand.push_back(temp);
    }  
    REP(i,0,m)
    {
        cin>>temp;
        available.push_back(temp);
    }
    sort(demand.begin(),demand.end());
    sort(available.begin(),available.end());
    // REP(i,0,x)
    // {
    //     REP(j,0,m)
    //     {
    //         if(demand[i]<=available[j]+k&&demand[i]>=available[j]-k)
    //         {
    //             count++;
    //             available.erase(available.begin()+j);
    //             m--;
    //             continue;
    //         }
    //     }
    // }
     i = 0; // Pointer for demand vector (applicants)
     j = 0; // Pointer for available vector (apartments)
     count = 0;

    while (i < x && j < m) {
        
        if (abs(demand[i] - available[j]) <= k) {
            
            count++;
            i++;
            j++; 
        } 
        else if (demand[i] < available[j] - k) {
            // Applicant i demands a smaller size than apartment j's minimum acceptable size (available[j] - k).
            // Apartment j is too large for applicant i (and any subsequent apartment j, j+1, ...).
            // Move to the next applicant (i+1) hoping for a match with a smaller apartment later.
            i++; 
        } 
        else { // demand[i] > available[j] + k
            // Applicant i demands a larger size than apartment j's maximum acceptable size (available[j] + k).
            // Apartment j is too small for applicant i (and any prior apartment 0, 1, ..., j-1).
            // Move to the next apartment (j+1) hoping to satisfy applicant i.
            j++;
        }
    }
    cout<<count;
      return 0;
}