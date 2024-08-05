#ifndef CODIGO_PAGAMENTO_H
#define CODIGO_PAGAMENTO_H

#include <stdexcept>
#include <iostream>
#include <string>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um código de pagamento.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de códigos de pagamento,
 * incluindo a validação do código e a manipulação de seus componentes.
 */
class CodigoPagamento {
  private:

    /**
     * @brief Atributo que armazena o código de pagamento.
     */
    string codigo_pagamento;

    /**
     * @brief Método responsável por validar um código de pagamento.
     *
     * Este método verifica se um código de pagamento é válido, seguindo as seguintes regras:
     * - O código de pagamento deve possuir 8 caracteres.
     * - Cada caractere deve ser um dígito (0-9).
     * - Primeiro digito tem que ser diferente de 0.
     *
     * @param codigo_pagamento O código de pagamento a ser validado.
     * @throw invalid_argument caso o código de pagamento seja inválido.
     */
    static void validar(const string& codigo_pagamento);

  public:

    /**
     * @brief Construtor padrão da classe.
     */
    CodigoPagamento() = default;
    explicit CodigoPagamento(const string& codigo) : codigo_pagamento(codigo) {
        validar(codigo);
    }

    /**
     * @brief Destrutor padrão da classe.
     */
    virtual ~CodigoPagamento();

    /**
     * @brief Constante que armazena o tamanho do código de pagamento.
     */
    static const int CODIGO_LEN = 8;

    /**
     * @brief Método responsável por atribuir um código de pagamento.
     *
     * @param codigo_pagamento O código de pagamento a ser atribuído.
     */
    void setCodigo(const string& codigo_pagamento);

    /**
     * @brief Método responsável por recuperar o código de pagamento.
     *
     * @return O código de pagamento.
     */
    string getCodigo() const;

    // Declaração do operador de extração como amigo da classe
    friend std::istream& operator>>(std::istream& in, CodigoPagamento& codigo);

    // Declaração do operador de inserção como amigo da classe
    friend std::ostream& operator<<(std::ostream& out, const CodigoPagamento& codigo);
};

inline string CodigoPagamento::getCodigo() const{
  return codigo_pagamento;
}


#endif // CODIGO_PAGAMENTO_H
