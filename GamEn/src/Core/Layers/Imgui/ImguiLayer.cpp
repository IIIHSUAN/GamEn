#include "GE_pch.h"
#include "ImguiLayer.h"

#include "Core/Manager.h"

#include "ref/OpenGL/imgui_impl_opengl3.h"  // readyMade renderer
#include <GLFW/glfw3.h>
#include <Glad/glad.h>

namespace GamEn {

	ImguiLayer::ImguiLayer() : Layer("Imgui Layer")
	{
		
	}

	void ImguiLayer::onAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors | ImGuiBackendFlags_HasSetMousePos;

		// tmp template only
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
		
		ImGui_ImplOpenGL3_Init("#version 410 core");
	}

	void ImguiLayer::onDetach()
	{
	}

	void GamEn::ImguiLayer::onUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Manager& m = Manager::get();
		io.DisplaySize = ImVec2(m.getWindow().getWidth(), m.getWindow().getHeight());

		float time = glfwGetTime();
		io.DeltaTime = _time > 0.0f ? time - _time : 1.0f / 60.0f;
		_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool isVisible = true;
		ImGui::ShowDemoWindow(&isVisible);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::onEvent(Event & e)
	{
		EventHandler eHandler(e);

		eHandler.dispatch<MouseButtonPressedEvent>(BIND_FUNC(ImguiLayer::bottonPress));
		eHandler.dispatch<MouseButtonReleasedEvent>(BIND_FUNC(ImguiLayer::bottonRelease));
		eHandler.dispatch<MouseMovedEvent>(BIND_FUNC(ImguiLayer::mouseMove));
		eHandler.dispatch<MouseScrolledEvent>(BIND_FUNC(ImguiLayer::mouseScroll));

		eHandler.dispatch<KeyPressedEvent>(BIND_FUNC(ImguiLayer::keyPress));
		eHandler.dispatch<KeyReleasedEvent>(BIND_FUNC(ImguiLayer::keyRelease));
		eHandler.dispatch<KeyTypedEvent>(BIND_FUNC(ImguiLayer::keyType));

		eHandler.dispatch<WindowResizeEvent>(BIND_FUNC(ImguiLayer::windowResize));
	}

	bool ImguiLayer::bottonPress(MouseButtonPressedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.getMouseButton()] = true;
		return false;
	}
	bool ImguiLayer::bottonRelease(MouseButtonReleasedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.getMouseButton()] = false;
		return false;
	}
	bool ImguiLayer::mouseMove(MouseMovedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.getX(), e.getY());
		return false;
	}
	bool ImguiLayer::mouseScroll(MouseScrolledEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel = e.getOffsetY();
		io.MouseWheelH = e.getOffsetX();
		return false;
	}
	bool ImguiLayer::keyPress(KeyPressedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		return false;
	}
	bool ImguiLayer::keyRelease(KeyReleasedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = false;
		return false;
	}
	bool ImguiLayer::keyType(KeyTypedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int key = e.getKeyCode();
		if (key > 0 && key < 0x10000)
			io.AddInputCharacter((USHORT)key);
		return false;
	}
	bool ImguiLayer::windowResize(WindowResizeEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.getWidth(), e.getHeight());
		return false;
	}
}