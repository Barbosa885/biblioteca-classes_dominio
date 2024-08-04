// CtrlTituloTest.cpp
#include "../../../include/testes_h/cotroladoras/TUCtrlTitulo.h"
#include <iostream>
#include <cassert>

// Definição das constantes para os testes
const std::string TUCtrlTitulo::CODIGO_VALIDO = "LCA3241AG84";
const std::string TUCtrlTitulo::EMISSOR_VALIDO = "Davi";
const std::string TUCtrlTitulo::SETOR_VALIDO = "Finanças";
const std::string TUCtrlTitulo::EMISSAO_VALIDA = "12-12-2022";
const std::string TUCtrlTitulo::VENCIMENTO_VALIDO = "12-12-2023";
const float TUCtrlTitulo::VALOR_VALIDO = 100.0;

void TUCtrlTitulo::setUp() {
    // Inicializando ServicoTitulo e CtrlTitulo
    TituloOAD* tituloOAD = new TituloOAD("path_to_db"); // Substitua "path_to_db" pelo caminho correto do banco de dados
    servicoTitulo = new ServicoTitulo(tituloOAD);
    ctrlTitulo = new CtrlTitulo(servicoTitulo);
    estado = SUCESSO;
}

void TUCtrlTitulo::tearDown() {
    delete ctrlTitulo;
    delete servicoTitulo;
}

void TUCtrlTitulo::testarCriarTitulo() {
    try {
        Titulo titulo;
        titulo.setCodigoTitulo(CodigoTitulo(CODIGO_VALIDO));
        titulo.setEmissor(Nome(EMISSOR_VALIDO));
        titulo.setSetor(Setor(SETOR_VALIDO));
        titulo.setEmissao(Data(EMISSAO_VALIDA));
        titulo.setVencimento(Data(VENCIMENTO_VALIDO));
        titulo.setValor(Dinheiro(VALOR_VALIDO));

        ctrlTitulo->criarTitulo(); // Método chamado sem parâmetros
        std::cout << "Teste criarTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste criarTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUCtrlTitulo::testarObterTitulo() {
    try {
        // A função `obterTitulo` precisa ser implementada ou ajustada na classe `CtrlTitulo`
        std::cerr << "Erro: Método `obterTitulo` não implementado." << std::endl;
        estado = FALHA;
    } catch (const std::exception& e) {
        std::cerr << "Teste obterTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUCtrlTitulo::testarAtualizarTitulo() {
    try {
        // A função `obterTitulo` precisa ser implementada ou ajustada na classe `CtrlTitulo`
        std::cerr << "Erro: Método `obterTitulo` não implementado." << std::endl;
        estado = FALHA;
    } catch (const std::exception& e) {
        std::cerr << "Teste atualizarTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUCtrlTitulo::testarExcluirTitulo() {
    try {
        // A função `excluirTitulo` precisa ser implementada ou ajustada na classe `CtrlTitulo`
        std::cerr << "Erro: Método `excluirTitulo` não implementado." << std::endl;
        estado = FALHA;
    } catch (const std::exception& e) {
        std::cerr << "Teste excluirTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

int TUCtrlTitulo::run() {
    setUp();
    testarCriarTitulo();
    testarObterTitulo();
    testarAtualizarTitulo();
    testarExcluirTitulo();
    tearDown();
    return estado;
}
