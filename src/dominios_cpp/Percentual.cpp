#include "../../include/dominios_h/Percentual.h"

Percentual::Percentual()
{
  //ctor
}

Percentual::~Percentual()
{
  //dtor
}

using namespace std;

// Método que valida o percentual
void Percentual::validar(float percentual) {
  // Método que verifica se o percentual está dentro do limite permitido
  if(percentual < 0 || percentual > LIMITE) {
    throw invalid_argument("Percentual invalido");
  }
}

// Método que define o percentual
void Percentual::setPercentual(float percentual) {
  validar(percentual);
  this->percentual = percentual;
}
