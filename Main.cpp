#include <iostream>
#include "Game.hpp"
#include <chrono>
#include <thread>


constexpr int TARGET_FPS = 60;
constexpr float TARGET_FPS_MS{ 1000.0f / TARGET_FPS };

template <class T>
auto printFPS = [](T fps) {
	printf("FPS: %.2f\n", fps);
	};

// count fps


int main() {
	std::shared_ptr<Game> game = std::make_shared<Game>("TestGame", 800, 600);

	int frames_rendered = 0;

	using clock = std::chrono::high_resolution_clock;

	
	clock::time_point start_time2 = clock::now();

	using clock = std::chrono::high_resolution_clock;


	while (game->Running()) {

		
		clock::time_point start_time = clock::now();

		game->Tick();

		clock::time_point elapsed_time = clock::now();

		++frames_rendered;
		double duration_seconds = std::chrono::duration<double>(elapsed_time - start_time2).count();
		if (duration_seconds >= 1.0) { // Print FPS every second
			double current_fps = frames_rendered / duration_seconds;
			printFPS<double>(current_fps);
			frames_rendered = 0;
			start_time2 = elapsed_time;
		}
		int64_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time - start_time).count();


		if (duration < TARGET_FPS_MS) {
			std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(TARGET_FPS_MS - duration)));
		}
	}


	return 0;
}