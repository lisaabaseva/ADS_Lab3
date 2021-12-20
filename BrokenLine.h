#pragma once
#include <complex>
#include <iostream>
#include <vector>

struct IntPoint2;
struct DoublePoint3;
struct StdComplexPoint;

template <typename T>
class BrokenLine {
private:
	std::vector<T> v;

public:
	BrokenLine() = default;
	BrokenLine(const BrokenLine<T>& rhs) = default;

	size_t GetSize() const {
		return v.size();
	}

	T& operator[](size_t index) {
		if (v.empty()) throw "Line is empty";
		if ((index >= v.size()) || (index < 0)) throw "Invalid index";
		return v[index];

	}
	T operator[](size_t index) const {
		if (v.empty()) throw "Line is empty";
		if ((index >= v.size()) || (index < 0)) throw "Invalid index";
		return v[index];

	}

	void AddToHead(const T& point) {
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] == point) throw "\nSuch a point already exists. Enter other coordinates: ";
		}
		v.insert(v.begin(), point);


	}
	void AddToEnd(const T& point) {
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] == point) throw "\nSuch a point already exists. Enter other coordinates: ";
		}
		v.push_back(point);
	}

	BrokenLine operator+(const BrokenLine& rhs) {
		if (v.empty()) return rhs;
		if (!rhs.v.size()) return *this;
		BrokenLine res(*this);
		res.v.resize(GetSize() + rhs.GetSize());
		for (size_t i = 0; i < v.size(); i++)
		{
			res.v[i] = v[i];
		}
		size_t size = v.size();
		for (size_t i = 0; i < rhs.GetSize(); i++)
		{
			res.v[size + i] = rhs.v[i];
		}
		return res;
	}

	BrokenLine operator+(const T& rhs) {
		BrokenLine tmp;
		tmp = *this;
		tmp.AddToEnd(rhs);

		return tmp;
	} 

	bool operator==(const BrokenLine& rhs) const {
		if (v.size() != rhs.v.size()) return false;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (!(v[i] == rhs.v[i])) return false;
		}
		return true;

	}

	bool operator!=(const BrokenLine& rhs) const {
		return !this->operator==(rhs);
	}

	double SizeLine() const {
		if ((v.empty()) || (v.size()<=1)) throw "Line is empty";
		float res = 0;
		for (size_t i = 0; i < v.size() - 1; i++)
		{
			res += v[i].Distance(v[i + 1]);
		}
		return res;

	}

	auto begin() {
		return v.begin();
	}

	auto end() {
		return v.end();
	}

	auto cbegin() {
		return v.cbegin();
	}

	auto cend() {
		return v.cend();
	}

};

struct IntPoint2
{
	int _x, _y;

	bool operator==(const IntPoint2& p) const noexcept
	{
		if ((_x == p._x) && (_y == p._y)) return true;
		else return false;
	}

	float Distance(const IntPoint2& p) const noexcept
	{
		return float(sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2)));
	}

	BrokenLine<IntPoint2> operator+(const BrokenLine<IntPoint2>& rhs) {
		BrokenLine<IntPoint2> tmp;
		tmp = rhs;
		tmp.AddToHead(*this);
		return tmp;
	}

};
struct DoublePoint3
{
	double _x, _y, _z;

	bool operator==(const DoublePoint3& p) const noexcept
	{
		if ((_x == p._x) && (_y == p._y) && (_z == p._z)) return true;
		else return false;
	}

	float Distance(const DoublePoint3& p) const noexcept
	{
		return float(sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2) + pow(_z - p._z, 2)));
	}
	BrokenLine<DoublePoint3> operator+(const BrokenLine<DoublePoint3>& rhs) {
		BrokenLine<DoublePoint3> tmp;
		tmp = rhs;
		tmp.AddToHead(*this);
		return tmp;
	}
};
struct StdComplexPoint {
	std::complex<double> _x, _y;

	bool operator==(const StdComplexPoint& p) const noexcept
	{
		if ((_x == p._x) && (_y == p._y)) return true;
		else return false;
	}

	float Distance(const StdComplexPoint& p) const noexcept
	{
		return float(sqrt(_x.real() * _x.real() + _y.imag() * _y.imag()));
	}

	BrokenLine<StdComplexPoint> operator+(const BrokenLine<StdComplexPoint>& rhs) {
		BrokenLine<StdComplexPoint> tmp;
		tmp = rhs;
		tmp.AddToHead(*this);
		return tmp;
	}
};

std::ostream& operator<<(std::ostream& out, const IntPoint2& point)
{
	out << "[" << point._x << ";" << point._y << "]";
	return out;
}

std::ostream& operator<< (std::ostream& out, const DoublePoint3& point)
{
	out << "[" << point._x << ";" << point._y << ";" << point._z << "]";
	return out;
}

std::ostream& operator<< (std::ostream& out, const StdComplexPoint& point)
{
	out << "[" << point._x << ";" << point._y << " * i" << "]";
	return out;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const BrokenLine<T>& rhs)
{
	out << "BrokenLine <";
	for (size_t i = 0; i < rhs.GetSize(); i++)
	{
		if (i != rhs.GetSize() - 1) out << rhs[i] << ", ";
		else out << rhs[i];
	}
	out << ">";
	return out;
}

std::ostream& operator<<(std::ostream& out, const BrokenLine<IntPoint2>& rhs)
{
	for (size_t i = 0; i < rhs.GetSize(); i++) {
		out << rhs[i];
	}
	return out;

}

std::ostream& operator<<(std::ostream& out, const BrokenLine<DoublePoint3>& rhs)
{
	for (size_t i = 0; i < rhs.GetSize(); i++) {
		out << rhs[i];
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const BrokenLine<std::complex<double>>& rhs)
{
	for (size_t i = 0; i < rhs.GetSize(); i++) {
		out << rhs[i];
	}
	return out;
}