#include <regex>
#include <stdexcept>
#include <string>
#include <sstream>
#include "../include/Email.h"

using namespace std;

Email::Email()
{
    //ctor
}

Email::~Email()
{
    //dtor
}

void Email::setEmail(const string& email)
{
  if(!isValid(email))
  {
    throw invalid_argument("Invalid email address");
  }
  this->email.str(email);
}

const stringstream& Email::getEmail() const 
{
  return email;
}

bool Email::isValid(const string& email)
{
  const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  istringstream ss(email);

  sregex_token_iterator it(email.begin(), email.end(), pattern, 0);
  sregex_token_iterator end;
  return regex_match(email, pattern);

  while (it != end)
  {
    string part = it->str();
    if(regex_match(part, pattern))
    {
      it++;
    } else {
      return false;
    }
  }

}
