#pragma once

#include <iostream>
#include <vector>

#include "Core.h"

#include "Events/Event.h"
#include "utils/Logger.h"
//#include "window.h"
#include "utils/timer.h"
#include "Layer.h"
#include "LayerStack.h"

namespace Engine
{

	class E_API Application
	{
	private:
		//graphics::Window* m_Window;
		//Timer* m_Timer;

		LayerStack m_LayerStack;
		EventQueue m_EventQueue;

		bool m_Running;

	public: // TODO: find a better way then making constructor and destructor public // because you should not create application
		Application();
		virtual ~Application();

		void start();

	protected:
		//graphics::Window* createWindow(std::string name, int width, int height);

		virtual void init() = 0;

		void OnEvent(Event* event);

		// callbacks for events
		void OnWindowCloseEvent(Event* event);

		// 
		virtual void PushLayer(Layer* layer);
		virtual void PushOverlay(Layer* overlay);

	private:
		void run();
	};

	// created by client
	Application* CreateApplication();

};