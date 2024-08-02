#include "../../include/dominios_h/Senha.h"

Senha::Senha()
{
  //ctor
}

Senha::~Senha()
{
  //dtor
}

using namespace std;

// Método que valida a senha
void Senha::validar(const string& senha) {
  // Verifica se a senha contém apenas digitos
  for (char c : senha) {
    if (!isdigit(c)) {
      throw invalid_argument("Senha inválida: deve conter apenas digitos");
    }
  }

  // Verifica se a senha tem 6 caracteres e o primeiro digito é diferente de 0
  if (senha.size() != TAMANHO_MAX && senha[0] == '0') {
    throw invalid_argument("Senha inválida: deve ter 6 digitos");
  }


  // Verifica se a senha não contém sequencia crescente ou decrescente
  if (!validarSequencia(senha)) {
    throw invalid_argument("Senha inválida: não pode conter sequencia crescente ou decrescente");
  }

  // Verifica se a senha não contém digitos repetidos
  if (!validarCaracteres(senha)) {
    throw invalid_argument("Senha inválida: não pode conter digitos repetidos");
  }

}

// Método que verifica se a senha possui digitos repetidos
bool Senha::validarCaracteres(const string& senha) {
  // Verifica se a senha possui digitos repetidos
  for (int i = 0; i < senha.size(); i++) {
    // Verifica se o digito atual é igual a algum outro digito
    for (int j = i + 1; j < senha.size(); j++) {
      // Se for igual, a senha é inválida
      if (senha[i] == senha[j]) {
        return false;
      }
    }
  }
  return true;
}

// Método que verifica se a senha possui sequencia crescente ou decrescente
bool Senha::validarSequencia(const string& senha) {
  if (senha.size() <= 2) {
    return false;
  }

  // Verifica se a senha possui sequencia crescente ou decrescente
  for (int i = 0; i < senha.size() - 1; i++) {
    // Verifica se o digito atual é igual ao proximo digito - 1 ou + 1
    if (senha[i] == senha[i + 1] - 1 || senha[i] == senha[i + 1] + 1) {
      return false;
    }
  }

  return true;
}

// Método que atribui a senha
void Senha::setSenha(const string& senha) {
  validar(senha);
  this->senha = senha;
}
