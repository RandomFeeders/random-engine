#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_position;
in vec4 v_color;

void main() {
	color = vec4(v_position * 0.5 + 0.5);
	color = v_color;
}
