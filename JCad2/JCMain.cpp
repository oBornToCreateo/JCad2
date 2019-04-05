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
		DoFrame();
	}
}

void JCMain::DoFrame()
{
	const float c = sin( timer.Peek() ) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer( c,c,1.0f );
	wnd.Gfx().DrawTestTriangle( timer.Peek() );
	wnd.Gfx().EndFrame();
}