#include "../../../include/testes_h/dominios/TUEstado.h"

const string TUEstado::ESTADO_VALIDO = "Previsto";
const string TUEstado::ESTADO_INVALIDO = "Invalido";

void TUEstado::setUp(){
  estado = new Estado();
  estadoAtual = SUCESSO;
}

void TUEstado::tearDown(){
  delete estado;
}

void TUEstado::testarCenarioSucesso(){
  try{
    estado->setEstado(ESTADO_VALIDO);
    if (estado->getEstado() != ESTADO_VALIDO){
      estadoAtual = FALHA;
    }
  } catch(invalid_argument &excecao){
    estadoAtual = FALHA;
  }
}

void TUEstado::testarCenarioFalha(){
  try{
    estado->setEstado(ESTADO_INVALIDO);
    estadoAtual = FALHA;
  } catch(invalid_argument &excecao){
    return;
  }
}

int TUEstado::run(){

  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estadoAtual;
}
