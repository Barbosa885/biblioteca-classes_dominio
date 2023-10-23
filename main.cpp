// Bibliotecas
#include <iostream>

// dominios
#include "./include/dominios_h/Email.h"
#include "./include/dominios_h/Codigo.h"
#include "./include/dominios_h/Coluna.h"
#include "./include/dominios_h/Limite.h"
#include "./include/dominios_h/Senha.h"
#include "./include/dominios_h/Texto.h"
#include "./include/entidades_h/Cartao.h"
#include "./include/entidades_h/Quadro.h"

// testes
#include "./include/testes_h/TULimite.h"
#include "./include/testes_h/TUColuna.h"
#include "./include/testes_h/TUCodigo.h"
#include "./include/testes_h/TUEmail.h"
#include "./include/testes_h/TUSenha.h"
#include "./include/testes_h/TUTexto.h"

// testes entidades
#include "./include/testes_h/TUCartao.h"
#include "./include/testes_h/TUQuadro.h"

using namespace std;

int main()
{
  cout << "Testando dominios..." << endl;
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
  
  TUTexto *testeTexto = new TUTexto();
  testeTexto->run();
  cout << "Testes de dominios concluidos." << endl;

  cout << "Testando entidades..." << endl;
  cout << "Testando entidade Cartao..." << endl;
  TUCartao *testeCartao = new TUCartao();
  testeCartao->run();

  cout << "Testando entidade Quadro..." << endl;
  TUQuadro *testeQuadro = new TUQuadro();
  testeQuadro->run();
}
