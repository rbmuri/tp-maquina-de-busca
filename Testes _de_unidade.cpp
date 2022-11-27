#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <indexacao.h>

int main(){
  
  TEST_CASE_CLASS(Indice){  
  //* Teste do método privado separar.
    vector<string> testando;
    SUBCASE("separar padrão 1"){
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
    SUBCASE("separar vazio"){
      string teste_02("");
      testando = separar(teste_02);
      CHECK(testando.size() == 0)
  }
    //* Testa o caso de string vazia para o método separar.
    SUBCASE("separar padrao 2"){
      string teste_03("Dé G.r.A.ç.ã aTê D.S.T.ê");
      testando = separar(teste_03);
      CHECK(testando.size() == 4);
      CHECK(testando[0] == "de");
      CHECK(testando[1] == "graca");
      CHECK(testando[2] == "ate");
      CHECK(testando[3] == "dste");
    }
    SUBCASE("separar padrão 3"){
      string teste_04("Os Trâbal-há-dôrè-s N.adã TEM -A- pÊR-dêr além d-e s.Ua.s ALGÉM..ÃS..");
      testando = separar(teste_03);
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
  }  
      
      
      
      
      
      
