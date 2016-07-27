#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>
#include <string>
#include "Layer.hpp"
#include "Origin.hpp"
#include "Vector2.hpp"
#include "Easing.hpp"
#include <fstream>
#include "Color.hpp"

class Sprite {
public:
	Sprite(const std::string& filePath, Vector2 position = Vector2(320.0f, 240.0f), Layer layer = Layer::Foreground, Origin origin = Origin::Centre);
	void Move(int startTime, int endTime, float startX, float startY, float endX, float endY, Easing easing = Easing::Linear);
	void Move(int startTime, int endTime, Vector2 startPos, Vector2 endPos, Easing easing = Easing::Linear);
	void MoveX(int startTime, int endTime, float startX, float endX, Easing easing);
	void MoveY(int startTime, int endTime, float startY, float endY, Easing easing);
	void Fade(int startTime, int endTime, float startOpacity, float endOpacity, Easing easing = Easing::Linear);
	void Rotate(int startTime, int endTime, float startRotate, float endRotate, Easing easing = Easing::Linear);
	void Scale(int startTime, int endTime, float startScale, float endScale, Easing easing = Easing::Linear);
	void ScaleVector(int startTime, int endTime, float startX, float startY, float endX, float endY, Easing easing = Easing::Linear);
	void ScaleVector(int startTime, int endTime, Vector2 startScale, Vector2 endScale, Easing easing = Easing::Linear);
	void Color(int startTime, int endTime, float startR, float startG, float startB, float endR, float endG, float endB, Easing easing = Easing::Linear);
	void Color(int startTime, int endTime, ::Color startColor, ::Color endColor, Easing easing = Easing::Linear);

	void Write(std::ofstream& outputFile);

	std::vector<std::string> commands;
	float fade;
	Vector2 position;
	float rotation;
	float scale;
	::Color color;
	Vector2 scaleVector;
	// Indicates when the sprite will no longer be on screen
	int endTime;
	Layer layer;
	Origin origin;
	std::string filePath;
};

#endif//SPRITE_HPP
