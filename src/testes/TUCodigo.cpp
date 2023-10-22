#include "../../include/testes_h/TUCodigo.h"
#include "../../include/dominios_h/Codigo.h"
#include <iostream>

using namespace std;

TUCodigo::TUCodigo()
{
  //ctor
}

TUCodigo::~TUCodigo()
{
  //dtor
}

const string TUCodigo::CODIGOS_VALIDOS[] = {
  "AB12",
  "CD34",
};

const string TUCodigo::CODIGOS_INVALIDOS[] = {
  "AB123",
  "ABCD",
};

void TUCodigo::setUp()
{
  codigo = new Codigo();
  estado = SUCESSO;
}

void TUCodigo::tearDown()
{
  delete codigo;
}

void TUCodigo::testarCenarioSucesso()
{
  cout << "CODIGO" << endl;
  cout << "Testando cenário de sucesso..." << endl;
  for(const string& codigoValido : CODIGOS_VALIDOS)
  {
    cout << "Testando codigo: " << codigoValido << endl;
    try
    {
      codigo->setCodigo(codigoValido);
      if(codigo->getCodigo() != codigoValido)
      {
        estado = FALHA;
      } else {
        cout << "Sucesso: " << codigo->getCodigo() << endl;
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

void TUCodigo::testarCenarioFalha()
{
  cout << "Testando cenário de falha..." << endl;
  for(const string& codigoInvalido : CODIGOS_INVALIDOS)
  {
    cout << "Testando codigo: " << codigoInvalido << endl;
    try{
      codigo->setCodigo(codigoInvalido);
      estado = FALHA;
    }
    catch(invalid_argument& e)
    {
      cout << "Exceção lançada: " << e.what() << endl;
      estado = SUCESSO;
    }
  }
}

void TUCodigo::run()
{
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
}
