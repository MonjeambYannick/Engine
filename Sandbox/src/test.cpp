#include <Engine.h>

#include <windows.h>

class TestLayer : public Engine::Layer 
{
public:
	TestLayer() 
		:Layer()
	{
	};
	~TestLayer() 
	{
	};
	void OnAttach() override
	{	
	};
	void OnDetach() override
	{
	};
	void OnUpdate() override 
	{
	};
	void OnEvent(Engine::Event* event) 
	{
		switch (event->GetType())
		{
			case Engine::EventType::WindowClose:
				ENGINE_CORE_INFO("WindowClosed Event handled...");
				event->m_Handled = true;
		}
	};
};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

	void init() 
	{
		PushLayer(new TestLayer());

		Engine::WindowCloseEvent* e1 = new Engine::WindowCloseEvent();
		Engine::WindowCloseEvent* e2 = new Engine::WindowCloseEvent();
		Engine::WindowCloseEvent* e3 = new Engine::WindowCloseEvent();
		Engine::WindowCloseEvent* e4 = new Engine::WindowCloseEvent();
		
		Sleep(1000);

		OnEvent(e1);
		OnEvent(e2);
		OnEvent(e3);
		OnEvent(e4);
	};
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}