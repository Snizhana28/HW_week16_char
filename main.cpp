#include <iostream>
#include <cstring>
using namespace std;

int mystrlen(const char* str);
char* mystrcpy(char* str1, const char* str2); 
char* mystrcat(char* str1, const char* str2);
char* mystrchr(char* str, char s);
char* mystrstr(char* str1, char* str2);

int main()
{
	const char* str = "The four seasons of the year are beautiful and pleasant.";
	cout << str << "\nresult: " << mystrlen(str) << endl << endl;

	char str1[] = "Ukraine has a wonderful language and culture.";
	char* strPtr1 = str1;
	cout << strPtr1 << endl;
	const char* str2 = "I am proud that I am Ukrainian!";
	cout << str2 << endl;
	cout <<"result: " << mystrcpy(str1, str2) << endl;
	cout <<"result: " << mystrcat(str1, str2) << endl << endl;

	char str3[] = "Ukraine is my home!";
	char* strPtr3 = str3;
	char s = 's';
	cout << str3 << "\nresult: ";
	if (mystrchr(str3, s) == NULL)
		cout << ("Not Found!\n");
	else
		cout << ("Found!\n");

	char str_1[] = "Ukraine is an independent state.";
	char* strPtr_1 = str_1;
	char str_2[] = "The capital is the city of Kyiv.";
	char* strPtr_2 = str_2;
	cout << str_1 << str_2 << "\nresult: ";
	if (mystrstr(str_1, str_2) == NULL)
		cout << ("Not Found!\n");
	else
		cout << ("Found!\n");
	return 0;
}
int mystrlen(const char* str)
{
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}
char* mystrcpy(char* str1, const char* str2)
{
	char* ptr = str1;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return ptr;
}
char* mystrcat(char* str1, const char* str2)
{
	char* ptr = str1 + strlen(str1);
	while (*str2 != '\0')
	{
		*ptr++ = *str2++;
	}
	*ptr = '\0';
	return str1;

}
char* mystrchr(char* str, char s)
{
	while (*str)
	{
		if (*str == s)
			return str;
		else
			s++;
	}
	return NULL;
}
char* mystrstr(char* str1, char* str2)
{	
	int i = 0, n = 0;
	int lensize = strlen(str1), len = strlen(str2);
	for (i = 0; i < lensize - len; i++)
	{
		int j = 0;
		for (j = j + i; j < len + i; j++)
		{
			if (*(str1 + j) == *(str2 + n)) 
				n++;
			else
				break;
		}
		if (n == len)
		{
			return str1 - len;
		}
		else       
		{
			str2 -= n;
			n = 0;

		}
	}
	return NULL;
}


