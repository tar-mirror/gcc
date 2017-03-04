// { dg-options "-std=gnu++11" }
// 2005-01-15 Douglas Gregor <dgregor@cs.indiana.edu>
//
// Copyright (C) 2005-2016 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 20.7.15 polymorphic function object wrapper
#include <functional>
#include <testsuite_hooks.h>

using namespace __gnu_test;

bool test __attribute__((unused)) = true;

struct secret {};

struct noncopyable_function_object_type
{
  noncopyable_function_object_type(secret) {}

  int operator()() const { return 42; }
  int operator()()       { return 17; }

 private:
  noncopyable_function_object_type();
  noncopyable_function_object_type(const noncopyable_function_object_type&);
  void operator=(const noncopyable_function_object_type&);
};

// Put reference_wrappers into function<> wrappers
void test06()
{
  using std::function;
  using std::ref;
  using std::cref;

  secret password;
  noncopyable_function_object_type x(password);

  function<int()> f(ref(x));
  VERIFY( f );
  VERIFY( f() == 17 );
  VERIFY( f.target_type() == typeid(noncopyable_function_object_type) );
  VERIFY( f.target<noncopyable_function_object_type>() == &x );

  function<int()> g = f;
  VERIFY( g );
  VERIFY( g() == 17 );
  VERIFY( g.target_type() == typeid(noncopyable_function_object_type) );
  VERIFY( g.target<noncopyable_function_object_type>() == &x );

  function<int()> h = cref(x);
  VERIFY( h );
  VERIFY( h() == 42 );
  VERIFY( h.target_type() == typeid(noncopyable_function_object_type) );
  VERIFY( h.target<const noncopyable_function_object_type>() == &x );
  VERIFY( h.target<const noncopyable_function_object_type>() == &x );

  const function<int()>& hc = h;
  VERIFY( h.target<noncopyable_function_object_type>() == 0 );
  VERIFY( hc.target<noncopyable_function_object_type>() == &x );
}

int main()
{
  test06();
  return 0;
}
