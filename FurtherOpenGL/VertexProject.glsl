

vec3 VertexProject()
{
	return vec3(MVP * vec4(vertexPosition, 1.0));
}