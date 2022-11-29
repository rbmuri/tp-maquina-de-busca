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

    filesystem::path dir;
    dir = "input";
    for (const auto& entry : filesystem::directory_iterator(dir)){
        index.indexar( filetostr(entry.path()), entry.path() );
    }  

    cout << "=-=-=-=- Digite sua consulta. -=-=-=-=\n";
    set<string> consulta = index.consulta();
    cout << "consulta concluída. resultados:\n\n";
    imprimirset(consulta);

    return 0;
}