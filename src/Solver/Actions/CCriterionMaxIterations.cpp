// Copyright (C) 2010 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#include "Common/CBuilder.hpp"
#include "Common/OptionComponent.hpp"
#include "Common/OptionT.hpp"

#include "Solver/CTime.hpp"
#include "Solver/Actions/CCriterionMaxIterations.hpp"

namespace CF {
namespace Solver {
namespace Actions {

using namespace Common;

ComponentBuilder< CCriterionMaxIterations, CCriterion, LibActions > CCriterionMaxIterations_Builder;

////////////////////////////////////////////////////////////////////////////////

CCriterionMaxIterations::CCriterionMaxIterations( const std::string& name  ) :
  CCriterion ( name )
{
  properties()["brief"] = std::string("Maximum Iterations Criterion object");
  std::string description =
      properties()["description"].value<std::string>()+
      "Returns true if a the maximum number of iterations is achived\n";
  properties()["description"] = description;
  
  properties().add_option(OptionComponent<Component>::create("iterative_step","Iteration","Iteration tracking component",&m_iter_comp));
}

CCriterionMaxIterations::~CCriterionMaxIterations() {}

////////////////////////////////////////////////////////////////////////////////

bool CCriterionMaxIterations::operator()()
{
  if (m_iter_comp.expired()) throw SetupError(FromHere(),"Component holding iteration number was not set in ["+uri().string()+"]");

  Component& comp_iter = *m_iter_comp.lock();
  
  const Uint cur_iter = comp_iter.property("iteration").value<Uint>();
  const Uint max_iter = comp_iter.property("MaxIter").value<Uint>();

  return ( cur_iter > max_iter );
}

////////////////////////////////////////////////////////////////////////////////

} // Actions
} // Solver
} // CF
