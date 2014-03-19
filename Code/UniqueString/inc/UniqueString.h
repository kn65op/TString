#ifndef UNIQUESTRING_H
#define UNIQUESTRING_H

#include <set>
#include <string>

template <class String> class UniqueString
{
public:
  UniqueString() : UniqueString("UniqueString")
  {}
  
  UniqueString(String s) : content(getUniqueName(s))
  {
    names_in_use.insert(*this);
  }
  
  operator String () const
  {
    return content;
  }     
  
  bool empty() const
  {
    return content.empty();
  }
  
  ~UniqueString()
  {
    names_in_use.erase(content);
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
  
  String content;
  typedef std::set<String> Container;
  static Container names_in_use;
};

template <class String> typename UniqueString<String>::Container UniqueString<String>::names_in_use;

template <class String> bool operator==(String s, UniqueString<String> us)
{
  return s == static_cast<String>(us);
}

template <class String> bool operator==(UniqueString<String> us, String s)
{
  return s == us;
}

template <class String> bool operator!=(String s, UniqueString<String> us)
{
  return !(s == us);
}

template <class String> bool operator!=(UniqueString<String> us, String s)
{
  return s != us;
}

template <class String> bool operator==(UniqueString<String> us1, UniqueString<String> us2)
{
  return static_cast<String>(us1) == us2;
}

template <class String> bool operator!=(UniqueString<String> us1, UniqueString<String> us2)
{
  return static_cast<String>(us1) != us2;
}

#endif // UNIQUESTRING_H
