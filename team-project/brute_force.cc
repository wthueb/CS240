#include <string>
#include <iostream>


bool brute_force(const std::string& password, int length, const std::string& chars, std::string attempt=""){
  if (attempt.compare(password) == 0){
    return true;
  }
  if (length > 0){
    for (char c: chars){
      std::string new_attempt = attempt + c;
      if (brute_force(password, length-1, chars, new_attempt)){
        return true;
      }
    }
  }
  return false;
}

bool brute_force_crack(const std::string& password, int max_characters){
  std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  for (int i = 1; i <= max_characters; i++){
    if(brute_force(password, i, chars)){
      return true;
    }
  }
  return false;

}
