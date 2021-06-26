#pragma once

#include <iostream>
#include <string>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <Windows.h>

using namespace std;

	const enum class Cell : char
	{
		CROSS = 'X',
		ZERO = 'O',
		EMPTY = '-'
	};

	struct Coord
	{
		size_t x;
		size_t y;
	};

	const enum class Progress : int
	{
		IN_PROGRESS,
		WON_HUMAN,
		WON_AI,
		DRAW
	};

#pragma pack(push, 1)
	struct Field
	{
		Cell** ppField = nullptr;
		const size_t SIZE = 3;
		Cell human = Cell::EMPTY;
		Cell ai = Cell::EMPTY;
		size_t turn = 0;
		Progress progress = Progress::IN_PROGRESS;
	};
#pragma pack(pop)

	Progress getWon(const Field& f);
	int32_t getRandomNum(int32_t min, int32_t max);
	void initField(Field& r);
	void deinitField(Field& r);
	void printField(const Field& r);
	void inline clearScr();
	Coord getHumanCoord(Field& f);
	Coord getAICoord(Field& f);
	void congrats(Progress progress);
	void TicTacToe();