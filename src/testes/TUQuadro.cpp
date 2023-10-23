#include "../../include/testes_h/TUQuadro.h"

TUQuadro::TUQuadro()
{
  //ctor
}

TUQuadro::~TUQuadro()
{
  //dtor
}

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
    cout << "Testando quadro: " << quadro->getCodigo().getCodigo() << endl;
    try {
      quadro->setCodigo(codigo);
      if (quadro->getCodigo().getCodigo() != CODIGO_VALIDO)
      {
        cout << "Falha: " << quadro->getCodigo().getCodigo() << endl;
        estado = FALHA;
      } else {
        cout << "Sucesso: " << quadro->getCodigo().getCodigo() << endl;
        estado = FALHA;
      }
    } catch (invalid_argument &excecao) {
      cout << "Exceção lançada: " << excecao.what() << endl;
      estado = FALHA;
    }

    Texto nome;
    nome.setTexto(NOME_VALIDO);
    quadro->setNome(nome);
    try {
      quadro->setNome(nome);
      if (quadro->getNome().getTexto() != NOME_VALIDO)
      {
        estado = FALHA;
        cout << "Falha: " << quadro->getNome().getTexto() << endl;
      } else {
        cout << "Sucesso: " << quadro->getNome().getTexto() << endl;
        estado = FALHA;
      }
    } catch (invalid_argument &excecao) {
      cout << "Exceção lançada: " << excecao.what() << endl;
      estado = FALHA;
    }

    Texto descricao;
    descricao.setTexto(DESCRICAO_VALIDA);
    quadro->setDescricao(descricao);
    try {
      quadro->setDescricao(descricao);
      if (quadro->getDescricao().getTexto() != DESCRICAO_VALIDA)
      {
        cout << "Falha: " << quadro->getDescricao().getTexto() << endl;
        estado = FALHA;
      } else {
        cout << "Sucesso: " << quadro->getDescricao().getTexto() << endl;
        estado = FALHA;
      }
    } catch (invalid_argument &excecao) {
      cout << "Exceção lançada: " << excecao.what() << endl;
      estado = FALHA;
    }

    Limite limite;
    limite.setLimite(LIMITE_VALIDO);
    quadro->setLimite(limite);
    try {
      quadro->setLimite(limite);
      if (quadro->getLimite().getLimite() != LIMITE_VALIDO)
      {
        cout << "Falha: " << quadro->getLimite().getLimite() << endl;
        estado = FALHA;
      } else {
        cout << "Sucesso: " << quadro->getLimite().getLimite() << endl;
        estado = FALHA;
      }
    } catch (invalid_argument &excecao) {
      cout << "Exceção lançada: " << excecao.what() << endl;
      estado = FALHA;
    }

    cout << "Sucesso: " << quadro->getLimite().getLimite() << endl;
}

void TUQuadro::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
}
