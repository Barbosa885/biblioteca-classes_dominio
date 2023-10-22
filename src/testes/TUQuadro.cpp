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
    codigo.setCodigo(CODIGO_VALIDO);
    quadro->setCodigo(codigo);
    if(quadro->getCodigo().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;

    Texto nome;
    nome.setTexto(NOME_VALIDO);
    quadro->setNome(nome);
    if(quadro->getNome().getTexto() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setTexto(DESCRICAO_VALIDA);
    quadro->setDescricao(descricao);
    if(quadro->getDescricao().getTexto() != DESCRICAO_VALIDA)
        estado = FALHA;

    Limite limite;
    limite.setLimite(LIMITE_VALIDO);
    quadro->setLimite(limite);
    if(quadro->getLimite().getLimite() != LIMITE_VALIDO)
        estado = FALHA;
}

void TUQuadro::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
}
