#version 420 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
//layout(location = 2) in vec2 UVs;

out vec3 normal;

uniform mat4 MVP;
uniform mat4 normalMatrix;


void main(){

	//  Find the position in screen space (model transformation, then view transformation, then project)
    gl_Position = VertexProject();

	//  Find the normal in eye-space
	normal = NormalProject();
}