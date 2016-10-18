# Task 1 [done with teacher]

Drawing of the missile and the source code exploration.

# Task 2 [1 point] `1_2-Y`

Draw the upper part of the UFO by `glDrawArrays()` command using the interleaved array (coordinates, colors).
* UFO's upper part is a hexagon whose triangles will be drawn separately (6 triangles)
* A hexagon is inscribed in the circle with radius 1.0
* Triangles will be drawn in two colors (yellow, magenta) that will be alternating

append lines in `data.h` to:
* Define contents of the interleaved array (coordinates + colors)
 - Array `ufoVertices[]`
* 3 yellow triangles should be stored first, followed by 3 magenta triangles

append lines to `render_stuff.cpp` to:
* Initialize ufo geometry in function `initUfoGeometry()`
 - Initialize vertex array object
 - Initialize vertex buffer object
 - Interconnect vertex shader attributes (locations are stored in shader structure - input parameter) with buffers
 - Buffers identifiers should be stored in the structure named geometry (input parameter) 
* Draw ufo geometry in function `drawUfo()`
 - Upper part is drawn by two calls `glDrawArrays()` - magenta and yellow triangles separately
 
# Task 3 [1 point] `1_3-Y`

Draw the bottom part of the ufo by `glDrawElements()` command using the interleaved array (coordinates, colors).
* UFO's bottom part is also a hexagon whose triangles will be drawn separately (6 triangles)
* A hexagon is inscribed in the circle with radius 1.0
* Vertices on the border have the same color while vertex in the middle differs

Append lines in `data.h` to:
* add contents of the interleaved array for the bottom part (coordinates + colors)
 - Array `ufoVertices[]` (array is shared with the 1st task, append vertices to the end)
* Define contents of the element array that includes indices of all vertices used for drawing
 - Array `ufoIndices[]`

Append lines to `render_stuff.cpp` to:
* Initialize geometry for the bottom part of the ufo in function `initUfoGeometry()`
 - Initialize vertex array object
 - Initialize vertex buffer object
 - Initialize element buffer object
 - interconnect vertex shader attributes (locations are stored in shader structure - input parameter) with buffers
 - Buffers identifiers should be stored in the structure named geometry (input parameter) 
* draw ufo bottom part's geometry in function `drawUfo()`
 - Bottom part is drawn by calling `glDrawElements()` command


# Notes:

* Missile vertices are stored in noninterlaced array (all vertices followed by all colors) 
* You can restart game by pressing "r" key
* Parts of the source code that should be modified to fullfill the tasks are marked by the following sequence of comments:

```c
// ======== BEGIN OF SOLUTION - TASK 1_X-Y ======== //
...
// ========  END OF SOLUTION - TASK 1_X-Y  ======== //
```

# What files do you have to edit:

## TASK `1_2-Y`
 - `render_stuff.cpp: 107, 111, 290`
 - `data.h: 146`

## TASK `1_3-Y`
 - `render_stuff.cpp: 116`
 - `data.h: 155, 165`
