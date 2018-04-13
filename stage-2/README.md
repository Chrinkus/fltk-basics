# Stage 2
### Begin the abstract interface

Minimally attempt to abstract the FLTK functionality to classes based on the Stroustrup "simple interface". Only write what is needed.

Design Decision: In the Stroustrup library, the Shape class offers a virtual target for derived classes to `draw_lines()` and calls that function from within Shape's own public `draw()` member function. The base class takes care of the color management and leaves only the line drawing to the derived shapes (circle, polygon, etc).

Though I appreciate the separation of responsibilities I choose for the moment to set colors and draw my lines from each derived shape class. Perhaps after creating many different shapes and observing that the color-setting code is indeed repetitive I will choose to refactor and bring my implementation closer to the text's.
