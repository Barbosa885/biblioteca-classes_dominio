#ifndef TU_PAGAMENTO_OAD_H
#define TU_PAGAMENTO_OAD_H

#include "../../persistencia_h/PagamentosOAD.h"

class TUPagamentoOAD {
private:
    PagamentoOAD* pagamentoOAD;
    int status;

    void setUp();
    void tearDown();

    void testarCriarPagamento();
    void testarLerPagamento();
    void testarAtualizarPagamento();
    void testarExcluirPagamento();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TU_PAGAMENTO_OAD_H
