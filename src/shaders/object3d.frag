#version 330 core

in vec2 TexCoord;
in vec3 FragPos;  
in vec3 Normal;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform vec3 lightPos;  

void main(){

    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0f,1.0f,1.0f);
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float alpha = 1.0f;
    vec3 light = ambient + diffuse;
    vec4 lightsAndColors = vec4(light,alpha);

    // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    FragColor = texture(ourTexture, TexCoord) * lightsAndColors;

}
