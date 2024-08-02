#include "../../../include/testes_h/dominios/TUSetor.h"

const string TUSetor::SETOR_VALIDO = "Finanças";
const string TUSetor::SETOR_INVALIDO = "Recursos Humanos";

void TUSetor::setUp() {
  setor = new Setor();
  estado = SUCESSO;
}

void TUSetor::tearDown() {
  delete setor;
}

void TUSetor::testarCenarioSucesso() {
  try {
    setor->setSetor(SETOR_VALIDO);
    if(setor->getSetor() != SETOR_VALIDO){
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUSetor::testarCenarioFalha() {
  try {
    setor->setSetor(SETOR_INVALIDO);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUSetor::run() {

  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}
