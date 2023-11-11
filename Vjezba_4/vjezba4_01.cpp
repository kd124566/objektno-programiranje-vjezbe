#include <iostream>


using namespace std;

void pojavljivanje(char s[], char pod[])
{
    int brojac = 0;
    int i = 0;
    int j = 0;
    while(s[i] != '\0')
    {
        if(s[i] == pod[j])
        {
           j++;
        }
        if(pod[j] == '\0')
        {
            brojac +=1;
            j = 0;
        }
        if(s[i] == '\0' && pod[j] == '\0')
        {
            break;
        }
        i++;
    }
    cout << brojac;

}
int main()
{
    char s[] = "kokosi";
    char pod[] = "ko";
    pojavljivanje(s, pod);
    return 0;
}
