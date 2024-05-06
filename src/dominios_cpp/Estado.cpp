#include "../../include/dominios_h/Estado.h"

using namespace std;

Estado::Estado(){
  //ctor
}

Estado::~Estado(){
  //dtor
}

// Lista de estados validos
const vector<string> Estado::ESTADOS = {
  "Previsto",
  "Liquidado",
  "Inadimplente"
};

// Método que valida o estado
void Estado::validar(const string& estado) {
  if (estado == ESTADOS[0] || estado == ESTADOS[1] || estado == ESTADOS[2]) {
    return;
  }
  throw invalid_argument("Estado invalido");
}

// Método que seta o estado
void Estado::setEstado(const string& estado) {
  validar(estado);
  this->estado = estado;
}
