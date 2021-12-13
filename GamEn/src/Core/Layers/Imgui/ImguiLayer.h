#pragma once

// ui for debug only, basic interface as console

#include "Core/Layers/Layer.h"
#include "Core/Events/AppEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"

namespace GamEn {

	class GE_API ImguiLayer :public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer() = default;

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onEvent(Event& e) override;

		virtual void onImguiRender() override;

		void begin();
		void end();
	private:
		float _time = 0.0f;
	};

}