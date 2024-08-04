// Data.cpp
#include "../../include/dominios_h/Data.h"
#include <regex>
#include <stdexcept>

using namespace std;

Data::Data() {
  // Construtor padrão
}

Data::Data(const string& data) {
  setData(data);
}

Data::~Data() {
  // Destrutor
}

// Valida o formato da data
bool Data::validarFormato(const string& data) {
  // Regex para formato DD-MM-AAAA
  regex formato("^[0-9]{2}-[0-9]{2}-[0-9]{4}$");
  return regex_match(data, formato);
}

// Método que valida a data fornecida
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
  bool isBissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
  if (mes == 2) {
    if (isBissexto && dia > 29) {
      throw invalid_argument("Data inválida: fevereiro tem no máximo 29 dias em anos bissextos");
    } else if (!isBissexto && dia > 28) {
      throw invalid_argument("Data inválida: fevereiro tem no máximo 28 dias em anos não bissextos");
    }
  } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
    throw invalid_argument("Data inválida: o mês especificado tem no máximo 30 dias");
  }
}

// Define a data após validação
void Data::setData(const string& data) {
  validar(data);
  this->data = data;
}
