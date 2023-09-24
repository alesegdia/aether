#pragma once

#include <string>

#include "lua.h"

namespace aether::lua
{

	class LuaState
	{
	public:
		LuaState()
		{
			m_luaState = luaL_newstate();
			luaL_openlibs(m_luaState);
		}

		int DoFile(const char* luaScriptPath)
		{
			if (luaL_dofile(m_luaState, "assets/jojo/boot.lua") == LUA_OK)
			{
				lua_pop(m_luaState, lua_gettop(m_luaState));
			}
			else
			{
				return -1;
			}
			return 0;
		}

		std::string GetGlobalString(const char* varName, int& status)
		{
			std::string outputString;
			lua_getglobal(m_luaState, varName);
			if(lua_isstring(m_luaState, -1))
			{
				const char* strC = lua_tostring(m_luaState, -1);
			}
		}

	private:
		lua_State* m_luaState;

	};
	
}