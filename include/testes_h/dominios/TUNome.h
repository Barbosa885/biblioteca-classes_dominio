#ifndef TU_NOME_H
#define TU_NOME_H

#include "../../dominios_h/Nome.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUNome {
  private:
    const static string NOME_VALIDO;
    const static string NOME_INVALIDO;

    Nome *nome;
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

#endif // TU_NOME_H
