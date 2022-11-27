#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Indice {
    public:
        Indice(){
        }
        void indexar(string doc, string nome){
            int i;
            vector<string> doclista = separar(doc);
            for (i=0; i<doclista.size(); i++){
                indice_[doclista[i]].insert(nome); 
            }
        }
    ~Indice(){
    }
    
    private:
        vector<string> separar(string doc){
            vector<string> resultado(0);
                resultado.push_back("");
                int i = 0;
                for(auto x: doc){
                    if(x == ' '){
                    resultado.push_back("");
                    i++;
                    }
                    else{
                        resultado[i].push_back(x);
                    }
                }
                return resultado;
        }
        //* Divide as palavras da String.

        string normalizar(string palavra);
            //* codigo do lucas
        

        map<string, set<string>> indice_;
};
