#include "../testes_h/TUCartao.h"
#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Coluna.h"

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
    if(cartao->getCodigo().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;

    Texto nome;
    nome.setTexto(NOME_VALIDO);
    cartao->setNome(nome);
    if(cartao->getNome().getTexto() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setTexto(DESCRICAO_VALIDA);
    cartao->setDescricao(descricao);
    if(cartao->getDescricao().getTexto() != DESCRICAO_VALIDA)
        estado = FALHA;

    Coluna coluna;
    coluna.setColuna(COLUNA_VALIDA);
    cartao->setColuna(coluna);
    if(cartao->getColuna().getColuna() != COLUNA_VALIDA)
        estado = FALHA;
}

void TUCartao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
}
