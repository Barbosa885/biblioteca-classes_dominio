#ifndef TU_PAGAMENTO_H
#define TU_PAGAMENTO_H

#include "../../entidades_h/Pagamento.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUPagamento {
  private:
    const static string CODIGO_VALIDO;
    const static string DATA_VALIDA;
    const static float VALOR_VALIDO;
    const static string ESTADO_VALIDO;

    Pagamento *pagamento;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TU_PAGAMENTO_H
