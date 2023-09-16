//  TASK #2
//  Abdul Aziz
//  BCSF19A026
//  Add/drop CS-Afternoon

#include <iostream>
#include <string>
#include <cmath>
#include "Stack.cpp"
using namespace std;
bool isBalanced(string);
string infixToPostfix(string);
int solOperator(int, int, char); // use in evaluation
int evaluate(string, bool);
int main()
{
    while (true)
    {
        cout << "\n\tSelect from the menu below\n";
        cout << "Press 1 for Checking isBalanced\n";
        cout << "Press 2 for infix to postfix Evaluation\n";
        cout << "Press 3 for infix evaluation to integer value\n";
        cout << "press 4 for postfix evaluation to integer value\n";
        cout << "Your Selection: ";
        char ch;
        cin.get(ch);
        while (ch < '1' || ch > '4')
        {
            cout << "ERROR!! Invalid Selection\nRe-enter in range of 1-4: ";
            cin.get(ch);
        }
        cin.ignore();
        string str;
        cout << endl;
        if (ch == '1')
        {
            cout << "Enter Expression to check for Balanced or Not\nExpression: ";
            getline(cin, str);
            if (isBalanced(str))
                cout << "Expression is Balanced\n";
            else
                cout << "Expression is Not Balanced\n";
        }
        else if (ch == '2')
        {
            // infixToPostfix Conversion
            cout << "Enter Expression to convert (infix to postfix)\nExpression: ";
            getline(cin, str);
            while (!isBalanced(str)) // Balance Checking of parenthesis
            {
                cout << "ERROR!! Invalid Expression\nPlease Re-enter a valid Expression: ";
                getline(cin, str);
            }
            str = infixToPostfix(str);
            cout << "\n********************************\n";
            cout << "Final Output Expression\n";
            cout << str << endl;
            cout << "********************************\n";
        }
        // Evaluation
        else if (ch == '3')
        {
            cout << "Enter an infix Expression (number|spaces|parenthesis|operator i.e (2 + 3) / 2 )\nExpression: ";
            getline(cin, str);
            while (!isBalanced(str)) // validation check for parenthesis
            {
                cout << "ERROR!! Invalid Expression\nPlease Re-enter a valid Expression: ";
                getline(cin, str);
            }
            int i = 0;
            while (str[i])
            {
                if (!(isspace(str[i]) || isdigit(str[i]) || str[i] == ',' || str[i] == '{' || str[i] == '(' || str[i] == '[' || str[i] == ')' || str[i] == '}' || str[i] == ']' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^'))
                {
                    cout << "ERROR!! Invalid Expression\nPlease Re-enter a valid Expression: ";
                    getline(cin, str);
                    i = 0;
                }
                i++;
            }
            cout << "************************************\n";
            cout << "\tAfter Evaluation\n";
            cout << "Result: " << evaluate(str, 0) << endl;
            cout << "************************************\n";
        }
        else
        {
            cout << "Enter an postfix Expression (numbers|spaces|operators i.e 2 3+)\nExpression: ";
            getline(cin, str);
            int i = 0;
            while (str[i])
            {
                if (!(isspace(str[i]) || isdigit(str[i]) || str[i] == ',' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^'))
                {
                    cout << "ERROR!! Invalid Expression\nPlease Re-enter a valid Expression: ";
                    getline(cin, str);
                    i = 0;
                }
                i++;
            }
            cout << "************************************\n";
            cout << "\tAfter Evaluation\n";
            cout << "Result: " << evaluate(str, 1) << endl;
            cout << "************************************\n";
        }
        cout << "\nPress Q to exit OR any key to check again for another input...";
        cin.get(ch);
        if (toupper(ch) == 'Q')
            exit(0);
        cin.ignore();
        cout << endl
             << endl;
    }

    return 0;
}
bool isBalanced(string expression)
{
    Stack<char> arr;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            arr.push(expression[i]);
        else if (expression[i] == ')')
        {
            if (arr.isEmpty() || arr.pop() != '(')
                return false;
        }
        else if (expression[i] == '}')
        {
            if (arr.isEmpty() || arr.pop() != '{')
                return false;
        }
        else if (expression[i] == ']')
        {
            if (arr.isEmpty() || arr.pop() != '[')
                return false;
        }
    }
    if (!arr.isEmpty())
        return false;
    return true;
}
string infixToPostfix(string expression)
{
    string str = expression;
    cout << endl;
    string result = "";
    int i = 0;
    Stack<char> stack;
    while (str[i])
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            stack.push(str[i]);
        else if (str[i] == '+' || str[i] == '-')
        {
            while (!stack.isEmpty() && stack.stackTop() != '(' && stack.stackTop() != '{' && stack.stackTop() != '[')
                result += stack.pop();
            stack.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            while (!(stack.stackTop() == '(' || stack.stackTop() == '{' || stack.stackTop() == '['))
                result += stack.pop();
            stack.pop();
        }
        else if (str[i] == '^')
        {

            if (!stack.isEmpty() && stack.stackTop() == '^')
                result += stack.pop();
            stack.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
        {
            if (!stack.isEmpty())
            {
                if (stack.stackTop() == '^')
                    result += stack.pop();
                if (stack.stackTop() == '/' || stack.stackTop() == '*' || stack.stackTop() == '%')
                    result += stack.pop();
            }
            stack.push(str[i]);
        }
        else
        {
            if (isalnum(str[i]))
            {
                if (isalpha(str[i]))
                    result += str[i];
                else
                {
                    result += " ";
                    while (isdigit(str[i]))
                    {
                        result += str[i];
                        i++;
                    }
                    result += " ";
                    i--;
                }
                cout << result << "\n";
            }
        }
        i++;
    }
    while (!stack.isEmpty())
        result += stack.pop();
    cout << result << endl;
    return result;
}
int solOperator(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    case '%':
        return a % b;
    }
    cout << "Invalid String\n";
    exit(0);
}
int evaluate(string expression, bool key)
{
    string str = expression;
    if (!key)
    {
        int i = 0;
        Stack<int> opnd;
        Stack<char> optr;
        while (i < str.length())
        {
            if (isdigit(str[i]))
            {
                int num = 0;
                while (isdigit(str[i]))
                {
                    num = num * 10 + (str[i] - 48);
                    i++;
                }
                opnd.push(num);
            }
            else if (isspace(str[i]) || str[i] == ',')
            {
                i++;
            }
            else if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                optr.push(str[i]);
                i++;
            }
            else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
            {
                while (optr.stackTop() != '(' && optr.stackTop() != '{' && optr.stackTop() != '[')
                {
                    char c = optr.pop();
                    int b = opnd.pop();
                    int a = opnd.pop();
                    opnd.push(solOperator(a, b, c));
                }
                optr.pop();
                i++;
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!optr.isEmpty() && optr.stackTop() != '(' && optr.stackTop() != '{' && optr.stackTop() != '[')
                {
                    char c = optr.pop();
                    int b = opnd.pop();
                    int a = opnd.pop();
                    opnd.push(solOperator(a, b, c));
                }
                optr.push(str[i]);
                i++;
            }
            else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
            {
                while (!optr.isEmpty() && (optr.stackTop() == '^' || optr.stackTop() == '*' || optr.stackTop() == '/' || optr.stackTop() == '%'))
                {
                    char c = optr.pop();
                    int b = opnd.pop();
                    int a = opnd.pop();
                    opnd.push(solOperator(a, b, c));
                }
                optr.push(str[i]);
                i++;
            }
            else if (str[i] == '^')
            {
                if (!optr.isEmpty() && optr.stackTop() == '^')
                {
                    i++;
                    while (isspace(str[i]))
                        i++;
                    int a = 0;
                    while (isdigit(str[i]))
                        a = a * 10 + (str[i++] - 48);
                    char c = optr.pop();
                    int b = opnd.pop();
                    opnd.push(solOperator(a, b, c));
                    optr.push('^');
                }
                else
                {
                    optr.push('^');
                    i++;
                }
            }
            else
            {
                cout << "invalid String\n";
                exit(0);
            }
        }
        while (!optr.isEmpty())
        {
            char c = optr.pop();
            int b = opnd.pop();
            int a = opnd.pop();
            opnd.push(solOperator(a, b, c));
        }
        return opnd.pop();
    }
    else
    {
        Stack<int> st;
        int i = 0;
        while (i < str.length())
        {

            if (isdigit(str[i]))
            {
                int val = 0;
                while (isdigit(str[i]))
                {
                    val = val * 10 + str[i] - 48;
                    i++;
                }
                st.push(val);
                i--;
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
            {
                int a = 0, b = 0;
                if (!st.isEmpty())
                    a = st.pop();
                else
                {
                    cout << "Invalid Postfix Expression\n";
                    exit(0);
                }
                if (!st.isEmpty())
                    b = st.pop();
                else
                {
                    cout << "Invalid Postfix Expression\n";
                    exit(0);
                }
                if (str[i] == '^')
                    st.push(pow(b, a));
                else if (str[i] == '+')
                    st.push(b + a);
                else if (str[i] == '-')
                    st.push(b - a);
                else if (str[i] == '*')
                    st.push(b * a);
                else if (str[i] == '/')
                    st.push(b / a);
                else
                    st.push(b % a);
            }
            i++;
        }
        return st.pop();
    }
}