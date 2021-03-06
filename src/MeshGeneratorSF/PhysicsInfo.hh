// Copyright (C) 2014 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef ShockFitting_PhysicsInfo_hh
#define ShockFitting_PhysicsInfo_hh

//--------------------------------------------------------------------------//

#include "SConfig/StringManip.hh"
#include "Framework/Connectivity.hh"
#include "Framework/MeshGenerator.hh"

//--------------------------------------------------------------------------//

namespace ShockFitting {

//--------------------------------------------------------------------------//

/// This class defines ReadMeshConstant, whose task is to read constant
/// values realted to the mesh and assign them to PhysicsData pattern.

class PhysicsInfo: public MeshGenerator {
public:

  /// Constructor
  /// @param objectName the concrete class name
  PhysicsInfo(const std::string& objectName);

  /// Destructor
  virtual ~PhysicsInfo();

  /// Set up object before its first use
  virtual void setup();

  ///Unset up object before its last use
  virtual void unsetup();

  /// Run constant values reading
  virtual void generate();

private: //helper functions

  /// assign values read by ReadPhysicsConstant to PhysicsData
  void setPhysicsData();

private: //data

  /// space dimension
  unsigned m_ndim;

  /// max number of degree of freedom
  unsigned m_ndofmax;

  /// max number of shocks
  unsigned m_nshmax;

  /// max number of shock points for each shock
  unsigned m_npshmax;

  /// max number of shock edges for each shock
  unsigned m_neshmax;

  /// max number of special points
  unsigned m_nspmax;

  /// max number of holes
  unsigned m_naddholesmax;

  /// model
  std::string m_model;

  /// mixture
  std::string m_mixture;

  /// space dimension 
  ///(assignable to PhysicsData)
  unsigned* ndim;

  /// max number of degree of freedom
  /// (assignable to PhysicsData)
  unsigned* ndofmax;

  /// max number of shocks
  /// (assignable to PhysicsData)
  unsigned* nshmax;

  /// max number of shock points for each shock
  /// (assignable to PhysicsData)
  unsigned* npshmax;

  /// max number of shock edges for each shock
  /// (assignable to PhysicsData)
  unsigned* neshmax;

  /// max number of special points
  /// (assignable to PhysicsData)
  unsigned* nspmax;

  /// max number of holes
  /// (assignable to PhysicsData)
  unsigned* naddholesmax;

  /// model type
  /// (assignable to PhysicsData)
  const char* model;

  /// mixture type
  /// (assignable to PhysicsData)
  const char* mixture;

};

} //namespace ShockFitting

#endif //ShockFitting_PhysicsInfo_hh
