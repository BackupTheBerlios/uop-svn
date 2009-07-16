#ifndef UBI_VM_HPP
#define UBI_VM_HPP


#include "UbivmDefs.hpp"


class CUbiVM
{
public:
   CUbiVM( SOptions *options );
   int run( );
private:
   SOptions *_options;
};

#endif

