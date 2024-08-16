#pragma once
#include "interfaces.h"

namespace cisim
{
	class Garrett
	{
		float _coeff = 0.3f;

	public:
		uint32_t boost(uint32_t speed)
		{
			return uint32_t(speed * _coeff);
		}
	};

	template <ITurbo T>
	class V6Turbo
	{
		bool _running = false;
		int32_t _speed = 0;

		T _turbo; // init from provider

	public:
		V6Turbo(T turbo)
			: _turbo(std::move(turbo))
		{}

		void start()
		{
			_running = true;
		}

		bool running()
		{
			return _running;
		}

		void accelerate()
		{
			_speed += 5 + _turbo.boost(_speed);
		}
	};

	class V8
	{
		bool _running = false;
		int32_t _speed = 0;

	public:
		void start()
		{
			_running = true;
		}

		bool running()
		{
			return _running;
		}

		void accelerate()
		{
			_speed += 10;
		}
	};

	class Automatic
	{
		uint32_t _gear = 0;
		const uint32_t _max_gear = 8;

	public:
		void on_start()
		{
			_gear = 1;
		}

		bool needs_shift(uint32_t speed)
		{
			return true; // depending on speed and gear determining this
		}

		void shift(ShiftDirection direction)
		{
			_gear = direction == ShiftDirection::Up
				? std::min(_max_gear, _gear + 1)
				: std::max(uint32_t(0), _gear - 1);
		}
	};

	class Manual
	{
		uint32_t _gear = 0;
		const uint32_t _max_gear = 5;

	public:
		void on_start()
		{
			_gear = 1;
		}

		bool needs_shift(uint32_t speed)
		{
			return true; // depending on speed and gear determining this
		}

		void shift(ShiftDirection direction)
		{
			_gear = direction == ShiftDirection::Up
				? std::min(_max_gear, _gear + 1)
				: std::max(uint32_t(0), _gear - 1);
		}
	};

	template <IEngine E, ITransmission T>
	class FordMustang
	{
		E _engine;
		T _transmission;

	public:
		FordMustang(E engine, T transmission)
			: _engine(std::move(engine))
			, _transmission(std::move(transmission)
		{}
	};
}