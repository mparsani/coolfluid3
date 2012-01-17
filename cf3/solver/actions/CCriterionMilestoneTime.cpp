// Copyright (C) 2010-2011 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#include "common/Builder.hpp"
#include "common/OptionComponent.hpp"
#include "common/OptionList.hpp"
#include "common/OptionT.hpp"
#include "common/PropertyList.hpp"

#include "solver/CTime.hpp"
#include "solver/Tags.hpp"
#include "solver/actions/CCriterionMilestoneTime.hpp"

namespace cf3 {
namespace solver {
namespace actions {

using namespace common;

ComponentBuilder< CCriterionMilestoneTime, CCriterion, LibActions > CCriterionMilestoneTime_Builder;

////////////////////////////////////////////////////////////////////////////////

CCriterionMilestoneTime::CCriterionMilestoneTime( const std::string& name  ) :
  CCriterion ( name ),
  m_tolerance(1e-12)
{
  properties()["brief"] = std::string("Time Criterion object");
  std::string description = properties().value<std::string>("description")+
    "Returns true if a time is reached\n";
  properties()["description"] = description;

  options().add_option(Tags::time(), m_time)
      .description("Time tracking component")
      .pretty_name("Time")
      .mark_basic()
      .link_to(&m_time)
      .add_tag("time");
}

////////////////////////////////////////////////////////////////////////////////

CCriterionMilestoneTime::~CCriterionMilestoneTime()
{
}

////////////////////////////////////////////////////////////////////////////////

bool CCriterionMilestoneTime::operator()()
{
  const Real dt = m_time->options().option("time_step").value<Real>();
  if ( dt == 0. )
    return true;

  const Real t = m_time->current_time();
  if ( t==0 ) return false;
  return ( t - Uint(t/dt) * dt == 0 );
}

////////////////////////////////////////////////////////////////////////////////

} // actions
} // solver
} // cf3
