#version 410 core

layout (location = 0) in vec4 vertex;

out gl_PerVertex{
vec4 gl_Position;
};

void main()
{
const vec4 vertices[3] = vec4[3](vec4(0.25,-0.25,0.5,1.0),
                                 vec4(-0.25,-0.25,0.5,1.0),
                                 vec4(0.25,0.25,0.5,1.0));
gl_Position = vertices[gl_VertexID];
//note I have to multiply this by the MVP matrix if there is no tessellation
}
