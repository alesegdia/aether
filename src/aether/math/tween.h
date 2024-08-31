#pragma once

#include <list>
#include <memory>
#include <functional>

#include <aether/aether.h>

#include <tweeny.h>

namespace aether {

	class Timer
	{
	public:
		Timer(float secondsToExpire)
		{
			m_expireTimeMs = uint64_t(secondsToExpire * 1e6);
		}

		Timer(uint64_t microsecondsToExpire)
		{
			m_expireTimeMs = microsecondsToExpire;
		}

		bool Update(uint64_t delta)
		{
			if (!m_expired)
			{
				m_currentTime += delta;
				if (m_currentTime >= m_expireTimeMs)
				{
					m_expired = true;
					DispatchExpire();
				}
			}
			return m_expired;
		}

		bool IsExpired()
		{
			return m_expired;
		}

		Timer& OnExpire(std::function<void(void)> onExpire)
		{
			m_onTimerExpiredCallbacks.push_back(onExpire);
			return *this;
		}

	private:
		void DispatchExpire()
		{
			for (const auto& item : m_onTimerExpiredCallbacks)
			{
				item();
			}
		}

		uint64_t m_expireTimeMs;
		uint64_t m_expired = false;
		uint64_t m_currentTime = 0;
		std::vector<std::function<void(void)>> m_onTimerExpiredCallbacks;

	};

	class TimerManager
	{
	private:
		TimerManager() = default;

	public:
		Timer& CreateTimer(float secondsToExpire)
		{
			m_allTimers.push_back(std::make_shared<Timer>(secondsToExpire));
			return *m_allTimers.back();
		}

		Timer& CreateTimer(uint64_t microsecondsToExpire)
		{
			m_allTimers.push_back(std::make_shared<Timer>(microsecondsToExpire));
			return *m_allTimers.back();
		}

		tweeny::tween<float>& from(float v)
		{
			auto tween = tweeny::from(v);
			m_floatTweens.push_back(tween);
			return m_floatTweens.back();
		}

		tweeny::tween<float, float>& from(float x, float y)
		{
			auto tween = tweeny::from(x, y);
			m_floatPairTweens.push_back(tween);
			return m_floatPairTweens.back();
		}

		void Update(uint64_t delta)
		{
			auto iterator = m_allTimers.begin();
			while (iterator != m_allTimers.end())
			{
				auto timer = *iterator;
				auto expired = timer->Update(delta);
				if (expired)
				{
					m_allTimers.erase(iterator++);
				}
				else
				{
					++iterator;
				}
			}

			ClearTweenList(m_floatTweens);
			ClearTweenList(m_floatPairTweens);
		}

		template <typename T>
		void ClearTweenList(T list)
		{
			auto iterator = list.begin();
			while (iterator != list.end())
			{
				auto tween = *iterator;
				auto expired = tween.progress() >= 1.f;
				if (expired)
				{
					list.erase(iterator++);
				}
				else
				{
					++iterator;
				}
			}
		}

		static TimerManager& GetInstance()
		{
			return s_timerManager;
		}

		void ClearAllTimers()
		{
			m_allTimers.clear();
		}

	private:
		std::list<std::shared_ptr<Timer>> m_allTimers;
		std::list<tweeny::tween<float>> m_floatTweens;
		std::list<tweeny::tween<float, float>> m_floatPairTweens;

		static TimerManager s_timerManager;
	};

	class ITweenStorage
	{
	public:
		virtual ~ITweenStorage() = default;
		virtual void Step(uint32_t delta) = 0;
	};

	template <typename T>
	class TweenStorage : public ITweenStorage
	{
	public:

	};
	              
	/*
	class TweenManager
	{
	public:
		void Step(uint32_t delta)
		{
			UpdateTweens(delta, m_intTweens);
		}

		tweeny::tween<int>& from(int startValue)
		{
			auto tween =  tweeny::from(startValue);
			m_intTweens.push_back(tween);
			return m_intTweens.back();
		}

	private:
		template <typename T>
		void UpdateTweens(uint32_t delta, std::vector<tweeny::tween<T>>& v)
		{
			for (auto& i : v)
			{
				i.step(delta);
			}
		}

		std::vector<tweeny::tween<int>> m_intTweens;

	};
	*/

}
