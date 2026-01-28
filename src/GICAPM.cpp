#include <pybind11/pybind11.h>
#include "../include/GICAPM.hpp"

namespace py = pybind11;

PYBIND11_MODULE(GICAPM, m) {
  m.doc() = "Engine for the GICAPM";
  m.def("loss ratio", &loss_ratio, "Computes loss rati");
}
