//  TASK #3
//  Abdul Aziz
//  BCSF19A026 
//  Add/drop CS-Afternoon
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstring>
#include "Stack.cpp"
using namespace std;

// Description  (must read)
//  I split this task to 3 small parts
//  1st part to place count of each Element after it i.e if no count to place 1 after it.
//  2nd part to resolve the parenthesis and multiply it to the count of each element if any.
//  3rd part to remove the duplicate and sum the count.
//  so, i made 3 function for it

bool valid(string); // to check if formula Valid or not
string countingOfEachElement(string);
string resolveParenthesis(string);
string removeDuplicate(string);
int main()
{
    while (true)
    {
        string formula;
        cout << "Enter Chemical Formula must (Start with UPPERCASE letter OR '(' )\nFormula: ";
        getline(cin, formula);
        while (!valid(formula))
        {
            cout << "ERROR!! Invalid Formula\nRe-enter i.e MgSO4, KlMnO4(H2O(NaCl)2)10: ";
            getline(cin, formula);
        }
        formula = countingOfEachElement(formula);
        formula = resolveParenthesis(formula);
        formula = removeDuplicate(formula);
        cout << "\n************************************\n";
        cout << "OUTPUT: " << formula << endl;
        cout << "************************************\n";
        char ch;
        cout << "\nPress Q to exit OR any key to check for another input: ";
        cin.get(ch);
        if (toupper(ch) == 'Q')
            exit(0);
        cin.ignore();
        cout << endl
             << endl;
    }
    return 0;
}
bool valid(string str)
{
    Stack<char> st;
    int i = 0;
    while (str[i] == ' ')
        i++;
    if (!(isupper(str[i]) || str[i] == '('))
        return false;
    for (; i < str.size(); i++)
    {
        if (isupper(str[i]))
            if (!(isalnum(str[i + 1]) || str[i + 1] == ' ' || str[i + 1] == '\0' || str[i + 1] == '(' || str[i + 1] == ')'))
                return false;
        if (isdigit(str[i]))
            if (!(isupper(str[i + 1]) || isdigit(str[i + 1]) || str[i + 1] == ' ' || str[i + 1] == '\0' || str[i + 1] == '(' || str[i + 1] == ')'))
                return false;
        if (str[i] == '(')
        {
            if (!(isupper(str[i + 1]) || str[i + 1] == ' ' || str[i + 1] == '\0' || str[i + 1] == '(' || str[i + 1] == ')'))
                return false;
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (!(isupper(str[i + 1]) || isdigit(str[i + 1]) || str[i + 1] == ' ' || str[i + 1] == '\0' || str[i + 1] == '(' || str[i + 1] == ')'))
                return false;
            if (st.isEmpty() || st.pop() != '(')
                return false;
        }
    }
    if (!st.isEmpty())
        return false;
    return true;
}
string countingOfEachElement(string str)
{
    int i = 0;
    string result = "";
    // To place count after each element.
    while (str[i])
    {
        if (str[i] == '(' || str[i] == ')')
        {
            result += str[i];
            int j = i + 1;
            while (isdigit(str[j]))
                result += str[j++];
        }
        else if (isupper(str[i]))
        {
            result += str[i];
            int j = i + 1;
            while (islower(str[j]))
                result += str[j++];
            if (isdigit(str[j]))
            {
                while (isdigit(str[j]))
                    result += str[j++];
            }
            else
                result += '1';
        }
        i++;
    }
    return result;
}
string resolveParenthesis(string formula)
{
    Stack<char> s{};
    Stack<char> r{};
    int i = 0;
    // Now to resolve the parentheses and multiply
    // the each Element with
    // the Number
    while (formula[i])
    {
        auto a = formula[i];
        i++;
        if (a != ')')
            s.push(a);
        else
        {
            if (isdigit(formula[i]))
            {
                int mul = 0;
                while (isdigit(formula[i]))
                    mul = mul * 10 + (formula[i++] - 48);
                while (s.stackTop() != '(')
                {
                    int temp = 0;
                    if (isdigit(s.stackTop()))
                    {
                        while (isdigit(s.stackTop()))
                        {
                            temp = temp + mul * (s.pop() - 48);
                            r.push(temp % 10 + 48);
                            temp = temp / 10;
                        }
                        if (temp)
                            r.push(temp + 48);
                    }
                    else
                        r.push(s.pop());
                }
            }
            else
            {
                while (s.stackTop() != '(')
                    r.push(s.pop());
            }
            s.pop();
            while (!r.isEmpty())
                s.push(r.pop());
        }
    }
    // To collect The Result
    while (!s.isEmpty())
        r.push(s.pop());
    string result = "";
    while (!r.isEmpty())
        result += r.pop();
    return result;
}
string removeDuplicate(string result)
{
    string *arr = new string[result.length()]{};
    int i = 0;
    int j = 0;
    while (i < result.length())
    {
        if (isalpha(result[i]))
        {
            while (isalpha(result[i]))
                arr[j] += result[i++];
            j++;
        }
        else if (isdigit(result[i]))
        {
            while (isdigit(result[i]))
                arr[j] += result[i++];
            j++;
        }
        else
        {
            i++;
        }
    }
    int count = 0;
    string output = "";
    for (int i = 0; i < j; i = i + 2)
    {
        count = stoi(arr[i + 1]);
        for (int k = i + 2; k < j; k = k + 2)
        {
            if (arr[i] == arr[k])
            {
                count += stoi(arr[k + 1]);
                int l = k;
                while (l + 2 < j)
                {
                    arr[l] = arr[l + 2];
                    arr[l + 1] = arr[l + 3];
                    l = l + 2;
                }
                j = j - 2;
                k = i;
            }
        }
        output += arr[i];
        if (count > 1)
            output += to_string(count);
    }
    delete[] arr;
    arr = NULL;
    return output;
}