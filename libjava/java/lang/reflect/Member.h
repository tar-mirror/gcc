
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_reflect_Member__
#define __java_lang_reflect_Member__

#pragma interface

#include <java/lang/Object.h>

class java::lang::reflect::Member : public ::java::lang::Object
{

public:
  virtual ::java::lang::Class * getDeclaringClass() = 0;
  virtual ::java::lang::String * getName() = 0;
  virtual jint getModifiers() = 0;
  virtual jboolean isSynthetic() = 0;
  static const jint DECLARED = 1;
  static const jint PUBLIC = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_lang_reflect_Member__