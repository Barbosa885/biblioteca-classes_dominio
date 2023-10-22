#include "../../include/dominios_h/Limite.h"
#include <string>
#include <iostream>

Limite::Limite()
{
  //ctor
}

Limite::~Limite()
{
  //dtor
}

void Limite::isValid(const int &limite)
{
  /** 
   * verifica se o limite atende a um critério específico:
   * - o limite deve ser um dos seguintes valores: 5, 10, 15, 20.
   * @param limite a ser verificado
   * saida: "argumento invalido" caso o limite não atenda ao critério estabelecido.
   */
  if (limite == 5 || limite == 10 || limite == 15 || limite == 20) {}
  else
    throw invalid_argument("Argumento invalido");
}

void Limite::setLimite(const int &limite)
{
  isValid(limite);
  this->limite = limite;
}
