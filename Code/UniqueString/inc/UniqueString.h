#ifndef UNIQUESTRING_H
#define UNIQUESTRING_H

template <class String> class UniqueString
{
public:
  UniqueString() : content("Non empty")
  {}
  
  UniqueString(String s) : content(s)
  {}
  
  operator String() const
  {
    return content;
  }
  
  bool empty() const
  {
    return content.empty();
  }
  
private:
  String content;
};

template <class String> bool             operator==(String s, UniqueString<String> us)
{
  return s == static_cast<String>(us);
}

template <class String> bool             operator==(UniqueString<String> us, String s)
{
  return s == static_cast<String>(us);
}

#endif // UNIQUESTRING_H
