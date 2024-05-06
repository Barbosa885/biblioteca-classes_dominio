#include "../../include/dominios_h/CodigoTitulo.h"
#include <cctype>

CodigoTitulo::CodigoTitulo()
{
  //ctor
}

CodigoTitulo::~CodigoTitulo()
{
  //dtor
}

// Lista de títulos válidos
const vector<string> CodigoTitulo::TITULOS_VALIDOS = {
  "CDB",
  "CRA",
  "CRI",
  "LCA",
  "LCI",
  "DEB",
};


// Método que valida o código de título
void CodigoTitulo::validar(string codigoTitulo) {
  // Verifica se o código de título possui 11 caracteres
  if (codigoTitulo.size() != TAMANHO_MAX) {
    throw invalid_argument("Codigo inválido: tamanho incorreto");
  }

  // Verifica se o código de título possui apenas dígitos e letras maiúsculas
  for (char c : codigoTitulo) {
    if (!isalnum(c)) {
      throw invalid_argument("CodigoTitulo inválido: contém caracteres inválidos.");
    }
  }

  // Verifica se o código de título possui um prefixo válido
  for (const auto& tituloValido : TITULOS_VALIDOS) {
    if (codigoTitulo.substr(0, tituloValido.size()) == tituloValido) {
      break; // Prefixo válido encontrado
    }
  }

}

// Método que atribui um código de título
void CodigoTitulo::setCodigoTitulo(string codigoTitulo) {
  validar(codigoTitulo);
  this->codigoTitulo = codigoTitulo;
}
