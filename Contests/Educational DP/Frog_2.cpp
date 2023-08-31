//Its practically the same but now the frog can jump up to k stones, contrary to the previous, where it could only jump up to 2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    //get N
    int n;
    cin >> n;

    //get heights
    vector<int> heights(n,0); //Initialize vector with all 0
    for (int i = 0; i < n; i++)
    {  
        cin >> heights[i];   
    }


    //This is a modification of the first frog
    vector<int> min_cost(n,0);
    min_cost[1] = abs(heights[1]-heights[0]);

    //Then we get the minimum cost to get to the i stone by adding the previous min cost of the i-1 or the i-2 stone to the cost of the i stone
    for (int i = 2; i < n; i++)
    {
        min_cost[i] = min(  min_cost[i-1] + abs(heights[i] - heights[i-1]),     //Cost of jumping from i-1 stone to i stone
                            min_cost[i-2] + abs(heights[i] - heights[i-2]));    //Cost of jumping from i-1 stone to i stone
    }
    
    //And finally, we give the end result of the last cost
    cout << min_cost[n-1];

    //This is for the error code, it needs to return 0 to indicate that it ended correctly
    return 0; 
}