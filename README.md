# Task 1 (done with teacher)

Drawing of the missile and the source code exploration.

# Task 2 [1 point] (TASK 1_2-Y)

Draw the upper part of the ufo by glDrawArrays() command using the interleaved array (coordinates, colors).
* ufo's upper part is a hexagon whose triangles will be drawn separately (6 triangles)
* hexagon is inscribed in the circle with radius 1.0
* triangles will be drawn in two colors (yellow, magenta) that will be altering

append lines in data.h to:
* define contents of the interleaved array (coordinates + colors)
  => array ufoVertices[]
* 3 yellow triangles should be stored first, followed by 3 magenta triangles

append lines to render_stuff.cpp to:
* initialize ufo geometry in function initUfoGeometry()
 - initialize vertex array object
 - initialize vertex buffer object
 - interconnect vertex shader attributes (locations are stored in shader structure - input parameter) with buffers
 - buffers identifiers should be stored in the structure named geometry (input parameter) 
* draw ufo geometry in function drawUfo() 
 - upper part is drawn by two calls glDrawArrays() - magenta and yellow triangles separately
 
# Task 3 [1 point] (TASK 1_3-Y)

Draw the bottom part of the ufo by glDrawElements() command using the interleaved array (coordinates, colors).
* ufo's bottom part is also a hexagon whose triangles will be drawn separately (6 triangles)
* hexagon is inscribed in the circle with radius 1.0
* vertices on the border have the same color while vertex in the middle differs

append lines in data.h to:
* add contents of the interleaved array for the bottom part (coordinates + colors)
  => array ufoVertices[] (array is shared with the 1st task, append vertices to the end)
* define contents of the element array that includes indices of all vertices used for drawing
  => array ufoIndices[]

append lines to render_stuff.cpp to:
* initialize geometry for the bottom part of the ufo in function initUfoGeometry()
 - initialize vertex array object
 - initialize vertex buffer object
 - initialize element buffer object
 - interconnect vertex shader attributes (locations are stored in shader structure - input parameter) with buffers
 - buffers identifiers should be stored in the structure named geometry (input parameter) 
* draw ufo bottom part's geometry in function drawUfo() 
 - bottom part is drawn by calling glDrawElements() command


# Notes:

* missile vertices are stored in noninterlaced array (all vertices followed by all colors) 
* you can restart game by pressing "r" key
* parts of the source code that should be modified to fullfill the tasks are marked
  by the following sequence of comments:

    // ======== BEGIN OF SOLUTION - TASK 1_X-Y ======== //
    ...
    // ========  END OF SOLUTION - TASK 1_X-Y  ======== //


# What files do you have to edit:

TASK 1_2:
 -> render_stuff.cpp: 107, 111, 290
 -> data.h: 146

TASK 1_3:
 -> render_stuff.cpp: 116
 -> data.h: 155, 165
