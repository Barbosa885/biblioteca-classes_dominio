#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "./dominios_h/Cpf.h"
#include "./dominios_h/CodigoTitulo.h"
#include "./dominios_h/CodigoPagamento.h"
#include "./entidades_h/Titulo.h"
#include "./entidades_h/Conta.h"
#include "./entidades_h/Pagamento.h"

#include <map>
#include <vector>

using namespace std;

/**
 * @class ContainerConta
 * @brief Singleton que gerencia objetos do tipo Conta.
 */
class ContainerConta {
private:
    map<string, Conta> container; ///< Contêiner que armazena objetos Conta com o CPF como chave.
    static ContainerConta *instancia; ///< Instância única da classe.
    
    /**
     * @brief Construtor privado para implementar o padrão Singleton.
     */
    ContainerConta() {};
    
public:
    /**
     * @brief Obtém a instância única do ContainerConta.
     * @return Ponteiro para a instância única de ContainerConta.
     */
    static ContainerConta* getInstancia();
    
    /**
     * @brief Cria uma nova Conta.
     * @param conta Objeto Conta a ser criado.
     * @return true se a conta foi criada com sucesso, false caso contrário.
     */
    bool criar(Conta conta);
    
    /**
     * @brief Exclui uma Conta.
     * @param cpf CPF da conta a ser excluída.
     * @return true se a conta foi excluída com sucesso, false caso contrário.
     */
    bool excluir(Cpf cpf);
    
    /**
     * @brief Visualiza uma Conta.
     * @param conta Ponteiro para o objeto Conta a ser visualizado.
     * @return Objeto Conta visualizado.
     */
    Conta visualizar(Conta* conta);
    
    /**
     * @brief Verifica se uma Conta existe.
     * @param conta Ponteiro para o objeto Conta a ser verificado.
     * @return true se a conta existe, false caso contrário.
     */
    bool existe(Conta* conta);
    
    /**
     * @brief Edita uma Conta existente.
     * @param conta Objeto Conta atualizado.
     * @return true se a conta foi editada com sucesso, false caso contrário.
     */
    bool editar(Conta conta);
};

/**
 * @class ContainerTitulos
 * @brief Singleton que gerencia objetos do tipo Titulo.
 */
class ContainerTitulos {
private:
    map<string, vector<Titulo>> container; ///< Contêiner que armazena vetores de objetos Titulo com o CPF como chave.
    static ContainerTitulos* instancia; ///< Instância única da classe.
    
    /**
     * @brief Construtor privado para implementar o padrão Singleton.
     */
    ContainerTitulos() {};
    
public:
    /**
     * @brief Obtém a instância única do ContainerTitulos.
     * @return Ponteiro para a instância única de ContainerTitulos.
     */
    static ContainerTitulos* getInstancia();
    
    /**
     * @brief Cria um novo Titulo.
     * @param cpf CPF do proprietário do Titulo.
     * @param titulo Objeto Titulo a ser criado.
     * @return true se o titulo foi criado com sucesso, false caso contrário.
     */
    bool criarTitulo(Cpf& cpf, Titulo& titulo);
    
    /**
     * @brief Exclui um Titulo.
     * @param cpf CPF do proprietário do Titulo.
     * @param codigoTitulo Código do Titulo a ser excluído.
     * @return true se o titulo foi excluído com sucesso, false caso contrário.
     */
    bool excluirTitulo(Cpf& cpf, CodigoTitulo& codigoTitulo);
    
    /**
     * @brief Visualiza Titulos.
     * @param cpf CPF do proprietário dos Titulos.
     * @return Vetor de objetos Titulo visualizados.
     */
    vector<Titulo> visualizarTitulos(Cpf& cpf);
    
    /**
     * @brief Verifica se um Titulo existe.
     * @param codigoDeTitulo Código do Titulo a ser verificado.
     * @return true se o titulo existe, false caso contrário.
     */
    bool existe(CodigoTitulo& codigoDeTitulo);
    
    /**
     * @brief Edita um Titulo existente.
     * @param cpf CPF do proprietário do Titulo.
     * @param tituloAtualizado Objeto Titulo atualizado.
     * @return true se o titulo foi editado com sucesso, false caso contrário.
     */
    bool editarTitulo(Cpf& cpf, Titulo& tituloAtualizado);
};

/**
 * @class ContainerPagamentos
 * @brief Singleton que gerencia objetos do tipo Pagamento.
 */
class ContainerPagamentos {
private:
    map<string, vector<Pagamento>> container; ///< Contêiner que armazena vetores de objetos Pagamento com o CPF como chave.
    static ContainerPagamentos* instancia; ///< Instância única da classe.
    
    /**
     * @brief Construtor privado para implementar o padrão Singleton.
     */
    ContainerPagamentos() {};
    
public:
    /**
     * @brief Obtém a instância única do ContainerPagamentos.
     * @return Ponteiro para a instância única de ContainerPagamentos.
     */
    static ContainerPagamentos* getInstancia();
    
    /**
     * @brief Cria um novo Pagamento.
     * @param codigoDeTitulo Código do Titulo relacionado ao Pagamento.
     * @param pagamento Objeto Pagamento a ser criado.
     * @return true se o pagamento foi criado com sucesso, false caso contrário.
     */
    bool criarPagamento(CodigoTitulo& codigoDeTitulo, Pagamento& pagamento);
    
    /**
     * @brief Exclui um Pagamento.
     * @param codigoDePagamento Código do Pagamento a ser excluído.
     * @return true se o pagamento foi excluído com sucesso, false caso contrário.
     */
    bool excluirPagamento(CodigoPagamento& codigoDePagamento);
    
    /**
     * @brief Exclui todos os Pagamentos relacionados a um Titulo.
     * @param codigoDeTitulo Código do Titulo cujos pagamentos serão excluídos.
     * @return true se os pagamentos foram excluídos com sucesso, false caso contrário.
     */
    bool excluirPagamentosPorTitulo(CodigoTitulo& codigoDeTitulo);
    
    /**
     * @brief Visualiza Pagamentos.
     * @param codigoDeTitulo Código do Titulo relacionado aos Pagamentos.
     * @return Vetor de objetos Pagamento visualizados.
     */
    vector<Pagamento> visualizarPagamentos(CodigoTitulo& codigoDeTitulo);
    
    /**
     * @brief Edita um Pagamento existente.
     * @param codigoDeTitulo Código do Titulo relacionado ao Pagamento.
     * @param pagamentoAtualizado Objeto Pagamento atualizado.
     * @return true se o pagamento foi editado com sucesso, false caso contrário.
     */
    bool editarPagamento(CodigoTitulo& codigoDeTitulo, Pagamento& pagamentoAtualizado);
};

#endif // CONTAINERS_H_INCLUDED
