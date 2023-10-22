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
  cout << "Testando cenário de sucesso" << endl;
  try{
    coluna->setColuna(COLUNA_VALIDA);
    if (coluna->getColuna() != COLUNA_VALIDA)
    {
      cout << "Coluna inválida" << endl;
      estado = FALHA;
    }
    else 
    {
      cout << "Coluna válida" << endl;
    }
  }
  catch(invalid_argument &excecao){
    {
      cout << "Coluna inválida" << endl;
      estado = FALHA;
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
  cout << "Testando cenário de falha" << endl;
  try{
    coluna->setColuna(COLUNA_INVALIDA);
    estado = FALHA;
  }
  catch(invalid_argument &e){
    if (coluna->getColuna() == COLUNA_INVALIDA)
    {
      estado = FALHA;
      cout << "Coluna inválida" << endl;
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
