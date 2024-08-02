#include "../../../include/testes_h/dominios/TUCodigoPagamento.h"

const string TUCodigoPagamento::CODIGO_VALIDO = "12345678";
const string TUCodigoPagamento::CODIGO_INVALIDO = "0000000";

void TUCodigoPagamento::setUp() {
  codigo_pagamento = new CodigoPagamento();
  estado = SUCESSO;
}

void TUCodigoPagamento::tearDown() {
  delete codigo_pagamento;
}

void TUCodigoPagamento::testarCenarioSucesso() {
  try {
    codigo_pagamento->setCodigo(CODIGO_VALIDO);
    if(codigo_pagamento->getCodigo() != CODIGO_VALIDO){
      estado = FALHA;
    }
  } catch(invalid_argument &excecao) {
    estado = FALHA;
  }
}

void TUCodigoPagamento::testarCenarioFalha() {
  try {
    codigo_pagamento->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(invalid_argument &excecao) {
    return;
  }
}

int TUCodigoPagamento::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();

  return estado;
}
