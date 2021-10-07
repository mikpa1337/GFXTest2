// Directly stolen from dokipen.com OpenGL tutorial
#version 450 core
//layout (location = 0) in vec2 position;

out vec3 color;
//
//const vec4 vertices[] = vec4[]( vec4(-0.5f, -0.7f,  0.0, 1.0),
//                                vec4( 0.5f, -0.7f,  0.0, 1.0),
//                                vec4( 0.0f, 0.6888f,0.0, 1.0));
//
//      

// Flipped triangle
//                                     X      Y      Z
const vec4 vertices[] = vec4[]( vec4(-0.5f,  0.7f,  0.0, 1.0),  // Point 1
                                vec4( 0.5f,  0.7f,  0.0, 1.0),  // Point 2
                                vec4( 0.0f, -0.6888f,0.0, 1.0)); // Point 3


const vec3 colors[] = vec3[] (  vec3( 1.0, 0.0, 0.0),
                                vec3( 0.0, 1.0, 0.0),
                                vec3( 0.0, 0.0, 1.0));

void main() {
    color = colors[gl_VertexID];
    gl_Position = vertices[gl_VertexID];
    //color = vec3(1.0f, 1.0f, 1.0f);
    //gl_Position = vec4(position, 0.0f, 1.0f);
}