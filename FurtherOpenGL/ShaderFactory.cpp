#include "ShaderFactory.h"
#include <string>
#include <sstream>


ShaderFactory::ShaderFactory(void)
{
}


ShaderFactory::~ShaderFactory(void)
{
}

void ShaderFactory::Initialize()
{
	
}

void ShaderFactory::BuildTestShader()
{
	std::stringstream shader;
	std::string version = "#version 420 core";
	int locations = 0;

	shader << version << std::endl;
	shader << "layout(location = " << locations++ << ") in vec3 vertexPosition;" << std::endl;
	shader << "uniform mat4 MVP;" << std::endl;

	//  if (mesh.has normals) {
	shader << "layout(location = " << locations++ << ") in vec3 vertexNormal" << std::endl;
	shader << "out vec3 normal;" << std::endl;
	shader << "uniform mat4 normalMatrix;" << std::endl;
	
	//  if (mesh.has textures) {
	shader << "layout(location = " << locations++ << ") in vec2 UVs;" << std::endl;
	shader << "out vec2 uvs;" << std::endl;

	//  if (mesh.has tangent) {
	shader << "layout(location = " << locations++ << ") in vec3 vertexTangent;" << std::endl;
	shader << "out vec3 tangent;" << std::endl;

	//shader << VertexProject.glsl << std::endl;

	//  if (mesh.has normals) {
	//shader << NormalProject.glsl << std::endl;

	//  if (mesh.has textures) {
	//shader << UVPass

	//  if (mesh.has tangent) {

}
