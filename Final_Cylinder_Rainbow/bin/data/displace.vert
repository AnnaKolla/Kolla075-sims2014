
#extension GL_EXT_gpu_shader4 : require

uniform sampler2D colormap;
uniform sampler2D bumpmap;
varying vec2  TexCoord;
uniform int maxHeight;



flat varying vec3  normal;        // note 'flat varying'


void main(void) {
    
	TexCoord = gl_MultiTexCoord0.st;

	vec4 bumpColor = texture2D(bumpmap, TexCoord);
	float df = 0.30*bumpColor.x + 0.59*bumpColor.y + 0.11*bumpColor.z;
	vec4 newVertexPos = vec4(gl_Normal * df * float(maxHeight), 0.0) + gl_Vertex;
    
    

	gl_Position = gl_ModelViewProjectionMatrix * newVertexPos;
    normal = gl_NormalMatrix * gl_Normal;
    gl_Position = ftransform();
}

