// CtrlTitulo.cpp
#include "../../include/controladora_h/CtrlTitulo.h"
#include <iostream>

CtrlTitulo::CtrlTitulo(ServicoTitulo* servico) : servico(servico) {}

void CtrlTitulo::executar() {
    int opcao = 0;
    while (opcao != 6) {
        std::cout << "\nMenu de Gerenciamento de Títulos\n";
        std::cout << "1. Criar Título\n";
        std::cout << "2. Listar Títulos\n";
        std::cout << "3. Consultar Título\n";
        std::cout << "4. Atualizar Título\n";
        std::cout << "5. Excluir Título\n";
        std::cout << "6. Sair\n";
        std::cout << "Selecione uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                criarTitulo();
                break;
            case 2:
                listarTitulos();
                break;
            case 3:
                consultarTitulo();
                break;
            case 4:
                atualizarTitulo();
                break;
            case 5:
                excluirTitulo();
                break;
            case 6:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

void CtrlTitulo::criarTitulo() {
    std::string codigo, emissor, setor, dataEmissao, dataVencimento;
    float valor;

    std::cout << "Digite o código do título: ";
    std::cin >> codigo;
    std::cout << "Digite o nome do emissor: ";
    std::cin >> emissor;
    std::cout << "Digite o setor: ";
    std::cin >> setor;
    std::cout << "Digite a data de emissão (dd-mm-aaaa): ";
    std::cin >> dataEmissao;
    std::cout << "Digite a data de vencimento (dd-mm-aaaa): ";
    std::cin >> dataVencimento;
    std::cout << "Digite o valor do título: ";
    std::cin >> valor;

    Titulo novoTitulo;

    try {
        CodigoTitulo codTitulo;
        codTitulo.setCodigoTitulo(codigo);
        novoTitulo.setCodigoTitulo(codTitulo);

        Nome nomeEmissor;
        nomeEmissor.setNome(emissor);
        novoTitulo.setEmissor(nomeEmissor);

        Setor setorTitulo;
        setorTitulo.setSetor(setor);
        novoTitulo.setSetor(setorTitulo);

        Data emissao;
        emissao.setData(dataEmissao);
        novoTitulo.setEmissao(emissao);

        Data vencimento;
        vencimento.setData(dataVencimento);
        novoTitulo.setVencimento(vencimento);

        Dinheiro valorTitulo;
        valorTitulo.setValor(valor);
        novoTitulo.setValor(valorTitulo);

        servico->criarTitulo(novoTitulo);
        std::cout << "Título criado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar título: " << e.what() << '\n';
    }
}

void CtrlTitulo::listarTitulos() {
    try {
        std::vector<Titulo> titulos = servico->listarTitulos();
        std::cout << "Lista de Títulos:\n";
        for (const auto& titulo : titulos) {
            std::cout << "Código: " << titulo.getCodigoTitulo().getCodigoTitulo() << "\n";
            std::cout << "Emissor: " << titulo.getEmissor().getNome() << "\n";
            std::cout << "Setor: " << titulo.getSetor().getSetor() << "\n";
            std::cout << "Data de Emissão: " << titulo.getEmissao().getData() << "\n";
            std::cout << "Data de Vencimento: " << titulo.getVencimento().getData() << "\n";
            std::cout << "Valor: " << titulo.getValor().getValor() << "\n\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao listar títulos: " << e.what() << '\n';
    }
}

void CtrlTitulo::consultarTitulo() {
    std::string codigo;
    std::cout << "Digite o código do título a consultar: ";
    std::cin >> codigo;

    try {
        CodigoTitulo codTitulo;
        codTitulo.setCodigoTitulo(codigo);
        Titulo titulo = servico->obterTitulo(codTitulo);
        std::cout << "Código: " << titulo.getCodigoTitulo().getCodigoTitulo() << "\n";
        std::cout << "Emissor: " << titulo.getEmissor().getNome() << "\n";
        std::cout << "Setor: " << titulo.getSetor().getSetor() << "\n";
        std::cout << "Data de Emissão: " << titulo.getEmissao().getData() << "\n";
        std::cout << "Data de Vencimento: " << titulo.getVencimento().getData() << "\n";
        std::cout << "Valor: " << titulo.getValor().getValor() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao consultar título: " << e.what() << '\n';
    }
}

void CtrlTitulo::atualizarTitulo() {
    std::string codigo;
    std::cout << "Digite o código do título a atualizar: ";
    std::cin >> codigo;

    try {
        CodigoTitulo codTitulo;
        codTitulo.setCodigoTitulo(codigo);
        Titulo titulo = servico->obterTitulo(codTitulo);
        std::string emissor, setor, dataEmissao, dataVencimento;
        float valor;

        std::cout << "Digite o novo nome do emissor: ";
        std::cin >> emissor;
        std::cout << "Digite o novo setor: ";
        std::cin >> setor;
        std::cout << "Digite a nova data de emissão (dd-mm-aaaa): ";
        std::cin >> dataEmissao;
        std::cout << "Digite a nova data de vencimento (dd-mm-aaaa): ";
        std::cin >> dataVencimento;
        std::cout << "Digite o novo valor do título: ";
        std::cin >> valor;

        Nome nomeEmissor;
        nomeEmissor.setNome(emissor);
        titulo.setEmissor(nomeEmissor);

        Setor setorTitulo;
        setorTitulo.setSetor(setor);
        titulo.setSetor(setorTitulo);

        Data emissao;
        emissao.setData(dataEmissao);
        titulo.setEmissao(emissao);

        Data vencimento;
        vencimento.setData(dataVencimento);
        titulo.setVencimento(vencimento);

        Dinheiro valorTitulo;
        valorTitulo.setValor(valor);
        titulo.setValor(valorTitulo);

        servico->atualizarTitulo(titulo);
        std::cout << "Título atualizado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao atualizar título: " << e.what() << '\n';
    }
}

void CtrlTitulo::excluirTitulo() {
    std::string codigo;
    std::cout << "Digite o código do título a excluir: ";
    std::cin >> codigo;

    try {
        CodigoTitulo codTitulo;
        codTitulo.setCodigoTitulo(codigo);
        servico->excluirTitulo(codTitulo);
        std::cout << "Título excluído com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao excluir título: " << e.what() << '\n';
    }
}
