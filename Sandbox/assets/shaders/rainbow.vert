#version 330 core

layout(location = 0) in vec4 _position;
layout(location = 1) in vec4 _color;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;
uniform vec4 u_Color;

out vec4 v_position;
out vec4 v_color;

void main() {
	v_position = _position;
	gl_Position = u_ViewProjection * u_Transform * _position;
	float w = u_Color.w + _color.w * (1 - u_Color.w);
	vec3 rgb = u_Color.xyz * u_Color.w + _color.xyz * _color.w * (1 - u_Color.w);
	v_color = vec4(rgb, w);
}
