// test QP examples 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <qpOASES.hpp>
#include <eigen3/Eigen/Dense>


int main ( void )
{
   USING_NAMESPACE_QPOASES
   std::cout << "test QP.." << std::endl;

   /* Setup data of first QP. */
    real_t H[2*2] = { 1.0, 0.0, 1.0, 0.5 };
    real_t A[1*2] = { 1.0, 1.0 };
    real_t g[2] = { 1.5, 1.0 };
    real_t lb[2] = { 0.5, -2.0 };
    real_t ub[2] = { 5.5, 2.0 };
    real_t lbA[1] = { -1.0 };
    real_t ubA[1] = { 2.0 };

    /* Setup data of second QP. */
    real_t g_new[2] = { 1.0, 1.5 };
    real_t lb_new[2] = { 0.0, -1.0 };
    real_t ub_new[2] = { 5.0, -0.5 };
    real_t lbA_new[1] = { -2.0 };
    real_t ubA_new[1] = { 1.0 };
    
    int nV = 2, nC = 1; 
    /* Setting up QProblem object. */
    QProblem example( nV,nC);
    
    // setup options 
    qpOASES::Options op;
    op.setToMPC();
    //op.printLevel = qpOASES::PL_NONE;
    example.setOptions(op); // set this before init 

    /* Solve first QP. */
    int_t nWSR = 5;
    returnValue status = example.init( H,g,A,lb,ub,lbA,ubA, nWSR );
    if(status ==  qpOASES::SUCCESSFUL_RETURN){
      std::cout << "status: " << status << std::endl;
    }
    
    
    /* Solve second QP. */
    nWSR = 10;
    //example.hotstart( g_new,lb_new,ub_new,lbA_new,ubA_new, nWSR );
    
    /* Get and print solution of second QP. */
    real_t xOpt[nV];
    example.getPrimalSolution( xOpt );
    printf( "\n xOpt = [ %e, %e ]; objVal = %e\n\n",
    xOpt[0],xOpt[1],example.getObjVal() );


   // test eigen LU 
   typedef Eigen::Matrix<double,5,5> Mat55; 
   Mat55 m = Mat55::Random();
   
   // FULL LU 
   Eigen::FullPivLU<Mat55> s(m); 

   Eigen::Matrix<double,5,1> v ;
   v << 1.,2.,3.,4.,5.0; 

   auto res = m.lu().solve(v) ; 
   auto res2 = s.solve(v);
   // res == res2 
   std::cout << res << std::endl;
   std::cout << res2 << std::endl;
   
   Eigen::Matrix<int,4,1> footContact = {0,1,1,0} ; 
   int nContact = footContact.sum(); 
   std::vector<int> contact_idx; 
   for(int i=0;i<4;i++){
       if(footContact(i)==1){
           contact_idx.push_back(i); 
       }
   }
   for(auto i : contact_idx){std::cout<<i<<std::endl;}
 
   Eigen::MatrixXd tt(6,nContact*3);
   std::cout << tt.rows() << ";" << tt.cols() << std::endl;
   std::cout << tt << std::endl;
   
   Eigen::Matrix<double , 4,4> mm,nn ; 
   mm.setIdentity(); 
   std::cout << mm << std::endl;
   nn = 4*mm; 
   std::cout << nn << std::endl;

  return 0; 
}