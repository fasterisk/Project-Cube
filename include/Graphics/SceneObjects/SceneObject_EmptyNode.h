/*
 * header file for SceneObject_EmptyNode class
 * written by: christian moellinger <ch.moellinger@gmail.com>
 * 03/2011 Project "Free Pool"
 */

#ifndef __freepool_sceneobject_emptynode_header
#define __freepool_sceneobject_emptynode_header

#include "Graphics/SceneObject.h"

/**
  * A SceneObject_EmptyNode is a SceneObject which can be placed in the SceneGraph,
  * but it does nothing - it's only a dummy node.
*/

class SceneObject_EmptyNode : public SceneObject
{
public:
    /*! \name Access to Vertices / Indices */
    //@{
	virtual float *GetVertices() { return NULL; };
	virtual int *GetIndices() { return NULL; };
	virtual int NumIndices() { return 0; };
	virtual int NumVertices() { return 0; };
    //@}


protected:
    /*! \name SceneObject Interface */
    //@{
	/*! this method is called before the render() method calls the render() methods of the children,
	    and can be used to bind a fbo (to render the children in this fbo) or something like that */
	virtual void ItlPreRenderChildren() {};

	/*! this method is called after all children were rendered,
	    and can be used to unbind a fbo or something like that */
	virtual void ItlPostRenderChildren() {};

	/*! this method is called before the sceneobject itself gets rendered.
	    shaders and things like that should be activated in this method */
	virtual void ItlPreRender() {};

	/*! this method is called to render the sceneobject.
	    Attention: If the correct shader program is not bound yet (should be done in itlBeforeRender()),
	    the transform matrices must be sent again */
	virtual void ItlRender() {};

	/*! this method is called after rendering the sceneobject itself. Cleaning up can be done here */
	virtual void ItlPostRender() {};
    //@}
};

#endif