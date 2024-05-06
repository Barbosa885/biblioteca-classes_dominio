#ifndef TU_CONTA_h
#define TU_CONTA_h

#include "../../entidades_h/Conta.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

class TUConta {
  private:
    const static string NOME_VALIDO;
    const static string CPF_VALIDO;
    const static string SENHA_VALIDA;

    Conta *conta;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TU_CONTA_h
