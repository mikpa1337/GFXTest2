# GFXTest2
GFXTest with CMake
\
Added as submodules: glfw(3), glbindings, glm
# how to build this garbage
###### on linux, install xorg-dev because of glfw
###### also, you'll obviously need a C++ compiler

### clone repo, make build directory, run cmake
```
git clone --recursive https://github.com/mikpa1337/GFXTest2.git
cd GFXTest2
mkdir build
cd build
cmake ../.
```
#### and build as normal
\
linux: run make;
\
MinGW: run make;
\
VS: open project file and.. build? (i dont know)
