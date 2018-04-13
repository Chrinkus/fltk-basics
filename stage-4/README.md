# Stage 4
### Add shapes and functionality

Line and Ellipse are added.

## FLTK Ellipses
An important thing to understand about creating an ellipse with FLTK's `fl_arc()` function is that the arguments are not what you would expect from a circle-type shape. Instead of requiring a center point and radius (or in the case of ellipses, the major and minor radii) you pass a point to the top left corner of a box that would contain the desired shape and the major and minor _diameters_.

Thus in my implementation the point that gets added to the points vector is the `center.x - a, center.y - b`. This is awkward and weird compared to other drawing libraries I've used.
