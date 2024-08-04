// Setor.cpp
#include "../../include/dominios_h/Setor.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

Setor::Setor() {
  // Construtor padrão
}

Setor::Setor(const string& setor) {
  setSetor(setor);
}

Setor::~Setor() {
  // Destrutor
}

// Lista de setores válidos
const vector<string> Setor::SETORES = {
  "Agricultura",
  "Construção civil",
  "Energia",
  "Finanças",
  "Imobiliário",
  "Papel e celulose",
  "Pecuária",
  "Química e petroquímica",
  "Metalurgia e siderurgia",
  "Mineração"
};

// Método que verifica se o setor está presente na lista de setores válidos
bool Setor::encontrarSetor(const string& setor) {
  return find(SETORES.begin(), SETORES.end(), setor) != SETORES.end();
}

// Método que valida o setor fornecido
void Setor::validar(const string& setor) {
  if (!encontrarSetor(setor)) {
    throw invalid_argument("Setor inválido");
  }
}

// Método que define o setor
void Setor::setSetor(const string& setor) {
  validar(setor);
  this->setor = setor;
}
