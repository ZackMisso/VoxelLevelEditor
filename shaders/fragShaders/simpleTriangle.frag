#version 410 core

in vec4 geom_color;

out vec4 color;

void main(void) {
  color = geom_color;
}
