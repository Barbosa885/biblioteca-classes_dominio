//// Dominios
//#include "./include/testes_h/dominios/TUCodigoPagamento.h"
//#include "./include/testes_h/dominios/TUSetor.h"
//#include "./include/testes_h/dominios/TUEstado.h"
//#include "./include/testes_h/dominios/TUNome.h"
//#include "./include/testes_h/dominios/TUPercentual.h"
//#include "./include/testes_h/dominios/TUDinheiro.h"
//#include "./include/testes_h/dominios/TUCodigoTitulo.h"
//#include "./include/testes_h/dominios/TUCpf.h"
//#include "./include/testes_h/dominios/TUSenha.h"
//#include "./include/testes_h/dominios/TUData.h"
//
//// Entidades
//#include "./include/testes_h/entidades/TUConta.h"
//#include "./include/testes_h/entidades/TUTitulo.h"
//#include "./include/testes_h/entidades/TUPagamento.h"

// Módulos
#include "./include/testes_h/controladoras/TUCtrlAprPagamentos.h"
#include "./include/testes_h/controladoras/TUCtrlSerPagamentos.h"
#include "./include/testes_h/persistencia/TUPagamentoOAD.h"

using namespace std;

int main() {

//  TUCodigoPagamento testeCodigo;
//  switch(testeCodigo.run()){
//    case TUCodigoPagamento::SUCESSO:
//      cout << "SUCESSO - CODIGO_PAGAMENTO" << endl;
//      break;
//    case TUCodigoPagamento::FALHA:
//      cout << "FALHA - CODIGO_PAGAMENTO" << endl;
//      break;
//  }
//
//  TUSetor testeSetor;
//  switch(testeSetor.run()){
//    case TUSetor::SUCESSO:
//      cout << "SUCESSO - SETOR" << endl;
//      break;
//    case TUSetor::FALHA:
//      cout << "FALHA - SETOR" << endl;
//      break;
//  }
//
//  TUEstado testeEstado;
//  switch(testeEstado.run()){
//    case TUEstado::SUCESSO:
//      cout << "SUCESSO - ESTADO" << endl;
//      break;
//    case TUEstado::FALHA:
//      cout << "FALHA - ESTADO" << endl;
//      break;
//  }
//
//  TUNome testeNome;
//  switch(testeNome.run()){
//    case TUNome::SUCESSO:
//      cout << "SUCESSO - NOME" << endl;
//      break;
//    case TUNome::FALHA:
//      cout << "FALHA - NOME" << endl;
//      break;
//  }
//
//  TUPercentual testePercentual;
//  switch(testePercentual.run()){
//    case TUPercentual::SUCESSO:
//      cout << "SUCESSO - PERCENTUAL" << endl;
//      break;
//    case TUPercentual::FALHA:
//      cout << "FALHA - PERCENTUAL" << endl;
//      break;
//  }
//
//  TUDinheiro testeDinheiro;
//  switch(testeDinheiro.run()){
//    case TUDinheiro::SUCESSO:
//      cout << "SUCESSO - DINHEIRO" << endl;
//      break;
//    case TUDinheiro::FALHA:
//      cout << "FALHA - DINHEIRO" << endl;
//      break;
//  }
//
//  TUCodigoTitulo testeCodigoTitulo;
//  switch(testeCodigoTitulo.run()){
//    case TUCodigoTitulo::SUCESSO:
//      cout << "SUCESSO - CODIGO_TITULO" << endl;
//      break;
//    case TUCodigoTitulo::FALHA:
//      cout << "FALHA - CODIGO_TITULO" << endl;
//      break;
//  }
//
//  TUCpf testeCpf;
//  switch(testeCpf.run()){
//    case TUCpf::SUCESSO:
//      cout << "SUCESSO - CPF" << endl;
//      break;
//    case TUCpf::FALHA:
//      cout << "FALHA - CPF" << endl;
//      break;
//  }
//
//  TUSenha testeSenha;
//  switch(testeSenha.run()){
//    case TUSenha::SUCESSO:
//      cout << "SUCESSO - SENHA" << endl;
//      break;
//    case TUSenha::FALHA:
//      cout << "FALHA - SENHA" << endl;
//      break;
//  }
//
//  TUData testeData;
//  switch(testeData.run()){
//    case TUData::SUCESSO:
//      cout << "SUCESSO - DATA" << endl;
//      break;
//    case TUData::FALHA:
//      cout << "FALHA - DATA" << endl;
//      break;
//  }
//
//  TUConta testeConta;
//  switch(testeConta.run()){
//    case TUConta::SUCESSO:
//      cout << "SUCESSO - CONTA" << endl;
//      break;
//    case TUConta::FALHA:
//      cout << "FALHA - CONTA" << endl;
//      break;
//  }
//
//  TUTitulo testeTitulo;
//  switch(testeTitulo.run()){
//    case TUTitulo::SUCESSO:
//      cout << "SUCESSO - TITULO" << endl;
//      break;
//    case TUTitulo::FALHA:
//      cout << "FALHA - TITULO" << endl;
//      break;
//  }
//
//  TUPagamento testePagamento;
//  switch(testePagamento.run()){
//    case TUPagamento::SUCESSO:
//      cout << "SUCESSO - PAGAMENTO" << endl;
//      break;
//    case TUPagamento::FALHA:
//      cout << "FALHA - PAGAMENTO" << endl;
//      break;
//  }

    try {
        PagamentoOAD* oadPagamento = new PagamentoOAD("./banco.db");
        CtrlSerPagamentos* servico_pgto = new CtrlSerPagamentos(oadPagamento);
        CtrlAprPagamentos ctrlAprPagamentos(servico_pgto);

        // Instanciação de um objeto Cpf e definição do valor
        Cpf cpf;
        cpf.setCpf("070.002.121-36"); // Define o CPF com a string válida

        // Executa o menu de gerenciamento de Pagamentos com o CPF fornecido
        ctrlAprPagamentos.executar(cpf);

        // Liberação de recursos
        delete servico_pgto;
        delete oadPagamento;
    } catch (const std::exception& e) {
        cerr << "Erro durante a execução: " << e.what() << endl;
    }

    return 0;
}
