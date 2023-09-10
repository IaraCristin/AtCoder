#include<iostream>
#include<vector>
using namespace std;

struct activity
{
    int a,b,c;
};




int main(){
    //get N
    int n;
    cin >> n;

    //get activities points
    vector<activity> act(n);
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].a >> act[i].b >> act[i].c;
    }
    
    //We then create the memo for dp
    vector<vector<int>> memo(n);

    //First, we need to declare the first day, since it won't be calculated in the cicle
    vector<int> first_day(3);
    first_day[0] = act[0].a;
    first_day[1] = act[0].b;
    first_day[2] = act[0].c;

    memo[0] = first_day;

    for (int i = 1; i < n; i++)
    {
        vector<int> today_points(3);
        today_points[0] = act[i].a + max(memo[i-1][1], memo[i-1][2]);//We choose the activity a, so we add yesterday's b or c points
        today_points[1] = act[i].b + max(memo[i-1][0], memo[i-1][2]);//We choose the activity b, so we add yesterday's a or c points
        today_points[2] = act[i].c + max(memo[i-1][0], memo[i-1][1]);//We choose the activity a, so we add yesterday's a or b points
        memo[i] = today_points;
    }
    

    cout << max(memo[n-1][0], max(memo[n-1][1], memo[n-1][2]));
    return 0;
}