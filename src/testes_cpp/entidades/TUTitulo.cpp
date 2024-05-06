#include "../../../include/testes_h/entidades/TUTitulo.h"

using namespace std;

const string TUTitulo::CODIGO_VALIDO = "LCA3241AG84";
const string TUTitulo::EMISSOR_VALIDO = "Gustavo";
const string TUTitulo::SETOR_VALIDO = "Finanças";
const string TUTitulo::EMISSAO_VALIDA = "12-12-2022";
const string TUTitulo::VENCIMENTO_VALIDO = "12-12-2023";
const float TUTitulo::VALOR_VALIDO = 100.0;

void TUTitulo::setUp() {
  titulo = new Titulo();
  estado = SUCESSO;
}

void TUTitulo::tearDown() {
  delete titulo;
}

void TUTitulo::testarCenarioSucesso() {
  try {
    CodigoTitulo codigoTitulo;
    codigoTitulo.setCodigoTitulo(CODIGO_VALIDO);
    titulo->setCodigoTitulo(codigoTitulo);
    
    Nome emissor;
    emissor.setNome(EMISSOR_VALIDO);
    titulo->setEmissor(emissor);

    Setor setor;
    setor.setSetor(SETOR_VALIDO);
    titulo->setSetor(setor);

    Data emissao;
    emissao.setData(EMISSAO_VALIDA);
    titulo->setEmissao(emissao);

    Data vencimento;
    vencimento.setData(VENCIMENTO_VALIDO);
    titulo->setVencimento(vencimento);

    Dinheiro valor;
    valor.setValor(VALOR_VALIDO);
    titulo->setValor(valor);

    if (titulo->getCodigoTitulo().getCodigoTitulo() != CODIGO_VALIDO) estado = FALHA;

    if (titulo->getEmissor().getNome() != EMISSOR_VALIDO) estado = FALHA;

    if (titulo->getSetor().getSetor() != SETOR_VALIDO) estado = FALHA;

    if (titulo->getEmissao().getData() != EMISSAO_VALIDA) estado = FALHA;

    if (titulo->getVencimento().getData() != VENCIMENTO_VALIDO) estado = FALHA;

    if (titulo->getValor().getValor() != VALOR_VALIDO) estado = FALHA;
  } catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

int TUTitulo::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();

  return estado;
}
