#include "JCMain.h"

JCMain::JCMain()
	:
	wnd( 1440,900,"  Jezier Cad 2" )
{}
int JCMain::Go()
{
	while( true )
	{
		// process all messages pending, but to not block for new messages
		if( const auto ecode = Window::ProcessMessages() )
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		ProcesImput();
		UpdateModel();
		wnd.Gfx().ClearBuffer(0.0f, 0.0f, 0.0f);
		Render();
		wnd.Gfx().EndFrame();

	}
}



void JCMain::ProcesImput()
{
}

void JCMain::UpdateModel()
{
	
}

void JCMain::Render()
{
	wnd.Gfx().DrawTestTriangle(timer.Peek());

}
