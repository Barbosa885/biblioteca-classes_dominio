/**
 * @file TULimite.cpp
 *
 * Autor: Hideki Tomiyama (190014351)
 *
 * @brief Configura o ambiente de teste.
 */

#include <iostream>
#include "../../include/testes_h/TULimite.h"
#include "../../include/dominios_h/Limite.h"

using namespace std;

TULimite::TULimite()
{
  // ctor
}

TULimite::~TULimite()
{
  // dtor
}

const int TULimite::LIMITES_VALIDOS[] = {
  5,
  10,
  15,
  20
};

const int TULimite::LIMITES_INVALIDOS[] = {
  1,
  3,
  4,
  30
};

void TULimite::setUp()
{
  limite = new Limite();
  estado = SUCESSO;
}

/** @brief Limpa o ambiente de teste, excluindo a instância LIMITE. */
void TULimite::tearDown()
{
  delete limite;
}

/** @brief Testa um cenário de sucesso em que o limite é definido como um limite válido. */
void TULimite::testarCenarioSucesso()
{
  cout << "LIMITE" << endl;
  cout << "Teste de sucesso do limite" << endl;
  for(const int limiteValido : LIMITES_VALIDOS)
  {
    cout << "Testando limite: " << limiteValido << endl;
    try{
      limite->setLimite(limiteValido);
      if(limite->getLimite() != limiteValido)
      {
        estado = FALHA;
      } else {
        cout << "Sucesso: " << limite->getLimite() << endl;
        estado = SUCESSO;
      }

    }
    catch(invalid_argument& e)
    {
      cout << "Exceção lançada: " << e.what() << endl;
      estado = FALHA;
    }
  }
}

/** @brief Testa um cenário de falha em que o limite é definido como um limite inválido. */
void TULimite::testarCenarioFalha()
{
  cout << "Testando cenário de falha..." << endl;
  for(const int limiteInvalido : LIMITES_INVALIDOS)
  {
    cout << "Testando limite: " << limiteInvalido << endl;
    try{
      limite->setLimite(limiteInvalido);
      estado = FALHA;
    }
    catch(invalid_argument& e)
    {
      cout << "Exceção lançada: " << e.what() << endl;
      estado = FALHA;
    }
  }
}

/**
 * @brief Executa os testes.
 *
 * Esta função é responsável por executar os testes.
 * Ela chama as funções setUp, testarCenarioSucesso, testarCenarioFalha e tearDown.
 *
 * @return Retorna o estado do teste (SUCESSO ou FALHA).
 */
void TULimite::run()
{
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
}
