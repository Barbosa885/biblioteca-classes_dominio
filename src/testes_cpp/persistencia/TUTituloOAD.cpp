#include "../../../include/testes_h/persistencia/TituloOADTest.h"
#include <iostream>
#include <cassert>

void TUTituloOAD::setUp() {
    tituloOAD = new TituloOAD("meu_banco.db");
    estado = SUCESSO;
}

void TUTituloOAD::tearDown() {
    delete tituloOAD;
}

void TUTituloOAD::testarCriarTitulo() {
    try {
        Titulo titulo;
        titulo.setCodigoTitulo(CodigoTitulo("ABC1234567"));
        titulo.setEmissor(Nome("Emissor Teste"));
        titulo.setSetor(Setor("Finanças"));
        titulo.setEmissao(Data("01-01-2024"));
        titulo.setVencimento(Data("01-01-2025"));
        titulo.setValor(Dinheiro(1000.0));

        tituloOAD->criarTitulo(titulo);
        std::cout << "Teste criarTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste criarTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUTituloOAD::testarObterTitulo() {
    try {
        Titulo titulo = tituloOAD->obterTitulo("ABC1234567");
        assert(titulo.getCodigoTitulo().getCodigoTitulo() == "ABC1234567");
        assert(titulo.getEmissor().getNome() == "Emissor Teste");
        assert(titulo.getSetor().getSetor() == "Finanças");
        assert(titulo.getEmissao().getData() == "01-01-2024");
        assert(titulo.getVencimento().getData() == "01-01-2025");
        assert(titulo.getValor().getValor() == 1000.0);
        std::cout << "Teste obterTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste obterTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUTituloOAD::testarAtualizarTitulo() {
    try {
        Titulo titulo = tituloOAD->obterTitulo("ABC1234567");
        titulo.setEmissor(Nome("Novo Emissor"));
        tituloOAD->atualizarTitulo(titulo);

        Titulo tituloAtualizado = tituloOAD->obterTitulo("ABC1234567");
        assert(tituloAtualizado.getEmissor().getNome() == "Novo Emissor");
        std::cout << "Teste atualizarTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste atualizarTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

void TUTituloOAD::testarExcluirTitulo() {
    try {
        tituloOAD->excluirTitulo("ABC1234567");
        // Tentar obter o título para garantir que ele foi excluído
        try {
            Titulo titulo = tituloOAD->obterTitulo("ABC1234567");
            std::cerr << "Teste excluirTitulo: FALHA - Título ainda existe" << std::endl;
            estado = FALHA;
        } catch (const std::exception&) {
            std::cout << "Teste excluirTitulo: SUCESSO" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Teste excluirTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

int TUTituloOAD::run() {
    try {
        setUp();
        std::cout << "Conexão com o banco de dados estabelecida com sucesso." << std::endl; // Mensagem de sucesso na conexão
        testarCriarTitulo();
        testarObterTitulo();
        testarAtualizarTitulo();
        testarExcluirTitulo();
    } catch (const std::exception& e) {
        std::cerr << "Erro durante a execução dos testes: " << e.what() << std::endl;
        estado = FALHA;
    }
    tearDown();
    return estado;
}
