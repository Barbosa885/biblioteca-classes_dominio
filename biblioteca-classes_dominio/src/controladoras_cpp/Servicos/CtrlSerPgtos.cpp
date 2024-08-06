#include "../../../include/controladoras_h/Servicos/CtrlSerPgtos.h"
#include <stdexcept>

CtrlSerPagamentos::CtrlSerPagamentos(PagamentoOAD* oad) : oad(oad) {}

CtrlSerPagamentos::~CtrlSerPagamentos() {
    delete oad;
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

std::vector<Pagamento> CtrlSerPagamentos::lerPagamentos() {
    try {
        return oad->listarPagamentos(); // Correção aqui
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao listar pagamentos: " + std::string(e.what()));
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
