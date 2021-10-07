#include "shaderLoader.hpp"

ShaderLoader::ShaderLoader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string     vertexCode;     // vertexCode will be stored here
    std::string     fragmentCode;   // fragmentCode will be stored here
    std::ifstream   vShaderFile;    // input file stream for vertex shader
    std::ifstream   fShaderFile;    // input file stream for fragment shader

    // enable exceptions? not really sure
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {
        // open the file(s)
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        
        // read the buffers (into the streams)
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // close file(s)
        vShaderFile.close();
        fShaderFile.close();

        // convert stream into string (wow)
        vertexCode      = vShaderStream.str();
        fragmentCode    = fShaderStream.str();
    } catch (std::ifstream::failure &e) {
        std::cerr << "can't read shader file.. -> " << e.what() << std::endl;
    }
    

    // i hate this, but glShaderSource expects const char* const *
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();


    // compile the shaders
    gl::GLuint vertex, fragment;
    gl::GLint success = 0;      // i also hate this, why cant it just be a bool?
    gl::GLchar infoLog[512];    // hardcoded 512 byte buffer

    // vertex shader compiling..
    vertex = gl::glCreateShader(gl::GL_VERTEX_SHADER);
    gl::glShaderSource(vertex, 1, &vShaderCode, nullptr);
    gl::glCompileShader(vertex);
    gl::glGetShaderiv(vertex, gl::GL_COMPILE_STATUS, &success);

    if (!success) {
        gl::glGetShaderInfoLog(vertex, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "vertex shader compilation failed\n" << infoLog << std::endl;
    }

    // same thing for fragment shader
    fragment = gl::glCreateShader(gl::GL_FRAGMENT_SHADER);
    gl::glShaderSource(fragment, 1, &fShaderCode, nullptr);
    gl::glCompileShader(fragment);
    gl::glGetShaderiv(fragment, gl::GL_COMPILE_STATUS, &success);

    if (!success) {
        gl::glGetShaderInfoLog(fragment, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "fragment shader compilation failed\n" << infoLog << std::endl;
    }

    // shader program
    programId = gl::glCreateProgram();
    gl::glAttachShader(programId, vertex);
    gl::glAttachShader(programId, fragment);
    gl::glLinkProgram(programId);

    // check for any errors
    gl::glGetProgramiv(programId, gl::GL_LINK_STATUS, &success);
    if (!success) {
        gl::glGetProgramInfoLog(programId, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "shader linking failed\n" << infoLog << std::endl;
    }

    // delete shaders (They are compiled&linked into the shader program)
    gl::glDeleteShader(vertex);
    gl::glDeleteShader(fragment);
}

void ShaderLoader::use() {
    gl::glUseProgram(programId);
}

void ShaderLoader::setBool(const std::string& name, bool value) const {
    gl::glUniform1i(gl::glGetUniformLocation(programId, name.c_str()), static_cast<int>(value));
}

void ShaderLoader::setInt(const std::string& name, int value) const {
    gl::glUniform1i(gl::glGetUniformLocation(programId, name.c_str()), value);
}

void ShaderLoader::setFloat(const std::string& name, float value) const {
    gl::glUniform1f(gl::glGetUniformLocation(programId, name.c_str()), value);
}

