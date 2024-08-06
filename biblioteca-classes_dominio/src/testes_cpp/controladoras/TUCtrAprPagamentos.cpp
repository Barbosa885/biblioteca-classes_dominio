#include "../../../include/testes_h/controladoras/TUCtrlAprPagamentos.h"
#include <iostream>
#include <cassert>

// Inicialização das constantes estáticas
const std::string TUCtrlAprPagamento::CODIGO_VALIDO = "ABC123";
const std::string TUCtrlAprPagamento::DATA_VALIDA = "01-01-2023";
const float TUCtrlAprPagamento::PERCENTUAL_VALIDO = 0.1f;
const std::string TUCtrlAprPagamento::ESTADO_VALIDO = "Pago";

void TUCtrlAprPagamento::setUp() {
    std::string caminhoBanco = "../../banco_de_dados.db";
    PagamentoOAD* pagamentoOAD = new PagamentoOAD(caminhoBanco);
    servicoPagamentos = new CtrlSerPagamentos(pagamentoOAD);
    estado = SUCESSO;
}

void TUCtrlAprPagamento::tearDown() {
    delete servicoPagamentos;
}

void TUCtrlAprPagamento::testarCriarPagamento() {
    try {
        Pagamento pagamento;
        pagamento.setCodigoPagamento(CodigoPagamento(CODIGO_VALIDO));
        pagamento.setData(Data(DATA_VALIDA));
        pagamento.setPercentual(Percentual(PERCENTUAL_VALIDO));
        pagamento.setEstado(Estado(ESTADO_VALIDO));

        bool resultado = servicoPagamentos->criar(pagamento);
        assert(resultado == true);
        std::cout << "Teste criarPagamento: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste criarPagamento: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUCtrlAprPagamento::testarLerPagamento() {
    try {
        Pagamento pagamento;
        pagamento.setCodigoPagamento(CodigoPagamento(CODIGO_VALIDO));

        bool resultado = servicoPagamentos->ler(&pagamento);
        assert(resultado == true);
        assert(pagamento.getCodigoPagamento().getCodigo() == CODIGO_VALIDO);
        assert(pagamento.getData().getData() == DATA_VALIDA);
        assert(pagamento.getPercentual().getPercentual() == PERCENTUAL_VALIDO);
        assert(pagamento.getEstado().getEstado() == ESTADO_VALIDO);
        std::cout << "Teste lerPagamento: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste lerPagamento: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUCtrlAprPagamento::testarAtualizarPagamento() {
    try {
        Pagamento pagamento;
        pagamento.setCodigoPagamento(CodigoPagamento(CODIGO_VALIDO));
        servicoPagamentos->ler(&pagamento);
        pagamento.setPercentual(Percentual(0.15f));

        bool resultado = servicoPagamentos->atualizar(pagamento);
        assert(resultado == true);

        Pagamento pagamentoAtualizado;
        pagamentoAtualizado.setCodigoPagamento(CodigoPagamento(CODIGO_VALIDO));
        servicoPagamentos->ler(&pagamentoAtualizado);
        assert(pagamentoAtualizado.getPercentual().getPercentual() == 0.15f);
        std::cout << "Teste atualizarPagamento: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste atualizarPagamento: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUCtrlAprPagamento::testarExcluirPagamento() {
    try {
        bool resultado = servicoPagamentos->excluir(CodigoPagamento(CODIGO_VALIDO));
        assert(resultado == true);

        Pagamento pagamento;
        pagamento.setCodigoPagamento(CodigoPagamento(CODIGO_VALIDO));
        bool leituraResultado = servicoPagamentos->ler(&pagamento);
        if (leituraResultado) {
            std::cerr << "Teste excluirPagamento: FALHA - Pagamento ainda existe" << std::endl;
            estado = FALHA;
        } else {
            std::cout << "Teste excluirPagamento: SUCESSO" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Teste excluirPagamento: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

int TUCtrlAprPagamento::run() {
    setUp();
    testarCriarPagamento();
    testarLerPagamento();
    testarAtualizarPagamento();
    testarExcluirPagamento();
    tearDown();
    return estado;
}
