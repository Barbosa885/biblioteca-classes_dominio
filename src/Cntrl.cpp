#include "../include/controladoras_h/CntrlAContas.h"
#include "../include/controladoras_h/CntrlAAutenticacao.h"
#include "../include/controladoras_h/CntrlIU.h"
#include "../include/controladoras_h/CntrlSAutenticacao.h"
#include "../include/interfaces_h/servico/ISAutenticacao.h"
#include "../include/interfaces_h/servico/ISContas.h"
#include "../include/interfaces_h/apresentacao/IAAutenticacao.h"
#include "../include/interfaces_h/apresentacao/IAContas.h"
#include "../include/Containers.h"
#include "../include/entidades_h/Conta.h"


 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 #include <string>
 #include <random>
// ---------------------------------------------------------------------------------
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";

// Configura o gerador de números aleatórios para o código do titulo e pagamentos.
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(100000, 999999);

// Função para limpar o terminal tanto para windows e linux.
void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CntrlIU::interagirComUsuario() {
    while(true) {
        int opcao;
        cout << "Seja bem vindo ao sistema de Titulos/Pagamentos" << endl;
        cout << "Escolha uma opção abaixo:" << endl << endl;
        cout << "1. Autenticar" << endl;
        cout << "2. Criar nova conta" << endl;
        cout << "3. Sair" << endl;
        cout << "Sua opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                limparTerminal();
                Cpf cpf;
                bool autenticado = cntrlAAutenticacao->autenticar(&cpf);

                if (autenticado) {
                    limparTerminal();
                    cout << GREEN << "Autenticação realizada com sucesso para o cpf: " << RESET << cpf.getCpf() << endl;
                    cout << "Pressione Enter para continuar" << endl;
                    cin.ignore();
                    cin.get();

                    bool tela = true;

                    while(tela) {
                        limparTerminal();
                        cout << "Escolha qual serviço deseja: " << endl << endl;
                        cout << "1. Acessar Conta." << endl;
                        cout << "2. Acessar Investimentos" << endl;
                        cout << "3. Voltar para a tela inicial." << endl;
                        cout << "Sua opção: ";
                        cin >> opcao;

                        switch(opcao) {
                            case 1: {
                                try {
                                    if(cntrlIAConta->executar(cpf)) {
                                        // Se a conta foi excluída retorna ao menu principal
                                        tela = false;
                                    }
                                } catch(const invalid_argument) {
                                    cout << RED << "Erro ao executar conta!" << RESET;
                                    tela = false;
                                }
                                break;
                            }

                            case 3: {
                                tela = false;
                                limparTerminal();
                                break;
                            }

                            default: {
                                limparTerminal();
                                cout << RED << "Opção Inválida" << RESET << endl;
                                cout << "Pressione Enter para continuar" << endl;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                        }
                    }
                } else {
                    limparTerminal();
                    cout << RED << "Autenticação falhou. Tente novamente." << RESET << endl;
                }
                break;
            }

            case 2: {
                limparTerminal();
                cntrlIAConta->criar();
                break;
            }

            case 3: {
                return;
            }

            default: {
                limparTerminal();
                cout << RED << "Opção Inválida" << RESET << endl;
                cout << "Pressione Enter para continuar" << endl;
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
}


void CntrlIU::setCntrlAAutenticacao(IAAutenticacao *cntr) {
    this->cntrlAAutenticacao = cntr;
}

void CntrlIU::setCntrlIAConta(IAContas *cntr) {
    this->cntrlIAConta = cntr;
}

bool CntrlAAutenticacao::autenticar(Cpf *cpf) {
    Senha senha;
    string entrada;

    cout << "Autenticacao de usuario." << endl << endl;

    try {
        cout << "Digite o Cpf : ";
        cin >> entrada;
        cpf->setCpf(entrada);
        cout << "Digite a senha : ";
        cin >> entrada;
        senha.setSenha(entrada);
    }
    catch (const invalid_argument &exp) {
        cout << endl << RED << "Dado em formato incorreto." << RESET << endl;
    }

    bool resultado = cntrlSAutenticacao->autenticar(*cpf, senha);

    return resultado;
}

void CntrIAContas::criar() {

    string nomeEntrada,cpfEntrada,senhaEntrada;

    Nome nome;
    Cpf cpf;
    Senha senha;

    cout << "Preencha os campos a seguir:" << endl;
    cout << "Seu Nome: ";
    cin.ignore();
    getline(cin, nomeEntrada);
    cout << "Seu Cpf: ";
    cin >> cpfEntrada;
    cout << "Sua senha: ";
    cin >> senhaEntrada;
    cout << endl;

    limparTerminal();

    try {
        nome.setNome(nomeEntrada);
        cpf.setCpf(cpfEntrada);
        senha.setSenha(senhaEntrada);
    } catch(invalid_argument &exp) {
        cout << RED << "Dados em formato incorreto. Tente novamente!" << RESET << endl;
        return;
    }

    Conta conta;

    conta.setNome(nome);
    conta.setCpf(cpf);
    conta.setSenha(senha);

    try {
        cntrSContas->criarConta(conta);
        cout << GREEN << "Sucesso ao criar a Conta!" << RESET << endl;
    } catch(invalid_argument &exp) {
        cout << RED << "Falha ao criar a Conta" << RESET << endl;
    }

}

bool CntrIAContas::executar(Cpf cpf) {
    int opcao;
    bool tela = true;
    char voltar[] = "Aperte Enter para voltar.";

    while(tela) {
        limparTerminal();
        cout << "Selecione algum serviço de conta abaixo: " << endl;
        cout << "1. Visualizar dados pessoais. " << endl;
        cout << "2. Editar dados pessoais. " << endl;
        cout << "3. Eliminar Conta. " << endl;
        cout << "4. Retornar." << endl;
        cout << "Sua opção: ";

        cin >> opcao;

        switch(opcao) {
            case 1: {
                limparTerminal();
                Conta conta;
                conta.setCpf(cpf);

                if(cntrSContas->lerConta(&conta)) {
                    cout << "Dados da Conta:" << endl;
                    cout << "Nome: " << conta.getNome().getNome() << endl;
                    cout << "Cpf: " << conta.getCpf().getCpf() << endl;
                    cout << "Senha: " << conta.getSenha().getSenha() << endl << endl;
                    cout << voltar;
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Falha ao acessar a conta." << endl;
                    cout << voltar;
                }
                break;
            }

            case 2: {
                while(true) {
                    limparTerminal();
                    Conta conta;
                    conta.setCpf(cpf);
                    string nomeEntrada;
                    string senhaEntrada;
                    Nome nome;
                    Senha senha;

                    cout << "Digite novos dados: " << endl;
                    cout << "Novo Nome: ";
                    cin.ignore();
                    getline(cin, nomeEntrada);
                    cout << "Nova Senha: ";
                    cin >> senhaEntrada;

                    try {
                        nome.setNome(nomeEntrada);
                        senha.setSenha(senhaEntrada);
                    } catch(exception& invalid_argument) {
                        cout << RED << "Dados invalidos!" << RESET << endl;
                        cout << voltar;
                        cin.ignore();
                        cin.get();
                        continue;
                    }

                    conta.setNome(nome);
                    conta.setSenha(senha);
                    limparTerminal();

                    if(cntrSContas->atualizarConta(conta)) {
                        cout << GREEN << "Alterações feitas com sucesso" << RESET << endl;
                        cout << voltar;
                        cin.ignore();
                        cin.get();
                        break;
                    } else {
                        cout << "Falha ao editar Conta." << endl;
                        cout << voltar;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                }
                break;
            }

            case 3: {
                if(cntrSContas->excluirConta(cpf)) {
                    cout << GREEN << "Exclusão feita com sucesso" << RESET << endl;
                    cout << voltar;
                    cin.ignore();
                    cin.get();
                    tela = false;
                    return true; // conta foi excluída
                } else {
                    cout << "Falha ao excluir Conta." << endl;
                    cout << voltar;
                    cin.ignore();
                    cin.get();
                    break;
                }
            }

            case 4: {
                tela = false;
                break;
            }

            default: {
                cout << RED << "Opção inválida!" << RESET << endl;
                cout << voltar;
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
    return false;
}



//-------------------------------------------------------------------//
bool CntrlSContas::criarConta(Conta conta) {
    ContainerConta *conConta;
    conConta = ContainerConta::getInstancia();

    return conConta->criar(conta);

}

bool CntrlSContas::visualizar(Conta* conta) {
    ContainerConta *conConta;

    conConta = ContainerConta::getInstancia();
    return conConta->existe(conta);
}

bool CntrlSContas::editar(Conta conta) {
    ContainerConta *conConta;
    conConta = ContainerConta::getInstancia();

    return conConta->editar(conta);
}

bool CntrlSContas::excluir(Cpf cpf) {
    ContainerConta *conConta;
    conConta = ContainerConta::getInstancia();

    return conConta->excluir(cpf);
}

bool CntrlSAutenticacao::autenticar(Cpf cpf, Senha senha) {
    ContainerConta *conConta;
    conConta = ContainerConta::getInstancia();
    Conta contaProvisoria;
    Conta contaReal;
    contaProvisoria.setCpf(cpf);
    contaProvisoria.setSenha(senha);
    if (conConta->existe(&contaProvisoria)) {
        contaReal = conConta->visualizar(&contaProvisoria);
        if(contaReal.getSenha().getSenha() == senha.getSenha()){
            return true;
        }
    }

    return false;
}
