#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <indexacao.h>
#include <filesystem>
#include <fstream>

set<string> intersecao(set<string> s1, set<string> s2)
{
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

string normalizar(string palavra)
{
    string resultado;
    string errado[79] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "ç", "Ç", "ñ", "Ñ", "ÿ", "ý", "Ý", "Á", "À", "Â", "Ã", "Ä", "Å", "å", "ä", "á", "à", "ã", "â", "É", "È", "Ê", "Ë", "é", "è", "ê", "ë", "Í", "Ì", "Î", "Ï", "í", "ì", "î", "ï", "Ó", "Ò", "Õ", "Ô", "Ö", "ó", "ò", "õ", "ô", "Ö", "Ú", "Ù", "Û", "Ü", "ú", "ù", "û", "ü"};
    string certo[79] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "c", "c", "n", "n", "y", "y", "y", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "e", "e", "e", "e", "e", "e", "e", "e", "i", "i", "i", "i", "i", "i", "i", "i", "o", "o", "o", "o", "o", "o", "o", "o", "o", "o", "u", "u", "u", "u", "u", "u", "u", "u"};
    for (int i = 0; i < 79; i++)
    {
        while (true)
        {
            string::size_type achada = palavra.find(errado[i]);
            if (achada != string::npos)
            {
                palavra.replace(achada, errado[i].length(), certo[i]);
            }
            else
            {
                break;
            }
        }
    }
    for (char x : palavra)
    {
        if (x > 96 && x < 123)
        {
            resultado.push_back(x);
        }
    }
    return resultado;
}
//* Normaliza as palavras.

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
//* Divide as palavras da string(que era um documento) e as normaliza.

TEST_CASE("separar")
{
    //* Teste do método privado separar.
    vector<string> testando;
    SUBCASE("separar padrão 1")
    {
        string teste_01("CADA MAMACO ÑO ÇEU GÁLHÓ");
        testando = separar(teste_01);
        CHECK(testando.size() == 5);
        CHECK(testando[0] == "cada");
        CHECK(testando[1] == "mamaco");
        CHECK(testando[2] == "no");
        CHECK(testando[3] == "ceu");
        CHECK(testando[4] == "galho");
    }
    //* Testa um caso padrão para o método separar.
    SUBCASE("separar vazio")
    {
        string teste_02("");
        testando = separar(teste_02);
        CHECK(testando.size() == 1);
        CHECK(testando[0] == "");
    }
    //* Testa o caso de string vazia para o método separar.
    SUBCASE("separar padrao 2")
    {
        string teste_03("Dé G.r.A.ç.ã aTê D.S.T.ê");
        testando = separar(teste_03);
        CHECK(testando.size() == 4);
        CHECK(testando[0] == "de");
        CHECK(testando[1] == "graca");
        CHECK(testando[2] == "ate");
        CHECK(testando[3] == "dste");
    }
    SUBCASE("separar padrão 3")
    {
        string teste_04("Os Trâbal-há-dôrè-s N.adã TEM -A- pÊR-dêr além d-e s.Ua.s ALGÉM..ÃS..");
        testando = separar(teste_04);
        CHECK(testando.size() == 10);
        CHECK(testando[0] == "os");
        CHECK(testando[1] == "trabalhadores");
        CHECK(testando[2] == "nada");
        CHECK(testando[3] == "tem");
        CHECK(testando[4] == "a");
        CHECK(testando[5] == "perder");
        CHECK(testando[6] == "alem");
        CHECK(testando[7] == "de");
        CHECK(testando[8] == "suas");
        CHECK(testando[9] == "algemas");
    }
    //* Testa mais 2 casos padrões para o método separar.
    SUBCASE("separar palavra única")
    {
        string teste_05("CÚ.-.Ìdâdõ");
        testando = separar(teste_05);
        CHECK(testando.size() == 1);
        CHECK(testando[0] == "cuidado");
    }
    //* Testa caso de palavra única do método separar.
}TEST_CASE("normalizar")
{
    //* Teste do método privado normalizar.
    string testar;
    SUBCASE("normalizar padrão 1")
    {
        string testeN_01("ÑÕS");
        testar = normalizar(testeN_01);
        CHECK(testar.size() == 3);
        CHECK(testar == "nos");
    }
    SUBCASE("normalizar padrão 2")
    {
        string testeN_02("D||--...--è");
        testar = normalizar(testeN_02);
        CHECK(testar.size() == 2);
        CHECK(testar == "de");
    }
    SUBCASE("normalizar padrão 3")
    {
        string testeN_03("ñ..Ö--T||â");
        testar = normalizar(testeN_03);
        CHECK(testar.size() == 4);
        CHECK(testar == "nota");
    }
    //* Testes de casos padrões do método provativo normalizar.
    SUBCASE("normalizar vazio")
    {
        string testeN_04("");
        testar = normalizar(testeN_04);
        CHECK(testar.size() == 0);
        CHECK(testar == "");
    }
    //* Teste do método privado normalizar para um caso de string vazia.
}
TEST_CASE("filetostr"){
    SUBCASE("filetostr padrão 1"){
        vector<string> testef_01(0);
        testef_01 = filetostr("input/CASOS_BOLOTA_TESTÃO.txt");
        CHECK(testef_01.size() == 9);
        CHECK(testef_01[0] == "A");
        CHECK(testef_01[1] == "bolota");
        CHECK(testef_01[2] == "do");
        CHECK(testef_01[3] == "esquilo");
        CHECK(testef_01[4] == "da");
        CHECK(testef_01[5] == "minha");
        CHECK(testef_01[6] == "casa");
        CHECK(testef_01[7] == "está");
        CHECK(testef_01[8] == "estragada.");
    }
    SUBCASE("filetostr padrão 2"){
        vector<string> testef_02(0);
        testef_02 = filetostr("input/CASOS_BOLOTA_TESTE.txt");
        CHECK(testef_02.size() == 9);
        CHECK(testef_02[0] == "A");
        CHECK(testef_02[1] == "bolota");
        CHECK(testef_02[2] == "do");
        CHECK(testef_02[3] == "esquilo");
        CHECK(testef_02[4] == "da");
        CHECK(testef_02[5] == "minha");
        CHECK(testef_02[6] == "casa");
        CHECK(testef_02[7] == "está");
        CHECK(testef_02[8] == "estragada.");
    }
    SUBCASE("filetostr padrão 3"){
        vector<string> testef_03(0);
        testef_03 = filetostr("input/CASOS_CHOCOLATE_TESTINHO.txt");
        CHECK(testef_03.size() == 9);
        CHECK(testef_03[0] == "A");
        CHECK(testef_03[1] == "bolota");
        CHECK(testef_03[2] == "do");
        CHECK(testef_03[3] == "esquilo");
        CHECK(testef_03[4] == "da");
        CHECK(testef_03[5] == "minha");
        CHECK(testef_03[6] == "casa");
        CHECK(testef_03[7] == "está");
        CHECK(testef_03[8] == "estragada.");
    }
    SUBCASE("filetostr vazio"){
        vector<string> testef_04(0);
        testef_04 = filetostr("input/CASOS_TESTE_VAZIO.txt");
        CHECK(testef_04.size() == 0);
    }
}
TEST_CASE("intersecao"){
    SUBCASE("intersecao padrão 1"){
        set<string> testeS01_01 = {"1", "2", "3", "colher", "batata", "recheada"};
        set<string> testeS01_02 = {"3", "4", "5", "colher", "trufa", "recheada"};
        set<string> testeS01_03 = intersecao(testeS01_01, testeS01_02);
        vector<string> checkS_01(0);
        CHECK(testeS01_03.size() == 3);
        for(auto it = testeS01_03.begin(); it != testeS01_03.end(); ++it){
            checkS_01.push_back(*(it));
        }
        CHECK(checkS_01.size() == 3);
        CHECK(checkS_01[0] == "3");
        CHECK(checkS_01[1] == "colher");
        CHECK(checkS_01[2] == "recheada");
    }
    SUBCASE("intersecao padrão 2"){
        set<string> testeS02_01 = {"1", "2", "3", "4", "5", "6"};
        set<string> testeS02_02 = {"3", "4", "5", "35", "44", "56"};
        set<string> testeS02_03 = intersecao(testeS02_01, testeS02_02);
        vector<string> checkS_02(0);
        CHECK(testeS02_03.size() == 3);
        for(auto it = testeS02_03.begin(); it != testeS02_03.end(); ++it){
            checkS_02.push_back(*(it));
        }
        CHECK(checkS_02.size() == 3);
        CHECK(checkS_02[0] == "3");
        CHECK(checkS_02[1] == "4");
        CHECK(checkS_02[2] == "5");
    }
    SUBCASE("intersecao padrão 3"){
        set<string> testeS03_01 = {".", "..", "...", "/", " ", ""};
        set<string> testeS03_02 = {".", "..", "....", "//", " ", ""};
        set<string> testeS03_03 = intersecao(testeS03_01, testeS03_02);
        vector<string> checkS_03(0);
        CHECK(testeS03_03.size() == 4);
        for(auto it = testeS03_03.begin(); it != testeS03_03.end(); ++it){
            checkS_03.push_back(*(it));
        }
        CHECK(checkS_03.size() == 4);
        CHECK(checkS_03[0] == "");
        CHECK(checkS_03[1] == " ");
        CHECK(checkS_03[2] == ".");
        CHECK(checkS_03[3] == "..");
    }
    SUBCASE("intersecao vazia"){
        set<string> testeS04_01 = {"1", "2", "6", "colher", "batata", "recheada"};
        set<string> testeS04_02 = {"3", "4", "5", "mulher", "trufa", "rechaçada"};
        set<string> testeS04_03 = intersecao(testeS04_01, testeS04_02);
        CHECK(testeS04_03.size() == 0);
    }
    SUBCASE("intersecao sets vazios"){
        set<string> testeS05_01 = {};
        set<string> testeS05_02 = {};
        set<string> testeS05_03 = intersecao(testeS05_01, testeS05_02);
        CHECK(testeS05_03.size() == 0);
    }
}