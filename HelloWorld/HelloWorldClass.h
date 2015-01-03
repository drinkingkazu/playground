/**
 * \file HelloWorldClass.h
 *
 * \ingroup HelloWorld
 * 
 * \brief Class def header for a class HelloWorldClass
 *
 * @author kazuhiro
 */

/** \addtogroup HelloWorld

    @{*/
#ifndef CPPEXAMPLE_HELLOWORLD_HELLOWORLDCLASS_H
#define CPPEXAMPLE_HELLOWORLD_HELLOWORLDCLASS_H

#include <iostream>

/**
   \class HelloWorldClass
 */
class HelloWorldClass {

public:

  /// Default constructor
  HelloWorldClass(){}

  /// Default destructor
  virtual ~HelloWorldClass(){}

  /// Greeting function
  void Hello() const
  { std::cout << "Hello world from class-func!" << std::endl; }

};

#endif
/** @} */ // end of doxygen group 

