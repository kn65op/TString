#ifndef UNIQUESTRING_H
#define UNIQUESTRING_H

#include <set>
#include <string>

template <class String> class UniqueString
{
public:
  UniqueString() : UniqueString("UniqueString")
  {}
  
  UniqueString(String s) : content(storeUniqueString(s))
  {
  }
  
  operator String () const
  {
    return getContent();
  }     
  
  String getContent() const
  {
    return *content;
  }
  
  bool empty() const
  {
    return content->empty();
  }
  
  ~UniqueString()
  {
    names_in_use.erase(content);
  }
  
  UniqueString(const UniqueString &) = delete;
  UniqueString& operator=(const UniqueString &) = delete;
  UniqueString(const UniqueString &&) = delete;
  UniqueString& operator=(const UniqueString &&) = delete;
  
private:
  typedef std::set<String> Container;
  typedef typename Container::iterator ContainerIterator;
  
  ContainerIterator storeUniqueString(String proposition)
  {
    String to_add = findUniqueName(proposition);
    auto ret = names_in_use.insert(to_add);
    return ret.first;
  }
    
  
  String findUniqueName(String proposition)
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
  
  ContainerIterator content;
  static Container names_in_use;
};

template <class String> typename UniqueString<String>::Container UniqueString<String>::names_in_use;

template <class String> bool operator==(const String &s, const UniqueString<String> &us)
{
  return s == static_cast<String>(us);
}

template <class String> bool operator==(const UniqueString<String> &us, const String &s)
{
  return s == us;
}

template <class String> bool operator!=(const String &s, const UniqueString<String> &us)
{
  return !(s == us);
}

template <class String> bool operator!=(const UniqueString<String> &us, const String &s)
{
  return s != us;
}

template <class String> bool operator==(const UniqueString<String> &us1, const UniqueString<String> &us2)
{
  return static_cast<String>(us1) == us2;
}

template <class String> bool operator!=(const UniqueString<String> &us1, const UniqueString<String> &us2)
{
  return static_cast<String>(us1) != us2;
}

#endif // UNIQUESTRING_H
