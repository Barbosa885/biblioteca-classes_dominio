#include "../../../include/testes_h/dominios/TUPercentual.h"

const int TUPercentual::PERCENTUAL_VALIDO = 10.0;
const int TUPercentual::PERCENTUAL_INVALIDO = 101.0;

void TUPercentual::setUp() {
  percentual = new Percentual();
  estadoAtual = SUCESSO;
}

void TUPercentual::tearDown() {
  delete percentual;
}

void TUPercentual::testarCenarioSucesso() {
  try {
    percentual->setPercentual(PERCENTUAL_VALIDO);
    if (percentual->getPercentual() != PERCENTUAL_VALIDO) {
      estadoAtual = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estadoAtual = FALHA;
  }
}

void TUPercentual::testarCenarioFalha() {
  try {
    percentual->setPercentual(PERCENTUAL_INVALIDO);
    estadoAtual = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUPercentual::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estadoAtual;
}
