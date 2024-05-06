#ifndef CODIGO_TITULO_H
#define CODIGO_TITULO_H

#include <iostream>
#include <vector>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um código de título de renda fixa.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de códigos de título de renda fixa,
 * incluindo a validação do código e a manipulação de seus componentes.
 */
class CodigoTitulo {
  private:

    /** 
     * @brief Atributo que armazena o código de título.
     */
    string codigoTitulo;

    /**
     * @brief Método responsável por validar um código de título.
     *
     * Este método verifica se um código de título é válido, seguindo as seguintes regras:
     * - O código de título deve possuir 11 caracteres.
     * - Cada caractere após o prefixo deve ser um dígito (0-9) ou letra maiúscula (A-Z).
     *
     * @param codigoTitulo O código de título a ser validado.
     * @throw invalid_argument caso o código de título seja inválido.
     */
    void validar(string codigoTitulo);

    /**
     * @brief Constante que armazena os títulos válidos pre-definidos.
     */
    static const vector<string> TITULOS_VALIDOS;

    /**
     * @brief Constante que armazena o tamanho máximo do código de título.
     */
    static const int TAMANHO_MAX = 11;

  public :

    /**
     * @brief Construtor padrão da classe.
     */
    CodigoTitulo();

    /**
     * @brief Destrutor padrão da classe.
     */
    virtual ~CodigoTitulo();

    /**
     * @brief Método responsável por atribuir um código de título.
     *
     * @param codigoTitulo O código de título a ser atribuído.
     */
    void setCodigoTitulo(string codigoTitulo);

    /**
     * @brief Método responsável por recuperar o código de título.
     *
     * @return O código de título.
     */
    string getCodigoTitulo() const;
};

inline string CodigoTitulo::getCodigoTitulo() const {
  return codigoTitulo;
}

#endif // CODIGO_TITULO_H
