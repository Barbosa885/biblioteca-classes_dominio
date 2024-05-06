#ifndef TU_SETOR_H
#define TU_SETOR_H

#include "../../dominios_h/Setor.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUSetor {
  private:
    const static string SETOR_VALIDO;
    const static string SETOR_INVALIDO;

    Setor *setor;
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

#endif // TU_SETOR_H
