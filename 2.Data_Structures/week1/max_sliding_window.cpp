#include<bits/stdc++.h>

using namespace std;

class lst
{
    class node{
        public:
        int data;
        node* prev;
        public:
        int mx;
        node(int d)
        {
            data = d;
            mx = INT_MIN;
            prev = NULL;
        }
    };

    public:
    int size = 0;
    node *last, *top;
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
        size++;
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
    lst t1, t2;
    int n,m,c=0;
    cin >> n;
    vector<int>ints(n);
    for (int i = 0; i < n; i++)
        cin >> ints[i];
    cin >> m;
    
    while(1)
    {
        bool f = 1;
        if(f)
        {
            int ctr = m;
            while(ctr--)
                t1.push(ints[c++]);
            f = 0;
            ctr = m;
            while(ctr--)
                t2.push(t1.pop());
            cout << t2.maxi() << " ";
        }
        int ctr,mx = INT_MIN;
    
        if(c%m == 0)
            ctr = m;
        else
            ctr = n%m;
        while(ctr--)
        {
            t2.pop();
            t1.push(ints[c++]);
            if(ctr+1 > 1){
                t2.top->mx = max(t2.maxi(),ints[c-1]);
                cout << max(t2.maxi(),ints[c-1]) << " "; 
            }
            // else
            // {
            //     int ctr1 = t1.size;
            //     while(ctr1--)
            //         t2.push(t1.pop());
            //     cout << t2.maxi() << " "; 
            // }
        }
        if(c==n)
            break;
    }
}