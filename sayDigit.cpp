#include<iostream>
#include<vector>
using namespace std;

void sayDigit(int value, vector<string> &words)
{
    //base case
    if(value <= 0)
    {
        return;
    }
    //processing
    int digit = value % 10;
    cout<<words[digit]<<", ";
    value = value /10;
    //recursive relation
    sayDigit(value, words);
}

int main()
{
    vector<string> words = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int value;
    cout<<"Enter any value: "<<endl;
    cin >> value;
    sayDigit(value, words);
    return 0;
}