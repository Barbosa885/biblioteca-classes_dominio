#include "../../include/dominios_h/Codigo.h"
#include <iostream>

using namespace std;

Codigo::Codigo()
{
  //ctor
}

Codigo::~Codigo()
{
  //dtor
}

bool Codigo::isValid(const string& codigo)
{
  if(codigo.length() != 4)
  {
    return false;
  }
  if(!isupper(codigo[0]) || !isupper(codigo[1]))
  {
    return false;
  }
  if(!isdigit(codigo[2]) || !isdigit(codigo[3]))
  {
    return false;
  }
  return true;
}

void Codigo::setCodigo(const string& codigo)
{
  if(!isValid(codigo))
  {
    throw invalid_argument("Código inválido");
  }
  this->codigo = codigo;
}

const string& Codigo::getCodigo() const
{
  return codigo;
}

