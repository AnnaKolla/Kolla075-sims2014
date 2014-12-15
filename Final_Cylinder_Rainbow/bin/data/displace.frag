#extension GL_EXT_gpu_shader4 : require

uniform sampler2D colormap;
uniform sampler2D bumpmap;
varying vec2  TexCoord;

flat varying vec3  normal;        // note 'flat varying'


void main(void) {
	gl_FragColor = texture2D(colormap, TexCoord);
    
    vec3 N = normalize(normal);
    
    // voila, we can use our flat normal! This will colour our fragment with the current normal for debug purposes.
   gl_FragColor = vec4((N + vec3(1.0, 1.0, 1.0)) / 2.0,1.0);
  
}




