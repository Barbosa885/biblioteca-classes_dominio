#ifndef TU_DINHEIRO_H
#define TU_DINHEIRO_H

#include "../../dominios_h/Dinheiro.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUDinheiro {
  private:
    const static float VALOR_VALIDO;
    const static float VALOR_INVALIDO;

    Dinheiro *dinheiro;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};


#endif // TU_DINHEIRO_H
