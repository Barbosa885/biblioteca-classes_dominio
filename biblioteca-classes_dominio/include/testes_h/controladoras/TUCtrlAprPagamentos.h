#ifndef TU_CTRLAPR_PAGAMENTO_H
#define TU_CTRLAPR_PAGAMENTO_H
#include "../../controladoras_h/Apresentacao/CtrlAprPgtos.h"
#include "../../controladoras_h/Servicos/CtrlSerPgtos.h"

class TUCtrlAprPagamento {
private:
    CtrlAprPagamentos* ctrlAprPagamento;
    CtrlSerPagamentos* ctrlSerPagamento;
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

    // Membros estáticos devem ser declarados no header
    static const std::string CODIGO_VALIDO;
    static const std::string DATA_VALIDA;
    static const float PERCENTUAL_VALIDO;
    static const std::string ESTADO_VALIDO;

    int run();
};

#endif //TU_CTRLAPR_PAGAMENTO_H
