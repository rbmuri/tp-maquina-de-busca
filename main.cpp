#include <iostream>
#include <indexacao.h>
#include <filesystem>
#include <fstream>

using namespace std;


vector<string> filetostr(string dir){
    vector<string> sfile;
    string word;
    fstream file;
    file.open(dir);

    while (file.good()) {
        file >> word;
        sfile.insert(word);
    }  
    sfile.pop_back();
    return sfile;
}


int main()
{
    string nome;
    Indice index;
    nome = "README.txt";

    filetostr(nome);

    
    
    

    

    /*index.indexar(file, nome);*/

    return 0;
}