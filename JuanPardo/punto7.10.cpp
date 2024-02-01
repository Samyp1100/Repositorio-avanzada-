#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string text, str, final_text;
    int count=0;
    cout<<"Digite una frase: ";
    getline(cin, text);
    // length of the text
    int len = text.length();
    cout<<"La longitud de la cadena es: "<<len<<endl;
    // hacer split del texto
  
    // ss contiene referencias a la cadena "text"  
    stringstream ss(text); 

    // Usamos un while para obtener cada palabra  
    // Referencia: https://favtutor.com/blogs/split-string-cpp
    while (getline(ss, str, ' ')) {
      if(str.length()==4){
        final_text += " **** ";
        count+=1;
      }else{
        final_text+= str+" ";
      }
    }
    cout<<"El número de palabras de 4 letras es: "<<count<<endl;
    cout<<"La frase final es: "<<final_text<<endl;
        
    return 0;
}