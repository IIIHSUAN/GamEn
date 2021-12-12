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

		virtual void onAttach();
		virtual void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& e) override;
	private:
		float _time = 0.0f;

		// event callback for imgui
		bool bottonPress(MouseButtonPressedEvent& e);
		bool bottonRelease(MouseButtonReleasedEvent& e);
		bool mouseMove(MouseMovedEvent& e);
		bool mouseScroll(MouseScrolledEvent& e);

		bool keyPress(KeyPressedEvent& e);
		bool keyRelease(KeyReleasedEvent& e);
		bool keyType(KeyTypedEvent& e);

		bool windowResize(WindowResizeEvent& e);
	};

}