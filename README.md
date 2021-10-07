# GFXTest2
GFXTest with CMake
\
Added as submodules: glfw(3), glbindings, glm
# How to build this garbage
###### On linux, install xorg-dev because of glfw
###### Also, you'll obviously need a C++ compiler

### Clone repo, make build directory, run cmake
```
git clone --recursive https://github.com/mikpa1337/GFXTest2.git
cd GFXTest2
mkdir build
cd build
cmake ../.
```
### Build as normal
linux: run make;
\
MinGW: run make;
\
VS: open project file and.. build? (i dont know)

### Afterwards, please move the shaders folder to where the executable is
