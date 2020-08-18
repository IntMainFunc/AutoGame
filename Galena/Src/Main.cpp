#include <Silver.h>

class GalenaApp : public Ag::App
{
private:
	bool m_IsRunning;
	Ag::Window* m_Window;

public:
	GalenaApp(Ag::Window* window = new Ag::Window())
		:m_IsRunning(true), m_Window(window)
	{
		AG_LOG("class(GalenaApp): Started.");
		m_Window->SetEventCallback(std::bind(&GalenaApp::OnEvent, this, std::placeholders::_1));
	}

	~GalenaApp()
	{
		AG_LOG("class(GalenaApp): Terminated.");
	}

	void OnRun()
	{
		AG_LOG("class(GalenaApp): Running.");

		while(m_IsRunning)
		{
			OnUpdate();
		}
	}

	void OnUpdate()
	{
		m_Window->OnUpdate();
	}

	void OnEvent(Ag::Event& event)
	{
		AG_LOG(event.GetDebug());

		Ag::EventDispatcher dispatcher(event);
		dispatcher.Dispatch<Ag::WindowCloseEvent>(std::bind(&GalenaApp::OnWindowClose, this, std::placeholders::_1));
	}

	bool OnWindowClose(Ag::WindowCloseEvent event)
	{
		delete m_Window;
		m_IsRunning = false;
		return true;
	}
};

int main()
{
	GalenaApp* galenaApp = new GalenaApp();
	galenaApp->OnRun();
	delete galenaApp;
}