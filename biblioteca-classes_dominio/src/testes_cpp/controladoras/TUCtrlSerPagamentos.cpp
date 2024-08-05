
#include "../../../include/controladoras_h/Servicos/CtrlSerPgtos.h"
#include <stdexcept>

// Construtor da classe CtrlSerPagamentos, inicializa o objeto de acesso a dados (OAD)
CtrlSerPagamentos::CtrlSerPagamentos(PagamentoOAD* oad) : oad(oad) {}

// Destrutor da classe CtrlSerPagamentos
CtrlSerPagamentos::~CtrlSerPagamentos() {
    delete oad; // Libera memória alocada para o OAD, caso tenha sido alocado dinamicamente
}

// Implementação do método para criar um novo pagamento
void CtrlSerPagamentos::criar(const Pagamento& pagamento) {
    try {
        oad->criarPagamento(pagamento); // Chama o método de criação de pagamento no OAD
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao criar pagamento: " + std::string(e.what()));
    }
}


// Implementação do método para listar todos os pagamentos
std::vector<Pagamento> CtrlSerPagamentos::lerPagamento() {
    try {
        return oad->lerPagamento(); // Chama o método de listagem de pagamentos no OAD
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao listar pagamentos: " + std::string(e.what()));
    }
}

// Implementação do método para atualizar um pagamento existente
void CtrlSerPagamentos::atualizar(const Pagamento& pagamento) {
    try {
        oad->atualizarPagamento(pagamento); // Chama o método de atualização de pagamento no OAD
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao atualizar pagamento: " + std::string(e.what()));
    }
}

// Implementação do método para excluir um pagamento pelo código
void CtrlSerPagamentos::excluir(const CodigoPagamento& codigo) {
    try {
        oad->excluirPagamento(codigo.getCodigoPagamento());
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao excluir pagamento: " + std::string(e.what()));
    }
}

