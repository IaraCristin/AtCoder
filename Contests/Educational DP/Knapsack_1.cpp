#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll max_weight = 100000;

int n;

struct item
{
    int weight;
    long value;
};

vector<item> items;
//Here we save the sum of values
vector<vector<ll>> mem;

//i index, c capacity
ll f(int i, int c){
    //Base case
    if (i == n || c < 0)
    {
        return 0;
    } 

    //Mem case
    if (mem[i][c] != -1)
    {
        return mem[i][c];
    }
    
    //Rec case
    ll with_item;
    if (c - items[i].weight >= 0)
    {
        with_item = f(i+1,c - items[i].weight);
    } else {
        with_item = 0;
    }
    

    ll no_item = f(i+1,c);

    return mem[i][c] = max(with_item, no_item);
}

int main(){
    //get N and W
    int w;
    cin >> n >> w;

    //get the items with their value and weight
    items.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;
    }
    
    mem.resize(n);
    for (int i = 0; i < n; i++)
    {
        vector<ll> col(max_weight,-1);
        mem[i] = col;
    }
    

    cout << f(0,w);

    return 0;
}