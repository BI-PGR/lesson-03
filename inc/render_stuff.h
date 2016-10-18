//----------------------------------------------------------------------------------------
/**
 * \file    render_stuff.h
 * \author  Jaroslav Sloup, Tomas Barak, Petr Felkel
 * \date    2013
 * \brief   Rendering stuff - drawing functions for models, etc.
 */
//----------------------------------------------------------------------------------------

#ifndef __RENDER_STUFF_H
#define __RENDER_STUFF_H

#include "data.h"


typedef struct MeshGeometry {
  GLuint        vertexBufferObject;   // identifier for the vertex buffer object
  GLuint        elementBufferObject;  // identifier for the element buffer object
  GLuint        vertexArrayObject;    // identifier for the vertex array object
  unsigned int  numTriangles;         // number of triangles in the mesh

} MeshGeometry;

typedef struct Object {
  glm::vec3 position;
  glm::vec3 direction;
  float     speed;
  float     size;

  bool destroyed;

  float startTime;
  float currentTime;

} Object;

typedef struct SpaceShipObject : public Object {

  float viewAngle; // in degrees

} SpaceShipObject;

typedef struct AsteroidObject : public Object {

  float rotationSpeed;

} AsteroidObject;

typedef struct MissileObject : public Object {

} MissileObject;

typedef struct UfoObject : public Object {

  float     rotationSpeed;
  glm::vec3 initPosition;

} UfoObject;


typedef struct _commonShaderProgram {
  // identifier for the program
  GLuint program;          // = 0;
  // vertex attributes locations
  GLint posLocation;       // = -1;
  GLint colorLocation;     // = -1;
  GLint PVMmatrixLocation;    // = -1;
} SCommonShaderProgram;


void drawSpaceShip(SpaceShipObject* spaceShip, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix);
void drawAsteroid(AsteroidObject* asteroid, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix);
void drawMissile(MissileObject* missile, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix);
void drawUfo(UfoObject* ufo, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix);

void initializeShaderPrograms();
void cleanupShaderPrograms();

void initializeModels();
void cleanupModels();

#endif // __RENDER_STUFF_H
