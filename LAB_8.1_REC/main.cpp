#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 3)
        return 0;
    if (str[i + 2] != '\0')
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
            return 1 + Count(str, i + 3);
        else
            return Count(str, i + 1);
    }
    else
    {
        return 0;
    }
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 2] != '\0')
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        {
            *t++ = '!';
            *t++ = '!';
            return Change(dest, str, t, i + 3);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}


int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str, 0) << " groups of '***'" << endl;
    char* dest = new char[151];
    dest[0] = '\0';
    char* result = Change(dest, str, dest, 0);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << result << endl;
    delete[] dest;
    return 0;
}
