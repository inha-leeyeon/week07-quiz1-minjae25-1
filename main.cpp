#include <iostream>
#include <vector>
#include "Point.h"
#include "square.h"
using namespace std;

// Point class
Point::Point(int px, int py)
{
	this->x = px;
	this->y = py;
}
int Point::getX() const
{
	return x;
}
int Point::getY() const
{
	return y;
}
void Point::setX(int x)
{
	this->x = x;
}
void Point::setY(int y)
{
	this->y = y;
}

// Square class
Square::Square(const string name, int x, int y, unsigned int side)
	:Point(x, y)
{
	this->name = name;
	this->side = side;
}
unsigned int Square::getSide() const
{
	return side;
}
unsigned int Square::getArea() const
{
	return side*side;
}
string Square::getName() const
{
	return name;
}
void Square::setSide(unsigned int side)
{
	this->side = side;
}
void Square::setArea(unsigned int area)
{
	this->area = area;
}
void Square::setName(string name)
{
	this->name = name;
}

void printSquare(vector<Square> arr, int size) {
	cout << '\n';
	for (int i = 0; i < size; i++) {
		cout << arr[i].getName() << '(' << arr[i].getX() << ", "
			<< arr[i].getY() << ") side=" << arr[i].getSide() << ", area=" << arr[i].getArea()
			<< endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<Square> squareArr;
	for (int i = 0; i < n; i++) {
		string name;
		int x, y;
		unsigned int side;
		cin >> name >> x >> y >> side;
		squareArr.push_back(Square(name, x, y, side));
	}

	cout << "Squares in increasing order of area" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (squareArr[j - 1].getArea() > squareArr[j].getArea()) {
				Square temp = squareArr[j];
				squareArr[j] = squareArr[j - 1];
				squareArr[j - 1] = temp;
			}
		}
	}
	printSquare(squareArr, n);

	cout << "Squares in increasing order of max x-coordinate" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (squareArr[j - 1].getX() > squareArr[j].getX()) {
				Square temp = squareArr[j];
				squareArr[j] = squareArr[j - 1];
				squareArr[j - 1] = temp;
			}
		}
	}
	printSquare(squareArr, n);

	cout << "Squares in increasing order of max y-coordinate" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (squareArr[j - 1].getY() > squareArr[j].getY()) {
				Square temp = squareArr[j];
				squareArr[j] = squareArr[j - 1];
				squareArr[j - 1] = temp;
			}
		}
	}
	printSquare(squareArr, n);

	return 0;
}