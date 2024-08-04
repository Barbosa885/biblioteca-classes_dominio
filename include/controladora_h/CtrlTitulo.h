// CtrlTitulo.h
#ifndef CTRL_TITULO_H
#define CTRL_TITULO_H

#include "../../include/servico_h/ServicoTitulo.h"
#include "../../include/dominios_h/CodigoTitulo.h"
#include "../../include/dominios_h/Nome.h"
#include "../../include/dominios_h/Setor.h"
#include "../../include/dominios_h/Data.h"
#include "../../include/dominios_h/Dinheiro.h"
#include "../../include/entidades_h/Titulo.h"

/**
 * @brief Classe de controle para gerenciamento de títulos.
 *
 * Esta classe é responsável por realizar as operações de CRUD (Create, Read, Update, Delete)
 * sobre os títulos, utilizando os serviços de persistência fornecidos pela camada de serviço.
 */
class CtrlTitulo {
private:
    ServicoTitulo* servico; // Ponteiro para o serviço de títulos

public:
    /**
     * @brief Construtor da classe CtrlTitulo.
     *
     * @param servico Ponteiro para o serviço de títulos utilizado pela classe.
     */
    CtrlTitulo(ServicoTitulo* servico);

    /**
     * @brief Função para executar o menu de gerenciamento de títulos.
     */
    void executar();

    /**
     * @brief Função para criar um novo título.
     */
    void criarTitulo();

    /**
     * @brief Função para listar todos os títulos.
     */
    void listarTitulos();

    /**
     * @brief Função para consultar um título específico pelo código.
     */
    void consultarTitulo();

    /**
     * @brief Função para atualizar os dados de um título existente.
     */
    void atualizarTitulo();

    /**
     * @brief Função para excluir um título pelo código.
     */
    void excluirTitulo();
};

#endif // CTRL_TITULO_H
