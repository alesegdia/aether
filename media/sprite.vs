#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 viewProjection;

uniform vec2 frame;
uniform vec2 size;

void main()
{
    gl_Position = viewProjection * model * vec4(aPos, 1.0);
    TexCoord = aTexCoord + frame * size;
}