#include "../../include/controladoras_h/CtrlAprPgtos.h"
#include "../../include/dominios_h/CodigoPagamento.h"
#include "../../include/entidades_h/Pagamento.h"
#include <iostream>

using namespace std;

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982

void CtrlAprPagamentos::executar(const Cpf& cpf) {
    int opcao;
    cout << "Selecione a operacao de pagamento:" << endl;
    cout << "1. Criar Pagamento" << endl;
    cout << "2. Ler Pagamento" << endl;
    cout << "3. Atualizar Pagamento" << endl;
    cout << "4. Excluir Pagamento" << endl;
    cout << "5. Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    CodigoPagamento codigoPagamento;
    Pagamento pagamento;
    Data dataPagamento;
    Percentual percentualPagamento;
    Estado estadoPagamento;

    switch (opcao) {
        case 1:
            // Criação de pagamento
            cout << "Digite o código do pagamento: ";
            cin >> codigoPagamento;
            pagamento.setCodigoPagamento(codigoPagamento);

            cout << "Digite a data do pagamento: ";
            cin >> dataPagamento;
            pagamento.setData(dataPagamento);

            cout << "Digite o percentual do pagamento: ";
            cin >> percentualPagamento;
            pagamento.setPercentual(percentualPagamento);

            cout << "Digite o estado do pagamento: ";
            cin >> estadoPagamento;
            pagamento.setEstado(estadoPagamento);

            if (servicoPagamentos->criar(pagamento)) {
                cout << "Pagamento criado com sucesso!" << endl;
            } else {
                cout << "Erro ao criar pagamento." << endl;
            }
            break;

        case 2:
            // Leitura de pagamento
            cout << "Digite o código do pagamento: ";
            cin >> codigoPagamento;
            pagamento.setCodigoPagamento(codigoPagamento);
            if (servicoPagamentos->ler(&pagamento)) {

                cout << "Código: " << pagamento.getCodigoPagamento() << endl;
                cout << "Data: " << pagamento.getData() << endl;
                cout << "Percentual: " << pagamento.getPercentual() << endl;
                cout << "Estado: " << pagamento.getEstado() << endl;

                cout << "Pagamento lido com sucesso!" << endl;

            } else {
                cout << "Erro ao ler pagamento." << endl;
            }
            break;

        case 3:
            // Atualização de pagamento
            cout << "Digite o código do pagamento: ";
            cin >> codigoPagamento;
            pagamento.setCodigoPagamento(codigoPagamento);

            cout << "Digite a data do pagamento: ";
            cin >> dataPagamento;
            pagamento.setData(dataPagamento);

            cout << "Digite o percentual do pagamento: ";
            cin >> percentualPagamento;
            pagamento.setPercentual(percentualPagamento);

            cout << "Digite o estado do pagamento: ";
            cin >> estadoPagamento;
            pagamento.setEstado(estadoPagamento);

            if (servicoPagamentos->atualizar(pagamento)) {
                cout << "Pagamento atualizado com sucesso!" << endl;
            } else {
                cout << "Erro ao atualizar pagamento." << endl;
            }
            break;

        case 4:
            // Exclusão de pagamento
            cout << "Digite o código do pagamento: ";
            cin >> codigoPagamento;
            if (servicoPagamentos->excluir(codigoPagamento)) {
                cout << "Pagamento excluído com sucesso!" << endl;
            } else {
                cout << "Erro ao excluir pagamento." << endl;
            }
            break;

        // verificar se isso aqui faz sentido
        case 5:
            break;

        default:
            cout << "Opcao invalida!" << endl;
            break;
    }
}

