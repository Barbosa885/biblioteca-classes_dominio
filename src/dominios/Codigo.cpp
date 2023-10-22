#include "../../include/dominios_h/Codigo.h"
#include <iostream>

using namespace std;

Codigo::Codigo()
{
  //construtor
}

Codigo::~Codigo()
{
  //destrutor
}

void Codigo::isValid(const string& codigo)
{
  if(codigo.length() != 4)
  {
    throw invalid_argument("Código inválido");
  }
  if(!isupper(codigo[0]) || !isupper(codigo[1]))
  {
    throw invalid_argument("Código inválido");
  }
  if(!isdigit(codigo[2]) || !isdigit(codigo[3]))
  {
    throw invalid_argument("Código inválido");
  }
}

void Codigo::setCodigo(const string& codigo)
{
  isValid(codigo);
  this->codigo = codigo;
}

