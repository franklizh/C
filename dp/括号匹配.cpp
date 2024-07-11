#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int minAddToMakeValid(const string &s) {
    stack<char> st;
    int addCount = 0;

    // Define matching pairs
    unordered_map<char, char> matching = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == matching[c]) {
                st.pop();
            } else {
                addCount++;
            }
        }
    }

    // Any remaining opening brackets need to be closed
    addCount += st.size();

    return addCount;
}

int main() {
    string s1 = "([])[]";
    string s2 = "([)]";
    string s3 = "(}(}";

    cout << "Input: " << s1 << " Output: " << minAddToMakeValid(s1) << endl;
    cout << "Input: " << s2 << " Output: " << minAddToMakeValid(s2) << endl;
    cout << "Input: " << s3 << " Output: " << minAddToMakeValid(s3) << endl;

    return 0;
}
