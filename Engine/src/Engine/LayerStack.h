#pragma once

#include "Core.h"

#include <vector>

#include "Layer.h"

namespace Engine
{

	class E_API LayerStack
	{
	private:
		std::vector<Layer*> m_LayerStack;
		std::vector<Layer*>::iterator m_LayerInsert; // position were layers should be inserted
	public:
		LayerStack()
		{
			m_LayerInsert = m_LayerStack.begin();
		};
		~LayerStack()
		{
			for (Layer* layer : m_LayerStack)
				delete layer;
				//layer->~Layer();
		};

		void PushLayer(Layer* layer)
		{
			m_LayerInsert = m_LayerStack.emplace(m_LayerInsert, layer);
		};
		void PopLayer(Layer* layer)
		{
			auto element = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
			if (element != m_LayerStack.end())
			{
				m_LayerStack.erase(element);
				m_LayerInsert--;
			}
		};
		void PushOverlay(Layer* overlay)
		{
			m_LayerStack.emplace_back(overlay);
		};
		void PopOverlay(Layer* overlay)
		{
			auto element = std::find(m_LayerStack.begin(), m_LayerStack.end(), overlay);
			if (element != m_LayerStack.end())
			{
				m_LayerStack.erase(element);
			}
		};

		inline std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }; // end of stack
		inline std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }; // top of stack
	};



}