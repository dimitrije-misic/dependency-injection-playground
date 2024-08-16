#pragma once
#include <concepts>

namespace cisim
{
	enum class ShiftDirection
	{
		Up,
		Down
	};

	template <typename T>
	concept ITurbo = requires (T t, uint32_t speed)
	{
		{ t.boost(speed) } -> std::convertible_to<uint32_t>;
	};

	template <typename E>
	concept IEngine = requires (E e)
	{
		{ e.running() } -> std::convertible_to<bool>;
		{ e.speed() } -> std::convertible_to<uint32_t>;
		{ e.start() };
		{ e.accelerate() };
	};

	template <typename T>
	concept ITransmission = requires (T t, uint32_t speed, ShiftDirection direction)
	{
		{ t.start() };
		{ t.needs_shift(speed) } -> std::convertible_to<bool>;
		{ t.shift(direction) };
	};
	
	template <typename T>
	concept IVehicle = requires (T t)
	{
		{ t.start() };
		{ t.run() };
	};
}