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

    

/*
    for (directory_entry& entry : directory_iterator("./input")){
    vector<string> sfile = filetostr(entry.path());
    index.indexar(sfile, entry.path())
    }  
*/
    filesystem::path dir;
    dir = "input";
    for (const auto& entry : filesystem::directory_iterator(dir)){
        index.indexar( filetostr(entry.path()), entry.path() );
    }  

    set<string> consulta = index.consulta();
    for (string const& docnome : consulta){
        cout << docnome << "\n"; 
    }
    
    

    /*index.indexar(file, nome);*/

    return 0;
}