#include <iostream>
#include <algorithm>
#include <string.h>
#include "INCLUDE/debug.hpp"
#include "INCLUDE/cesare.hpp"

extern char CHARSET[26];
bool DEBUG_FLAG = false;

using namespace std;

int main(int argc, char** argv)
{
    if(argc > 1 && strcmp(argv[1],"-d")==0)
        DEBUG_FLAG = true;
    debug_print("Debug mode enabled with args: ");
    string args_used = "";
    for (size_t i = 1; i < argc; i++)
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
    debug_print("Frase inserita: "+frase + "\nChiave inserita: " + to_string(key));

    transform(frase.begin(), frase.end(), frase.begin(), ::toupper);
    cout<<"La frase cifrata è\t: "<<TORED(encode(frase,key))<<endl;
    cout<<"La frase decifrata è\t: "<<decode(encode(frase,key),key)<<endl;

    return 0;
}
