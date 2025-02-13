#include <iostream>
#define CHAR_START 65
char CHARSET[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
std::string decode(std::string str, int key = 3)
{
    std::string result = "";
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

std::string encode(std::string str, int key = 3)
{
    std::string result = "";
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