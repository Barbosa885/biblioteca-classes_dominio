#include "../../../include/controladoras_h/Servicos/CtrlSerPgtos.h"

CtrlSerPagamentos::CtrlSerPagamentos(PagamentoOAD* oad) : oad(oad) {}

CtrlSerPagamentos::~CtrlSerPagamentos() {
    // Se for necessário, limpe os recursos
    delete oad; // Certifique-se de que oad foi alocado dinamicamente, caso contrário, não delete
}

bool CtrlSerPagamentos::criar(const Pagamento& pagamento) {
    try {
        oad->criarPagamento(pagamento);
        return true;
    } catch (...) {
        return false;
    }
}

bool CtrlSerPagamentos::ler(Pagamento* pagamento) {
    try {
        *pagamento = oad->lerPagamento(pagamento->getCodigoPagamento().getCodigo());
        return true;
    } catch (...) {
        return false;
    }
}

bool CtrlSerPagamentos::atualizar(const Pagamento& pagamento) {
    try {
        oad->atualizarPagamento(pagamento);
        return true;
    } catch (...) {
        return false;
    }
}

bool CtrlSerPagamentos::excluir(const CodigoPagamento& codigoPagamento) {
    try {
        oad->excluirPagamento(codigoPagamento.getCodigo());
        return true;
    } catch (...) {
        return false;
    }
}



