#ifndef TU_CTRLSER_TITULO_H
#define TU_CTRLSER_TITULO_H

#include "../../controladoras_h/Servicos/CtrlSerPgtos.h"

class TUCtrlSerPagamento {
private:
    CtrlSerPagamentos* crtlSerPagamento;
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

#endif // TU_CTRLSER_TITULO_H
