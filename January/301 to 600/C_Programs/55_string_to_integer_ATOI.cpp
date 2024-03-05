#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    
    while (i < str.length() && str[i] == ' ')
    {
        i++;
    }

    
    if (i < str.length() && (str[i] == '+' || str[i] == '-'))
    {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    
    while (i < str.length() && isdigit(str[i]))
    {
        int digit = str[i] - '0';

        
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

int main()
{
    string str = "   -42";

    int result = myAtoi(str);

    cout << "Converted Integer: " << result << endl;

    return 0;
}
