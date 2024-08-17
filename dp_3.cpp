//third approach Space Optimization
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>> n;
    //step 1
    int prev_1 = 1;
    int prev_2 = 0;
    //step 2
    for(int i = 2; i <= n; i++)
    {
        int current = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = current;
    }
    cout<<prev_1<<endl;
    return 0;
}