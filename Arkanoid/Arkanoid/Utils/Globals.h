#pragma once

namespace Globals
{
	enum class UpdateState
	{
		Continue = 1,
		Stop,
		Error
	};

	constexpr int SCREEN_WIDTH = 964;
	constexpr int SCREEN_HEIGHT = 950;

	constexpr int TOP_PANEL_HEIGHT = 150;

	constexpr int ARENA_WIDTH = 900;
	constexpr int ARENA_HEIGHT = 800;
	constexpr int ARENA_H_BORDER = 32;
	constexpr int ARENA_V_BORDER = 30;
}

