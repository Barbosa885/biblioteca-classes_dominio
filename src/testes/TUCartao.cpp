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
    codigo.setValor(CODIGO_VALIDO);
    cartao->setCodigo(codigo);
    if(cartao->getCodigo().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;

    TEXTO nome;
    nome.setTexto(TEXTO_VALIDO);
    cartao->setNome(nome);
    if(cartao->getNome().getTexto() != TEXTO_VALIDO)
        estado = FALHA;

    TEXTO descricao;
    descricao.setTexto(DESCRICAO_VALIDA);
    cartao->setDescricao(descricao);
    if(cartao->getDescricao().getTexto() != DESCRICAO_VALIDA)
        estado = FALHA;

    COLUNA coluna;
    coluna.SetColuna(COLUNA_VALIDA);
    cartao->SetColuna(coluna);
    if(cartao->GetColuna().GetColuna() != COLUNA_VALIDA)
        estado = FALHA;
}

int TUCartao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
