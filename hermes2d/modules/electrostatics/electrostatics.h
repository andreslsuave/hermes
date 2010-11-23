#include "hermes2d.h"

// This is a simple electrostatics module based on the Hermes library. The purpose
// of the module is to provide higher-level API where the user is not exposed to 
// wesk forms and other technical details. 
//
// PDE: Poisson equation -div(epsilon grad phi) = rho 
//      epsilon... permittivity (given, element-wise constant)
//      phi...     electric potential (unknown)
//      rho...     charge density (element-wise constant) 
//
// BC: piecewise-constant on Dirichlet boundaries
//     piecewise constant normal derivative on Neumann boundaries


class Electrostatics {
public:
  Electrostatics();
  ~Electrostatics();
  bool set_mesh_filename(const std::string &filename);
  void set_initial_mesh_refinement(int init_ref_num);
  void set_initial_poly_degree(int p);
  void set_material_markers(const std::vector<int> mat_markers);
  void set_permittivity_array(const std::vector<double> p_array);
  void set_charge_density_array(const std::vector<double> cd_array);
  void set_boundary_markers_value(const std::vector<int> &bdy_markers_val);
  void set_boundary_values(const std::vector<double> bc_val);
  void set_boundary_markers_derivative(const std::vector<int> bdy_markers_der);
  void set_boundary_derivatives(const std::vector<double> bc_der);
  bool calculate(Solution* phi);

private:
  std::string mesh_filename;
  int init_ref_num;
  int init_p;
  int n_mat_markers;
  std::vector<int> mat_markers;
  std::vector<double> permittivity_array;
  std::vector<double> charge_density_array;
  int n_bc_value;
  std::vector<int> bc_markers_value;
  std::vector<double> bc_values;
  int n_bc_derivative;
  std::vector<int> bc_markers_derivative;
  std::vector<double> bc_derivative;

  Mesh* mesh;
  H1Space* space;
};
