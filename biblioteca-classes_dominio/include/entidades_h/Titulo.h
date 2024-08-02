#ifndef TITULO_H
#define TITULO_H

#include <iostream>
#include "../dominios_h/CodigoTitulo.h"
#include "../dominios_h/Nome.h"
#include "../dominios_h/Setor.h"
#include "../dominios_h/Data.h"
#include "../dominios_h/Dinheiro.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;


/**
 * @class Titulo
 * @brief Representa um título, que pode ser usado para representar títulos de documentos, títulos de livros, etc.
 *
 * Esta classe encapsula informações sobre um título, incluindo seu código, emissor, setor, data de emissão, data de vencimento e valor.
 */
class Titulo {
  private:
    /**
     * @brief Armazena o código do título.
     */
    CodigoTitulo codigoTitulo;

    /**
     * @brief Armazena o nome do emissor do título.
     */
    Nome emissor;

    /**
     * @brief Armazena o setor ao qual o título pertence.
     */
    Setor setor;

    /**
     * @brief Armazena a data de emissão do título.
     */
    Data emissao;

    /**
     * @brief Armazena a data de vencimento do título.
     */
    Data vencimento;

    /**
     * @brief Armazena o valor do título.
     */
    Dinheiro valor;

  public:
    /**
     * @brief Define o código do título.
     *
     * @param codigoTitulo O novo código para o título.
     */
    void setCodigoTitulo(const CodigoTitulo& codigoTitulo);

    /**
     * @brief Define o emissor do título.
     *
     * @param emissor O novo emissor para o título.
     */
    void setEmissor(const Nome& emissor);

    /**
     * @brief Define o setor do título.
     *
     * @param setor O novo setor para o título.
     */
    void setSetor(const Setor& setor);

    /**
     * @brief Define a data de emissão do título.
     *
     * @param emissao A nova data de emissão para o título.
     */
    void setEmissao(const Data& emissao);

    /**
     * @brief Define a data de vencimento do título.
     *
     * @param vencimento A nova data de vencimento para o título.
     */
    void setVencimento(const Data& vencimento);

    /**
     * @brief Define o valor do título.
     *
     * @param valor O novo valor para o título.
     */
    void setValor(const Dinheiro& valor);

    /**
     * @brief Obtém o código do título.
     *
     * @return O código atual do título.
     */
    CodigoTitulo getCodigoTitulo() const;

    /**
     * @brief Obtém o emissor do título.
     *
     * @return O emissor atual do título.
     */
    Nome getEmissor() const;

    /**
     * @brief Obtém o setor do título.
     *
     * @return O setor atual do título.
     */
    Setor getSetor() const;

    /**
     * @brief Obtém a data de emissão do título.
     *
     * @return A data de emissão atual do título.
     */
    Data getEmissao() const;

    /**
     * @brief Obtém a data de vencimento do título.
     *
     * @return A data de vencimento atual do título.
     */
    Data getVencimento() const;

    /**
     * @brief Obtém o valor do título.
     *
     * @return O valor atual do título.
     */
    Dinheiro getValor() const;
};

inline void Titulo::setCodigoTitulo(const CodigoTitulo& codigoTitulo) {
  this->codigoTitulo = codigoTitulo;
}

inline void Titulo::setEmissor(const Nome& emissor) {
  this->emissor = emissor;
}

inline void Titulo::setSetor(const Setor& setor) {
  this->setor = setor;
}

inline void Titulo::setEmissao(const Data& emissao) {
  this->emissao = emissao;
}

inline void Titulo::setVencimento(const Data& vencimento) {
  this->vencimento = vencimento;
}

inline void Titulo::setValor(const Dinheiro& valor) {
  this->valor = valor;
}

inline CodigoTitulo Titulo::getCodigoTitulo() const {
  return codigoTitulo;
}

inline Nome Titulo::getEmissor() const {
  return emissor;
}

inline Setor Titulo::getSetor() const {
  return setor;
}

inline Data Titulo::getEmissao() const {
  return emissao;
}

inline Data Titulo::getVencimento() const {
  return vencimento;
}

inline Dinheiro Titulo::getValor() const {
  return valor;
}

#endif // TITULO_H
