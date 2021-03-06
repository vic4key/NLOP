cmake_minimum_required(VERSION 2.8)

project(NLOP)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O0")

find_package(Eigen3 REQUIRED)

include_directories(
    "include"
    ${Eigen3_INCLUDE_DIR}
)

set(HEADERS
    # Utils
    include/Utils/Matrix.hpp
    include/Utils/Types.hpp
    include/Utils/Utils.hpp
    include/Utils/Functor.hpp

    ######################################################
    # Optimizer Params
    include/OptimizerParams/OptimizerParamsBase.hpp
    include/OptimizerParams/LineSearchParams.hpp
    include/OptimizerParams/TrustRegionParams.hpp

    ## Line search method params
    include/OptimizerParams/SteepestDescentParams.hpp
    include/OptimizerParams/ConjuateGradientParams.hpp
    include/OptimizerParams/MomentumParams.hpp
    include/OptimizerParams/NesterovMomentumParams.hpp
    include/OptimizerParams/AdagradParams.hpp
    include/OptimizerParams/RMSPropParams.hpp
    include/OptimizerParams/AdaDeltaParams.hpp
    include/OptimizerParams/AdamParams.hpp
    include/OptimizerParams/HookeJeevesParams.hpp

    ## Newton's and Quasi-Newton method params
    include/OptimizerParams/NewtonParams.hpp
    include/OptimizerParams/LevenbergMarquardtParams.hpp
    include/OptimizerParams/DFP_Params.hpp
    include/OptimizerParams/BFGS_Params.hpp

    ######################################################
    # Optimizer
    include/OptimizerBase/OptimizerBase.hpp
    include/OptimizerBase/LineSearchOptimizer.hpp
    include/OptimizerBase/TrustRegionOptimizer.hpp

    ## Line Search Methods
    include/LineSearchMethods/SteepestDescentOptimizer.hpp
    include/LineSearchMethods/NewtonOptimizer.hpp
    include/LineSearchMethods/ConjuateGradientOptimizer.hpp
    include/LineSearchMethods/MomentumOptimizer.hpp
    include/LineSearchMethods/NesterovMomentumOptimizer.hpp
    include/LineSearchMethods/AdagradOptimizer.hpp
    include/LineSearchMethods/RMSPropOptimizer.hpp
    include/LineSearchMethods/AdaDeltaOptimizer.hpp
    include/LineSearchMethods/AdamOptimizer.hpp
    include/LineSearchMethods/HookeJeevesOptimizer.hpp

    ## Newton's method and Quasi-Newton method
    include/LineSearchMethods/NewtonOptimizer.hpp
    include/LineSearchMethods/DFP_Optimizer.hpp
    include/LineSearchMethods/BFGS_Optimizer.hpp

    ## Trust Region Methods
    include/TrustRegionMethods/LevenbergMarquardtOptimizer.hpp

    ######################################################

    # Stepsize Search Methods
    include/StepsizeSearch/StepsizeSearchBase.hpp
    include/StepsizeSearch/Accurate/AccurateSearchBase.hpp
    include/StepsizeSearch/Inaccurate/InaccurateSearchBase.hpp

    ## Accurate stepsize search
    include/StepsizeSearch/Accurate/GoldenSectionMethod.hpp
    include/StepsizeSearch/Accurate/FibonacciMethod.hpp
    include/StepsizeSearch/Accurate/DichotomousMethod.hpp

    ## Inaccurate stepsize search
    include/StepsizeSearch/Inaccurate/InaccurateSearchBase.hpp
    include/StepsizeSearch/Inaccurate/GoldsteinMethod.hpp
    include/StepsizeSearch/Inaccurate/ArmijoMethod.hpp
    include/StepsizeSearch/Inaccurate/WolfePowellMethod.hpp

    ## Stepsize search params
    include/StepsizeSearchParams/StepsizeSearchParamsBase.hpp
    include/StepsizeSearchParams/AccurateSearchParams.hpp
    include/StepsizeSearchParams/InaccurateSearchParams.hpp

    include/StepsizeSearchParams/GoldenSectionParams.hpp
    include/StepsizeSearchParams/FibonacciParams.hpp
    include/StepsizeSearchParams/DichotomousParams.hpp

    include/StepsizeSearchParams/ArmijoParams.hpp
    include/StepsizeSearchParams/GoldsteinParams.hpp
    include/StepsizeSearchParams/WolfePowellParams.hpp

    ######################################################
    )

# Generate cmake configuration scripts
#set(NLOP_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
#set(NLOP_VERSION_CONFIG "${NLOP_GENERATED_DIR}/${PROJECT_NAME}ConfigVersion.cmake")
#set(NLOP_PROJECT_CONFIG "${NLOP_GENERATED_DIR}/${PROJECT_NAME}Config.cmake")
#set(NLOP_CONFIG_INSTALL_DIR "lib/cmake/${PROJECT_NAME}")
#set(NLOP_VERSION 1.0.0)

#configure_file("${NLOP_SOURCE_DIR}/cmake_modules/Config.cmake.in" "${NLOP_PROJECT_CONFIG}" @ONLY)

#install(
#    FILES "${NLOP_PROJECT_CONFIG}"
#    DESTINATION "${NLOP_CONFIG_INSTALL_DIR}")

#set(INCLUDES_DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
#set(INCLUDES_INSTALL_DIR ${INCLUDES_DESTINATION}/NLOP)
#install(FILES ${HEADERS} DESTINATION ${INCLUDES_INSTALL_DIR})

add_subdirectory(examples)
