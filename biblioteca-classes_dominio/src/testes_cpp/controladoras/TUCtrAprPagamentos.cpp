// CtrlAprPagamentos.cpp
#include "../../../include/testes_h/controladoras/TUCtrlAprPagamentos.h"
#include <iostream>

CtrlAprPagamentos::CtrlAprPagamentos(CtrlSerPagamentos* servico) : servico(servico) {}

void CtrlAprPagamentos::executar() {
    int opcao = 0;
    while (opcao != 5) {
        std::cout << "\nMenu de Gerenciamento de Títulos\n";
        std::cout << "1. Criar Pagamento\n";
        std::cout << "2. Ler Pagamento\n";
        std::cout << "3. Atualizar Pagamento\n";
        std::cout << "4. Excluir Pagamento\n";
        std::cout << "5. Sair";
        std::cout << "Selecione uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                criarPagamento();
                break;
            case 2:
                lerPagamento();
                break;
            case 3:
                atualizarPagamento();
                break;
            case 4:
                excluirPagamento();
                break;
            case 5:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

void CtrlAprPagamentos::criarPagamento() {
    std::string codigo, data, estado;
    float percentual;

    std::cout << "Digite o código do pagamento: ";
    std::cin >> codigo;
    std::cout << "Digite a data (dd-mm-aaaa) do pagamento: ";
    std::cin >> data;
    std::cout << "Digite o percentual: ";
    std::cin >> percentual;
    std::cout << "Digite o estado do pagamento: ";
    std::cin >> estado;

    Pagamento novoPagamento;

    try {
        CodigoPagamento codigo_pgto;
        codigo_pgto.setCodigoPagamento(codigo);
        novoPagamento.setCodigoPagamento(codigo_pgto);

        Data data_pgto;
        data_pgto.setData(data);
        novoPagamento.setData(data_pgto);

        Percentual percentual_pgto;
        percentual_pgto.setPagamento(percentual);
        novoPagamento.setPercentual(percentual_pgto);

        Estado estado_pgto;
        estado_pgto.setEstado(estado);
        novoPagamento.setEstado(estado_pgto);

        servico->criarPagamento(novoPagamento);
        std::cout << "Pagamento criado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar pagamento: " << e.what() << '\n';
    }
}

void CtrlAprPagamentos::lerPagamentos() {
    try {
        std::vector<Pagamento> pagamentos = servico->lerPagamentos();
        std::cout << "Lista de Pagamentos:\n";
        for (const auto& pagamento : pagamentos) {
            std::cout << "Código: " << pagamento.getCodigoPagamento().getCodigo() << "\n";
            std::cout << "Data: " << pagamento.getData().getData() << "\n";
            std::cout << "Percentual: " << pagamento.getPercentual().getPercentual() << "\n";
            std::cout << "Estado: " << pagamento.getEstado().getEstado() << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao listar pagamentos: " << e.what() << '\n';
    }
}


void CtrlAprPagamentos::atualizarPagamento() {
    std::string codigo;
    std::cout << "Digite o código do pagamento a atualizar: ";
    std::cin >> codigo;

    try {
        CodigoPagamento codigo_pgto;
        codigo_pgto.setCodigoPagamento(codigo);
        Pagamento pagamento = servico->obterPagamento(codigo_pgto);
        std::string data, estado;
        float percentual;

        std::cout << "Digite a nova data (dd-mm-aaaa): ";
        std::cin >> data;
        std::cout << "Digite o novo percentual: ";
        std::cin >> percentual;
        std::cout << "Digite o novo estado: ";
        std::cin >> estado;

        Data data_pgto;
        data_pgto.setData(data);
        pagamento.setData(data_pgto);

        Percentual percentual_pgto;
        percentual_pgto.setPercentual(percentual);
        pagamento.setPercentual(percentual_pgto);

        Estado estado_pgto;
        estado_pgto.setEstado(estado);
        pagamento.setEstado(estado_pgto);


        servico->atualizarPagamento(pagamento);
        std::cout << "Pagamento atualizado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao atualizar pagamento: " << e.what() << '\n';
    }
}

void CtrlAprPagamentos::excluirPagamento() {
    std::string codigo;
    std::cout << "Digite o código do pagamento a excluir: ";
    std::cin >> codigo;

    try {
        CodigoPagamento codigo_pgto;
        codigo_pgto.setCodigo(codigo);
        servico->excluirPagamento(codigo_pgto);
        std::cout << "Pagamento excluído com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao excluir pagamento: " << e.what() << '\n';
    }
}
