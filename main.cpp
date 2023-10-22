// Bibliotecas
#include <iostream>

// Header dominios
#include "./include/dominios_h/Email.h"
#include "./include/dominios_h/Codigo.h"
#include "./include/dominios_h/Coluna.h"
#include "./include/dominios_h/Limite.h"
#include "./include/dominios_h/Senha.h"

// Header testes
#include "./include/testes_h/TULimite.h"
#include "./include/testes_h/TUColuna.h"
#include "./include/testes_h/TUCodigo.h"
#include "./include/testes_h/TUEmail.h"
#include "./include/testes_h/TUSenha.h"


using namespace std;

int main()
{

  TUEmail *testeEmail = new TUEmail();
  testeEmail->run();

  TUCodigo *testeCodigo = new TUCodigo();
  testeCodigo->run();

  TULimite *testeLimite = new TULimite();
  testeLimite->run();

  TUColuna *testeColuna = new TUColuna();
  testeColuna->run();

  TUSenha *testeSenha = new TUSenha();
  testeSenha->run();


  // TUSenha testeSenha;
  // switch(testeSenha.run())
  // {
  //   case TUSenha::SUCESSO:
  //     cout << "SUCESSO - SENHA" << endl;
  //     break;
  //   case TUSenha::FALHA:
  //     cout << "FALHA - SENHA" << endl;
  //     break;
  // }
  //
  // TUTexto testeTexto;
  // switch(testeTexto.run())
  // {
  //   case TUTexto::SUCESSO:
  //     cout << "SUCESSO - TEXTO" << endl;
  //     break;
  //   case TUTexto::FALHA:
  //     cout << "FALHA - TEXTO" << endl;
  //     break;
  // }
  //
  // TULimite testeLimite;
  // switch(testeLimite.run())
  // {
  //   case TULimite::SUCESSO:
  //     cout << "SUCESSO - LIMITE" << endl;
  //     break;
  //   case TULimite::FALHA:
  //     cout << "FALHA - LIMITE" << endl;
  //     break;
  // }
  //
  // TUColuna testeColuna;
  // switch(testeColuna.run())
  // {
  //   case TUColuna::SUCESSO:
  //     cout << "SUCESSO - COLUNA" << endl;
  //     break;
  //   case TUColuna::FALHA:
  //     cout << "FALHA - COLUNA" << endl;
  //     break;
  // }
}
