#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> & arr, int value)
{
    //base condition: if the last element of array is smaller or equal to value then push back value into array
    if(arr.size() == 0 || arr[arr.size()-1] <= value)
    {
        arr.push_back(value);
        return;
    }

    //induction step
    int temp = arr[arr.size()-1];
    arr.pop_back();
    //hypothesis
    insert(arr, value);
    arr.push_back(temp);
}


void recur_sort(vector<int>& arr)
{
    //base condition
    if(arr.size() == 1) //array having only one element considered sorted
    {
        return;
    }

    //induction step: step to make input smalller
    int last_val = arr[arr.size()-1];
    arr.pop_back();
    //Hypothesis: call function on smaller input
    recur_sort(arr);
    insert(arr, last_val);

}

int main()
{
    vector<int> arr = {2, 4, 0, 1, 5, 8};
    recur_sort(arr);
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}