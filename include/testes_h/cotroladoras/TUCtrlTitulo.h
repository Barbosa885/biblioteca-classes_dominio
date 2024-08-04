// CtrlTituloTest.h
#ifndef TU_CTRL_TITULO_H
#define TU_CTRL_TITULO_H
#include "../../controladora_h/CtrlTitulo.h"
#include "../../servico_h/ServicoTitulo.h"

class TUCtrlTitulo {
private:
    CtrlTitulo* ctrlTitulo;
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

    // Membros estáticos devem ser declarados no header
    static const std::string CODIGO_VALIDO;
    static const std::string EMISSOR_VALIDO;
    static const std::string SETOR_VALIDO;
    static const std::string EMISSAO_VALIDA;
    static const std::string VENCIMENTO_VALIDO;
    static const float VALOR_VALIDO;

    int run();
};

#endif // TU_CTRL_TITULO_H
