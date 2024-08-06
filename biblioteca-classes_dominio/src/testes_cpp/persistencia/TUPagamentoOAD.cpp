#include "../../../include/testes_h/persistencia/TUPagamentoOAD.h"
#include <iostream>
#include <cassert>

void TUPagamentoOAD::setUp() {
    pagamentoOAD = new PagamentoOAD("meu_banco.db");
    status = SUCESSO;
}

void TUPagamentoOAD::tearDown() {
    delete pagamentoOAD;
}

void TUPagamentoOAD::testarCriarPagamento() {
    try {
        Pagamento pagamento;
        pagamento.setCodigoPagamento(CodigoPagamento("12345678"));
        pagamento.setData(Data("20-05-2020"));
        pagamento.setPercentual(Percentual(40));
        pagamento.setEstado(Estado("Previsto"));

        pagamentoOAD->criarPagamento(pagamento);
        std::cout << "Teste criarPagamento: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Pagamento criarPagamento: FALHA - " << e.what() << std::endl;
        status = FALHA;
    }
}

void TUPagamentoOAD::testarLerPagamento() {
    try {
        Pagamento pagamento = pagamentoOAD->lerPagamento("12345678");
        assert(pagamento.getCodigoPagamento().getCodigo() == "12345678");
        assert(pagamento.getData().getData() == "20-05-2020");
        assert(pagamento.getPercentual().getPercentual() == 40);
        assert(pagamento.getEstado().getEstado() == "Previsto");
        std::cout << "Teste lerPagamento: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste lerPagamento: FALHA - " << e.what() << std::endl;
        status = FALHA;
    }
}

void TUPagamentoOAD::testarAtualizarPagamento() {
    try {
        Pagamento pagamento = pagamentoOAD->lerPagamento("12345678");
        pagamento.setData(Data("09-02-2021"));
        pagamentoOAD->atualizarPagamento(pagamento);

        Pagamento pagamentoAtualizado = pagamentoOAD->lerPagamento("12345678");
        assert(pagamentoAtualizado.getData().getData() == "09-02-2021");
        std::cout << "Teste atualizarPagamento: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste atualizarPagamento: FALHA - " << e.what() << std::endl;
        status = FALHA;
    }
}

void TUPagamentoOAD::testarExcluirPagamento() {
    try {
        pagamentoOAD->excluirPagamento("12345678");
        // Tentar obter o pagamento para garantir que ele foi excluído
        try {
            Pagamento pagamento = pagamentoOAD->lerPagamento("12345678");
            std::cerr << "Teste excluirPagamento: FALHA - Pagamento ainda existe" << std::endl;
            status = FALHA;
        } catch (const std::exception&) {
            std::cout << "Teste excluirPagamento: SUCESSO" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Teste excluirPagamento: FALHA - " << e.what() << std::endl;
        status = FALHA;
    }
}

int TUPagamentoOAD::run() {
    try {
        setUp();
        std::cout << "Conexão com o banco de dados estabelecida com sucesso." << std::endl; // Mensagem de sucesso na conexão
        testarCriarPagamento();
        testarLerPagamento();
        testarAtualizarPagamento();
        testarExcluirPagamento();
    } catch (const std::exception& e) {
        std::cerr << "Erro durante a execução dos testes: " << e.what() << std::endl;
        status = FALHA;
    }
    tearDown();
    return status;
}
