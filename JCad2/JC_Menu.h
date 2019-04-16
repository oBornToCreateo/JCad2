#pragma once

#include <queue>


class JC_Menu
{
	friend class Window;

private:
	class Event
	{
	public:
		enum class Type
		{
			Null,
			TwoPointCircle,
			ThreePointCircle,
			PoliLine,
			BezierCurve,
			Count
		};
	private:
		Type type;
		bool leftIsPressed;
		bool rightIsPressed;

	public:
		Event(Type type, const Mouse& parent) noexcept
			:
			type(type),
			leftIsPressed(parent.leftIsPressed),
			rightIsPressed(parent.rightIsPressed),
			x(parent.x),
			y(parent.y)
		{}
		Type GetType() const noexcept
		{
			return type;
		}
		std::pair<int, int> GetPos() const noexcept
		{
			return{ x,y };
		}
		int GetPosX() const noexcept
		{
			return x;
		}
		int GetPosY() const noexcept
		{
			return y;
		}
		bool LeftIsPressed() const noexcept
		{
			return leftIsPressed;
		}
		bool RightIsPressed() const noexcept
		{
			return rightIsPressed;
		}
	};

private:
	static constexpr unsigned int bufferSize = 16u;


	std::queue<Event> buffer;
public:
	void Draw();
	void Update();
	void ProcessInput();
};