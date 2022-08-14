#pragma once

class Controller
{
private:
	int speed;
	int key;
	int score;

public:
	Controller() : speed(200), key(1), score(0) {}
	int Menu();
	int PlayGame();
	int GameOver();

	void Game();
	void Start();
	void Select();
	void DrawGame();
	void RewriteScore();
	void UpdateScore(const int&);
};