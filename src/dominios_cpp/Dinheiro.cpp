// Dinheiro.cpp
#include "../../include/dominios_h/Dinheiro.h"
#include <stdexcept>

using namespace std;

Dinheiro::Dinheiro() {
  // Construtor padrão
}

Dinheiro::Dinheiro(float valor) {
  setValor(valor);
}

Dinheiro::~Dinheiro() {
  // Destrutor
}

// Método que valida o dinheiro
void Dinheiro::validar(float valor) {
  // Verifica se o valor é negativo ou maior que o limite
  if (valor < 0 || valor > LIMITE) {
    throw invalid_argument("Dinheiro invalido");
  }
}

// Método que define o valor do dinheiro
void Dinheiro::setValor(float valor) {
  validar(valor);
  this->valor = valor;
}
