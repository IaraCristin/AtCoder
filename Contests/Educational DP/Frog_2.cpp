//Its practically the same but now the frog can jump up to k stones, contrary to the previous, where it could only jump up to 2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    //get N and K
    int n,k;

    cin >> n >> k;

    //get heights
    vector<int> heights(n,0); //Initialize vector with all 0
    for (int i = 0; i < n; i++)
    {  
        cin >> heights[i];   
    }

    int max_cost = 1e9;
    vector<int> min_cost(n,max_cost);
    min_cost[0] = 0;

    for(int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k && i-j >= 0; j++)
        {
            min_cost[i] = min(min_cost[i],min_cost[i-j] + abs(heights[i] - heights[i-j]));
        }
        
    }
    
    
    //And finally, we give the end result of the last cost
    cout << min_cost[n-1];

    //This is for the error code, it needs to return 0 to indicate that it ended correctly
    return 0; 
}