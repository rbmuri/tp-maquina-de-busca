#include <iostream>
#include <indexacao.h>
#include <filesystem>
#include <fstream>

using namespace std;

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
    cout << "=-=-=-=- Digite sua consulta. -=-=-=-=\n";
    set<string> consulta = index.consulta();
    cout << "consulta concluída.\n";
    imprimirset(consulta);
    
    

    /*index.indexar(file, nome);*/

    return 0;
}