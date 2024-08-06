// Dominios
// #include "./include/testes_h/dominios/TUCodigoPagamento.h"
// #include "./include/testes_h/dominios/TUSetor.h"
// #include "./include/testes_h/dominios/TUEstado.h"
// #include "./include/testes_h/dominios/TUNome.h"
// #include "./include/testes_h/dominios/TUPercentual.h"
// #include "./include/testes_h/dominios/TUDinheiro.h"
// #include "./include/testes_h/dominios/TUCodigoTitulo.h"
// #include "./include/testes_h/dominios/TUCpf.h"
// #include "./include/testes_h/dominios/TUSenha.h"
// #include "./include/testes_h/dominios/TUData.h"
//
// // Entidades
// #include "./include/testes_h/entidades/TUConta.h"
// #include "./include/testes_h/entidades/TUTitulo.h"
// #include "./include/testes_h/entidades/TUPagamento.h"

// Controladoras
#include "./include/controladoras_h/CntrlAContas.h"
#include "./include/controladoras_h/CntrlSAutenticacao.h"
#include "./include/controladoras_h/CntrlAAutenticacao.h"
#include "./include/controladoras_h/CntrlIU.h"

using namespace std;

int main() {

    // Criar instâncias das classes controladoras.
    CntrlIU cntrlIU;
    CntrlAAutenticacao cntrlAAutenticacao;
    CntrIAContas cntrlIAConta;

    // Criar instâncias das classes de serviço.
    CntrlSAutenticacao cntrlSAutenticacao;

    // Configurar dependências das controladoras.
    cntrlAAutenticacao.setCntrlSAutenticacao(&cntrlSAutenticacao);
    cntrlIAConta.setCntrSConta(&cntrlIAConta);

    // Configurar dependências da interface de usuário.
    cntrlIU.setCntrlAAutenticacao(&cntrlAAutenticacao);
    cntrlIAConta.setCntrSConta(&cntrlIAConta);

    // Interagir com o usuário.
    cntrlIU.interagirComUsuario();

    CntrlSAutenticacao cntrlISAutenticacao;

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

  return 0;
}
