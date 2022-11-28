#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Indice {
    public:
        Indice(){
        }
        void indexar(vector<string> doclista, string nome){
            int i;
            for (i=0; i<doclista.size(); i++){
                indice_[doclista[i]].insert(nome); 
            }
        }
        ~Indice(){
        }
        
        set<string> consulta(){
            string cons;
            cin >> cons;
            vector<string> vet = separar(cons);
            set<string> palavras = vectoset( vet );
            set<string> docs = indice_[vet[0]];
            for (auto x : palavras){
                
                set<string> temp = indice_[x];
                docs = intersection(docs, temp);
            }
            return docs;
        }

    protected:

        set<string> intersection(set<string> v1, set<string> v2){
            set<string> v3;

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());

            set_intersection(v1.begin(),v1.end(),
                             v2.begin(),v2.end(),
                             back_inserter(v3));
            return v3;
        }   

        set<string> vectoset(vector<string> str){
            set<string> res;
            for (int i=0; i<str.size(); i++){
                res.insert(str[i]);
            }
        }    
/*
        set<string> separarSET(string doc){
            set<string> resultado;
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
        }*/

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
        //* Divide as palavras da String(doc) e as normaliza.
    
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
