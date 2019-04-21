#include "Application.h"

namespace Engine
{

	Application::Application()
	{

	}

	Application::~Application()
	{
		//delete m_Timer;
		//delete m_Window;
	}

	void Application::run()
	{

		while (m_Running)
		{

			// distributing the events
			for (auto layer = m_LayerStack.end(); layer != m_LayerStack.begin(); /*layer--*/)
			{
				for (auto event = m_EventQueue.queue.begin(); event != m_EventQueue.queue.end(); )
				{

					(*--layer)->OnEvent(*event);
					if ((*event)->m_Handled == true)
					{
						m_EventQueue.queue.erase(event);
						break;
					}
					if (event != m_EventQueue.queue.end())
					{
						event++;
					}
				}
			}

			// updating all the layers
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

		}
	};

	void Application::start()
	{
		init();
		run();
	};

	void Application::OnEvent(Event* event) 
	{
		m_EventQueue.queue.push_back(event);
		ENGINE_CORE_INFO("Added new Event to EventQueue...");
	};

	void Application::OnWindowCloseEvent(Event* event)
	{
		
	};

	/*graphics::Window* Application::createWindow(std::string name, int width, int height)
	{
		//m_Window = new graphics::Window(name, width, height);
		return m_Window;
	}*/

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	};
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	};

}