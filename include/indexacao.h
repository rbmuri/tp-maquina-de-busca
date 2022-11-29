#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
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

void imprimirset(set<string> docs){
    set<string>::iterator it;
    for (it = docs.begin(); it != docs.end(); it++){
        cout << *it << "\n";
    }
} 

class Indice {
    public:
        Indice(){
        }
        void indexar(vector<string> doclista, string nome){
            int i;
            for (i=0; i<doclista.size(); i++){
                indice_[normalizar(doclista[i])].insert(nome); 
            }
        }
        ~Indice(){
        }
    
        set<string> consulta(){
            string cons, each;
            getline (cin, cons);
        
            vector<string> vet = separar(cons);
            
            set<string> docs = indice_[vet[0]];
            
            for (int x = 0; x<vet.size(); x++){
                set<string> temp = indice_[vet[x]];
                docs = intersecao(docs, temp);               
            }
            return docs;
        }

    protected:

        set<string> intersecao(set<string> s1, set<string> s2){
            vector<string> s1s2;
            set<string> s1_s2;
            set_intersection(s1.begin(), s1.end(),
                             s2.begin(), s2.end(),
                             std::back_inserter(s1s2));
            for (int i=0; i<s1s2.size(); i++){
                s1_s2.insert(s1s2[i]);
            }
            return s1_s2;
        }  

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
                for (int i = 0; i < resultado.size(); i++){
                    resultado[i] = normalizar(resultado[i]);
                }
                return resultado;
        }
        //* Divide as palavras da string documento e as normaliza.
    
        string normalizar(string palavra){
            string resultado;
            string errado[79] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"
                , "J", "K", "L", "M", "N", "O", "P", "Q"
                , "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "ç", "Ç", "ñ"
                , "Ñ", "ÿ", "ý", "Ý", "Á", "À", "Â", "Ã", "Ä"
                , "Å", "å", "ä", "á", "à", "ã", "â", "É", "È", "Ê", "Ë", "é"
                , "è", "ê", "ë", "Í", "Ì", "Î", "Ï", "í", "ì"
                , "î", "ï", "Ó", "Ò", "Õ", "Ô", "Ö", "ó", "ò", "õ", "ô", "Ö"
                , "Ú", "Ù", "Û", "Ü", "ú", "ù", "û", "ü"
            };
            string certo[79] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"
                , "j", "k", "l", "m", "n", "o", "p", "q"
                , "r", "s", "t", "u", "v", "w", "x", "y", "z", "c", "c", "n"
                , "n", "y", "y", "y", "a", "a", "a", "a", "a"
                , "a", "a", "a", "a", "a", "a", "a", "e", "e", "e", "e", "e"
                , "e", "e", "e", "i", "i", "i", "i", "i", "i"
                , "i", "i", "o", "o", "o", "o", "o", "o", "o", "o", "o", "o"
                , "u", "u", "u", "u", "u", "u", "u", "u"
            };
            for (int i = 0; i < 79; i++){
                while (true){
                    string::size_type achada = palavra.find(errado[i]);
                    if (achada != string::npos){
                        palavra.replace(achada, errado[i].length(), certo[i]);
                    }
                    else{
                        break;
                    }
                }
            }
            for(char x: palavra){
                if(x > 96 && x < 123){
                    resultado.push_back(x);
                }
            }
            return resultado;
        }
    //* Normaliza as palavras.
        map<string, set<string>> indice_;
};
