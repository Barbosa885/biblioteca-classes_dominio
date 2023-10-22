#include <iostream>
#include "../../include/testes_h/TUSenha.h"
#include "../../include/dominios_h/Senha.h"

TUSenha::TUSenha()
{
  //ctor
}

TUSenha::~TUSenha()
{
  //dtor
}

using namespace std;

const string TUSenha::SENHAS_VALIDAS[] = {
  "Abc1.",
  "Zy?x2"
};

const string TUSenha::SENHAS_INVALIDAS[] = {
  "abc.1",
  "ABC?2",
  "Abc!e",
  "Abcd3",
  "Abb,4"
};

void TUSenha::setUp(){  /** Configura o ambiente de teste. */
  senha = new Senha();
  estado = SUCESSO;
}

void TUSenha::tearDown(){ /** Limpa o ambiente de teste, excluindo a instância SENHA. */
  delete senha;
}

void TUSenha::testarCenarioSucesso(){ /** Testa um cenário de sucesso em que a senha é definida como uma senha válida. */
  cout << "SENHA" << endl;
  cout << "Testando cenário de sucesso..." << endl;
  for (const string &senhaValida : SENHAS_VALIDAS)
  {
    cout << "Testando senha: " << senhaValida << endl;
    try
    {
      senha->setSenha(senhaValida);
      if (senha->getSenha() != senhaValida)
      {
        cout << "Falha: " << senha->getSenha() << endl;
        estado = FALHA;
      } else {
        cout << "Sucesso: " << senha->getSenha() << endl;
        estado = FALHA;
      }
    }
    catch(invalid_argument &excecao)
    {
      cout << "Exceção lançada: " << excecao.what() << endl;
      estado = FALHA;
    }
  }
}

void TUSenha::testarCenarioFalha(){ /** Testa um cenário de falha em que a senha é definida como uma senha inválida. */
  cout << "Testando cenário de falha..." << endl;
  for (const string &senhaInvalida : SENHAS_INVALIDAS)
  {
    cout << "Testando senha: " << senhaInvalida << endl;
    try
    {
      senha->setSenha(senhaInvalida);
      estado = FALHA;
    }
    catch(invalid_argument &e)
    {
      cout << "Exceção lançada: " << e.what() << endl;
      estado = FALHA;
    }
  }
}

void TUSenha::run(){
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
}
