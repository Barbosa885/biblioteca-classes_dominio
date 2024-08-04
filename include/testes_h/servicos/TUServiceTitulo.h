#ifndef TU_SERVICE_TITULO_H
#define TU_SERVICE_TITULO_H

#include "../../servico_h/ServicoTitulo.h"

class TUServiceTitulo {
private:
    ServicoTitulo* servicoTitulo;
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

#endif // TU_SERVICE_TITULO_H
