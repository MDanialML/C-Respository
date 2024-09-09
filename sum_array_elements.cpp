#include<iostream>
using namespace std;

int sumEle(int *arr, int size)
{
    //base condition: minimum valid input
    if(size == 1)
    {
        return arr[0]; // return element of array
    }

    //induction
    int sum = arr[0];
    //hypothesis
    sum = sum + sumEle(arr+1, size - 1);
    return sum;

}

int main()
{
    int arr[] = {3, 2, 5, 1, 6};
    int sum = sumEle(arr, 5);
    cout<<"Sum of all element of given array: "<<sum<<endl;
    return 0;
}