#ifndef UNIQUESTRING_H
#define UNIQUESTRING_H

#include <set>
#include <string>

template <class String> class UniqueString : public String
{
public:
  UniqueString() : UniqueString(getUniqueName("UniqueString"))
  {}
  
  UniqueString(String s) : String(s)
  {
    names_in_use.insert(s);
  }
  
private:
  String getUniqueName(String proposition)
  {
    if (names_in_use.find(proposition) == names_in_use.end())
    {
      return proposition;
    }
    unsigned i = 2;
    std::string proposition_accumulator = proposition + std::to_string(i++);
    while (names_in_use.find(proposition_accumulator) != names_in_use.end())
    {
      proposition_accumulator = proposition + std::to_string(i++);
    }
    return proposition_accumulator;
  }
  
  typedef std::set<String> Container;
  static Container names_in_use;
};

template <class String> typename UniqueString<String>::Container UniqueString<String>::names_in_use;

#endif // UNIQUESTRING_H
