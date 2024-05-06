#ifndef TUPERCENTUAL_H
#define TUPERCENTUAL_H

#include "../../dominios_h/Percentual.h"
#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUPercentual {
  private:
    const static int PERCENTUAL_VALIDO;
    const static int PERCENTUAL_INVALIDO;

    Percentual *percentual;
    int estadoAtual;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TUPERCENTUAL_H
