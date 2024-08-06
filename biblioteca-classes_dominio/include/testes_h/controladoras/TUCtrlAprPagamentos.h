#ifndef TUCTRL_APR_PAGAMENTOS_H_INCLUDED
#define TUCTRL_APR_PAGAMENTOS_H_INCLUDED

#include "../../controladoras_h/Apresentacao/CtrlAprPgtos.h"
#include "../../controladoras_h/Servicos/CtrlSerPgtos.h"
#include "../../entidades_h/Pagamento.h"
#include "../../dominios_h/CodigoPagamento.h"
#include "../../dominios_h/Data.h"
#include "../../dominios_h/Percentual.h"
#include "../../dominios_h/Estado.h"

class TUCtrlAprPagamento {
private:
    CtrlSerPagamentos* servicoPagamentos;
    int estado;

    static const std::string CODIGO_VALIDO;
    static const std::string DATA_VALIDA;
    static const float PERCENTUAL_VALIDO;
    static const std::string ESTADO_VALIDO;

public:
    static const int SUCESSO = 0;
    static const int FALHA = 1;

    void setUp();
    void tearDown();
    void testarCriarPagamento();
    void testarLerPagamento();
    void testarAtualizarPagamento();
    void testarExcluirPagamento();
    int run();
};

#endif //TU_CTRLAPR_PAGAMENTO_H
