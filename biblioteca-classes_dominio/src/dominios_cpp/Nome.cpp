#include "../../include/dominios_h/Nome.h"
#include <sstream>

using namespace std;

Nome::Nome(){
  //ctor
}

Nome::~Nome(){
  //dtor
}

// Método que valida o nome
void Nome::validar(const string& nome) {
  // Verifica se o nome contém apenas letras
  stringstream ss(nome);
  string termo;
  int termos = 0;

  while (ss >> termo) {
    // Verifica se o nome possui no máximo dois termos
    if (termos >= 2) {
      throw invalid_argument("Nome inválido: mais de dois termos.");
    }

    // Verifica se o termo possui entre 3 e 10 caracteres
    if (termo.length() < 3 || termo.length() > 10) {
      throw invalid_argument("Nome inválido: cada termo deve ter entre 3 e 10 caracteres.");
    }

    // Verifica se o termo começa com letra maiúscula
    if (!isupper(termo[0])) {
      throw invalid_argument("Nome inválido: o primeiro caractere de cada termo deve ser maiúsculo.");
    }


    // Verifica se o termo possui apenas letras
    for (char c : termo) {
      if (!isalpha(c)) {
        throw invalid_argument("Nome inválido: todos os caracteres devem ser letras.");
      }
    }

    // Incrementa o contador de termos
    termos++;
  }

  // Verifica se o nome possui pelo menos um termo
  if (termos == 0) {
    throw invalid_argument("Nome inválido: pelo menos um termo é necessário.");
  }
}

// Método que atribui um nome
void Nome::setNome(const string& nome) {
  validar(nome);
  this->nome = nome;
}
