#ifndef BISECTIONMETHOD_HPP
#define BISECTIONMETHOD_HPP

#include <OneDimensionalSearch/OneDimensionalSearchMethods.hpp>

namespace NLOP {

/// @class NLOP::BisectionMethod
/// @brief Bisection method for derivable functions
/// @param T The numeric scalar type
template<typename T>
class BisectionMethod: public OneDimSearch
{
protected:

    using OneDimSearch::alpha;
    using OneDimSearch::beta;
    using OneDimSearch::epsilon;
    using OneDimSearch::lambda;
    using OneDimSearch::iteration_times;
    using OneDimSearch::max_iteration_times;
    using OneDimSearch::phi;
public:
    T search() override
    {
        while (true) {
            std::cout << "interative times: " << iteration_times << "  "
                      << "[alpha, lambda, beta]: "
                      << "[" << alpha << ", " << lambda << ", "
                      << beta << "]" << std::endl;

            /// Update Jacobian matrix for phi(lambda)
            phi.updateValueAndJacobian();
            /// stoping condition: (alpha - beta) < epsilon || phi'(lambda) == 0
            if (beta - alpha < epsilon || phi.getJacobian.norm() == 0)
            {
                std::cout << "Finished! Optimal lambda: "
                          << lambda << std::endl;
                return lambda;
            }
            iteration_times++;

            if (phi.getJacobian.norm() > 0)
            {
                /// cut the right half of the interval
                beta = lambda;
                lambda = (alpha + beta)/2;
                phi.setX(lambda);
            }

            else
            {
                /// cut the left half of the interval
                alpha = lambda;
                lambda = (alpha + beta)/2;
                phi.setX(lambda);
            }
        }
    }

};
}

#endif
