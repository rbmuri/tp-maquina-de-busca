#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Indice {
    public:
        void indexar(string doc, string nome){
            int i;
            vector<string> doclista = separar(doc);
            for (i=0; i<doclista.size(); i++){
                indice_[doclista[i]].insert(nome); 
            }
        }
    
    private:
        vector<string> separar(string doc);
            //* codigo do lucas
        

        string normalizar(string palavra);
            //* codigo do lucas
        

        std::map<string, std::set<string>> indice_;
};