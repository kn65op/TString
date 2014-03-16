#ifndef UNIQUESTRING_H
#define UNIQUESTRING_H

template <class String> class UniqueString
{
public:
  UniqueString() : content("Non empty")
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

#endif // UNIQUESTRING_H
