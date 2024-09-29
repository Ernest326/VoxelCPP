#version 330 core

uniform sampler2D texture1;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(-2.0, -3.0, -1.0));
    float diff = max(dot(norm, -lightDir), 0.0);

    vec3 ambient = 0.35 * vec3(texture(texture1, TexCoord));
    vec3 diffuse = diff * vec3(texture(texture1, TexCoord));

    FragColor = vec4(ambient + diffuse, 1.0);
} 