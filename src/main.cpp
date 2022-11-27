#include <iostream>
#include <indexacao.h>
#include <filesystem>
#include <fstream>

using namespace std;

//* turns a file to a vector of strings
vector<string> filetostr(string dir){
    vector<string> sfile;
    string word;
    fstream file;
    file.open(dir);

    while (file.good()) {
        file >> word;
        sfile.push_back(word);
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

/*
    for (directory_entry& entry : directory_iterator("./input")){
    vector<string> sfile = filetostr(entry.path());
    index.indexar(sfile, entry.path())
    }  
*/

    for (directory_entry& entry : directory_iterator("./input")){
        cout << entry.path();
    }  
    
    

    /*index.indexar(file, nome);*/

    return 0;
}