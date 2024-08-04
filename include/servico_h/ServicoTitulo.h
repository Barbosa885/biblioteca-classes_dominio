// ServicoTitulo.h
#ifndef SERVICOTITULO_H
#define SERVICOTITULO_H

#include "IServicoTitulo.h"
#include "../persistencia_h/TituloOAD.h"

/**
 * @brief Implementação da interface IServicoTitulo para operações de gerenciamento de títulos.
 *
 * Esta classe implementa os métodos de criação, obtenção, listagem, atualização e exclusão de títulos,
 * utilizando um objeto de acesso a dados (OAD) para persistência.
 */
class ServicoTitulo : public IServicoTitulo {
public:
    /**
     * @brief Construtor que inicializa o serviço com um objeto de acesso a dados (OAD).
     *
     * @param oad Ponteiro para o objeto de acesso a dados responsável pela persistência.
     */
    ServicoTitulo(TituloOAD* oad);

    /**
     * @brief Destrutor da classe ServicoTitulo.
     */
    ~ServicoTitulo();

    /**
     * @brief Cria um novo título.
     *
     * @param titulo O objeto Titulo a ser criado.
     */
    void criarTitulo(const Titulo& titulo) override;

    /**
     * @brief Obtém um título com base no código.
     *
     * @param codigo O código do título a ser obtido.
     * @return O objeto Titulo correspondente ao código.
     */
    Titulo obterTitulo(const CodigoTitulo& codigo) override;

    /**
     * @brief Lista todos os títulos disponíveis.
     *
     * @return Um vetor contendo todos os objetos Titulo.
     */
    std::vector<Titulo> listarTitulos() override;

    /**
     * @brief Atualiza um título existente.
     *
     * @param titulo O objeto Titulo contendo as informações atualizadas.
     */
    void atualizarTitulo(const Titulo& titulo) override;

    /**
     * @brief Exclui um título com base no código.
     *
     * @param codigo O código do título a ser excluído.
     */
    void excluirTitulo(const CodigoTitulo& codigo) override;

private:
    TituloOAD* oad; // Dependência de acesso a dados
};

#endif // SERVICOTITULO_H
