#pragma once

#ifdef E_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main()
{
	Engine::Log::Init();
	ENGINE_CORE_INFO("Logger Initialized... \n");

	Engine::Application* app = Engine::CreateApplication();
	app->start();
	delete app;
}

#endif