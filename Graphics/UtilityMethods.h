#pragma once
#define _USE_MATH_DEFINES
#include <math.h> 
#include <chrono>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


class Utility {
public:
	static double timeNow() {
		using namespace std::chrono;
		duration<double, std::milli> time = high_resolution_clock::now().time_since_epoch();
		return time.count();
	}
	
	static float angleBetween(sf::Vector2f a, sf::Vector2f b) {
		return radsBetween(a, b) * (180 / M_PI);
	}
	static float radsBetween(sf::Vector2f a, sf::Vector2f b) {
		return atan2(b.y - a.y, b.x - a.x);
	}

	static void print(std::string str, int number) {
		std::cout << str << ": " << std::to_string(number) << std::endl;
	}
	static void print(std::string str, double number) {
		std::cout << str << ": " << std::to_string(number) << std::endl;
	}
	static void print(std::string str, sf::Vector2f vect) {
		std::cout << str << ": " << std::to_string(vect.x) << ", " << std::to_string(vect.y) << std::endl;
	}
	static void print(std::string str) {
		std::cout << str << std::endl;
	}
	static void print(sf::Vector2f vect) {
		std::stringstream sstr;
		sstr << vect.x << ", " << vect.y << std::endl;
		Utility::print(sstr.str());
	}

	template <typename T>
	static std::vector<T> GetSubVector(std::vector<T> vec, int start, int end) {
		auto first = vec.begin() + start;
		auto last = vec.begin() + end + 1;

		return std::vector<T>(first, last);
	}
};