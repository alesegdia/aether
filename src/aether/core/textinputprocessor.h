#pragma once

#include "aether/core/input.h"
#include "aether/core/iinputprocessor.h"

namespace aether::core {


class TextInputProcessor : public IInputProcessor
{
public:
	virtual ~TextInputProcessor()
	{

	}

	// IInputProcessor interface
	void OnKeyUp(aether::core::KeyCode key) override
	{
		if( IsShift(key) )
		{
			m_mayus = false;
		}
	}

	void OnKeyDown(aether::core::KeyCode key) override
	{
		if( key >= aether::core::KeyCode::A && key <= aether::core::KeyCode::Z )
		{
			pushChar( char(int(key) - int(aether::core::KeyCode::A)) + (m_mayus?'A':'a') );
		}
		else if( key >= aether::core::KeyCode::K0 && key <= aether::core::KeyCode::K9 )
		{
			pushChar( char(int(key) - int(KeyCode::A)) + '0' );
		}
		else if( key == KeyCode::Fullstop)
		{
			pushChar( '.' );
		}
		else if( key == KeyCode::Space )
		{
			pushChar( ' ' );
		}
		else if( key == aether::core::KeyCode::Backspace )
		{
			popChar();
		}
		else if( IsShift(key) )
		{
			m_mayus = true;
		}
	}

	void pushChar( char c )
	{
		if( m_cursor < 128 - 1 )
		{
			m_buffer[m_cursor++] = c;
			m_buffer[m_cursor] = '\0';
		}
	}

	void popChar()
	{
		if( m_cursor > 0 )
		{
			m_buffer[--m_cursor] = '\0';
		}
	}

	const char* str()
	{
		return m_buffer;
	}

private:
	bool IsShift(KeyCode key)
	{
		return key == KeyCode::LShift || key == KeyCode::RShift;
	}

	char m_buffer[128];
	size_t m_cursor = 0;
	bool m_mayus = false;

};

}