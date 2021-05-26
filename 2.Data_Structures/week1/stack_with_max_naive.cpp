#include<bits/stdc++.h>

using namespace std;

class lst
{
    class node{
        public:
        int data, mx;
        node* prev;

        node(int d)
        {
            data = d;
            mx = INT_MIN;
            prev = NULL;
        }
    };

    node *last, *top;

    public:
    lst()
    {
        last = NULL;
        top = NULL;
    }
    void push(int x)
    {
        node *temp;
        if(last == NULL)
        {
            temp = new node(x);
            temp->mx = x;
            this->top = temp;
            this->last = temp;
        }
        else{
            temp = new node(x);
            temp->mx = max(x,this->top->mx);
            temp->prev = this->top;
            this->top = temp;
        }
    }

    int pop()
    {
        if(this->top == this->last)
        {
            int x = this->top->data;
            delete this->top;
            this->top = NULL;
            this->last = NULL;
            return x;
        }
        else{
            node *temp = this->top;
            this->top = this->top->prev;
            int x = temp->data;
            delete temp;
            return x;
        }
    }

    int maxi()
    {
        return this->top->mx;
    }
};


int main()
{
    lst lklst;
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        int x;
        cin >> s;
        if(s == "push")
        {
            cin >> x;
            lklst.push(x);
        }
        if(s == "pop")
            lklst.pop();
        if(s == "max")
            cout << lklst.maxi() << endl;
    }
}