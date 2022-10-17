#include <casadi/casadi.hpp>
using namespace casadi;

int main() {
  int y_dim = 5; 
  SX x = SX::sym("x");
  SX y = SX::sym("y", y_dim );
  SX Z = SX::sym("Z",4,2);
  SX f = pow(x,2) + 10;
  f = sqrt(f);
  std::cout << "f: " << f << std::endl;
  std::cout << "y: " << y << std::endl;

  // test opti stack======
  //auto opti = Opti(); 
  auto opti = Opti("conic"); 
  
  auto x1 = opti.variable();
  auto y1 = opti.variable(); 

  opti.minimize( sq(x1)+sq(y1));
  opti.subject_to(x1+y1>=10 );

  //opti.solver("ipopt"); // for nlopt
  //opti.solver("qrsqp"); // for nlopt

  opti.solver("qpoases"); // for conic 

  auto sol = opti.solve();
  std::cout <<  "x1:" << sol.value(x1) << std::endl;
  std::cout << "x2:" <<sol.value(x1) << std::endl;

  return 0;
}

// install notes for casadi:
// cmake -DWITH_IPOPT=true -DWITH_QPOASES=true -DWITH_LAPACK=true ..
// make 
// sudo make install

