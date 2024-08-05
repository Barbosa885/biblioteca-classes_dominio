#ifndef CTRLSERPAGAMENTOS_H_INCLUDED
#define CTRLSERPAGAMENTOS_H_INCLUDED

#include "../../interfaces_h/InterfacesServicos.h"
#include "../../persistencia_h/PagamentosOAD.h"

class CtrlSerPagamentos : public ISPagamentos {
public:
    CtrlSerPagamentos(PagamentoOAD* oad);
    ~CtrlSerPagamentos();
    bool criar(const Pagamento& pagamento) override;
    bool ler(Pagamento* pagamento) override;
    bool atualizar(const Pagamento& pagamento) override;
    bool excluir(const CodigoPagamento& codigoPagamento) override;
private:
    PagamentoOAD* oad;
};

#endif // CTRLSERPAGAMENTOS_H_INCLUDED

