#include <regex>
#include <stdexcept>
#include <string>
#include <sstream>
#include "../../include/dominios_h/Email.h"

using namespace std;

Email::Email()
{

}

Email::~Email()
{

}

void Email::setEmail(const string& email)
{
  isValid(email);
  this->email.str(email);
}


void Email::isValid(const string& email)
{
  const regex pattern("^([a-zA-Z0-9]{2,10})([.])?([a-zA-Z0-9]{1,})@([a-zA-Z0-9]{2,20})([.][a-zA-Z0-9]{2,20})+$");
  istringstream ss(email);

  sregex_token_iterator it(email.begin(), email.end(), pattern, 0);
  sregex_token_iterator end;
  regex_match(email, pattern);

  while (it != end)
  {
    string part = it->str();
    if(regex_match(part, pattern))
    {
      it++;
    } else {
      throw invalid_argument("Endereço de email inválido");
    }
  }
}
