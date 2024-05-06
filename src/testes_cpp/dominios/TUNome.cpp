#include "../../../include/testes_h/dominios/TUNome.h"

const string TUNome::NOME_VALIDO = "Joao";
const string TUNome::NOME_INVALIDO = "Joao123";

void TUNome::setUp() {
  nome = new Nome();
  estado = SUCESSO;
}

void TUNome::tearDown() {
  delete nome;
}

void TUNome::testarCenarioSucesso() {
  try {
    nome->setNome(NOME_VALIDO);
    if (nome->getNome() != NOME_VALIDO) {
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUNome::testarCenarioFalha() {
  try {
    nome->setNome(NOME_INVALIDO);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUNome::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}
