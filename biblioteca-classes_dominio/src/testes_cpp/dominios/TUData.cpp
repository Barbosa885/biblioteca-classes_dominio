#include "../../../include/testes_h/dominios/TUData.h"

const string TUData::DATA_VALIDA = "01-01-2023";
const string TUData::DATA_INVALIDA = "01-01-23";

void TUData::setUp() {
  data = new Data();
  estado = SUCESSO;
}

void TUData::tearDown() {
  delete data;
}

void TUData::testarCenarioSucesso() {
  try {
    data->setData(DATA_VALIDA);
    if (data->getData() != DATA_VALIDA) {
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUData::testarCenarioFalha() {
  try {
    data->setData(DATA_INVALIDA);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUData::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estado;
}
