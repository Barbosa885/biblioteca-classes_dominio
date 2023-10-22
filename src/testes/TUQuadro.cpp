#include "../testes_h/TUQuadro.h"
#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Limite.h"

void TUQuadro::setUp(){
    quadro = new Quadro();
    estado = SUCESSO;
}

void TUQuadro::tearDown(){
    delete quadro;
}

void TUQuadro::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(CODIGO_VALIDO);
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
