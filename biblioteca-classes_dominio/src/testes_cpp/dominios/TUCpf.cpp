#include "../../../include/testes_h/dominios/TUCpf.h"

const string TUCpf::CPF_VALIDO = "079.830.681-58";
const string TUCpf::CPF_INVALIDO = "542-2131-434-23";

void TUCpf::setUp() {
  cpf = new Cpf();
  estado = SUCESSO;
}

void TUCpf::tearDown() {
  delete cpf;
}

void TUCpf::testarCenarioSucesso() {
  try {
    cpf->setCpf(CPF_VALIDO);
    if (cpf->getCpf() != CPF_VALIDO) {
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUCpf::testarCenarioFalha() {
  try {
    cpf->setCpf(CPF_INVALIDO);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUCpf::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estado;
}
