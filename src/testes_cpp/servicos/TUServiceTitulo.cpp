#include "../../../include/testes_h/servicos/TUServiceTitulo.h"
#include <iostream>
#include <cassert>

// Definições de constantes para os testes
const std::string CODIGO_VALIDO = "LCA3241AG84";
const std::string EMISSOR_VALIDO = "Davi";
const std::string SETOR_VALIDO = "Finanças";
const std::string EMISSAO_VALIDA = "12-12-2022";
const std::string VENCIMENTO_VALIDO = "12-12-2023";
const float VALOR_VALIDO = 100.0;

// Método para configurar o ambiente de teste
void TUServiceTitulo::setUp() {
    std::string caminhoBanco = "../../banco_de_dados.db"; // Caminho relativo para o banco de dados
    TituloOAD* tituloOAD = new TituloOAD(caminhoBanco); // Instância correta de TituloOAD com argumento
    servicoTitulo = new ServicoTitulo(tituloOAD); // Passando o ponteiro corretamente
    estado = SUCESSO;
}

// Método para limpar o ambiente de teste
void TUServiceTitulo::tearDown() {
    delete servicoTitulo;
}

// Método para testar a criação de um título
void TUServiceTitulo::testarCriarTitulo() {
    try {
        Titulo titulo;
        titulo.setCodigoTitulo(CodigoTitulo(CODIGO_VALIDO));
        titulo.setEmissor(Nome(EMISSOR_VALIDO));
        titulo.setSetor(Setor(SETOR_VALIDO));
        titulo.setEmissao(Data(EMISSAO_VALIDA));
        titulo.setVencimento(Data(VENCIMENTO_VALIDO));
        titulo.setValor(Dinheiro(VALOR_VALIDO));

        servicoTitulo->criarTitulo(titulo);
        std::cout << "Teste criarTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste criarTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

// Método para testar a obtenção de um título
void TUServiceTitulo::testarObterTitulo() {
    try {
        Titulo titulo = servicoTitulo->obterTitulo(CODIGO_VALIDO);
        assert(titulo.getCodigoTitulo().getCodigoTitulo() == CODIGO_VALIDO);
        assert(titulo.getEmissor().getNome() == EMISSOR_VALIDO);
        assert(titulo.getSetor().getSetor() == SETOR_VALIDO);
        assert(titulo.getEmissao().getData() == EMISSAO_VALIDA);
        assert(titulo.getVencimento().getData() == VENCIMENTO_VALIDO);
        assert(titulo.getValor().getValor() == VALOR_VALIDO);
        std::cout << "Teste obterTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste obterTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

// Método para testar a atualização de um título
void TUServiceTitulo::testarAtualizarTitulo() {
    try {
        Titulo titulo = servicoTitulo->obterTitulo(CODIGO_VALIDO);
        titulo.setEmissor(Nome("Novo Emissor"));
        servicoTitulo->atualizarTitulo(titulo);

        Titulo tituloAtualizado = servicoTitulo->obterTitulo(CODIGO_VALIDO);
        assert(tituloAtualizado.getEmissor().getNome() == "Novo Emissor");
        std::cout << "Teste atualizarTitulo: SUCESSO" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Teste atualizarTitulo: FALHA - " << e.what() << std::endl;
        estado = FALHA;
    }
}

// Método para testar a exclusão de um título
void TUServiceTitulo::testarExcluirTitulo() {
    try {
        servicoTitulo->excluirTitulo(CODIGO_VALIDO);
        try {
            Titulo titulo = servicoTitulo->obterTitulo(CODIGO_VALIDO);
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

// Método principal para rodar todos os testes
int TUServiceTitulo::run() {
    setUp();
    testarCriarTitulo();
    testarObterTitulo();
    testarAtualizarTitulo();
    testarExcluirTitulo();
    tearDown();
    return estado;
}
