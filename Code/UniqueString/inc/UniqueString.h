#ifndef UNIQUESTRING_H
#define UNIQUESTRING_H

template <class String> class UniqueString : public String
{
public:
  UniqueString() : String("UniqueString")
  {}
  
  UniqueString(String s) : String(s)
  {}
};


#endif // UNIQUESTRING_H
