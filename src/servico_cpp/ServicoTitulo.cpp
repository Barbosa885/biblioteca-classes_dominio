#include "../../include/servico_h/ServicoTitulo.h"
#include <stdexcept>

// Construtor da classe ServicoTitulo, inicializa o objeto de acesso a dados (OAD)
ServicoTitulo::ServicoTitulo(TituloOAD* oad) : oad(oad) {}

// Destrutor da classe ServicoTitulo
ServicoTitulo::~ServicoTitulo() {
    delete oad; // Libera memória alocada para o OAD, caso tenha sido alocado dinamicamente
}

// Implementação do método para criar um novo título
void ServicoTitulo::criarTitulo(const Titulo& titulo) {
    try {
        oad->criarTitulo(titulo); // Chama o método de criação de título no OAD
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao criar título: " + std::string(e.what()));
    }
}

// Implementação do método para obter um título pelo código
Titulo ServicoTitulo::obterTitulo(const CodigoTitulo& codigo) {
    try {
        return oad->obterTitulo(codigo.getCodigoTitulo()); // Obtém o código de título como string e chama o método de obtenção de título no OAD
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao obter título: " + std::string(e.what()));
    }
}

// Implementação do método para listar todos os títulos
std::vector<Titulo> ServicoTitulo::listarTitulos() {
    try {
        return oad->listarTitulos(); // Chama o método de listagem de títulos no OAD
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao listar títulos: " + std::string(e.what()));
    }
}

// Implementação do método para atualizar um título existente
void ServicoTitulo::atualizarTitulo(const Titulo& titulo) {
    try {
        oad->atualizarTitulo(titulo); // Chama o método de atualização de título no OAD
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Erro ao atualizar título: " + std::string(e.what()));
    }
}

// Implementação do método para excluir um título pelo código
void ServicoTitulo::excluirTitulo(const CodigoTitulo& codigo) {
    try {
        oad->excluirTitulo(codigo.getCodigoTitulo()); // Obtém o código de título como string e chama o método de exclusão de título no OAD
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao excluir título: " + std::string(e.what()));
    }
}
