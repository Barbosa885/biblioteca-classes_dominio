#ifndef TU_CPF_H
#define TU_CPF_H

#include "../../dominios_h/Cpf.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUCpf {
  private:
    const static string CPF_VALIDO;
    const static string CPF_INVALIDO;

    Cpf *cpf;
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

#endif // TU_CPF_H
