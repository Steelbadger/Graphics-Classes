#version 420 core


in vec3 normal;

// Ouput data
out vec4 color;

void main()
{
	color = vec4(ambient + diffuse + specular, 1.0);
}