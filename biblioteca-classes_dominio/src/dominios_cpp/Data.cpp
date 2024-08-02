#include "../../include/dominios_h/Data.h"
#include <regex>

Data::Data() {
  // ctor
}

Data::~Data() {
  // dtor
}

using namespace std;


void Data::validar(const string& data) {
  // Verifica se a data está no formato correto
  if (!validarFormato(data)) {
    throw invalid_argument("Data inválida: formato inválido");
  }

  // Extrai os componentes da data
  int dia = stoi(data.substr(0, 2));
  int mes = stoi(data.substr(3, 2));
  int ano = stoi(data.substr(6, 4));

  // Verifica se os componentes são válidos
  if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 2000 || ano > 2100) {
    throw invalid_argument("Data inválida: data inexistente");
  }

  // Considera anos bissextos
  if (ano % 4 == 0 && (ano % 100!= 0 || ano % 400 == 0)) {
    if (mes == 2 && dia > 29) {
      throw invalid_argument("Data inválida: data inexistente");
    }
  } else if (mes == 2 && dia > 28) {
    throw invalid_argument("Data inválida: data inexistente");
  }
}

// Método que valida o formato da data
bool Data::validarFormato(const string& data) {
  regex formato("^[0-9]{2}-[0-9]{2}-[0-9]{4}$");
  return regex_match(data, formato);
}

void Data::setData(const string& data) {
  validar(data);
  this->data = data;
}
