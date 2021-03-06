// Copyright (C) 2010-2013 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef cf3_physics_navierstokes_navierstokes2d_Types_hpp
#define cf3_physics_navierstokes_navierstokes2d_Types_hpp

#include "cf3/physics/MatrixTypes.hpp"

namespace cf3 {
namespace physics {
namespace navierstokes {
namespace navierstokes2d {

//////////////////////////////////////////////////////////////////////////////////////////////

  enum {NDIM=2};
  enum {NEQS=4};

  typedef MatrixTypes<NDIM,NEQS>::RowVector_NEQS       RowVector_NEQS;
  typedef MatrixTypes<NDIM,NEQS>::ColVector_NDIM       ColVector_NDIM;
  typedef MatrixTypes<NDIM,NEQS>::Matrix_NEQSxNEQS     Matrix_NEQSxNEQS;
  typedef MatrixTypes<NDIM,NEQS>::Matrix_NDIMxNEQS     Matrix_NDIMxNEQS;
  typedef MatrixTypes<NDIM,NEQS>::Matrix_NDIMxNDIM     Matrix_NDIMxNDIM;

//////////////////////////////////////////////////////////////////////////////////////////////

} // navierstokes2d
} // navierstokes
} // physics
} // cf3

#endif // cf3_physics_navierstokes_navierstokes2d_Types_hpp
