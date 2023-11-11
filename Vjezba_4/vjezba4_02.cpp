#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

void s(string &str, int len)
{
    string novi;
    for(int i = 0; i < len; i++)
    {
         if (str[i] == ' ' && str[i + 1] == ',') {
            continue;
        }
        if (str[i] == ',' && str[i + 1] != ' ') {
            novi.push_back(',');
            novi.push_back(' ');
        } else {
            novi.push_back(str[i]);
        }
    }
    str = novi;
}
int main()
{
    string str = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.";
    int len = str.length();
    s(str,len);
    cout << str;
    return 0;
}
