#include "../include/Codigo.h"
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

void Codigo::setCodigo(const string& codigo)
{
  if(!isValid(codigo))
  {
    throw invalid_argument("Invalid code");
  }
  this->codigo = codigo;
}

const string& Codigo::getCodigo() const
{
  return codigo;
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

