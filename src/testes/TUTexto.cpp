#include <iostream>
#include "../../include/testes_h/TUTexto.h"
#include "../../include/dominios_h/Texto.h"

TUTexto::TUTexto()
{
    //ctor
}

TUTexto::~TUTexto()
{
    //dtor
}

using namespace std;

const string TUTexto::TEXTOS_VALIDOS[] = {
    "Ab1.C ",
    "Z1,y x",
    "This is a valid text.",
    "Another valid Text, 1!"
};

const string TUTexto::TEXTOS_INVALIDOS[] = {
    "invalid text",
    "Invalid text.with punctuation and capitals.",
    "Invalid text with a Double  Space",
    "Double Punctuation!?",
    "áçéñtuaçãoInválida",
    "valid text with leading lowercase",
    "Erro",
    "Pneumoultramicroscopicossilicovulcanoconiótico"
}

void TUTexto::setUp(){  /** Configura o ambiente de teste. */
    texto = new TEXTO();
    estado = SUCESSO;
}

void TUTexto::tearDown(){ /** Limpa o ambiente de teste, excluindo a instância TEXTO. */
    delete texto;
}

void TUTexto::testarCenarioSucesso(){ /** Testa um cenário de sucesso em que o texto é definido como um texto válido. */
    for (const string &textoValido : TEXTOS_VALIDOS){
        try{
            texto->setTexto(textoValido);
            if (texto->getTexto() != textoValido)
                estado = FALHA;
        }
        catch(invalid_argument &excecao){
            estado = FALHA;
        }
    }
}

void TUTexto::testarCenarioFalha(){ /** Testa um cenário de falha em que o texto é definido como um texto inválido. */
    for (const string &textoInvalido : TEXTOS_INVALIDOS){
        try{
            texto->setTexto(textoInvalido);
            estado = FALHA;
        }
        catch(invalid_argument &excecao){
            if (texto->getTexto() == textoInvalido)
                estado = FALHA;
        }
    }
}

void TUTexto::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
}
