#include "../../include/testes_h/TUEmail.h"
#include "../../include/dominios_h/Email.h"
#include <iostream>

using namespace std;

TUEmail::TUEmail()
{
    //ctor
}

TUEmail::~TUEmail()
{
    //dtor
}

const string TUEmail::EMAILS_VALIDOS[] = {
  "abcde12345@abcde12345.com",
  "user@domain.com",
};

const string TUEmail::EMAILS_INVALIDOS[] = {
  "a@b.com"
  "user@domain..com",
  "user.@domain.com",
  "user@.domain.com",
};

void TUEmail::setUp()
{
  estado = SUCESSO;
  email = new Email();
}

void TUEmail::tearDown()
{
  delete email;
}

void TUEmail::testarCenarioSucesso()
{
  cout << "EMAIL" << endl;
  cout << "Testando cenário de sucesso..." << endl;
  for(const string& emailValido : EMAILS_VALIDOS)
  {
    cout << "Testando email: " << emailValido << endl;
    try{
      email->setEmail(emailValido);
      if(email->getEmail().str() != emailValido)
      {
        cout << "Falha: " << email->getEmail().str() << endl;
        estado = FALHA;
      }
      else
      {
        cout << "Sucesso: " << email->getEmail().str() << endl;
        estado = SUCESSO;
      }
    }
    catch(invalid_argument& e)
    {
      cout << "Exceção lançada: " << e.what() << endl;
      estado = FALHA;
    }
  }
}

void TUEmail::testarCenarioFalha()
{
  cout << "Testando cenário de falha..." << endl;
  for(const string& emailInvalido : EMAILS_INVALIDOS)
  {
    cout << "Testando email: " << emailInvalido << endl;
    try{
      cout << "Email inválido: " << emailInvalido << endl;
      email->setEmail(emailInvalido);
      estado = FALHA;
    }
    catch(invalid_argument& e)
    {
      cout << "Exceção lançada: " << e.what() << endl;
      estado = FALHA;
    }
  }
}

void TUEmail::run()
{
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
}
