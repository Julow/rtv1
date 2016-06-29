from random import choice, uniform, randint
import sys

SPHERE_ONLY = True
SIZE = 200

print "<scene>"

for i in range(500 if len(sys.argv) <= 1 else int(sys.argv[1])):
	print """	<%s pos="%f, %f, %f" rot="%f, %f, %f" scale="%f" color="#%.2x%.2x%.2x" />""" % (
		"sphere" if SPHERE_ONLY else choice(["sphere", "cone", "cylinder", "plane"]),
		uniform(-SIZE, SIZE), uniform(0, 25), uniform(-SIZE, SIZE),
		uniform(-1, 1), uniform(-1, 1), uniform(-1, 1),
		uniform(0.5, 3),
		randint(0, 255), randint(0, 255), randint(0, 255),
	)

print """
	<plane pos="0, %f, %f" rot="1, 0, 0" scale="%f" reflection="0.7" color="#dddddd" />
	<plane scale="%f" color="map:tests/wall.tga" />

	<light pos="0, 100, 0" />

	<camera pos="0, %f, %f" dir="0, -1, 0.8" />
	<camera pos="0, %f, %f" dir="0, -1, -0.8" />

</scene>""" % (SIZE, SIZE, SIZE*2, SIZE*2, SIZE*1.5, -SIZE, SIZE*1.5, SIZE)
