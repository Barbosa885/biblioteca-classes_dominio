// CodigoTitulo.cpp
#include "../../include/dominios_h/CodigoTitulo.h"
#include <cctype>
#include <stdexcept>

CodigoTitulo::CodigoTitulo() {
  // Construtor padrão
}

CodigoTitulo::CodigoTitulo(const std::string& codigo) {
  setCodigoTitulo(codigo);
}

CodigoTitulo::~CodigoTitulo() {
  // Destrutor
}

// Lista de títulos válidos
const std::vector<std::string> CodigoTitulo::TITULOS_VALIDOS = {
    "CDB",
    "CRA",
    "CRI",
    "LCA",
    "LCI",
    "DEB"
};

// Método que valida o código de título
void CodigoTitulo::validar(const std::string& codigoTitulo) {
  // Verifica se o código de título possui 11 caracteres
  if (codigoTitulo.size() != TAMANHO_MAX) {
    throw std::invalid_argument("Codigo inválido: tamanho incorreto");
  }

  // Verifica se o código de título possui apenas dígitos e letras maiúsculas
  for (char c : codigoTitulo) {
    if (!isalnum(c)) {
      throw std::invalid_argument("CodigoTitulo inválido: contém caracteres inválidos.");
    }
  }

  // Verifica se o código de título possui um prefixo válido
  bool prefixoValido = false;
  for (const auto& tituloValido : TITULOS_VALIDOS) {
    if (codigoTitulo.substr(0, tituloValido.size()) == tituloValido) {
      prefixoValido = true;
      break; // Prefixo válido encontrado
    }
  }

  if (!prefixoValido) {
    throw std::invalid_argument("CodigoTitulo inválido: prefixo inválido.");
  }
}

// Método que atribui um código de título
void CodigoTitulo::setCodigoTitulo(const std::string& codigoTitulo) {
  validar(codigoTitulo);
  this->codigoTitulo = codigoTitulo;
}
