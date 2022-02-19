#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include<string>
#include<stdio.h>
using namespace std;
char* _substr(char* str, int i, int len) {
    char* out, * ptr;
    int pos = 0;
    out = (char*)malloc(len + 1);
    ptr = out;
    str = str + i - 1;
    while (*str!='\0' && len > 0) {
        *ptr = *str;
        str++;
        len--;
        ptr++;
    }
    *ptr = '\0';
    return(out);
}
int _strlen(char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}
int main()
{
    system("chcp 1251");
    char str[255];
    int size,i=0,pos=0;
    cout<<"Enter string : ";
    gets_s(str);
    size =_strlen(str);
    cout<< "String length is "<<size<<endl;
    cout << "Enter position : ";
    cin >> pos;
  
        for (i =pos; i > 0;i--) {
            if (str[i] == ' ') {
                cout << _substr(str,1,i) << endl;
                cout <<_substr(str, i + 1, size -i) << endl; // get the rest of string
                break;
            }
            
        }

}


