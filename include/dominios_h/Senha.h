/**
 * @file Senha.h
 * @brief Definição da classe Senha.
 *
 * @brief Esta classe é usada para manipular e verificar uma string de senha.
 *
 * Autor: Gabriel Kenzo Nomura ()
 */

class SENHA{
    private:
        /** 
         * @brief Variável de senha.
         * 
         * Esta variável armazena a string de senha que a classe manipula.
         */
        string senha;
        
        /** 
         * @brief Método de verificação.
         * 
         * Este método privado é usado para verificar a string de senha de acordo com algum critério.
         * @param string A senha a ser verificada.
         */
        void isValid(const string &senha);
    
    public:
        /** 
         * @brief Método GetSenha.
         * 
         * Este método é usado para obter o valor da variável de senha.
         * @return Retorna a string de senha.
         */
        string GetSenha();
        
        /** 
         * @brief Método SetSenha.
         * 
         * Este método é usado para definir o valor da variável de senha.
         * @param string A nova string de senha.
         */
        void SetSenha(string);
};

inline void SENHA::SetSenha(string senha){
    verifica(senha);
    this -> senha = senha;
}

inline string SENHA::GetSenha() {
    return senha;
}
