#include "../../../include/testes_h/dominios/TUCodigoTitulo.h"

const string TUCodigoTitulo::CODIGO_VALIDO = "LCA3241AG84";
const string TUCodigoTitulo::CODIGO_INVALIDO = "CSD3241AG841";

void TUCodigoTitulo::setUp() {
  codigoTitulo = new CodigoTitulo();
  estado = SUCESSO;
}

void TUCodigoTitulo::tearDown() {
  delete codigoTitulo;
}

void TUCodigoTitulo::testarCenarioSucesso() {
  try {
    codigoTitulo->setCodigoTitulo(CODIGO_VALIDO);
    if (codigoTitulo->getCodigoTitulo() != CODIGO_VALIDO) {
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUCodigoTitulo::testarCenarioFalha() {
  try {
    codigoTitulo->setCodigoTitulo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUCodigoTitulo::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estado;
}

