#pragma once

#include <list>
#include <memory>
#include <functional>

#include <aether/aether.h>

#include <tweeny.h>

namespace aether {
namespace math {

	class Timer
	{
	public:
		Timer(float secondsToExpire)
		{
			m_expireTimeMs = aether::core::get_time() + uint64_t(secondsToExpire * 10e6);
		}

		Timer(uint64_t microsecondsToExpire)
		{
			m_expireTimeMs = aether::core::get_time() + microsecondsToExpire;
		}

		bool Update(uint64_t currentTime)
		{
			if (!m_expired && currentTime >= m_expireTimeMs)
			{
				m_expired = true;
				onTimerExpired();
			}
		}

	private:
		uint64_t m_expireTimeMs;
		uint64_t m_expired = false;
		std::function<void(void)> onTimerExpired;

	};

	class TimerManager
	{
	private:
		TimerManager() = default;

	public:

		std::shared_ptr<Timer> CreateTimer(float secondsToExpire)
		{
			m_allTimers.push_back(std::make_shared<Timer>(secondsToExpire));
		}

		std::shared_ptr<Timer> CreateTimer(uint64_t microsecondsToExpire)
		{
			m_allTimers.push_back(std::make_shared<Timer>(microsecondsToExpire));
		}

		void Update()
		{
			auto time = aether::core::get_time();
			for (const auto& timer : m_allTimers)
			{
				timer->Update(time);
			}
		}

		static TimerManager& Get()
		{
			return s_timerManager;
		}

	private:
		std::vector<std::shared_ptr<Timer>> m_allTimers;

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


}
}
