#include <iostream>
#include <algorithm>
#include <string.h>
#include "INCLUDE/debug.hpp"

#define CHAR_START 65
#define TORED(str)("\033[31m"+str+"\033[0m")
char CHARSET[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

bool DEBUG_FLAG = false;

using namespace std;

string decode(string str, int key = 3)
{
    string result = "";
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]==' ') continue;                                       // skip in case of a space
        if(str[i]>='0' && str[i]<='9'){ result += str[i]; continue; }   // skip in case of a number
        int temp = (str.at(i)-CHAR_START)-key;
        if (temp < 0) temp += strlen(CHARSET);
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
        int temp = (str.at(i)-CHAR_START)+key;
        if (temp >= strlen(CHARSET)) temp -= strlen(CHARSET);
        result += CHARSET[temp];
    }
    return result;
}

int main(int argc, char** argv)
{
    if(argc > 1 && strcmp(argv[1],"-d")==0)
        DEBUG_FLAG = true;
    debug_print("Debug mode enabled with args: ");
    string args_used = "";
    for (size_t i = 0; i < argc; i++)
        args_used += argv[i] + string(" ");
    debug_print(args_used);
    
    string frase = ""; int key = 0;
    cout<<"Inserisci la frase\t: ";     getline(cin>>ws, frase);
insert_key:
    cout<<"Inserisci la chiave\t: ";    cin>>key;
    if(key < 0 || key > strlen(CHARSET) || cin.fail())                      // check if the key is valid
    {
        cin.clear(); cin.ignore(10000, '\n');                               // clear the buffer
        cout<<"Chiave non valida, riprova"<<endl;
        goto insert_key;
    }

    transform(frase.begin(), frase.end(), frase.begin(), ::toupper);
    cout<<"La frase cifrata è\t: "<<TORED(encode(frase,key))<<endl;
    cout<<"La frase decifrata è\t: "<<decode(encode(frase,key),key)<<endl;

    return 0;
}
