#ifndef NEWTONOPTIMIZER_HPP
#define NEWTONOPTIMIZER_HPP

#include <OptimizerBase/LineSearchOptimizer.hpp>
#include <OptimizerParams/NewtonParams.hpp>

namespace NLOP {
/// @class NewtonOptimizer
/// @brief Newton method optimizer
/// @param FunctorType Target function type
/// @param HessianFunctorType mammal Hessian functor of target function
template<typename FunctorType, typename HessianFunctorType>
class NewtonOptimizer: public LineSearchOptimizer<FunctorType>
{
protected:
    using LineSearch = LineSearchOptimizer<FunctorType>;

    using typename LineSearch::InputType;
    using typename LineSearch::ValueType;
    using typename LineSearch::JacobianType;
    using typename LineSearch::T;

    using LineSearch::f;

public:
    /// @brief Constructor and Deconstructor
    NewtonOptimizer() {}
    ~NewtonOptimizer() {}

    /// @brief Initialization
    void init(const InputType& initial, FunctorType* f,
              NewtonParams* params)
    {
        this->f = f;
        this->f->setX(initial);
        this->updateValue();
        this->params = params;
    }

    /// @brief Newton optimization process
    InputType optimize() override
    {
        // get params
        auto max_iterations = params->getMaxIterations();
        auto min_delta_x = params->getMinDeltaX();

        this->printInitialConfigurations(params);
        if (params->isLogFile())
            this->writer.open("../data/Newton.txt");
        while (true){
            this->updateValueAndJacobian();
            this->printProcessInformation(params);
            if (this->writer.is_open())
                this->writeInformation();
            if (params->getIterationTimes() > max_iterations)
            {
                std::cerr << "Beyond max iteration times, cannot convergence" << std::endl;
                return f->getX();
            }
            else
            {
                x = f->getX();
                g = f->getJacobian();

                delta_x = H(x).inverse() * g.transpose();

                if (delta_x.norm() < min_delta_x)
                {
                    this->printResult(params);
                    return f->getX();
                }
                // update x
                f->setX(x - delta_x);
                params->nextIteration();
            }
        }
        if (this->writer.is_open())
            this->writer.close();
    }

private:
    NewtonParams* params;

    HessianFunctorType H; // Hessian matrix
    InputType delta_x;    // delta x for every step
    InputType x;
    JacobianType g;       // Jacobian
};
}

#endif
