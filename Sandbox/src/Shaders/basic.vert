#version 330 core

layout(location = 0) in vec4 _position;
layout(location = 1) in vec4 _color;

uniform mat4 u_ViewProjection;

out vec4 v_position;
out vec4 v_color;

void main() {
	v_position = _position;
	gl_Position = u_ViewProjection * _position;
	v_color = _color;
}