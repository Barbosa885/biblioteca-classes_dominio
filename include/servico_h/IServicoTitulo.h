#ifndef ISERVICOTITULO_H
#define ISERVICOTITULO_H

#include <vector>
#include "../entidades_h/Titulo.h"
#include "../dominios_h/CodigoTitulo.h"

/**
 * @brief Interface para o serviço de gerenciamento de títulos.
 *
 * Define as operações disponíveis para o gerenciamento de títulos,
 * que devem ser implementadas pelas classes de serviço.
 */
class IServicoTitulo {
public:
    virtual ~IServicoTitulo() = default;

    /**
     * @brief Cria um novo título.
     *
     * @param titulo O título a ser criado.
     */
    virtual void criarTitulo(const Titulo& titulo) = 0;

    /**
     * @brief Obtém um título pelo código.
     *
     * @param codigo O código do título a ser obtido.
     * @return O título correspondente ao código fornecido.
     */
    virtual Titulo obterTitulo(const CodigoTitulo& codigo) = 0;

    /**
     * @brief Lista todos os títulos.
     *
     * @return Um vetor contendo todos os títulos.
     */
    virtual std::vector<Titulo> listarTitulos() = 0;

    /**
     * @brief Atualiza um título existente.
     *
     * @param titulo O título a ser atualizado.
     */
    virtual void atualizarTitulo(const Titulo& titulo) = 0;

    /**
     * @brief Exclui um título pelo código.
     *
     * @param codigo O código do título a ser excluído.
     */
    virtual void excluirTitulo(const CodigoTitulo& codigo) = 0;
};

#endif // ISERVICOTITULO_H
