#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 normals;
in vec3 FragPos;

//uniform sampler2D texture_diffuse1;
uniform vec3 lightPos;
uniform vec3 viewPos;


void main()
{    
	float ambient_s=0.2f;
	vec3 color=vec3(0.0f,0.8f,0.8f);
	vec3 ambient=ambient_s*color;

	vec3 nor=normalize(normals);
	vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(nor, lightDir), 0.0);
    vec3 diffuse = diff * color;

	float spec_s=1.0f;
	vec3 viewDir=normalize(viewPos-FragPos);
	vec3 reflectDir=reflect(-lightDir,nor);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3 specular = spec_s* spec * color;


    FragColor = vec4(ambient+diffuse+specular,1.0f);
}