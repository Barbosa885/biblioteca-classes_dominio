#include "../../../include/controladoras_h/Apresentacao/CtrlAprPgtos.h"

using namespace std;

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982

void CtrlAprPagamentos::executar(const Cpf& cpf) {
    int opcao;
    do {
        cout << "Selecione a operacao de pagamento:" << endl;
        cout << "1. Criar Pagamento" << endl;
        cout << "2. Ler Pagamento" << endl;
        cout << "3. Atualizar Pagamento" << endl;
        cout << "4. Excluir Pagamento" << endl;
        cout << "5. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                criarPagamento();
                break;
            case 2:
                lerPagamentos();
                break;
            case 3:
                atualizarPagamento();
                break;
            case 4:
                excluirPagamento();
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    } while (opcao != 5);
}

void CtrlAprPagamentos::criarPagamento() {
    CodigoPagamento codigo;
    Pagamento pagamento;
    Data data;
    Percentual percentual;
    Estado estado;

    cout << "Digite o código do pagamento: ";
    cin >> codigo;
    pagamento.setCodigoPagamento(codigo);

    cout << "Digite a data do pagamento: ";
    cin >> data;
    pagamento.setData(data);

    cout << "Digite o percentual do pagamento: ";
    cin >> percentual;
    pagamento.setPercentual(percentual);

    cout << "Digite o estado do pagamento: ";
    cin >> estado;
    pagamento.setEstado(estado);

    if (servicoPagamentos->criar(pagamento)) {
        cout << "Pagamento criado com sucesso!" << endl;
    } else {
        cout << "Erro ao criar pagamento." << endl;
    }
}

void CtrlAprPagamentos::lerPagamentos() {
    CodigoPagamento codigo;
    Pagamento pagamento;

    cout << "Digite o código do pagamento: ";
    cin >> codigo;
    pagamento.setCodigoPagamento(codigo);

    if (servicoPagamentos->ler(&pagamento)) {
        cout << "Código: " << pagamento.getCodigoPagamento() << endl;
        cout << "Data: " << pagamento.getData() << endl;
        cout << "Percentual: " << pagamento.getPercentual() << endl;
        cout << "Estado: " << pagamento.getEstado() << endl;
        cout << "Pagamento lido com sucesso!" << endl;
    } else {
        cout << "Erro ao ler pagamento." << endl;
    }
}

void CtrlAprPagamentos::atualizarPagamento() {
    CodigoPagamento codigo;
    Pagamento pagamento;
    Data data;
    Percentual percentual;
    Estado estado;

    cout << "Digite o código do pagamento: ";
    cin >> codigo;
    pagamento.setCodigoPagamento(codigo);

    cout << "Digite a nova data do pagamento: ";
    cin >> data;
    pagamento.setData(data);

    cout << "Digite o novo percentual do pagamento: ";
    cin >> percentual;
    pagamento.setPercentual(percentual);

    cout << "Digite o novo estado do pagamento: ";
    cin >> estado;
    pagamento.setEstado(estado);

    if (servicoPagamentos->atualizar(pagamento)) {
        cout << "Pagamento atualizado com sucesso!" << endl;
    } else {
        cout << "Erro ao atualizar pagamento." << endl;
    }
}

void CtrlAprPagamentos::excluirPagamento() {
    CodigoPagamento codigo;

    cout << "Digite o código do pagamento: ";
    cin >> codigo;

    if (servicoPagamentos->excluir(codigo)) {
        cout << "Pagamento excluído com sucesso!" << endl;
    } else {
        cout << "Erro ao excluir pagamento." << endl;
    }
}
