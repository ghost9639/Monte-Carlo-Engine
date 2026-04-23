
# Table of Contents

1.  [Project Purpose](#org023e1bf)
2.  [Currently Implemented Methods](#org3898c4d)
3.  [Python Integration](#orga48f93d)
4.  [Unit Testing](#org49f4085)
5.  [How to Use](#org69a5a41)
6.  [Documentation](#orgad4b546)



<a id="org023e1bf"></a>

# Project Purpose

This project is an investigation into different Monte Carlo sampling methods. It typically targets Normal distribution sampling for experimental solutions to stock price SDEs. For greater ease of use, the project uses pybind11 integration, exporting fast C++ sampling functions into Python as vectorised \`numpy\` arrays. This allows for speed without losing usability, but the internal functions can all be used and called in a C++ main file as normal. All functions are documented in [a html file](docs/html/index.html).


<a id="org3898c4d"></a>

# Currently Implemented Methods

1.  The Box-Muller Transform, using trigonometric functions, we can convert uniformly distributed functions to normal ones,
2.  The Inverse Quantile Transform, by using an approximation to the probability function, we can quickly convert uniform variables to normally distributed variables.


<a id="orga48f93d"></a>

# Python Integration

This project wraps frontend commands using [pybind11](https://github.com/pybind/pybind11). Functions written in optimised C++ can be imported and used in python with strong numpy / pandas compatibility to fit easily into any data scientist's toolkit.


<a id="org49f4085"></a>

# Unit Testing

This project uses [Google's C++ Unit Testing Framework](https://github.com/google/googletest) to ensure functions stay reliable in the presence of rewrites and edge cases. Tests can be accessed by using the typical CTest commands (\`cmake &ndash;build build &ndash;target test\`).


<a id="org69a5a41"></a>

# How to Use

The project can be installed and built with a fairly minimal toolchain. On MacOS / Linux:

    git clone https://github.com/ghost9639/Monte-Carlo-Engine
    cd Monte-Carlo-Engine
    
    rm -rf build
    mkdir build
    
    cmake -S . -B build -G Ninja
    cmake --build build
    
    export PYTHONPATH=$PYTHONPATH:$(pwd)/build
    python <YOUR_PYTHON_FILE>

On Windows:

    git clone https://github.com/ghost9639/Monte-Carlo-Engine
    cd Monte-Carlo-Engine
    
    cmake -S . -B build -G Ninja
    cmake --build build
    
    # One of:
    set PYTHONPATH=%PYTHONPATH%;%cd%\build # if using cmd
    $env:PYTHONPATH = "$env:PYTHONPATH;$(Get-Location)\build" # if using powershell
    
    python <YOUR_PYTHON_FILE>


<a id="orgad4b546"></a>

# Documentation

All functions are documented in [the doxygen file](docs/html/index.html), and implemented in [an application file](src/App.cpp).

