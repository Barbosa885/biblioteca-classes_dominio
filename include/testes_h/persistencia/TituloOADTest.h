#ifndef TU_TITULO_OAD_H
#define TU_TITULO_OAD_H

#include "../../persistencia_h/TituloOAD.h"

class TUTituloOAD {
private:
    TituloOAD* tituloOAD;
    int estado;

    void setUp();
    void tearDown();

    void testarCriarTitulo();
    void testarObterTitulo();
    void testarAtualizarTitulo();
    void testarExcluirTitulo();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TU_TITULO_OAD_H
