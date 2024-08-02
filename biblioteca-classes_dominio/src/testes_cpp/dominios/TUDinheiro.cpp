#include "../../../include/testes_h/dominios/TUDinheiro.h"

const float TUDinheiro::VALOR_VALIDO = 1234.56;
const float TUDinheiro::VALOR_INVALIDO = -1234.56;

void TUDinheiro::setUp() {
  dinheiro = new Dinheiro();
  estado = SUCESSO;
}

void TUDinheiro::tearDown() {
  delete dinheiro;
}

void TUDinheiro::testarCenarioSucesso() {
  try {
    dinheiro->setValor(VALOR_VALIDO);
    if(dinheiro->getValor() != VALOR_VALIDO){
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUDinheiro::testarCenarioFalha() {
  try {
    dinheiro->setValor(VALOR_INVALIDO);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUDinheiro::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estado;
}
