// mostly stolen from learnopengl: shaders chapter

#pragma once

#include <glbinding/gl/gl.h>

#include <iostream>
#include <fstream>  // std::ifstream
#include <sstream>  // std::stringstream
#include <string>   // std::string

// if its all going to be public, why is it even a class and not just a struct..?
class ShaderLoader {
public:
    // program id
    gl::GLuint programId;

    // sick constructor
    ShaderLoader(const std::string& vertexPath, const std::string& fragmentPath);
    
    // use the shader
    void use();

    // uniform functions (????????)
    void setBool    (const std::string& name, bool value)   const;
    void setInt     (const std::string& name, int value)    const;
    void setFloat   (const std::string& name, float value)  const;
};
