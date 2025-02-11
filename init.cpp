#include <iostream>
#include <algorithm>
#include <string.h>

#define uint unsigned int
#define CHAR_START 65
#define TORED(str)("\033[31m"+str+"\033[0m")
char CHARSET[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

using namespace std;

string decode(string str, int key = 3)
{
    string result = "";
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]==' ') continue;                                       // skip in case of a space
        if(str[i]>='0' && str[i]<='9'){ result += str[i]; continue; }   // skip in case of a number
        uint temp = (str.at(i)-CHAR_START)-key;
        temp < 0 ? temp+=strlen(CHARSET)+1 : 0;
        result += CHARSET[temp];
    }
    return result;
}

string encode(string str, int key = 3)
{
    string result = "";
    for(int i = 0; i<str.length(); ++i)
    {
        if(str[i]==' ') continue;                                       // skip in case of a space
        if(str[i]>='0' && str[i]<='9'){ result += str[i]; continue; }   // skip in case of a number
        uint temp = (str.at(i)-CHAR_START)+key;
        temp > strlen(CHARSET)+1 ? temp-=strlen(CHARSET)+1 : 0;
        result += CHARSET[temp];
    }
    return result;
}

int main(int argc, char** argv)
{
    string frase = ""; int key = 0;
    cout<<"Inserisci la frase\t: ";     getline(cin>>ws, frase);
    cout<<"Inserisci la chiave\t: ";    cin>>key;

    transform(frase.begin(), frase.end(), frase.begin(), ::toupper);
    cout<<"La frase cifrata è\t: "<<TORED(encode(frase,key))<<endl;
    cout<<"La frase decifrata è\t: "<<decode(encode(frase,key),key)<<endl;

    return 0;
}
