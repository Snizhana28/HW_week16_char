#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int WordCount(char* str, char* str2);
int numberOFsentences(char* str);
int PointComma(char* str);
void ReverseText(char* str);
void ReverseSentences(char* str);

int main()
{
  
    char* str = new char[65] {"Ukraine is an independent state.The capital is the city of Kyiv."};
    cout << str << endl << endl;;
    char word[25];
    char* ptr = word;
    cout << "Enter a word --> ";
    gets_s(word);
    cout << "result --> " << WordCount(str, word) << endl;
    cout << "result --> " << numberOFsentences(str) << endl;
    cout << "result --> " << PointComma(str) << endl;
    cout << "result --> ";   ReverseText(str);
    cout << "\nresult --> "; ReverseSentences(str);
    cout << endl << endl;
   
    delete[] str;
    return 0;
}


int WordCount(char* str1, char* str2)
{
    int count = 0;
    char* pos = strchr(str1, str2[0]);
    do
    {
        if (!strncmp(&pos[0], str2, strlen(str2)))
            count++;
        pos = strchr(&str1 [strlen(str1) - strlen(pos) + 1], str2[0]);
    } while (pos);
    return count;
}
int numberOFsentences(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
            count++;
    return count;
}
int PointComma(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '.' || str[i] == ',')
            count++;
    return count;
}
void ReverseText(char *str)
{
    int n = strlen(str); 
    char* s1 = new char[n];
    for (size_t i = 0; i < n; i++)
        s1[i] = str[strlen(str) - i - 1];
    s1[n] = '\0';
    cout << s1;
}
void ReverseSentences(char* str)
{
    for (char* s = strtok(str, ".!?"); s;
        s = strtok(NULL, ".!?"))
    {
        for (char* b = s + strlen(s) - 1, *a = s; a < b; ++a, --b)
        {
            char temp = *a; 
            *a = *b; 
            *b = temp;
        }
        cout << s << " ";
    }
}


