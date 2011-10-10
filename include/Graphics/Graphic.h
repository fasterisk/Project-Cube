/*
 * header file for Graphic class
 * written by: christian moellinger <ch.moellinger@gmail.com>
 * 10/2010 Projekt "BambooIsland"
 * 03/2011 Projekt "Free Pool"
 */

#ifndef __realtime_lu_graphic
#define __realtime_lu_graphic

// stl includes
#include <memory>
#include <list>
#include <string>
#include <map>

// glm includes
#include <glm/core/type_mat4x4.hpp>

// settings class
#include "Settings.h"

// eventmanager
#include "EventManager.h"

// forward declarations
class SceneObject;
class SceneObject_RenderTarget;
class Camera;
class ShaderManager;
class TextureManager;

class Graphic : EventManager::IEventListener
{
public:
    /*! \name Nested classes */
    //@{
        /// forward declarations
        class GlfwWindow;
        class Camera;

        class IRenderTarget
        {
        public:
            virtual void ClearBuffers() = 0;
            virtual void SwapBuffers() = 0;

        protected:
            IRenderTarget() {}
            virtual ~IRenderTarget() {}
        };

        class IInputEventListener
        {
        public:
            /// handles keyboard events and sends signals to listener
            virtual void ItlHandleKeyboardEvent(int iKeyIdentifier, int iNewKeyState) = 0;

            /// handles mouse movements and sends signals to the listener
            virtual void ItlHandleMousePos(int iX, int iY) = 0;

            /// handles mouse wheel input events and sends signals to the listener
            virtual void ItlHandleMouseWheel(int iPosition) = 0;

            /// handles mouse button events and sends signals to the listener
            virtual void ItlHandleMouseButton(int iButton, int iAction) = 0;
        };

        class QtWidgetWrapper : public IRenderTarget
        {
            // to be done ...
            // this class is supposed to use an existing QT widget as the render target
        };



        class Scene
        {
        public:
            static std::shared_ptr<Scene> Create(std::shared_ptr<Graphic::Camera> spCamera);

            void CallRenderPath();

        private:
            std::shared_ptr<SceneObject> m_spRenderPath;
        };

       /* class ISceneObject
        {

        };

        class LoadedModel : public ISceneObject
        {

        };

        class Cube : public ISceneObject
        {

        };

        class BasicLight : public ISceneObject
        {

        };

        class Node : public ISceneObject
        {

        };*/
    //@}

    /*! \name Nested classes */
    //@{
	class Camera : public EventManager::IEventListener
        {
        public:
            /*! \name Construction / Destruction */
            //@{
                /// constructor
                Camera();
            //@}

            /*! \name Public attributes */
            //@{
                /// returns the ModelviewMatrix
                glm::mat4 GetViewMatrix() const;

                /// returns the projection matrix
                glm::mat4 GetProjectionMatrix() const;
            //@}

	    /*! \name EventManager::IEventListener interface */
	    //@{
		virtual bool OnEvent(std::shared_ptr<EventManager::IEvent> spEvent);
	    //@}


            /*! \name Methods to manipulate the camera view direction or position */
            //@{
                /// rotates the camera in vertical direction
                void RotateVertical(float fValue);

                /// rotates the camera in horizontal direction
                void RotateHorizontal(float fValue);

                /// adds the given vector to the move vector.
                /// the move vector is always relative to the
                /// current camera viewing direction
                void AddToMoveVector(glm::vec3 vVector);

                /// moves the camera along the move vector.
                /// must be called! otherwise, the view matrices are not up to date
                void Move(float fFactor);
            //@}

            /*! \name Methods to set up the projection */
            //@{
                /// sets up an perspective projection matrix
                void SetPerspectiveProjection (float fFieldOfView, float fAspectRatio, float fNearPlane, float fFarPlane);

                /// sets up an orthographic projection matrix
                void SetOrthoProjection (float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar);
            //@}

	    /*! \name Other Methods */
	    //@{
                void SetActive(bool bActive) { m_bActive = bActive; }
	    //@}

        private:


	    /*! \name Private members */
            //@{
		bool        m_bActive;		    ///< whether this camera is the currently active one
		bool        m_bInitialized;         ///< whether the projection matrix was set up
                glm::mat4   m_m4ProjectionMatrix;
                glm::mat4   m_m4ViewMatrix;
                glm::vec3   m_v3MoveVector;
                glm::vec3   m_v3CameraPosition;

                float       m_fRotationHorizontal;
                float       m_fRotationVertical;
            //@}
        };

    //@}

    /*! \name Construction / Destruction */
    //@{
        /// constructor
        Graphic();

        /// destructor
        ~Graphic();
    //@}

    /*! \name Initialization / Cleanup */
    //@{

        /// initializes the open gl stuff and creates the window + context.
        bool InitializeOpenGL();

    //@}


    /*! \name EventManager::IEventListener interface */
    //@{
	virtual bool OnEvent(std::shared_ptr<EventManager::IEvent> spEvent);
    //@}

    /*! \name Public Attributes */
    //@{
	/// returns the responsible shader manager for this graphics instance
	ShaderManager * GetShaderManager();

	/// returns the responsible texture manager for this graphics instance
	TextureManager * GetTextureManager();
    //@}

    /*! \name Methods for render */
    //@{
        void Render();
    //@}

    /*! \name new methods - refactoring - comments tbd */
    //@{
        void SingleRenderCall(std::shared_ptr<IRenderTarget> spRenderTarget, std::shared_ptr<Camera> spCamera, std::shared_ptr<Scene> spScene);

        int AddRenderLoop(std::shared_ptr<IRenderTarget> spRenderTarget, std::shared_ptr<Camera> spCamera, std::shared_ptr<Scene> spScene);

        void RemoveRenderLoop(int iLoopID);
    //@}

private:
    /*! \name new methods - refactoring - comments tbd */
    //@{
        struct TItlRenderLoop
        {
            std::shared_ptr<IRenderTarget> spRenderTarget;
            std::shared_ptr<Camera> spCamera;
            std::shared_ptr<Scene> spScene;
        };

        std::map<int, TItlRenderLoop>   m_mRenderLoops;
    //@}

    /*! \name Internal helper methods */
    //@{
	/// load basic settings
	void ItlLoadSettings();
    //@}

    /*! \name Private members */
    //@{
	std::map<std::string, std::shared_ptr<SceneObject> >    m_vRenderPaths;

	static int	    s_iInstances;		///< how many instances are created ?
	static Graphic *    s_pInstance;

	Settings::TSettingsGroup * m_pSettings;		///< the settings group used for the graphics engine
    //@}
};

#endif
