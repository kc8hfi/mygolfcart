/*
Copyright (c) 2006-2009, Fred Emmott <mail@fredemmott.co.uk>

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#include "Joystick.h"

#include <QBasicTimer>
#include <QDebug>

#define POLL_INTERVAL 20

Joystick::Joystick(int js)
{
	// Sure, we're only using the Joystick, but SDL doesn't work if video isn't initialised
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);

	Q_ASSERT(js < attachedJoysticks());
	Q_ASSERT(js >= 0);

	m_joystick = SDL_JoystickOpen(js);

	m_timer = new QBasicTimer();
	m_timer->start(POLL_INTERVAL, this);
}

int Joystick::currentJoystick()
{
	return SDL_JoystickIndex(m_joystick);
}

QString Joystick::joystickName(int js)
{
	Q_ASSERT(js < attachedJoysticks());
	Q_ASSERT(js >= 0);
	return QString(SDL_JoystickName(js));
}

void Joystick::setJoystick(int js)
{
	Q_ASSERT(js < attachedJoysticks());
	Q_ASSERT(js >= 0);

	SDL_JoystickClose(m_joystick);
	m_joystick = SDL_JoystickOpen(js);
}

Joystick::~Joystick()
{
	delete m_timer;
	SDL_JoystickClose(m_joystick);
	SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
}

void Joystick::timerEvent(QTimerEvent* ignored)
{
	SDL_Event event;

	m_timer->stop();
	while ( SDL_PollEvent(&event) )
	{
		switch(event.type)
		{
		case SDL_JOYAXISMOTION:
			emit axisEvent(event.jaxis.axis, event.jaxis.value);
			break;
		case SDL_JOYBUTTONDOWN:
			emit buttonPress(event.jbutton.button);
			break;
		case SDL_JOYBUTTONUP:
			emit buttonRelease(event.jbutton.button);
			break;
		}
	}
	m_timer->start(POLL_INTERVAL, this);
}

int Joystick::attachedJoysticks()
{
	return SDL_NumJoysticks();
}
