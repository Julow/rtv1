# rtv1

### Scene file

```xml
<!--
	def:
	<name>		any printable char
	<vec3>		3 floats separated by ',', spaces are trimed
	<float>		float value, spaces are trimed
	<color>		color value: #RRGGBB, '#' is optionnal
	<texture>	path to a .tga image file
	unspecified default values are "0"
-->

<!-- scene -->
<scene
	name="<name>" // default ""
	sky_color="<color>"
>

	<light
		pos="<vec3>"
		dir="<vec3>" // default "0, 1, 0"
		color="<color>" // default "#FFFFFF"
		brightness="<float>" // default "1"
		cutoff="<float>" // default "1"
	/>

	<sphere|plane|cone|cylinder
		pos="<vec3>"
		rot="<vec3>"
		shear="<vec3>"
		scale="<vec3>" // default "1"
		texture="<texture>"
		specular_map="<texture>"
		normal_map="<texture>"
		color="<color>" // only used if 'texture' is unset
		specular_color="<color>" // default "#FFFFFF", only used if 'specular_map' is unset
		ambient="<float>" // default "0.01"
		reflection="<float>"
		refract_index="<float>" // default "1", no refraction deviation if negative
		specular_exp="<float>" // default "128"
	/>

	<camera
		pos="<vec3>"
		dir="<vec3>" // default "0, 0, 1"
	/>

</scene>
```
