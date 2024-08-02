#include "../../../include/testes_h/dominios/TUSenha.h"

const string TUSenha::SENHA_VALIDA = "862490";
const string TUSenha::SENHA_INVALIDA = "123456";

void TUSenha::setUp() {
  senha = new Senha();
  estado = SUCESSO;
}

void TUSenha::tearDown() {
  delete senha;
}

void TUSenha::testarCenarioSucesso() {
  try {
    senha->setSenha(SENHA_VALIDA);
    if (senha->getSenha() != SENHA_VALIDA) {
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUSenha::testarCenarioFalha() {
  try {
    senha->setSenha(SENHA_INVALIDA);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUSenha::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estado;
}
