/*
Copyright (c) 2006-2009, Fred Emmott <mail@fredemmott.co.uk>

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <QObject>
#include <QString>

#include <SDL.h>

class QBasicTimer;
class QTimerEvent;

class Joystick : public QObject
{
	Q_OBJECT;
	public:
		Joystick(int jsNumber = 0);
		~Joystick();

		int attachedJoysticks();
		int currentJoystick();
		QString joystickName(int id);
	public slots:
		void setJoystick(int jsNumber);
	private slots:
		virtual void timerEvent(QTimerEvent* event);
	signals:
		void axisEvent(int axis, int value);
		void buttonPress(int button);
		void buttonRelease(int button);
	private:
		QBasicTimer* m_timer;
		SDL_Joystick* m_joystick;
};

#endif
