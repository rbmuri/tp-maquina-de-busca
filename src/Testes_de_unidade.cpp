#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <indexacao.h>
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
vector<string> separar(string doc)
{
    vector<string> resultado(0);
    resultado.push_back("");
    int i = 0;
    for (auto x : doc)
    {
        if (x == ' ')
        {
            resultado.push_back("");
            i++;
        }
        else
        {
            resultado[i].push_back(x);
        }
    }
    for (int i = 0; i < resultado.size(); i++)
    {
        resultado[i] = normalizar(resultado[i]);
    }
    return resultado;
}
//* Divide as palavras da String(doc) e as normaliza.

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
}
