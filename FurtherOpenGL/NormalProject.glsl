

vec3 NormalProject()
{
	return normalize(vec3(normalMatrix * vec4(vertexNormal, 1.0)));
}