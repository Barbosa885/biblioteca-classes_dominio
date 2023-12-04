#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "cntrlservices.h"
#include <string>
#include <iostream>

using namespace std;

class RegistrationController {
  private:
    Sconta servicosConta;

  public:
    bool registerUser(const string& email, const string& name, const string& password);
};

class BoardController {
  private:
    SQuadro servicosQuadro;

  public:
    BoardController();

    bool createBoard(const string& userEmail, const string& code, const string& name, const string& description, int limit);
    bool editBoard(const string& userEmail, const string& boardCode, const optional<string>& newName, const optional<string>& newDescription, const optional<int>& newLimit);
    bool deleteBoard(const string& userEmail, const string& boardCode);
    void viewBoard(const string& userEmail, const string& boardCode);
};

class CardController {
  private:
    SCartao servicosCartao;

  public:
    CardController();

    bool createCard(const string& boardCode, const string& cardCode, const string& name, const string& description, const string& column);
    bool editCard(const string& boardCode, const string& cardCode, const optional<string>& newName, const optional<string>& newDescription, const optional<string>& newColumn);
    bool deleteCard(const string& boardCode, const string& cardCode);
};

#endif // CONTROLADOR_HPP
