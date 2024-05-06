#ifndef TU_SENHA_H
#define TU_SENHA_H

#include "../../dominios_h/Senha.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUSenha {
  private:
    static const string SENHA_VALIDA;
    static const string SENHA_INVALIDA;
    
    Senha *senha;
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

#endif // TU_SENHA_H
