#include<iostream>
#include<stack>
using namespace std;

void insert_onto_stack(stack<int>& st, int val)
{
    //base condition
    if(st.empty() || st.top() <= val)
    {
        st.push(val);
        return;
    }
    // Induction step
    int temp = st.top();
    st.pop();
    //Hypothesis
    insert_onto_stack(st, val);
    st.push(temp);
}

void sort_stack(stack<int>& st)
{
    //base condition 
    if(st.size() == 1)
    {
        return;
    }

    //Induction step
    //hold top element
    int value = st.top();
    st.pop();
    //Hypothesis
    sort_stack(st);
    //insert back poped element
    insert_onto_stack(st,value);
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(0);
    st.push(2);
    sort_stack(st);

    //print stack element
    while (!st.empty())
    {
        int top = st.top();
        cout<<top<<", ";
        st.pop();
    }
    return 0;
}