#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<int> v(n);
    stack<double> s;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            s.push(v[str[i] - 'A']);

        else {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();
            
            if (str[i] == '+')
                s.push(operand1 + operand2);
            else if (str[i] == '-')
                s.push(operand1 - operand2);
            else if (str[i] == '*')
                s.push(operand1 * operand2);
            else if (str[i] == '/')
                s.push(operand1 / operand2);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << "\n";

    return 0;
}
