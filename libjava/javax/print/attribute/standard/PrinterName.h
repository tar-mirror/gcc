
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_print_attribute_standard_PrinterName__
#define __javax_print_attribute_standard_PrinterName__

#pragma interface

#include <javax/print/attribute/TextSyntax.h>
extern "Java"
{
  namespace javax
  {
    namespace print
    {
      namespace attribute
      {
        namespace standard
        {
            class PrinterName;
        }
      }
    }
  }
}

class javax::print::attribute::standard::PrinterName : public ::javax::print::attribute::TextSyntax
{

public:
  PrinterName(::java::lang::String *, ::java::util::Locale *);
  jboolean equals(::java::lang::Object *);
  ::java::lang::Class * getCategory();
  ::java::lang::String * getName();
private:
  static const jlong serialVersionUID = 299740639137803127LL;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_print_attribute_standard_PrinterName__
