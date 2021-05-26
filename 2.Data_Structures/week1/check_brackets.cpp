#include<bits/stdc++.h>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    stack<pair<char,int> > st;
    int pos = 1;

    for(char c:text)
    {
        if(c=='(' || c == '[' || c=='{')
        {
            st.push(make_pair(c,pos));
            pos++;
        }
        else if(c==')')
        {
            if(st.top().first == '('){
                st.pop();
                pos++;
            }
            else
            {
                cout << st.top().second;
                break;
            } 
        }
        else if(c==']')
        {
            if(st.top().first == '['){
                st.pop();
                pos++;
            }
            else
            {
                cout << st.top().second;
                break;
            } 
        }
        else if(c=='}')
        {
            if(st.top().first == '{'){
                st.pop();
                pos++;
            }
            else
            {
                cout << st.top().second;
                break;
            } 
        }
        else
            pos++;
    }

    if(st.empty())
        cout << "Success";
    else
        cout << st.top().second;

    return 0;
}
