#version 330 core

layout(location = 0) in vec4 _position;
layout(location = 1) in vec2 _texCoord;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec2 v_TexCoord;

void main() {
	v_TexCoord = _texCoord;
	gl_Position = u_ViewProjection * u_Transform * _position;
}
