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
    codigo.setValor(VALOR_VALIDO);
    cartao->setCodigo(codigo);
    if(cartao->getCodigo().getValor() != VALOR_VALIDO)
        estado = FALHA;

    Prioridade prioridade;
    prioridade.setValor(VALOR_VALIDO);
    cartao->setPrioridade(prioridade);
    if(cartao->getPrioridade().getValor() != VALOR_VALIDO)
        estado = FALHA;
}

int TUCartao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
