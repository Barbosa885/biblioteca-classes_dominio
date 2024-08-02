#include "../../include/dominios_h/Cpf.h"
#include <algorithm>
#include <cctype>
#include <regex>

Cpf::Cpf()
{
  //ctor
}

Cpf::~Cpf()
{
  //dtor
}

/* Método que valida o CPF */
/*
  Formato XXX.XXX.XXX-CC
  X - Dígito (0-9)
  Pontos usados para separar sequências de três dígitos
  Hífen usado para separar sequências de dígitos de caracteres de validação
  CC - Caracteres de validação calculados segundo algoritmo de validação de CPF
*/

// Método que valida os dígitos verificadores do CPF
bool Cpf::validarDigitos(int digito1, int digito2, string digitos) {
  // Converte os dígitos para inteiros
  int ultimoDigito = digitos[digitos.size() - 1] - '0';
  int penultimoDigito = digitos[digitos.size() - 2] - '0';

  // Verifica se os dígitos verificadores são iguais aos calculados
  if (ultimoDigito != digito2 || penultimoDigito != digito1) {
    return false;
  }
  return true;
}

// Método que valida o formato do CPF
bool Cpf::validarFormato(const string& cpf) {
  regex formato("^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}-[0-9]{2}$");
  return regex_match(cpf, formato);
}


// Método que valida o CPF
void Cpf::validar(const string& cpf) {
  // Verifica se o CPF está no formato correto
  if (!validarFormato(cpf)) {
    throw invalid_argument("CPF inválido: formato inválido");
  }

  // Remove os pontos e o hífen do CPF
  string digitos = cpf;
  digitos.erase(remove_if(digitos.begin(), digitos.end(), [](char c) {
    return !isdigit(c);
  }), digitos.end());

  // Calcula o primeiro dígito verificador
  int soma = 0;
  for (int i = 0; i < 9; i++) {
    soma += (digitos[i] - '0') * (10 - i);
  }

  int resto = soma % 11;
  int digito1 = resto < 2? 0 : 11 - resto;

  // Calcula o segundo dígito verificador
  soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += (digitos[i] - '0') * (11 - i);
  }

  resto = soma % 11;
  int digito2 = resto < 2? 0 : 11 - resto;

  // Verifica se os dígitos verificadores são válidos
  if (!validarDigitos(digito1, digito2, digitos)) {
    throw invalid_argument("CPF inválido: dígitos verificadores inválidos");
  }
}

void Cpf::setCpf(const string& cpf) {
  validar(cpf);
  this->cpf = cpf;
}
