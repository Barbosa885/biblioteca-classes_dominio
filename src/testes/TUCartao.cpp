#include "../../include/testes_h/TUCartao.h"

TUCartao::TUCartao()
{
  //ctor
}

TUCartao::~TUCartao()
{
  //dtor
}

void TUCartao::setUp(){
    cartao = new Cartao();
    estado = SUCESSO;
}

void TUCartao::tearDown(){
    delete cartao;
}

void TUCartao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setCodigo(CODIGO_VALIDO);
    cartao->setCodigo(codigo);
    cout << "Testando cartao: " << cartao->getCodigo().getCodigo() << endl;
    if(cartao->getCodigo().getCodigo() != CODIGO_VALIDO)
    {
      cout << "Falha: " << cartao->getCodigo().getCodigo() << endl;
      estado = FALHA;
    }

    Texto nome;
    nome.setTexto(NOME_VALIDO);
    cartao->setNome(nome);
    if(cartao->getNome().getTexto() != NOME_VALIDO)
    {
      estado = FALHA;
      cout << "Falha: " << cartao->getNome().getTexto() << endl;
    }

    Texto descricao;
    descricao.setTexto(DESCRICAO_VALIDA);
    cartao->setDescricao(descricao);
    if(cartao->getDescricao().getTexto() != DESCRICAO_VALIDA)
    {
      cout << "Falha: " << cartao->getDescricao().getTexto() << endl;
      estado = FALHA;
    }

    Coluna coluna;
    coluna.setColuna(COLUNA_VALIDA);
    cartao->setColuna(coluna);
    if(cartao->getColuna().getColuna() != COLUNA_VALIDA)
    {
      cout << "Falha: " << cartao->getColuna().getColuna() << endl;
      estado = FALHA;
    }
    cout << "Sucesso: " << cartao->getColuna().getColuna() << endl;
}

void TUCartao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
}
