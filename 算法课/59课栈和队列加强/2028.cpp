#include <bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin>>s;
    stack<int> st;
    int i = 0;
    int n = s.size();
    while(i<n)
    {
        if(isdigit(s[i]))
        {
            string temp;
            while(i<n&&isdigit(s[i]))
            {
                temp.push_back(s[i]);
                i++;
            }
            if(i<n&&s[i]=='.')
            {
                i++;
            }
            int num = stoi(temp);
            st.push(num);
            
        }else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            /* if (stack.size() < 2) {
                cerr << "Error: Not enough operands." << endl;
                return 1;
            } */
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = 0;
            if (s[i] == '+') {
                result = a + b;
            } else if (s[i] == '-') {
                result = a - b;
            } else if (s[i] == '*') {
                result = a * b;
            } else if (s[i] == '/') {
                /* if (b == 0) {
                    cerr << "Error: Division by zero." << endl;
                    return 1;
                } */
                result = a / b; // Integer division towards zero
            }
            st.push(result);
            i++;
        } else if (s[i] == '@') {
            break;
        /* } else {
            // Skip any other character (should not happen in valid input)
            i++;
        } */
    }

    /* if (stack.size() != 1) {
        cerr << "Error: Invalid expression." << endl;
        return 1;
    } */
    

        
    }
cout << st.top() << endl;
    return 0;
}



