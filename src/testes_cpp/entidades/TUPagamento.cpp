#include "../../../include/testes_h/entidades/TUPagamento.h"

using namespace std;

const string TUPagamento::CODIGO_VALIDO = "12345678";
const string TUPagamento::DATA_VALIDA = "12-12-2021";
const float TUPagamento::VALOR_VALIDO = 80.0;
const string TUPagamento::ESTADO_VALIDO = "Previsto";

void TUPagamento::setUp() {
  pagamento = new Pagamento();
  estado = SUCESSO;
}

void TUPagamento::tearDown() {
  delete pagamento;
}

void TUPagamento::testarCenarioSucesso() {
  try {
    CodigoPagamento codigoPagamento;
    codigoPagamento.setCodigo(CODIGO_VALIDO);
    pagamento->setCodigoPagamento(codigoPagamento);
    if (pagamento->getCodigoPagamento().getCodigo() != CODIGO_VALIDO) {
      estado = FALHA;
    }
  } catch(invalid_argument excecao) {
    estado = FALHA;
  }

  try {
    Data data;
    data.setData(DATA_VALIDA);
    pagamento->setData(data);
    if (pagamento->getData().getData() != DATA_VALIDA) {
      estado = FALHA;
    }
  } catch(invalid_argument excecao) {
    estado = FALHA;
  }

  try {
    Percentual percentual;
    percentual.setPercentual(VALOR_VALIDO);
    pagamento->setPercentual(percentual);
    if (pagamento->getPercentual().getPercentual() != VALOR_VALIDO) {
      estado = FALHA;
    }
  } catch(invalid_argument excecao) {
    estado = FALHA;
  }

  try {
    Estado estadoPagamento;
    estadoPagamento.setEstado(ESTADO_VALIDO);
    pagamento->setEstado(estadoPagamento);
    if (pagamento->getEstado().getEstado() != ESTADO_VALIDO) {
      estado = FALHA;
    }
  } catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

int TUPagamento::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();

  return estado;
}
