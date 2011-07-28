/*
 * header file for SceneObject_Camera class
 * written by: Christian Möllinger <ch.moellinger@gmail.com>
 * 03/2011, Project "BambooEngine", Projekt "Free Pool"
 */

#ifndef __BambooEngine_Header_SceneObject_Camera
#define __BambooEngine_Header_SceneObject_Camera

#include <memory>
#include "Graphics/SceneObject.h"
#include "Graphics/Graphic.h"


class SceneObject_Camera : public SceneObject
{
public:
    SceneObject_Camera(std::shared_ptr<Graphic::Camera> spCamera, bool bSetMatrices=true);

    /*! \name Operations */
    //@{
	//! renders the sceneobject and its children (first, it renders the children).
	/*! First, the itlTestSkipRendering() method is called, if false, itlBeforeRender() gets called.
	 *  Then, the render()-method of the children is called and finally the own itlRender()-method is called. */
	virtual void Render(std::shared_ptr<TItlRenderInfo> pCurrentRenderInfo);
    //@}
protected:
    /*! \name SceneObject Interface */
    //@{
	virtual void ItlPreRenderChildren() {};
	virtual void ItlPostRenderChildren() {};
	virtual void ItlPreRender();
	virtual void ItlRender();
	virtual void ItlPostRender();
    //@}

private:
    std::shared_ptr<Graphic::Camera> m_spCamera;
    bool m_bSetMatrices;

    GLuint m_nVertexArrayObject;	///< The opengl name (=unsigned int) of the vertex array object
    GLuint m_nVertexBufferObject;	///< The opengl name (=unsigned int) of the vertex buffer object
    GLuint m_nIndexBufferObject;	///< The opengl name (=unsigned int) of the index buffer object
    int m_iIndexArraySize;		///< The size of the index array
};

#endif