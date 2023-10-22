/**
 * @file TUColuna.cpp
 *
 * Autor: Hideki Tomiyama (190014351)
 *
 * @brief Configura o ambiente de teste.
 *
 * Esta função é responsável por configurar o ambiente de teste.
 * Ela inicializa a coluna e define o estado para SUCESSO.
 */

#include <iostream>
#include "../../include/testes_h/TUColuna.h"
#include "../../include/dominios_h/Coluna.h"

TUColuna::TUColuna()
{
  //ctor
}

TUColuna::~TUColuna()
{
  //dtor
}

using namespace std;

const string TUColuna::COLUNAS_VALIDAS[] = {
  "SOLICITADO",
  "EM EXECUCAO",
  "CONCLUIDO"
};

const string TUColuna::COLUNAS_INVALIDAS[] = {
  "SOLICITADOOOO",
  "EM EXECUCAOOOO",
  "CONCLUIDOOOO"
};

void TUColuna::setUp()
{
  coluna = new Coluna();
  estado = SUCESSO;
}

/**
 * @brief Limpa o ambiente de teste.
 *
 * Esta função é responsável por limpar o ambiente de teste.
 * Ela deleta a coluna.
 */
void TUColuna::tearDown()
{
  delete coluna;
}

/**
 * @brief Testa o cenário de sucesso.
 *
 * Esta função é responsável por testar o cenário de sucesso.
 * Ela tenta definir a coluna para um valor válido e verifica se a coluna foi definida corretamente.
 */
void TUColuna::testarCenarioSucesso()
{
  cout << "COLUNA" << endl;
  cout << "Testando cenário de sucesso" << endl;
  for(const string& colunaValida : COLUNAS_VALIDAS)
  {
    cout << "Testando coluna: " << colunaValida << endl;
    try{
      coluna->setColuna(colunaValida);
      if (coluna->getColuna() != colunaValida)
      {
        cout << "Coluna inválida" << endl;
        estado = FALHA;
      }
      else 
      {
        cout << "Coluna válida: " << colunaValida << endl;
        estado = SUCESSO;
      }
    }
    catch(invalid_argument &excecao){
      {
        cout << "Coluna inválida" << endl;
        estado = FALHA;
      }
    }
  }
}

/**
 * @brief Testa o cenário de falha.
 *
 * Esta função é responsável por testar o cenário de falha.
 * Ela tenta definir a coluna para um valor inválido e verifica se uma exceção foi lançada.
 */
void TUColuna::testarCenarioFalha()
{
  cout << "Testando cenário de falha..." << endl;
  for(const string& colunaInvalida : COLUNAS_INVALIDAS)
  {
    cout << "Testando coluna: " << colunaInvalida << endl;
    try{
      coluna->setColuna(colunaInvalida);
      estado = FALHA;
    }
    catch(invalid_argument &e){
      {
        cout << "Exceção lançada: " << e.what() << endl;
        estado = FALHA;
      }
    }
  }
}

/**
 * @brief Executa os testes.
 *
 * Esta função é responsável por executar os testes.
 * Ela chama as funções SetUp, TestarCenarioSucesso, TestarCenarioFalha e TearDown na ordem.
 *
 * @return Retorna o estado do teste.
 */
void TUColuna::run()
{
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
}
